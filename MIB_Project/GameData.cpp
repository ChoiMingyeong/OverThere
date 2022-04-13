#include "pch.h"

void GameData::LoadData(MIBEngine* pEngine)
{
#pragma region 스프라이트 파일 경로 지정
	//배경 스프라이트 파일 경로
	const wchar_t* BGpath[(int)BG::BGNUM] =
	{
		L"Resources/BG_Image_Hallway_blood.bmp",              //피칠갑 복도
		L"Resources/BG_Image_Room301.bmp",                    //301호
		L"Resources/BG_Image_Room302.bmp",                    //302호
		L"Resources/BG_Image_Room303.bmp",                    //303호
		L"Resources/BG_Image_Room304.bmp",                    //304호
		L"Resources/BG_Image_SecretRoom.bmp",                //비밀방

		L"Resources/BG_Scene_Title_Image.bmp",                //타이틀
		L"Resources/BG_Scene_GameOver_image.bmp",				//게임오버
		L"Resources/BG_Scene_Ending_image.bmp",                //엔딩
		L"Resources/BG_Scene_Ending2_image.bmp",                //엔딩

		L"Resources/BG_Image_Hallway.bmp",                //인트로 복도
		L"Resources/BG_Image_Room303.bmp",                    //303호
	};

	//오브젝트 스프라이트 파일 경로
	const wchar_t* OBJpath[(int)OBJ::OBJNUM] =
	{
		L"Resources/BG_Obj_Room301_Bucket.bmp",			// 양동이
		L"Resources/BG_Obj_Room301_Amulet.bmp",			// 부적
		L"Resources/BG_Obj_Room302_body.bmp",			// 목 메단 시체
		L"Resources/BG_Obj_Room302_note.bmp",			// 책(책상 위)
		L"Resources/BG_Obj_Room303_Switch.bmp",			// 전등 스위치
		L"Resources/BG_Obj_Room303_Bag.bmp",			// 가방
		L"Resources/BG_Obj_Room304_Body.bmp",			// 시체(칼)
		L"Resources/BG_Obj_Room304_Notebook.bmp",		// 책상(컴퓨터)
		L"Resources/BG_Obj_Room304_Camera.bmp",			// 촬영장비
		L"Resources/BG_Obj_SecretRoom_Alter.bmp",		// 재단
		L"Resources/BG_Obj_Common_Sink.bmp",			// 화장실
		L"Resources/BG_Obj_Hallway_FireHydrant.bmp",	// 소화전
		L"Resources/BG_Obj_Board.bmp",					// 게시판
		L"Resources/BG_Image_MagicCircle.bmp",			// 마법진
		L"Resources/BG_Image_Candle_fire.bmp",			// 촛불 왼쪽
		L"Resources/BG_Image_Candle_fire.bmp",			 // 촛불 오른쪽
		L"Resources/BG_Obj_VentilationShaft.bmp",		 // 환풍구


		L"Resources/BG_Obj_Common_Door.bmp",			// 현관문(공통)
		L"Resources/BG_Obj_Door_301.bmp",				// 301호 문
		L"Resources/BG_Obj_Door_302.bmp",				// 302호 문
		L"Resources/BG_Obj_Door_303_blood.bmp",			// 303호 문
		L"Resources/BG_Obj_Door_304.bmp",				// 304호 문
		L"Resources/BG_Obj_Door_Secret.bmp",			// 비밀 문
		L"Resources/BG_Obj_Door_Escape.bmp",			// 탈출구

		L"Resources/BG_Obj_Door303.bmp",			// 인트로 303호
	};

	//UI 스프라이트 파일 경로
	const wchar_t* UIpath[(int)UI::UINUM] =
	{
		L"Resources/BG_Scene_Title_GameStrat.bmp",	//타이틀 게임시작
		L"Resources/BG_Scene_Title_Exit.bmp",       //타이틀 게임종료
		L"Resources/BG_Scene_Title_Arrow.bmp",      //타이틀 화살표

		L"Resources/UI_Inventory.bmp",              //인벤토리
		L"Resources/UI_Arrow.bmp",                  //인벤토리 화살표

		L"Resources/UI_Item_Crowbar.bmp",           //아이템 빠루
		L"Resources/UI_Item_SDCard.bmp",            //아이템 SD 카드
		L"Resources/UI_Item_Knife.bmp",             //아이템 칼
		L"Resources/UI_Item_KeySet.bmp",            //아이템 열쇠꾸러미
		L"Resources/UI_Item_Bucket.bmp",            //아이템 양동이
		L"Resources/UI_Item_BoneKey.bmp",           //아이템 뼈 열쇠
	};

	//Player 스프라이트 파일 경로
	const wchar_t* PLAYERpath[(int)PLAYER::STATENUM] =
	{
		L"Resources/Human_Standing_Left.bmp",    //왼쪽 서있기
		L"Resources/Human_Standing_Right.bmp",    //오른쪽 서있기
		L"Resources/Human_Run_Left.bmp",        //왼쪽 달리기
		L"Resources/Human_Run_Right.bmp"        //오른쪽 달리기
	};

	//Monster 스프라이트 파일 경로
	const wchar_t* MONSTERpath[(int)MONSTER::STATENUM] =
	{
		L"Resources/Monster_run_Left.bmp",        //왼쪽 달리기
		L"Resources/Monster_run_Right.bmp"        //오른쪽 달리기
	};
#pragma endregion

#pragma region 스프라이트 로드
	//배경 스프라이트 로드
	for (int i = 0; i < (int)BG::BGNUM; i++)
	{
		pBGSpr[i] = new MIBSprite();
		pEngine->LoadSprite(pBGSpr[i], BGpath[i]);
	}

	//오브젝트 스프라이트 로드
	for (int i = 0; i < (int)OBJ::OBJNUM; i++)
	{
		pObjSpr[i] = new MIBSprite();
		pEngine->LoadSprite(pObjSpr[i], OBJpath[i]);
	}

	//UI 스프라이트 로드
	for (int i = 0; i < (int)UI::UINUM; i++)
	{
		pUISpr[i] = new MIBSprite();
		pEngine->LoadSprite(pUISpr[i], UIpath[i]);
	}

	//Player 스프라이트 로드
	for (int i = 0; i < (int)PLAYER::STATENUM; i++)
	{
		pPlayerSpr[i] = new MIBSprite();
		pEngine->LoadSprite(pPlayerSpr[i], PLAYERpath[i]);
	}

	//Monster 스프라이트 로드
	for (int i = 0; i < (int)MONSTER::STATENUM; i++)
	{
		pMonsterSpr[i] = new MIBSprite();
		pEngine->LoadSprite(pMonsterSpr[i], MONSTERpath[i]);
	}

#pragma region 애니메이션 설정
	//배경 애니메이션 설정

	//오브젝트 애니메이션 설정
	pObjSpr[(int)OBJ::DOOR301]->SetAnim(4);
	pObjSpr[(int)OBJ::DOOR302]->SetAnim(2);
	pObjSpr[(int)OBJ::FIREHYDRANT]->SetAnim(2);
	pObjSpr[(int)OBJ::CHARM]->SetAnim(2);
	pObjSpr[(int)OBJ::DEADBODY]->SetAnim(2);
	pObjSpr[(int)OBJ::BAG]->SetAnim(2);
	pObjSpr[(int)OBJ::NOTEBOOK]->SetAnim(2);
	pObjSpr[(int)OBJ::ALTAR]->SetAnim(2);
	pObjSpr[(int)OBJ::MAGICCIRCLE]->SetAnim(3);   // 마법진
	pObjSpr[(int)OBJ::CANDLE_FIRE_L]->SetAnim(2);   // 촛불 왼쪽
	pObjSpr[(int)OBJ::CANDLE_FIRE_R]->SetAnim(2); // 촛불 오른쪽

	//UI 애니메이션 설정
	pUISpr[(int)UI::TITLE_START]->SetAnim(2);
	pUISpr[(int)UI::TITLE_EXIT]->SetAnim(2);
	pUISpr[(int)UI::ITEM_BUCKET]->SetAnim(2);

	//Player 애니메이션 설정
	pPlayerSpr[(int)PLAYER::RUN_L]->SetAnim(5, 1, 1.5f);
	pPlayerSpr[(int)PLAYER::RUN_R]->SetAnim(5, 1, 1.5f);

	//Monster 애니메이션 설정
	pMonsterSpr[(int)MONSTER::RUN_L]->SetAnim(4, 1, 2);
	pMonsterSpr[(int)MONSTER::RUN_R]->SetAnim(4, 1, 2);
#pragma endregion

#pragma endregion

#pragma region 오브젝트 생성
	//게임 오브젝트들 생성
	for (int i = 0; i < (int)OBJ::OBJNUM; i++)
	{
		pGameObject[i] = new GameObject();
		pGameObject[i]->SetSprite(pObjSpr[i]);
	}

	//게임 오브젝트 정보 설정
	pGameObject[(int)OBJ::BUCKET]->SetObj({ INFO_ID::SEARCH_BUCKET, ITEM_, OBJ::BUCKET });			//양동이
	pGameObject[(int)OBJ::CHARM]->SetObj({ INFO_ID::SEARCH_CHARM, ITEM_, OBJ::CHARM });				//부적
	pGameObject[(int)OBJ::HANGDEAD]->SetObj({ INFO_ID::SEARCH_HANGDEAD, ITEM_, OBJ::HANGDEAD });	//목 매단 시체
	pGameObject[(int)OBJ::BOOK]->SetObj({ INFO_ID::SEARCH_DIARY, ITEM_, OBJ::BOOK });				//경비 일지
	pGameObject[(int)OBJ::SWITCH]->SetObj({ INFO_ID::INTER_SWITCH, ITEM_, OBJ::SWITCH });			//전등 스위치
	pGameObject[(int)OBJ::BAG]->SetObj({ INFO_ID::SEARCH_BAG, ITEM_, OBJ::BAG });					//가방
	pGameObject[(int)OBJ::DEADBODY]->SetObj({ INFO_ID::SEARCH_DEADGIRL, ITEM_, OBJ::DEADBODY });	//시체(칼)		
	pGameObject[(int)OBJ::NOTEBOOK]->SetObj({ INFO_ID::SEARCH_COMPUTER, ITEM_, OBJ::NOTEBOOK });	//책상(컴퓨터)	
	pGameObject[(int)OBJ::CAMERA]->SetObj({ INFO_ID::SEARCH_CAMERA, ITEM_, OBJ::CAMERA });			//촬영장비
	pGameObject[(int)OBJ::ALTAR]->SetObj({ INFO_ID::SEARCH_ALTAR, ITEM_, OBJ::ALTAR });				//제단
	pGameObject[(int)OBJ::TOILET]->SetObj({ INFO_ID::SEARCH_TOILET, ITEM_, OBJ::TOILET });			//화장실
	pGameObject[(int)OBJ::FIREHYDRANT]->SetObj({ INFO_ID::SEARCH_FIREHOSE, ITEM_, OBJ::FIREHYDRANT });	//소화전
	pGameObject[(int)OBJ::BOARD]->SetObj({ INFO_ID::SEARCH_BOARD, ITEM_, OBJ::BOARD });				//게시판
	pGameObject[(int)OBJ::VENT]->SetObj({ INFO_ID::SEARCH_VENT, ITEM_, OBJ::VENT });				//환풍구

	pGameObject[(int)OBJ::CANDLE_FIRE_R]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::CANDLE_FIRE_R });				//촛불
	pGameObject[(int)OBJ::CANDLE_FIRE_L]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::CANDLE_FIRE_L });				//촛불
	pGameObject[(int)OBJ::MAGICCIRCLE]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::MAGICCIRCLE });				//마법진

	pGameObject[(int)OBJ::DOOR]->SetObj({ INFO_ID::TO_HALLWAY, DOOR_, OBJ::DOOR, ROOM::HALLWAY });					//현관문(공통)
	pGameObject[(int)OBJ::DOOR301]->SetObj({ INFO_ID::TO_301, DOOR_, OBJ::DOOR301, ROOM::ROOM301 });				//301호 문
	pGameObject[(int)OBJ::DOOR302]->SetObj({ INFO_ID::TO_302, DOOR_, OBJ::DOOR302, ROOM::ROOM302 });				//302호 문
	pGameObject[(int)OBJ::DOOR303]->SetObj({ INFO_ID::TO_303, DOOR_, OBJ::DOOR303, ROOM::ROOM303 });				//303호 문
	pGameObject[(int)OBJ::DOOR304]->SetObj({ INFO_ID::TO_304, DOOR_, OBJ::DOOR304 , ROOM::ROOM304 });				//304호 문
	pGameObject[(int)OBJ::SECRETDOOR]->SetObj({ INFO_ID::TO_SECRET, DOOR_, OBJ::SECRETDOOR, ROOM::SECRETROOM });		//비밀 문
	pGameObject[(int)OBJ::INTRO303]->SetObj({ INFO_ID::TO_303, DOOR_, OBJ::INTRO303,  ROOM::INTRO_303 });		//인트로 303호 문

	pGameObject[(int)OBJ::ESCAPE]->SetObj({ INFO_ID::TO_ESC, ESC_, OBJ::ESCAPE });					//탈출구
