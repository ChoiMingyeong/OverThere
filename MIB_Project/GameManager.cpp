#include "pch.h"

#pragma region 생성자 & 소멸자
GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}
#pragma endregion

#pragma region 데이터 초기화
void GameManager::Init(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight)
{
	//그래픽스 엔진 초기화
	pEngine = new MIBEngine();
	pEngine->Initialize(hinst, hWnd, screenWidth, screenHeight);

	//시간 재기 시작
	pEngine->StartTimestamp();

	//게임 데이터 로드
	pGD = new GameData();
	pGD->LoadData(pEngine);

	//스크립트 로드
	pSM = new ScriptManager();
	pSM->Init();

	//소리 로드
	pAM = AudioManager::GetInstance();
	pAM->Init();

	//플레이어 생성
	pPlayer = new Player();
	pPlayer->Initialize(pGD->pPlayerSpr);

	//몬스터 생성
	pMonster = new Monster();
	pMonster->Initialize(pGD->pMonsterSpr, pPlayer);

	ResetData();
}

void GameManager::ResetData()
{
	pGD->ResetData();

	pPlayer->Reset();
	pMonster->Reset();

	NowScene = SCENE::TITLE;
	NowRoom = ROOM::HALLWAY;
	NowScript = { "" };

	InfoText = "";
	Scripts.clear();

	title_cursor = 0;

	DebugMode = false;

	cur_key = false;
	pre_key = false;

	GameState = 0;
	StoryState = 0;
	waitTime = 0.0f;
}
#pragma endregion

#pragma region Key
void GameManager::KeyInput()
{
	pre_key = cur_key;

	if (GetAsyncKeyState(VK_UP))		cur_key |= KEY_UP;		else cur_key &= ~KEY_UP;
	if (GetAsyncKeyState(VK_DOWN))		cur_key |= KEY_DOWN;	else cur_key &= ~KEY_DOWN;
	if (GetAsyncKeyState(VK_RETURN))	cur_key |= KEY_ENTER;	else cur_key &= ~KEY_ENTER;
	if (GetAsyncKeyState(VK_SPACE))		cur_key |= KEY_SPACE;	else cur_key &= ~KEY_SPACE;
	if (GetAsyncKeyState(VK_TAB))		cur_key |= KEY_TAB;		else cur_key &= ~KEY_TAB;
	if (GetAsyncKeyState(VK_ESCAPE))	cur_key |= KEY_ESC;		else cur_key &= ~KEY_ESC;
	if (GetAsyncKeyState(VK_F8))		cur_key |= KEY_F8;		else cur_key &= ~KEY_F8;
	if (GetAsyncKeyState(VK_F1))		cur_key |= KEY_F1;		else cur_key &= ~KEY_F1;

	//치트키
	if (GetAsyncKeyState(VK_F7))		cur_key |= KEY_F7;		else cur_key &= ~KEY_F7;
}

bool GameManager::GetKey(int key)
{
	return (cur_key & key) && !(pre_key & key);
}
#pragma endregion

#pragma region CheckState
bool GameManager::IsGame(int state)
{
	return GameState & state;
}

bool GameManager::IsStory(long state)
{
	return StoryState & state;
}

bool GameManager::IsItem(UI item)
{
	return (pPlayer->m_pInven->CheckItem() == (int)item);
}

void GameManager::SetGame(int state)
{
	GameState |= state;
}

void GameManager::SetStory(long state)
{
	StoryState |= state;
}
bool GameManager::IsAniFrm(OBJ target, OBJ id)
{
	return pGD->pGameObject[(int)target]->m_pSpr->AniFrm == pGD->pGameObject[(int)id]->m_pSpr->AniMAXFrm - 1;
}
void GameManager::AniPlay(OBJ id)
{
	pGD->pGameObject[(int)id]->m_pSpr->AnimPlay(GetdTime());
}

void GameManager::SoundPlay(AUDIO id, float v)
{
	pAM->Play(id, v);
}

