///
/// MIB_Project : 첫 번째 WinAPI 프로젝트
/// 게임명 : 거기에.
/// 장르 : 공포, 방탈출
/// 제작자 : 최민경 & 임효빈
/// 제작일시 : 2020 - 11 - 15
/// 

#include "pch.h"
//#pragma comment(lib, "./Release/MIB_Engine")
////////////////////////////////////////////////////
const wchar_t* g_ClassName = L"MIB WinAPI Project";
const wchar_t* g_WindowName = L"거기에.";

#pragma region 전역변수들
//GameManager
GameManager* pGM;	// 게임 매니저(모든 데이터 관리)

//Scene
void (*pScenes[(int)SCENE::SCENENUM])();	// 씬 포인터

//Room
void (*pRooms[(int)ROOM::ROOMNUM])();	//방 포인터
#pragma endregion

// 윈도 프로시저의 전방선언
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

//게임에 필요한 데이터들을 불러오는 함수
void LoadData();

#pragma region Scenes
//Scene
void Title();
void Intro();
void InGame();
void GameOver();
void Ending();
#pragma endregion

#pragma region Room
//Room
void HallWay();
void Room301();
void Room302();
void Room303();
void Room304();
void SecretRoom();
#pragma endregion

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
	/// 윈도를 등록한다.
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL; // MAKEINTRESOURCEW(IDC_PROJECT1);
	wcex.lpszClassName = g_ClassName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassExW(&wcex);

	// 애플리케이션 초기화를 수행합니다.
	HWND hWnd = CreateWindowW(g_ClassName, g_WindowName, WS_OVERLAPPED | WS_SYSMENU,
		CW_USEDEFAULT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	//ynMMedia_Initial(hWnd);

	//게임에 필요한 데이터들을 로드한다.
	pGM = new GameManager();
	pGM->Init(hInstance, hWnd, WINDOW_WIDTH, WINDOW_HEIGHT);
	LoadData();

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;

	// 기본 메시지 루프입니다:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			// 시간에 따른 프레임 체크 
			if (!pGM->FPSCheck())
			{
				continue;
			}

			//키 입력
			pGM->KeyInput();

			pGM->ResetInfo();
			//게임 부분
			if (pGM->IsWaitScript())
			{
				if (pGM->GetKey(KEY_ESC))
				{
					pGM->ClearScripts();
					pGM->ResetScript();
				}
				if (pGM->GetKey(KEY_SPACE))
				{
					pGM->ResetScript();
				}
			}
			else
			{
				pGM->Update();

				pGM->DrawBegin();
				//씬 실행
				pScenes[pGM->GetScene()]();

				pGM->DrawEnd();
			}
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

//데이터 로드
void LoadData()
{
#pragma region Scene 로드
	pScenes[(int)SCENE::TITLE] = Title;
	pScenes[(int)SCENE::INTRO] = Intro;
	pScenes[(int)SCENE::INGAME] = InGame;
	pScenes[(int)SCENE::GAMEOVER] = GameOver;
	pScenes[(int)SCENE::ENDING] = Ending;
#pragma endregion

#pragma region Room 로드
	pRooms[(int)ROOM::HALLWAY] = HallWay;
	pRooms[(int)ROOM::ROOM301] = Room301;
	pRooms[(int)ROOM::ROOM302] = Room302;
	pRooms[(int)ROOM::ROOM303] = Room303;
	pRooms[(int)ROOM::ROOM304] = Room304;
	pRooms[(int)ROOM::SECRETROOM] = SecretRoom;
#pragma endregion
}

#pragma region Scene 함수 정의
//Title
void Title()
{
	pGM->BGMStop(AUDIO::BGM_RAIN);
	pGM->BGMStop(AUDIO::BGM_WIND);

	if (pGM->GetKey(KEY_UP))
		if (pGM->GetCursor() > 0)
			pGM->SetCursor(pGM->GetCursor() - 1);
	if (pGM->GetKey(KEY_DOWN))
		if (pGM->GetCursor() < 1)
			pGM->SetCursor(pGM->GetCursor() + 1);

	switch (pGM->GetCursor())
	{
	case 0:
		//Start
		pGM->SetAniFrm(UI::TITLE_START, 0);
		pGM->SetAniFrm(UI::TITLE_EXIT, 1);

		//시작하기 버튼 선택
		if (pGM->GetKey(KEY_SPACE))
		{
			pGM->ResetData();
			pGM->SetScene(SCENE::INTRO);
			pGM->SetRoom(ROOM::INTRO_HALLWAY);
			pGM->RoomSet();
			pGM->AddScripts(SCR_ID::STORY_INTRO_1);
			pGM->SetWaitTime(1);

			pGM->SoundPlay(AUDIO::EFS_PHONE_RING);

			return;
		}
		break;

	case 1:
		//Quit
		pGM->SetAniFrm(UI::TITLE_START, 1);
		pGM->SetAniFrm(UI::TITLE_EXIT, 0);
		if (pGM->GetKey(KEY_SPACE))
		{
			PostQuitMessage(WM_DESTROY);
		}
		break;
	}

	//그리기
	pGM->DrawBG(BG::TITLE);
	pGM->DrawUI();
}

//Intro
void Intro()
{
	if (pGM->IsWaitTime())
	{
		return;
	}
	if (pGM->IsStory(START_SOUND_) && !pGM->IsStory(SCREAMING_))
	{
		pGM->SoundPlay(AUDIO::MONSTER_ROAR, 0.7f);	//★안들림
		pGM->SoundPlay(AUDIO::EFS_SCREAMING, 0.4f);
		pGM->SetStory(SCREAMING_);
	}

	//시스템 키 체크
	pGM->SystemCheck();

	//게임 시작
	if (pGM->IsStory(INTRO_SWITCH) && pGM->IsStory(START_SOUND_))
	{
		if (pGM->GetScriptsSize() <= 0)
		{
			pGM->AddScripts(SCR_ID::STORY_1_1);
			pGM->SetScene(SCENE::INGAME);
			pGM->SetRoom(ROOM::ROOM303);
			pGM->RoomSet();

			pGM->SetSavePos(DOOR303_POS);
			pGM->SetPlayerPos(280);

			return;
		}
	}

	//캐릭터 이동
	if (pGM->IsStory(END_CALL_))
	{
		//아이템 변경
		if (pGM->GetKey(KEY_TAB))
		{
			pGM->ChangeEquip();
		}

		//캐릭터 이동
		pGM->PlayerMove();

		//충돌 검사
		pGM->HitObj();

		//예외상황 막아두기
		switch (pGM->GetInfo().m_Item)
		{
		case OBJ::ESCAPE:
		case OBJ::DOOR:
		{
			pGM->ResetInfo();
		}
		break;
		}

		//상호작용
		if (pGM->GetKey(KEY_SPACE))
		{
			switch (pGM->GetInfo().m_Item)
			{
			case OBJ::INTRO303:
			{
				pGM->SoundPlay(AUDIO::EFS_DOOR_OPEN);
				pGM->MoveDoor();
			}
			break;

			case OBJ::SWITCH:
			{
				pGM->AddScripts(SCR_ID::STORY_INTRO_3);
				pGM->SetStory(INTRO_SWITCH);
				pGM->SoundPlay(AUDIO::EFS_SWICH);
			}
			break;

			case OBJ::TOILET:
			{
				pGM->AddScripts(SCR_ID::NORMAL_5);
			}
			break;

			}
		}
	}

	//배경 그리기
	if (!pGM->IsStory(END_CALL_))
	{
		if (pGM->GetScriptsSize() < 8)
		{
			pGM->DrawBG(BG::ENDING, { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 }, true);
			if (pGM->GetScriptsSize() == 7)
			{
				pGM->SoundPause(AUDIO::EFS_PHONE_RING);
			}
		}
	}
	else if (!pGM->IsStory(INTRO_SWITCH))
	{
		pGM->Scroll();
		(pGM->GetRoom() == (int)ROOM::INTRO_HALLWAY) ?
			pGM->DrawBG(BG::INTROHALL, { pGM->GetScrollX() , 200 }) :
			pGM->DrawBG(BG::INTRO303, { pGM->GetScrollX() , 200 });
	}

	//오브젝트 & 플레이어 그리기
	if (pGM->IsStory(END_CALL_) && !pGM->IsStory(INTRO_SWITCH))
	{
		pGM->DrawObj();
		pGM->DrawUnit();
	}

	//Script 출력
	pGM->ScriptOut();

	//UI 그리기
	if (pGM->IsStory(END_CALL_) && !pGM->IsStory(INTRO_SWITCH))
	{
		pGM->DrawUI();
	}

	if (pGM->GetScriptsSize() <= 0)
	{
		if (!pGM->IsStory(END_CALL_))
		{
			pGM->RoomSet();
			pGM->SetStory(END_CALL_);
			pGM->AddScripts(SCR_ID::STORY_INTRO_2);
			pGM->SetPlayerPos(2600);
			pGM->Scroll();
		}
		else if (!pGM->IsStory(START_SOUND_))
		{
			if (pGM->IsStory(INTRO_SWITCH))
			{
				pGM->AddScripts(SCR_ID::STORY_INTRO_4);
				pGM->SetWaitTime(3);
				pGM->SetStory(START_SOUND_);
			}
		}
	}
	if (pGM->IsStory(END_CALL_))
	{
		pGM->SoundPause(AUDIO::EFS_PHONE_RING);
	}
}

//InGame
void InGame()
{
	//시스템 키 체크
	pGM->SystemCheck();

	//아이템 변경
	if (pGM->GetKey(KEY_TAB))
	{
		pGM->ChangeEquip();
	}

	//이동
	pGM->PlayerMove();		//캐릭터 이동
	pGM->MonsterMove();		//몬스터 이동

	//충돌 검사
	pGM->HitObj();

	//몬스터랑 부딫혔는지 체크
	if (pGM->IsDead())
	{
		pGM->SetScene(SCENE::GAMEOVER);
		pGM->SetWaitTime(1);

		return;
	}

	//현재 방 함수 실행
	pRooms[pGM->GetRoom()]();

	//그리기
	pGM->DrawBG();		//배경 그리기
	pGM->DrawObj();		//오브젝트 그리기
	pGM->DrawUnit();	//캐릭터 & 몬스터 그리기
	pGM->DrawUI();		//UI 그리기
	pGM->ScriptOut();	//Script 출력
}

//GameOver
void GameOver()
{
	if (pGM->IsWaitTime())
	{
		return;
	}

	pGM->DrawBG(BG::GAMEOVER);

	if (pGM->GetKey(KEY_SPACE))
	{
		pGM->BGMStop(AUDIO::BGM_RAIN);
		pGM->BGMStop(AUDIO::BGM_WIND);
		pGM->SetScene(SCENE::TITLE);
	}
}

//Ending
void Ending()
{
	//배경 그리기
	if (!pGM->IsStory(ENDING_))
	{
		if (pGM->GetScriptsSize() <= 15)
		{
			(pGM->GetScriptsSize() > 1) ?
				pGM->DrawBG(BG::ENDING, { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 }, true) :
				pGM->DrawBG(BG::ENDING2, { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 }, true);
		}
	}

	//Script 출력
	pGM->ScriptOut();

	//Script 진행
	if (pGM->GetScriptsSize() <= 0)
	{
		if (!pGM->IsStory(ENDING_))
		{
			pGM->SetStory(ENDING_);
			pGM->AddScripts(SCR_ID::STORY_END_STAFF);
		}
		else
		{
			if (!pGM->IsStory(ENDING_STAFF))
			{
				
				pGM->SetStory(ENDING_STAFF);
				pGM->SetWaitTime(1);
			}
			if (!pGM->IsWaitTime())
			{
				pGM->SetScene(SCENE::TITLE);
			}
		}
	}
	else
	{
		if (!pGM->IsStory(ENDING_))
		{
			if (pGM->GetScriptsSize() == 15)
			{
				pGM->SoundPlay(AUDIO::EFS_PHONE_RING);
			}
			else
			{
				pGM->SoundPause(AUDIO::EFS_PHONE_RING);
			}
		}
	}
	if (pGM->IsStory(ENDING_))
	{
		pGM->SoundPause(AUDIO::EFS_PHONE_RING);
	}
}
#pragma endregion

#pragma region Room 함수 정의
void HallWay()
{
	//횡스크롤
	pGM->Scroll();

	//Event
	if (pGM->IsStory(BREAK_SEAL_))
	{
		if (pGM->GetMonsterWaitTime() > 0)
		{
			pGM->SetMonsterWaitTime(pGM->GetMonsterWaitTime() - pGM->GetdTime());
		}
		else
		{
			pGM->SetMonsterWait(false);
			pGM->SetMonsterActive(true);
		}
	}

	if (pGM->GetScriptsSize() == 0 && pGM->IsStory(COMPLETE_RUN_))
	{
		pGM->SetScene(SCENE::ENDING);
		pGM->AddScripts(SCR_ID::STORY_END_1);
	}

	//예외상황들
	if (!pGM->IsGame(USE_KNIFE_))
	{
		switch (pGM->GetInfo().m_Item)
		{
			//301호 문
		case OBJ::DOOR301:
		{
			//뼈 열쇠 사용 전 : 잠긴 문 / 사용 후 : 301호 문
			if (!pGM->IsGame(USE_BONEKEY_))
			{
				pGM->SetInfo(OBJ::DOOR301, { INFO_ID::INTER_DOOR, ITEM_,OBJ::DOOR301, ROOM::ROOM301 });
			}
			else
			{
				pGM->SetInfo(OBJ::DOOR301, { INFO_ID::TO_301, DOOR_,OBJ::DOOR301, ROOM::ROOM301 });
			}
		}
		break;

		//302호 문
		case OBJ::DOOR302:
		{
			//몬스터에게 쫓길때(스페이스 연타로 문 열기 할때) 상호작용 막아두기
			if (pGM->IsGame(GET_BONEKEY_) && pGM->GetMonsterActive())
			{
				pGM->ResetInfo();
			}
		}
		break;

		//303호 문
		case OBJ::DOOR303:
		{
			//문 고장난거 체크하면 더이상 상호작용 못함
			if (!pGM->IsStory(CHECK_303_))
			{
				pGM->SetInfo(OBJ::DOOR303, { INFO_ID::TO_303, ITEM_,OBJ::DOOR303 });
			}
			else
			{
				pGM->ResetInfo();
			}
		}
		break;

		//304호 문
		case OBJ::DOOR304:
		{
			if (!pGM->IsGame(USE_KEYS_))
			{
				pGM->SetInfo(OBJ::DOOR304, { INFO_ID::INTER_DOOR , ITEM_,OBJ::DOOR304 });
			}
			else
			{
				pGM->SetInfo(OBJ::DOOR304, { INFO_ID::TO_304 , DOOR_ ,OBJ::DOOR304, ROOM::ROOM304 });
			}
		}
		break;

		//소화전
		case OBJ::FIREHYDRANT:
		{
			//SD카드 사용 전까지 비활성화
			if (!pGM->IsGame(USE_SDMEMORY_))
			{
				pGM->ResetInfo();
			}
		}
		break;

		}
	}
	else if (pGM->GetInfo().m_Type != ESC_)
	{
		pGM->ResetInfo();
	}

	////게시판(치트)
	//if (pGM->GetInfo().m_Item == OBJ::BOARD)
	//{
	//	if (pGM->GetKey(KEY_F7))
	//	{
	//		pGM->SetGame(0xffff);
	//		pGM->SetStory(DEBUG_FIN_);
	//		pGM->AddScripts(SCR_ID::DEBUG);
	//	}
	//}

	//상호작용
	if (pGM->GetKey(KEY_SPACE))
	{
		if (!pGM->IsStory(CHECK_ESCAPE_))
		{
			if (pGM->GetInfo().m_Type == ESC_)
			{
				pGM->SetStory(CHECK_ESCAPE_);
				pGM->AddScripts(SCR_ID::STORY_2_2);

				pGM->SetAniFrm(OBJ::DOOR302, 1);

				pGM->SoundPlay(AUDIO::MONSTER_ROAR);
				pGM->SetMonsterActive(true);
				pGM->SetMonsterPos(3400);
			}
			else if (pGM->GetInfo().m_Type != NONE_)
			{
				pGM->AddScripts(SCR_ID::EVENT_MESSAGE_1);
			}
		}
		else
		{
			switch (pGM->GetInfo().m_Type)
			{
			case DOOR_:
			{
				switch (pGM->GetInfo().m_Item)
				{
				case OBJ::DOOR301:
				{
					pGM->SoundPlay(AUDIO::EFS_DOOR_OPEN);
					pGM->SetSavePos(DOOR301_POS);
					pGM->MoveDoor();
				}
				break;

				case OBJ::DOOR302:
				{
					if (!pGM->IsStory(RUN_MONSTER_))
					{
						pGM->SetStory(RUN_MONSTER_);
						pGM->SetMonsterActive(false);
						pGM->SetAniFrm(OBJ::DOOR302, 0);
						pGM->AddScripts(SCR_ID::STORY_3_1);
					}
					pGM->SoundPlay(AUDIO::EFS_DOOR_OPEN);
					pGM->SetSavePos(DOOR302_POS);
					pGM->MoveDoor();
				}
				break;

				case OBJ::DOOR304:
				{
					pGM->SoundPlay(AUDIO::EFS_DOOR_OPEN);
					pGM->SetSavePos(DOOR304_POS);
					pGM->MoveDoor();
				}
				break;

				}
			}
			break;

			case ITEM_:
			{
				switch (pGM->GetInfo().m_Item)
				{
				case OBJ::DOOR301:
				{
					if (!pGM->IsGame(GET_BONEKEY_))
					{
						pGM->AddScripts(SCR_ID::NORMAL_1);
					}
					else if (pGM->IsItem(UI::ITEM_BONEKEY))
					{
						static int n = 0;
						if (!pGM->IsStory(UNLOCK_1_))
						{
							pGM->SetStory(UNLOCK_1_);
							pGM->SetAniFrm(OBJ::DOOR301, 1);
							pGM->AddScripts(SCR_ID::STORY_5_3);
						}
						else if (!pGM->IsStory(UNLOCK_2_))
						{
							pGM->SetStory(UNLOCK_2_);
							pGM->SetAniFrm(OBJ::DOOR301, 2);
							pGM->AddScripts(SCR_ID::STORY_5_4);
							n = 0;
						}
						else
						{
							if (n <= 0)
							{
								pGM->AddScripts(SCR_ID::STORY_5_5);
								n++;
							}
							else if (n == 1)
							{
								pGM->AddScripts(SCR_ID::STORY_5_6);

								if (!pGM->IsStory(RUN_MONSTER_2_))
								{
									//몬스터 두둥등장
									pGM->SetMonsterActive(true);
									pGM->SetMonsterPos(pGM->GetPlayerX() + 1000);
									pGM->SetMonsterSpeed(12);
								}

								n++;
							}
							else if (n >= 7)
							{
								pGM->SetAniFrm(OBJ::DOOR301, 3);

								pGM->UseItem();
								pGM->SetGame(USE_BONEKEY_);

								pGM->SetMonsterActive(false);
								pGM->SetMonsterSpeed(11.0f);
								pGM->SetStory(RUN_MONSTER_2_);

								pGM->SoundPlay(AUDIO::EFS_DOOR_OPEN);
								pGM->SetRoom(ROOM::ROOM301);
								pGM->SoundPlay(AUDIO::EFS_KEY_SKELETON);
								pGM->MoveDoor();
								pGM->SetSavePos(DOOR301_POS);
							}
							else
							{
								if (n >= 6)
								{
									pGM->AddScripts(SCR_ID::STORY_5_9);
								}
								else
								{
									if (n % 2 == 1)
										pGM->AddScripts(SCR_ID::STORY_5_7);
									else
										pGM->AddScripts(SCR_ID::STORY_5_8);
								}
								n++;
							}
						}
					}
					else
					{
						pGM->AddScripts(SCR_ID::NORMAL_3);
					}
				}
				break;

				case OBJ::DOOR303:
				{
					if (!pGM->IsStory(RUN_MONSTER_))
					{
						pGM->AddScripts(SCR_ID::EVENT_MESSAGE_3);
						pGM->AddScripts(SCR_ID::EVENT_MESSAGE_2);
					}
					else if (!pGM->IsStory(CHECK_303_))
					{
						pGM->SetStory(CHECK_303_);
						pGM->AddScripts(SCR_ID::EVENT_MESSAGE_4);
					}
				}
				break;

				case OBJ::DOOR304:
				{
					if (!pGM->IsStory(RUN_MONSTER_))
					{
						pGM->AddScripts(SCR_ID::EVENT_MESSAGE_2);
					}
					else if (!pGM->IsGame(USE_KEYS_))
					{
						if (pGM->IsItem(UI::ITEM_KEYSET))
						{
							pGM->SoundPlay(AUDIO::EFS_KEY_UNLOCKING);
							pGM->SetGame(USE_KEYS_);
							pGM->UseItem();
							pGM->AddScripts(SCR_ID::STORY_3_3);
						}
						else
						{
							pGM->AddScripts(SCR_ID::NORMAL_3);
						}
					}
					else
					{
						pGM->AddScripts(SCR_ID::NORMAL_3);
					}
				}
				break;

				case OBJ::BOARD:
				{
					pGM->AddScripts(SCR_ID::INTER_BOARD);
				}
				break;

				case OBJ::FIREHYDRANT:
				{
					if (!pGM->IsGame(GET_BONEKEY_))
					{
						if (!pGM->IsStory(CHECK_FIRE_))
						{
							pGM->SoundPlay(AUDIO::EFS_HYDRANT_OPEN);
							pGM->SetStory(CHECK_FIRE_);
							pGM->SetAniFrm(OBJ::FIREHYDRANT, 1);
							pGM->AddScripts(SCR_ID::STORY_5_1);
						}
						else
						{
							pGM->SoundPlay(AUDIO::EFS_KEY_CHARMING);
							pGM->SetGame(GET_BONEKEY_);
							pGM->GetItem(UI::ITEM_BONEKEY);
							pGM->AddScripts(SCR_ID::STORY_5_2);
						}
					}
					else
					{
						pGM->AddScripts(SCR_ID::NORMAL_2);
					}
				}
				break;

				}
			}
			break;

			case ESC_:
			{
				if (pGM->IsGame(USE_KNIFE_))
				{
					pGM->SetStory(COMPLETE_RUN_);
					pGM->SoundPlay(AUDIO::EFS_DOOR_OPEN);
					pGM->AddScripts(SCR_ID::STORY_7_6);
				}
				else
				{
					pGM->AddScripts(SCR_ID::NORMAL_1);
				}
			}
			break;
			}

		}
	}
}

void Room301()
{
	//Event
	if (pGM->IsStory(BREAK_SEAL_))
	{
		if (pGM->GetMonsterWaitTime() > 0)
		{
			pGM->SetMonsterWaitTime(pGM->GetMonsterWaitTime() - pGM->GetdTime());
		}
		else
		{
			pGM->SetMonsterWait(false);
			pGM->SetMonsterActive(true);
		}
	}

	//예외처리
	pGM->SetInfo(OBJ::SECRETDOOR, { INFO_ID::TO_SECRET, DOOR_, OBJ::SECRETDOOR, ROOM::SECRETROOM });
	if (pGM->IsGame(USE_KNIFE_))
	{
		if (pGM->GetInfo().m_Item != OBJ::DOOR)
			pGM->ResetInfo();
	}
	if (pGM->IsGame(USE_FULLBUCKET_))
	{
		pGM->SetInfo(OBJ::CHARM, { INFO_ID::TO_SECRET, DOOR_, OBJ::SECRETDOOR, ROOM::SECRETROOM });
	}

	//상호작용
	if (pGM->GetKey(KEY_SPACE))
	{
		switch (pGM->GetInfo().m_Type)
		{
		case DOOR_:
		{
			switch (pGM->GetInfo().m_Item)
			{
				//현관문
			case OBJ::DOOR:
			{
				if (pGM->IsGame(USE_KNIFE_))
				{
					pGM->SetMonsterActive(false);
					pGM->SetMonsterWaitTime(1.0f);
					pGM->SetMonsterPos(150);
				}
				pGM->MoveDoor();
			}
			break;

			//비밀문
			case OBJ::SECRETDOOR:
			{
				pGM->MoveDoor();
			}
			break;

			}
		}
		break;

		case ITEM_:
		{
			switch (pGM->GetInfo().m_Item)
			{

				//화장실
			case OBJ::TOILET:
			{
				if (!pGM->IsGame(GET_EMPTYBUCKET_))
				{
					pGM->AddScripts(SCR_ID::NORMAL_5);
				}
				else if (pGM->IsStory(CHECK_CHARM_))
				{
					if (!pGM->IsGame(GET_FULLBUCKET_))
					{
						if (pGM->IsItem(UI::ITEM_BUCKET))
						{
							pGM->SoundPlay(AUDIO::EFS_WATER_FLOW);
							pGM->SetGame(GET_FULLBUCKET_);
							pGM->SetAniFrm(UI::ITEM_BUCKET, 1);
							pGM->AddScripts(SCR_ID::STORY_6_3);
						}
						else
						{
							pGM->AddScripts(SCR_ID::NORMAL_3);
						}
					}
					else
					{
						pGM->AddScripts(SCR_ID::NORMAL_4);
					}
				}
				else
				{
					pGM->AddScripts(SCR_ID::NORMAL_5);
				}
			}
			break;

			//양동이
			case OBJ::BUCKET:
			{
				if (!pGM->IsGame(GET_EMPTYBUCKET_))
				{
					pGM->SoundPlay(AUDIO::EFS_EMPTY_BUCKET);
					pGM->SetGame(GET_EMPTYBUCKET_);
					pGM->GetItem(UI::ITEM_BUCKET);
					pGM->SetObjActive(OBJ::BUCKET, false);
					pGM->AddScripts(SCR_ID::STORY_6_2);
				}
			}
			break;

			//부적
			case OBJ::CHARM:
			{
				if (!pGM->IsStory(CHECK_CHARM_))
				{
					pGM->SetStory(CHECK_CHARM_);
					pGM->AddScripts(SCR_ID::STORY_6_1);
				}
				else
				{
					if (pGM->IsGame(GET_FULLBUCKET_))
					{
						if (!pGM->IsGame(USE_FULLBUCKET_))
						{
							if (pGM->IsItem(UI::ITEM_BUCKET))
							{
								pGM->SoundPlay(AUDIO::EFS_CHAMR_MELT);
								pGM->SetGame(USE_FULLBUCKET_);
								pGM->UseItem();
								pGM->SetAniFrm(OBJ::CHARM, 1);
								pGM->AddScripts(SCR_ID::STORY_6_4);
							}
							else
							{
								pGM->AddScripts(SCR_ID::NORMAL_3);
							}
						}
						else
						{
							if (!pGM->IsStory(FIND_SECRET_))
							{
								pGM->SetStory(FIND_SECRET_);
								pGM->SetObjActive(OBJ::SECRETDOOR, true);
								pGM->AddScripts(SCR_ID::STORY_6_5);
							}
						}
					}
					else
					{
						pGM->AddScripts(SCR_ID::STORY_6_1);
					}
				}
			}
			break;
			}
		}
		break;

		}

	}
}

void Room302()
{
	//상호작용
	if (pGM->GetKey(KEY_SPACE))
	{
		switch (pGM->GetInfo().m_Type)
		{
		case DOOR_:
		{
			switch (pGM->GetInfo().m_Item)
			{
				//현관문
			case OBJ::DOOR:
			{
				pGM->SoundPlay(AUDIO::EFS_DOOR_OPEN);
				pGM->MoveDoor();
			}
			break;
			}
		}
		break;

		case ITEM_:
		{
			switch (pGM->GetInfo().m_Item)
			{

				//목 매단 시체
			case OBJ::HANGDEAD:
			{
				if (!pGM->IsGame(GET_KEYS_))
				{
					pGM->SoundPlay(AUDIO::EFS_KEY_CHARMING);
					pGM->SetGame(GET_KEYS_);
					pGM->GetItem(UI::ITEM_KEYSET);
					pGM->AddScripts(SCR_ID::STORY_3_2);
				}
				else
				{
					pGM->AddScripts(SCR_ID::NORMAL_2);
				}
			}
			break;

			//경비 일지
			case OBJ::BOOK:
			{
				pGM->SoundPlay(AUDIO::EFS_PAPER);
				pGM->AddScripts(SCR_ID::INTER_BOOK);
			}
			break;

			}
		}
		break;

		}

	}
}

void Room303()
{
	//INFO 예외 상황
	switch (pGM->GetInfo().m_Item)
	{
		//현관문
	case OBJ::DOOR:
	{
		// 첫 문 체크 전 : 일반 문 / 체크 후 : 망가진 문 / 고친 후 : 일반 문
		if (!pGM->IsStory(CHECK_DOOR_))
		{
			pGM->SetInfo(OBJ::DOOR, { INFO_ID::TO_HALLWAY , ITEM_,OBJ::DOOR });
		}
		else if (!pGM->IsGame(USE_CROWBAR_))
		{
			pGM->SetInfo(OBJ::DOOR, { INFO_ID::INTER_DOOR , ITEM_,OBJ::DOOR });
		}
		else
		{
			pGM->SetInfo(OBJ::DOOR, { INFO_ID::TO_HALLWAY , DOOR_,OBJ::DOOR, ROOM::HALLWAY });
		}
	}
	break;

	case OBJ::SWITCH:
	{
		pGM->ResetInfo();
	}
	break;

	}

	//상호작용
	if (pGM->GetKey(KEY_SPACE))
	{
		switch (pGM->GetInfo().m_Type)
		{
		case DOOR_:
		{
			switch (pGM->GetInfo().m_Item)
			{
				//현관문
			case OBJ::DOOR:
			{
				pGM->SoundPlay(AUDIO::EFS_DOOR_OPEN);
				pGM->MoveDoor();
			}
			break;
			}
		}
		break;

		case ITEM_:
		{
			switch (pGM->GetInfo().m_Item)
			{
				//현관문
			case OBJ::DOOR:
			{
				if (!pGM->IsStory(CHECK_DOOR_))
				{
					pGM->SetStory(CHECK_DOOR_);
					pGM->AddScripts(SCR_ID::STORY_1_2);
				}
				else if (pGM->IsGame(GET_CROWBAR_))
				{
					if (pGM->IsItem(UI::ITEM_CROWBAR))
					{
						pGM->SetGame(USE_CROWBAR_);
						pGM->UseItem();
						pGM->AddScripts(SCR_ID::STORY_1_4);
					}
					else
					{
						pGM->AddScripts(SCR_ID::NORMAL_2);
					}
				}
				else
				{
					pGM->AddScripts(SCR_ID::NORMAL_1);
				}
			}
			break;

			//가방
			case OBJ::BAG:
			{
				if (pGM->IsStory(CHECK_DOOR_) && !pGM->IsGame(GET_CROWBAR_))
				{
					pGM->SoundPlay(AUDIO::EFS_BAG);
					pGM->SetGame(GET_CROWBAR_);
					pGM->SetAniFrm(OBJ::BAG, 1);
					pGM->GetItem(UI::ITEM_CROWBAR);
					pGM->AddScripts(SCR_ID::STORY_1_3);
				}
				else
				{
					pGM->AddScripts(SCR_ID::NORMAL_2);
				}
			}
			break;

			//화장실
			case OBJ::TOILET:
			{
				pGM->AddScripts(SCR_ID::NORMAL_5);
			}
			break;

			}
		}
		break;

		}

	}
}

void Room304()
{
	//상호작용
	if (pGM->GetKey(KEY_SPACE))
	{
		switch (pGM->GetInfo().m_Type)
		{
		case DOOR_:
		{
			switch (pGM->GetInfo().m_Item)
			{
				//현관문
			case OBJ::DOOR:
			{
				pGM->MoveDoor();
			}
			break;
			}
		}
		break;

		case ITEM_:
		{
			switch (pGM->GetInfo().m_Item)
			{

				//칼 꽂힌 시체
			case OBJ::DEADBODY:
			{
				if (!pGM->IsStory(CHECK_DEADGIRL_))
				{
					pGM->SetStory(CHECK_DEADGIRL_);
					pGM->AddScripts(SCR_ID::STORY_4_2);
				}
				else if (!pGM->IsGame(GET_KNIFE_))
				{
					pGM->SetGame(GET_KNIFE_);
					pGM->SetAniFrm(OBJ::DEADBODY, 1);
					pGM->GetItem(UI::ITEM_KNIFE);
					pGM->AddScripts(SCR_ID::STORY_4_3);
				}
				else
				{
					pGM->AddScripts(SCR_ID::NORMAL_2);
				}
			}
			break;

			//카메라
			case OBJ::CAMERA:
			{
				if (!pGM->IsGame(GET_SDMEMORY_))
				{
					pGM->SetGame(GET_SDMEMORY_);
					pGM->GetItem(UI::ITEM_SDCARD);
					pGM->AddScripts(SCR_ID::STORY_4_5);
				}
				else
				{
					pGM->AddScripts(SCR_ID::NORMAL_2);
				}
			}
			break;

			//컴퓨터
			case OBJ::NOTEBOOK:
			{
				if (!pGM->IsGame(GET_SDMEMORY_))
				{
					if (!pGM->IsStory(CHECK_NOTEBOOK_))
					{
						pGM->SetStory(CHECK_NOTEBOOK_);
						pGM->AddScripts(SCR_ID::STORY_4_4);
					}
					else
					{
						pGM->AddScripts(SCR_ID::NORMAL_2);
					}
				}
				else
				{
					if (!pGM->IsGame(USE_SDMEMORY_))
					{
						if (pGM->IsItem(UI::ITEM_SDCARD))
						{
							pGM->SetGame(USE_SDMEMORY_);
							pGM->SoundPlay(AUDIO::SDCARD);
							pGM->SetAniFrm(OBJ::NOTEBOOK, 1);
							pGM->UseItem();
							pGM->AddScripts(SCR_ID::STORY_4_6);
						}
						else
						{
							pGM->AddScripts(SCR_ID::NORMAL_3);
						}
					}
					else
					{
						pGM->AddScripts(SCR_ID::NORMAL_4);
					}
				}
			}
			break;

			//화장실
			case OBJ::TOILET:
			{
				pGM->AddScripts(SCR_ID::NORMAL_5);
			}
			break;
			}
		}
		break;

		}

	}
}

void SecretRoom()
{
	//Event
	if (pGM->IsGame(USE_KNIFE_) && !pGM->IsStory(BREAK_SEAL_))
	{
		if (pGM->IsAniFrm(OBJ::MAGICCIRCLE, OBJ::MAGICCIRCLE))
		{
			pGM->SetStory(BREAK_SEAL_);
			pGM->SetStory(RUN_MONSTER_3_);
			pGM->AddScripts(SCR_ID::STORY_7_5);

			pGM->SoundPlay(AUDIO::MONSTER_ROAR);
			pGM->SetMonsterActive(true);
			pGM->SetMonsterPos(80);
			pGM->SetMonsterState(MONSTER::RUN_R);
		}
		else
		{
			pGM->SetAniFrm(OBJ::ALTAR, 1);
			pGM->AniPlay(OBJ::MAGICCIRCLE);
			pGM->AniPlay(OBJ::CANDLE_FIRE_L);
			pGM->AniPlay(OBJ::CANDLE_FIRE_R);
		}
	}

	//예외처리
	pGM->SetInfo(OBJ::SECRETDOOR, { INFO_ID::TO_301, DOOR_, OBJ::SECRETDOOR, ROOM::ROOM301 });
	pGM->SetInfo(OBJ::MAGICCIRCLE, { INFO_ID::INTER_ALTAR, DOOR_, OBJ::MAGICCIRCLE });
	switch (pGM->GetInfo().m_Item)
	{
	case OBJ::MAGICCIRCLE:
	case OBJ::ALTAR:
	{
		if (!pGM->IsStory(CHECK_ALTAR_))
		{
			pGM->SetInfo(OBJ::MAGICCIRCLE, { INFO_ID::SEARCH_ALTAR, ITEM_, OBJ::MAGICCIRCLE });
			pGM->SetInfo(OBJ::ALTAR, { INFO_ID::SEARCH_ALTAR, ITEM_, OBJ::ALTAR });
		}
		else
		{
			pGM->SetInfo(OBJ::MAGICCIRCLE, { INFO_ID::INTER_ALTAR, ITEM_, OBJ::MAGICCIRCLE });
			pGM->SetInfo(OBJ::ALTAR, { INFO_ID::INTER_ALTAR, ITEM_, OBJ::ALTAR });
		}
	}
	break;

	//현관문
	case OBJ::CANDLE_FIRE_L:
	case OBJ::CANDLE_FIRE_R:
	{
		pGM->ResetInfo();
	}
	break;
	}

	//상호작용
	if (pGM->GetKey(KEY_SPACE))
	{
		switch (pGM->GetInfo().m_Type)
		{
		case DOOR_:
		{
			switch (pGM->GetInfo().m_Item)
			{
				//비밀의 문(301호로 나옴)
			case OBJ::SECRETDOOR:
			{
				if (pGM->IsGame(USE_KNIFE_))
				{
					pGM->SetMonsterActive(false);
					pGM->SetMonsterPos(429);
					pGM->SetMonsterWaitTime(0.8f);
				}
				pGM->MoveDoor();
				pGM->SetPlayerPos(449);
			}
			break;
			}
		}
		break;

		case ITEM_:
		{
			switch (pGM->GetInfo().m_Item)
			{
				//제단
			case OBJ::ALTAR:
			case OBJ::MAGICCIRCLE:
			{
				if (!pGM->IsStory(CHECK_ALTAR_))
				{
					pGM->SetStory(CHECK_ALTAR_);
					pGM->AddScripts(SCR_ID::STORY_7_3);
				}
				else
				{
					if (!pGM->IsGame(USE_KNIFE_))
					{
						if (pGM->IsItem(UI::ITEM_KNIFE))
						{
							pGM->SoundPlay(AUDIO::EFS_KNIFE_HIT);
							pGM->SetGame(USE_KNIFE_);
							pGM->UseItem();
							pGM->SetAniFrm(OBJ::ALTAR, 1);
							pGM->AddScripts(SCR_ID::STORY_7_4);
						}
						else
						{
							pGM->AddScripts(SCR_ID::NORMAL_3);
						}
					}
				}
			}
			break;

			//환풍구
			case OBJ::VENT:
			{
				if (!pGM->IsStory(CHECK_VENT_))
				{
					pGM->SetStory(CHECK_VENT_);
					pGM->AddScripts(SCR_ID::STORY_7_2);
				}
				else
				{
					pGM->AddScripts(SCR_ID::NORMAL_4);
				}
			}
			break;

			}
		}
		break;

		}

	}
}
#pragma endregion