#pragma endregion

#pragma region Item 이름 설정
	LPCSTR names[(int)UI::UINUM] =
	{
		"",
		"",
		"",

		"",
		"",

		"빠루",
		"SD 카드",
		"칼",
		"열쇠꾸러미",
		"양동이",
		"뼈 열쇠",
	};

	for (int i = 0; i < (int)UI::UINUM; i++)
	{
		pItemName[i] = names[i];
	}
#pragma endregion

}

void GameData::ResetData()
{
#pragma region 스프라이트 애니메이션 리셋
	//배경 애니 리셋
	for (int i = 0; i < (int)BG::BGNUM; i++)
	{
		if (pBGSpr[i]->AniMAXFrm <= 1)	continue;

		pBGSpr[i]->AniTime = 0.0f;
		pBGSpr[i]->AniFrm = 0;
		pBGSpr[i]->AniState = 0;
	}

	//오브젝트 애니 리셋
	for (int i = 0; i < (int)OBJ::OBJNUM; i++)
	{
		if (pObjSpr[i]->AniMAXFrm <= 1)	continue;

		pObjSpr[i]->AniTime = 0.0f;
		pObjSpr[i]->AniFrm = 0;
		pObjSpr[i]->AniState = 0;
	}

	//UI 애니 리셋
	for (int i = 0; i < (int)UI::UINUM; i++)
	{
		if (pUISpr[i]->AniMAXFrm <= 1)	continue;

		pUISpr[i]->AniTime = 0.0f;
		pUISpr[i]->AniFrm = 0;
		pUISpr[i]->AniState = 0;
	}

	//플레이어 애니 리셋
	for (int i = 0; i < (int)PLAYER::STATENUM; i++)
	{
		if (pPlayerSpr[i]->AniMAXFrm <= 1)	continue;

		pPlayerSpr[i]->AniTime = 0.0f;
		pPlayerSpr[i]->AniFrm = 0;
		pPlayerSpr[i]->AniState = 0;
	}

	//몬스터 애니 리셋
	for (int i = 0; i < (int)MONSTER::STATENUM; i++)
	{
		if (pMonsterSpr[i]->AniMAXFrm <= 1)	continue;

		pMonsterSpr[i]->AniTime = 0.0f;
		pMonsterSpr[i]->AniFrm = 0;
		pMonsterSpr[i]->AniState = 0;
	}

	//게임 오브젝트 리셋
	for (int i = 0; i < (int)OBJ::OBJNUM; i++)
	{
		pGameObject[i]->m_Active = true;
	}

	pGameObject[(int)OBJ::BUCKET]->SetObj({ INFO_ID::SEARCH_BUCKET, ITEM_, OBJ::BUCKET });			//양동이
	pGameObject[(int)OBJ::CHARM]->SetObj({ INFO_ID::SEARCH_CHARM, ITEM_, OBJ::CHARM });				//부적
	pGameObject[(int)OBJ::HANGDEAD]->SetObj({ INFO_ID::SEARCH_HANGDEAD, ITEM_, OBJ::HANGDEAD });	//목 매단 시체
	pGameObject[(int)OBJ::BOOK]->SetObj({ INFO_ID::SEARCH_DIARY, ITEM_, OBJ::BOOK });				//경비 일지
	pGameObject[(int)OBJ::SWITCH]->SetObj({ INFO_ID::INTER_SWITCH, ITEM_, OBJ::SWITCH });			//전등 스위치
	pGameObject[(int)OBJ::BAG]->SetObj({ INFO_ID::SEARCH_BAG, ITEM_, OBJ::BAG });					//가방
	pGameObject[(int)OBJ::DEADBODY]->SetObj({ INFO_ID::SEARCH_DEADGIRL, ITEM_, OBJ::DEADBODY });	//시체(칼)		
	pGameObject[(int)OBJ::NOTEBOOK]->SetObj({ INFO_ID::SEARCH_COMPUTER, ITEM_, OBJ::NOTEBOOK });	//책상(컴퓨터)	
	pGameObject[(int)OBJ::CAMERA]->SetObj({ INFO_ID::SEARCH_CAMERA, ITEM_, OBJ::CAMERA });			//촬영장비
	pGameObject[(int)OBJ::ALTAR]->SetObj({ INFO_ID::SEARCH_ALTAR, ITEM_, OBJ::ALTAR });				//제단
	pGameObject[(int)OBJ::TOILET]->SetObj({ INFO_ID::SEARCH_TOILET, ITEM_, OBJ::TOILET });			//화장실
	pGameObject[(int)OBJ::FIREHYDRANT]->SetObj({ INFO_ID::SEARCH_FIREHOSE, ITEM_, OBJ::FIREHYDRANT });	//소화전
	pGameObject[(int)OBJ::BOARD]->SetObj({ INFO_ID::SEARCH_BOARD, ITEM_, OBJ::BOARD });				//게시판
	pGameObject[(int)OBJ::VENT]->SetObj({ INFO_ID::SEARCH_VENT, ITEM_, OBJ::VENT });				//환풍구

	pGameObject[(int)OBJ::CANDLE_FIRE_R]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::CANDLE_FIRE_R });				//촛불
	pGameObject[(int)OBJ::CANDLE_FIRE_L]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::CANDLE_FIRE_L });				//촛불
	pGameObject[(int)OBJ::MAGICCIRCLE]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::MAGICCIRCLE });				//마법진

	pGameObject[(int)OBJ::DOOR]->SetObj({ INFO_ID::TO_HALLWAY, DOOR_, OBJ::DOOR, ROOM::HALLWAY });					//현관문(공통)
	pGameObject[(int)OBJ::DOOR301]->SetObj({ INFO_ID::TO_301, DOOR_, OBJ::DOOR301, ROOM::ROOM301 });				//301호 문
	pGameObject[(int)OBJ::DOOR302]->SetObj({ INFO_ID::TO_302, DOOR_, OBJ::DOOR302, ROOM::ROOM302 });				//302호 문
	pGameObject[(int)OBJ::DOOR303]->SetObj({ INFO_ID::TO_303, DOOR_, OBJ::DOOR303, ROOM::ROOM303 });				//303호 문
	pGameObject[(int)OBJ::DOOR304]->SetObj({ INFO_ID::TO_304, DOOR_, OBJ::DOOR304 , ROOM::ROOM304 });				//304호 문
	pGameObject[(int)OBJ::SECRETDOOR]->SetObj({ INFO_ID::TO_SECRET, DOOR_, OBJ::SECRETDOOR, ROOM::SECRETROOM });		//비밀 문
	pGameObject[(int)OBJ::INTRO303]->SetObj({ INFO_ID::TO_303, DOOR_, OBJ::INTRO303,  ROOM::INTRO_303 });		//인트로 303호 문

	pGameObject[(int)OBJ::ESCAPE]->SetObj({ INFO_ID::TO_ESC, ESC_, OBJ::ESCAPE });
#pragma endregion
}