void GameManager::SoundPause(AUDIO id)
{
	pAM->Pause(id);
}

void GameManager::BGMPlay(AUDIO id, float v)
{
	pAM->BGM(id, v);
}

void GameManager::BGMStop(AUDIO id)
{
	pAM->Stop(id);
}

#pragma endregion

#pragma region Scripts
void GameManager::ScriptOut()
{
	//추가할 스크립트가 없으면 함수 종료
	if (Scripts.size() <= 0)
	{
		NowScript = { "" };
		return;
	}

	NowScript = Scripts[Scripts.size() - 1];
	Scripts.pop_back();
	waitScript = true;

	COLORREF col = RGB(255, 255, 255);
	switch ((int)NowScript.color)
	{
		//흰색
	case (int)SCR_COLOR::WHITE:
		col = RGB(255, 255, 255);
		break;

		//회색
	case (int)SCR_COLOR::GREY:
		col = RGB(170, 170, 170);
		break;

		//빨간색
	case (int)SCR_COLOR::RED:
		col = RGB(255, 0, 0);
		break;
	}

	pEngine->DrawTextFormat(SCRIPTS_POS, col, 20, NowScript.script);	//Script 출력
	pEngine->DrawTextFormat({ WINDOW_WIDTH / 2, 570 }, RGB(150, 150, 150), "[SPACE]");	//Space 도움말 출력
}
void GameManager::AddScripts(SCR_ID id)
{
	pSM->AddScripts(Scripts, id);
}
void GameManager::AddInfo(INFO_ID id)
{
	pSM->AddInfo(InfoText, id);
}
void GameManager::ResetInfo()
{
	NowInfo = {};
	InfoText = "";
}
bool GameManager::IsWait()
{
	return (Scripts.size() > 0) || (waitTime > 0.0f);
}
void GameManager::ResetScript()
{
	waitScript = false;
	NowScript = { "" };
}
#pragma endregion

void GameManager::Update()
{
	waitTime -= pEngine->GetElaspedTimeSec() * 0.001f;

	pEngine->Update();
}

void GameManager::SystemCheck()
{
	//Debug 정보 표시
	if (GetKey(KEY_F1))
	{
		DebugMode = !DebugMode;
		pEngine->m_DrawCollider = DebugMode ? true : false;
	}

	//Collider 표시
	if (GetKey(KEY_F8))
	{
		pEngine->m_DrawCollider = !pEngine->m_DrawCollider;
	}

	//스킵
	if (GetKey(KEY_ESC))
	{
		Scripts.clear();
	}
}

void GameManager::SetAniFrm(OBJ id, int frm)
{
	pGD->pObjSpr[(int)id]->AniFrm = frm;
}

void GameManager::SetAniFrm(UI id, int frm)
{
	pGD->pUISpr[(int)id]->AniFrm = frm;
}

void GameManager::RoomSet()
{
	//초기화
	pEngine->m_objs.clear();
	pPlayer->m_Limit = pGD->pBGSpr[(int)NowRoom]->m_Width;
	Scroll();

	switch (NowRoom)
	{
	case ROOM::HALLWAY:
	{
		if (!IsStory(CHECK_DEADBODY_))
		{
			BGMPlay(AUDIO::BGM_WIND, 0.2f);
			SetStory(CHECK_DEADBODY_);
			AddScripts(SCR_ID::STORY_2_1);
		}

		AddObj(OBJ::DOOR304);
		AddObj(OBJ::DOOR303);
		AddObj(OBJ::DOOR302);
		AddObj(OBJ::DOOR301);
		AddObj(OBJ::ESCAPE);
		AddObj(OBJ::BOARD);
		AddObj(OBJ::FIREHYDRANT);

		SetObj(OBJ::DOOR301, { 142, 242 });
		SetObj(OBJ::DOOR302, { 629, 243 });
		SetObj(OBJ::DOOR303, { 1361, 243 });
		SetObj(OBJ::DOOR304, { 2173, 243 });
		SetObj(OBJ::ESCAPE, { 2643, 292 });
		SetObj(OBJ::BOARD, { 918, 255 });
		SetObj(OBJ::FIREHYDRANT, { 1717, 319 });

		OnSavePos();
	}
	break;

	case ROOM::ROOM301:
	{
		AddObj(OBJ::DOOR);
		AddObj(OBJ::TOILET);
		AddObj(OBJ::SECRETDOOR);
		AddObj(OBJ::CHARM);
		AddObj(OBJ::BUCKET);

		SetObj(OBJ::DOOR, MAINDOOR_POS);
		SetObj(OBJ::TOILET, { 875, 378 });
		SetObj(OBJ::SECRETDOOR, { 449,326 });
		SetObj(OBJ::CHARM, { 431,310 });
		SetObj(OBJ::BUCKET, { 720,430 });

		SetObjActive(OBJ::SECRETDOOR, IsStory(FIND_SECRET_));

		SetPlayerPos(INFRONTDOOR_X);
	}
	break;

	case ROOM::ROOM302:
	{
		AddObj(OBJ::DOOR);
		AddObj(OBJ::HANGDEAD);
		AddObj(OBJ::BOOK);

		SetObj(OBJ::DOOR, MAINDOOR_POS);
		SetObj(OBJ::HANGDEAD, { 405,220 });
		SetObj(OBJ::BOOK, { 500,365 });

		SetPlayerPos(INFRONTDOOR_X);
	}
	break;

	case ROOM::ROOM303:
	{
		AddObj(OBJ::DOOR);
		AddObj(OBJ::TOILET);
		AddObj(OBJ::SWITCH);
		AddObj(OBJ::BAG);

		SetObj(OBJ::DOOR, MAINDOOR_POS);
		SetObj(OBJ::TOILET, { 820, 380 });
		SetObj(OBJ::SWITCH, { 767, 345 });
		SetObj(OBJ::BAG, { 270, 410 });

		SetPlayerPos(INFRONTDOOR_X);
	}
	break;

	case ROOM::ROOM304:
	{
		if (!IsStory(CHECK_304_))
		{
			SetStory(CHECK_304_);
			AddScripts(SCR_ID::STORY_4_1);
		}

		AddObj(OBJ::DOOR);
		AddObj(OBJ::TOILET);
		AddObj(OBJ::DEADBODY);
		AddObj(OBJ::CAMERA);
		AddObj(OBJ::NOTEBOOK);

		SetObj(OBJ::DOOR, MAINDOOR_POS);
		SetObj(OBJ::TOILET, { 875, 380 });
		SetObj(OBJ::DEADBODY, { 110, 350 });
		SetObj(OBJ::CAMERA, { 380, 345 });
		SetObj(OBJ::NOTEBOOK, { 670,368 });

		SetPlayerPos(INFRONTDOOR_X);
	}
	break;

	case ROOM::SECRETROOM:
	{
		if (!IsStory(ENTER_SECRET_))
		{
			SetStory(ENTER_SECRET_);
			AddScripts(SCR_ID::STORY_7_1);
		}

		AddObj(OBJ::SECRETDOOR);
		AddObj(OBJ::MAGICCIRCLE);
		AddObj(OBJ::ALTAR);
		AddObj(OBJ::CANDLE_FIRE_R);
		AddObj(OBJ::CANDLE_FIRE_L);
		AddObj(OBJ::VENT);

		SetObj(OBJ::SECRETDOOR, { 1013,326 });
		SetObj(OBJ::ALTAR, { 492,363 });
		SetObj(OBJ::MAGICCIRCLE, { 568,260 });
		SetObj(OBJ::CANDLE_FIRE_L, { 428,311 });
		SetObj(OBJ::CANDLE_FIRE_R, { 794,311 });
		SetObj(OBJ::VENT, { 78,284 });

		SetObjActive(OBJ::SECRETDOOR, true);

		SetPlayerPos(INFRONTSECRETDOOR_X);
	}
	break;

	case ROOM::INTRO_HALLWAY:
	{
		BGMPlay(AUDIO::BGM_RAIN, 0.5f);

		AddObj(OBJ::INTRO303);
		AddObj(OBJ::ESCAPE);

		SetObj(OBJ::INTRO303, { 1361, 243 });
		SetObj(OBJ::ESCAPE, { 2643, 292 });

		OnSavePos();
	}
	break;

	case ROOM::INTRO_303:
	{
		AddObj(OBJ::DOOR);
		AddObj(OBJ::TOILET);
		AddObj(OBJ::SWITCH);

		SetObj(OBJ::DOOR, MAINDOOR_POS);
		SetObj(OBJ::TOILET, { 820, 380 });
		SetObj(OBJ::SWITCH, { 767, 345 });

		SetPlayerPos(INFRONTDOOR_X);
	}
	break;

	}

	SetScrollX(0);
	PushUnits();
}

void GameManager::AddObj(OBJ id)
{
	pEngine->m_objs.push_back(pGD->pGameObject[(int)id]);
}

void GameManager::SetObj(OBJ id, POINT pos)
{
	pGD->pGameObject[(int)id]->m_pos = pos;
}

void GameManager::OnSavePos()
{
	pPlayer->m_pos.x = PlayerSavePos.x;
}

void GameManager::ChangeSavePos(int x)
{
	PlayerSavePos.x = x;
}

void GameManager::PushUnits()
{
	pEngine->m_objs.push_back(pMonster);
	pEngine->m_objs.push_back(pPlayer);
}

#pragma region Player
void GameManager::ChangeEquip()
{
	pPlayer->m_pInven->ChangeEquip();
}

void GameManager::UseItem()
{
	pPlayer->m_pInven->UseItem();
}

void GameManager::GetItem(UI id)
{
	pPlayer->m_pInven->GetItem((int)id);
}

void GameManager::PlayerMove()
{
	pPlayer->Move();
}

void GameManager::MonsterMove()
{
	if (pMonster->m_Active)
	{
		pMonster->Move();
	}
}

void GameManager::HitObj()
{
	//몬스터 충돌 체크
	for (int i = 0; i < pPlayer->m_hitobjs.size(); i++)
	{
		if (pPlayer->m_hitobjs[i] == pMonster && pMonster->m_Active)
		{
			pPlayer->m_Dead = true;
			return;
		}
	}

	//다른 오브젝트 충돌 체크
	if (pPlayer->m_hitobjs.size() > 0)
	{
		GameObject* obj = dynamic_cast<GameObject*>(pPlayer->m_hitobjs[0]);
		obj->GetObj(NowInfo);

		AddInfo(NowInfo.m_info);
	}
}

void GameManager::MoveDoor()
{
	NowRoom = NowInfo.m_Room;
	RoomSet();
}

void GameManager::Interaction()
{

}

void GameManager::Scroll()
{
	if (pPlayer->m_pos.x > WINDOW_WIDTH / 2 && pPlayer->m_pos.x < pPlayer->m_Limit - WINDOW_WIDTH / 2)
	{
		pEngine->m_Scroll = WINDOW_WIDTH / 2 - pPlayer->m_pos.x;
	}
}

bool GameManager::IsDead()
{
	return pPlayer->m_Dead;
}

#pragma endregion

#pragma region Draw
void GameManager::DrawBegin()
{
	pEngine->BeginRender();
}
void GameManager::DrawBG(BG bg, POINT pos, bool center)
{
	pEngine->DrawSprite(pGD->pBGSpr[(int)bg], pos, center);
}

void GameManager::DrawBG(int pos)
{
	pEngine->DrawSprite(pGD->pBGSpr[(int)NowRoom], { pEngine->m_Scroll, pos }, false);
}

void GameManager::DrawObj()
{
	//Player 와 Monster를 제외한 현재 씬의 오브젝트들을 그린다.
	for (int i = 0; i < pEngine->m_objs.size() - 2; i++)
	{
		pEngine->m_objs[i]->Draw(pEngine);
	}
}

void GameManager::DrawUnit()
{
	//Player 그리기
	pPlayer->m_Spr[pPlayer->m_State]->AnimPlay(pEngine->GetElaspedTimeSec() * 0.001f);
	pPlayer->Draw(pEngine);

	//몬스터 그리기
	if (pMonster->m_Active)
	{
		pMonster->m_Spr[pMonster->m_State]->AnimPlay(pEngine->GetElaspedTimeSec() * 0.001f);
	}
	pMonster->Draw(pEngine);
}

void GameManager::DrawUI()
{
	switch (NowScene)
	{
	case SCENE::TITLE:
	{
		pEngine->DrawSprite(pGD->pUISpr[(int)UI::TITLE_START], { 600, 500 }, false);
		pEngine->DrawSprite(pGD->pUISpr[(int)UI::TITLE_EXIT], { 600, 550 }, false);
		pEngine->DrawSprite(pGD->pUISpr[(int)UI::TITLE_ARROW], { 550, 500 + 50 * title_cursor }, false);
	}
	break;

	case SCENE::INTRO:
	case SCENE::INGAME:
	{
		pEngine->DrawTextFormat(INFO_POS, RGB(255, 255, 255), 16, InfoText);	//Info
		pEngine->DrawTextFormat({ 115, 60 }, RGB(150, 150, 150), "[TAB] : 아이템 변경");
		pEngine->DrawSprite(pGD->pUISpr[(int)UI::INVEN_SLOTS], { 50, 70 }, false);
		//인벤토리 그리기
		for (int i = 0; i < MAX_; i++)
		{
			int index = pPlayer->m_pInven->GetItemInfo(i);
			if (index != EMPTY_)
			{
				pEngine->DrawSprite(pGD->pUISpr[index], { 55 + 85 * i, 75 }, false);
			}
			if (i == pPlayer->m_pInven->m_EquipIndex)
			{
				pEngine->DrawSprite(pGD->pUISpr[(int)UI::INVEN_ARROW], { 90 + 85 * i, 170 }, false);
				//아이템 이름 출력
				if (index != -1)
				{
					pEngine->DrawTextFormat({ 95 + 85 * i, 190 }, RGB(150, 150, 150), pGD->pItemName[index]);
				}
			}
		}

		//Debug 정보 표시
		if (DebugMode)
		{
			int x = 1180;
			int y = 0;

			pEngine->DrawTextFormat({ x,y += 16 }, RGB(0, 255, 0), "GameState : %x", GameState);
			pEngine->DrawTextFormat({ x,y += 16 }, RGB(0, 255, 0), "StoryState : %x", StoryState);

			pEngine->DrawTextFormat({ x,y += 16 }, RGB(0, 255, 0), "PlayerPos : %d, %d", pPlayer->m_pos.x, pPlayer->m_pos.y);
			pEngine->DrawTextFormat({ x,y += 16 }, RGB(255, 0, 0), "MonsterPos : %d, %d", pMonster->m_pos.x, pMonster->m_pos.y);
			pEngine->m_DrawCollider ?
				pEngine->DrawTextFormat({ x,y += 16 }, RGB(0, 255, 0), "DrawCollider(F8) : TRUE") :
				pEngine->DrawTextFormat({ x,y += 16 }, RGB(0, 255, 0), "DrawCollider(F8) : FALSE");
		}
	}
	break;

	case SCENE::GAMEOVER:
	{
		//스크립트 출력
		ScriptOut();
	}
	break;

	case SCENE::ENDING:
	{

	}
	break;
	}
}

void GameManager::DrawEnd()
{
	pEngine->EndRender();
}
#pragma endregion
