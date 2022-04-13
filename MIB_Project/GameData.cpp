#include "pch.h"

void GameData::LoadData(MIBEngine* pEngine)
{
#pragma region ��������Ʈ ���� ��� ����
	//��� ��������Ʈ ���� ���
	const wchar_t* BGpath[(int)BG::BGNUM] =
	{
		L"Resources/BG_Image_Hallway_blood.bmp",              //��ĥ�� ����
		L"Resources/BG_Image_Room301.bmp",                    //301ȣ
		L"Resources/BG_Image_Room302.bmp",                    //302ȣ
		L"Resources/BG_Image_Room303.bmp",                    //303ȣ
		L"Resources/BG_Image_Room304.bmp",                    //304ȣ
		L"Resources/BG_Image_SecretRoom.bmp",                //��й�

		L"Resources/BG_Scene_Title_Image.bmp",                //Ÿ��Ʋ
		L"Resources/BG_Scene_GameOver_image.bmp",				//���ӿ���
		L"Resources/BG_Scene_Ending_image.bmp",                //����
		L"Resources/BG_Scene_Ending2_image.bmp",                //����

		L"Resources/BG_Image_Hallway.bmp",                //��Ʈ�� ����
		L"Resources/BG_Image_Room303.bmp",                    //303ȣ
	};

	//������Ʈ ��������Ʈ ���� ���
	const wchar_t* OBJpath[(int)OBJ::OBJNUM] =
	{
		L"Resources/BG_Obj_Room301_Bucket.bmp",			// �絿��
		L"Resources/BG_Obj_Room301_Amulet.bmp",			// ����
		L"Resources/BG_Obj_Room302_body.bmp",			// �� �޴� ��ü
		L"Resources/BG_Obj_Room302_note.bmp",			// å(å�� ��)
		L"Resources/BG_Obj_Room303_Switch.bmp",			// ���� ����ġ
		L"Resources/BG_Obj_Room303_Bag.bmp",			// ����
		L"Resources/BG_Obj_Room304_Body.bmp",			// ��ü(Į)
		L"Resources/BG_Obj_Room304_Notebook.bmp",		// å��(��ǻ��)
		L"Resources/BG_Obj_Room304_Camera.bmp",			// �Կ����
		L"Resources/BG_Obj_SecretRoom_Alter.bmp",		// ���
		L"Resources/BG_Obj_Common_Sink.bmp",			// ȭ���
		L"Resources/BG_Obj_Hallway_FireHydrant.bmp",	// ��ȭ��
		L"Resources/BG_Obj_Board.bmp",					// �Խ���
		L"Resources/BG_Image_MagicCircle.bmp",			// ������
		L"Resources/BG_Image_Candle_fire.bmp",			// �к� ����
		L"Resources/BG_Image_Candle_fire.bmp",			 // �к� ������
		L"Resources/BG_Obj_VentilationShaft.bmp",		 // ȯǳ��


		L"Resources/BG_Obj_Common_Door.bmp",			// ������(����)
		L"Resources/BG_Obj_Door_301.bmp",				// 301ȣ ��
		L"Resources/BG_Obj_Door_302.bmp",				// 302ȣ ��
		L"Resources/BG_Obj_Door_303_blood.bmp",			// 303ȣ ��
		L"Resources/BG_Obj_Door_304.bmp",				// 304ȣ ��
		L"Resources/BG_Obj_Door_Secret.bmp",			// ��� ��
		L"Resources/BG_Obj_Door_Escape.bmp",			// Ż�ⱸ

		L"Resources/BG_Obj_Door303.bmp",			// ��Ʈ�� 303ȣ
	};

	//UI ��������Ʈ ���� ���
	const wchar_t* UIpath[(int)UI::UINUM] =
	{
		L"Resources/BG_Scene_Title_GameStrat.bmp",	//Ÿ��Ʋ ���ӽ���
		L"Resources/BG_Scene_Title_Exit.bmp",       //Ÿ��Ʋ ��������
		L"Resources/BG_Scene_Title_Arrow.bmp",      //Ÿ��Ʋ ȭ��ǥ

		L"Resources/UI_Inventory.bmp",              //�κ��丮
		L"Resources/UI_Arrow.bmp",                  //�κ��丮 ȭ��ǥ

		L"Resources/UI_Item_Crowbar.bmp",           //������ ����
		L"Resources/UI_Item_SDCard.bmp",            //������ SD ī��
		L"Resources/UI_Item_Knife.bmp",             //������ Į
		L"Resources/UI_Item_KeySet.bmp",            //������ ����ٷ���
		L"Resources/UI_Item_Bucket.bmp",            //������ �絿��
		L"Resources/UI_Item_BoneKey.bmp",           //������ �� ����
	};

	//Player ��������Ʈ ���� ���
	const wchar_t* PLAYERpath[(int)PLAYER::STATENUM] =
	{
		L"Resources/Human_Standing_Left.bmp",    //���� ���ֱ�
		L"Resources/Human_Standing_Right.bmp",    //������ ���ֱ�
		L"Resources/Human_Run_Left.bmp",        //���� �޸���
		L"Resources/Human_Run_Right.bmp"        //������ �޸���
	};

	//Monster ��������Ʈ ���� ���
	const wchar_t* MONSTERpath[(int)MONSTER::STATENUM] =
	{
		L"Resources/Monster_run_Left.bmp",        //���� �޸���
		L"Resources/Monster_run_Right.bmp"        //������ �޸���
	};
#pragma endregion

#pragma region ��������Ʈ �ε�
	//��� ��������Ʈ �ε�
	for (int i = 0; i < (int)BG::BGNUM; i++)
	{
		pBGSpr[i] = new MIBSprite();
		pEngine->LoadSprite(pBGSpr[i], BGpath[i]);
	}

	//������Ʈ ��������Ʈ �ε�
	for (int i = 0; i < (int)OBJ::OBJNUM; i++)
	{
		pObjSpr[i] = new MIBSprite();
		pEngine->LoadSprite(pObjSpr[i], OBJpath[i]);
	}

	//UI ��������Ʈ �ε�
	for (int i = 0; i < (int)UI::UINUM; i++)
	{
		pUISpr[i] = new MIBSprite();
		pEngine->LoadSprite(pUISpr[i], UIpath[i]);
	}

	//Player ��������Ʈ �ε�
	for (int i = 0; i < (int)PLAYER::STATENUM; i++)
	{
		pPlayerSpr[i] = new MIBSprite();
		pEngine->LoadSprite(pPlayerSpr[i], PLAYERpath[i]);
	}

	//Monster ��������Ʈ �ε�
	for (int i = 0; i < (int)MONSTER::STATENUM; i++)
	{
		pMonsterSpr[i] = new MIBSprite();
		pEngine->LoadSprite(pMonsterSpr[i], MONSTERpath[i]);
	}

#pragma region �ִϸ��̼� ����
	//��� �ִϸ��̼� ����

	//������Ʈ �ִϸ��̼� ����
	pObjSpr[(int)OBJ::DOOR301]->SetAnim(4);
	pObjSpr[(int)OBJ::DOOR302]->SetAnim(2);
	pObjSpr[(int)OBJ::FIREHYDRANT]->SetAnim(2);
	pObjSpr[(int)OBJ::CHARM]->SetAnim(2);
	pObjSpr[(int)OBJ::DEADBODY]->SetAnim(2);
	pObjSpr[(int)OBJ::BAG]->SetAnim(2);
	pObjSpr[(int)OBJ::NOTEBOOK]->SetAnim(2);
	pObjSpr[(int)OBJ::ALTAR]->SetAnim(2);
	pObjSpr[(int)OBJ::MAGICCIRCLE]->SetAnim(3);   // ������
	pObjSpr[(int)OBJ::CANDLE_FIRE_L]->SetAnim(2);   // �к� ����
	pObjSpr[(int)OBJ::CANDLE_FIRE_R]->SetAnim(2); // �к� ������

	//UI �ִϸ��̼� ����
	pUISpr[(int)UI::TITLE_START]->SetAnim(2);
	pUISpr[(int)UI::TITLE_EXIT]->SetAnim(2);
	pUISpr[(int)UI::ITEM_BUCKET]->SetAnim(2);

	//Player �ִϸ��̼� ����
	pPlayerSpr[(int)PLAYER::RUN_L]->SetAnim(5, 1, 1.5f);
	pPlayerSpr[(int)PLAYER::RUN_R]->SetAnim(5, 1, 1.5f);

	//Monster �ִϸ��̼� ����
	pMonsterSpr[(int)MONSTER::RUN_L]->SetAnim(4, 1, 2);
	pMonsterSpr[(int)MONSTER::RUN_R]->SetAnim(4, 1, 2);
#pragma endregion

#pragma endregion

#pragma region ������Ʈ ����
	//���� ������Ʈ�� ����
	for (int i = 0; i < (int)OBJ::OBJNUM; i++)
	{
		pGameObject[i] = new GameObject();
		pGameObject[i]->SetSprite(pObjSpr[i]);
	}

	//���� ������Ʈ ���� ����
	pGameObject[(int)OBJ::BUCKET]->SetObj({ INFO_ID::SEARCH_BUCKET, ITEM_, OBJ::BUCKET });			//�絿��
	pGameObject[(int)OBJ::CHARM]->SetObj({ INFO_ID::SEARCH_CHARM, ITEM_, OBJ::CHARM });				//����
	pGameObject[(int)OBJ::HANGDEAD]->SetObj({ INFO_ID::SEARCH_HANGDEAD, ITEM_, OBJ::HANGDEAD });	//�� �Ŵ� ��ü
	pGameObject[(int)OBJ::BOOK]->SetObj({ INFO_ID::SEARCH_DIARY, ITEM_, OBJ::BOOK });				//��� ����
	pGameObject[(int)OBJ::SWITCH]->SetObj({ INFO_ID::INTER_SWITCH, ITEM_, OBJ::SWITCH });			//���� ����ġ
	pGameObject[(int)OBJ::BAG]->SetObj({ INFO_ID::SEARCH_BAG, ITEM_, OBJ::BAG });					//����
	pGameObject[(int)OBJ::DEADBODY]->SetObj({ INFO_ID::SEARCH_DEADGIRL, ITEM_, OBJ::DEADBODY });	//��ü(Į)		
	pGameObject[(int)OBJ::NOTEBOOK]->SetObj({ INFO_ID::SEARCH_COMPUTER, ITEM_, OBJ::NOTEBOOK });	//å��(��ǻ��)	
	pGameObject[(int)OBJ::CAMERA]->SetObj({ INFO_ID::SEARCH_CAMERA, ITEM_, OBJ::CAMERA });			//�Կ����
	pGameObject[(int)OBJ::ALTAR]->SetObj({ INFO_ID::SEARCH_ALTAR, ITEM_, OBJ::ALTAR });				//����
	pGameObject[(int)OBJ::TOILET]->SetObj({ INFO_ID::SEARCH_TOILET, ITEM_, OBJ::TOILET });			//ȭ���
	pGameObject[(int)OBJ::FIREHYDRANT]->SetObj({ INFO_ID::SEARCH_FIREHOSE, ITEM_, OBJ::FIREHYDRANT });	//��ȭ��
	pGameObject[(int)OBJ::BOARD]->SetObj({ INFO_ID::SEARCH_BOARD, ITEM_, OBJ::BOARD });				//�Խ���
	pGameObject[(int)OBJ::VENT]->SetObj({ INFO_ID::SEARCH_VENT, ITEM_, OBJ::VENT });				//ȯǳ��

	pGameObject[(int)OBJ::CANDLE_FIRE_R]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::CANDLE_FIRE_R });				//�к�
	pGameObject[(int)OBJ::CANDLE_FIRE_L]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::CANDLE_FIRE_L });				//�к�
	pGameObject[(int)OBJ::MAGICCIRCLE]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::MAGICCIRCLE });				//������

	pGameObject[(int)OBJ::DOOR]->SetObj({ INFO_ID::TO_HALLWAY, DOOR_, OBJ::DOOR, ROOM::HALLWAY });					//������(����)
	pGameObject[(int)OBJ::DOOR301]->SetObj({ INFO_ID::TO_301, DOOR_, OBJ::DOOR301, ROOM::ROOM301 });				//301ȣ ��
	pGameObject[(int)OBJ::DOOR302]->SetObj({ INFO_ID::TO_302, DOOR_, OBJ::DOOR302, ROOM::ROOM302 });				//302ȣ ��
	pGameObject[(int)OBJ::DOOR303]->SetObj({ INFO_ID::TO_303, DOOR_, OBJ::DOOR303, ROOM::ROOM303 });				//303ȣ ��
	pGameObject[(int)OBJ::DOOR304]->SetObj({ INFO_ID::TO_304, DOOR_, OBJ::DOOR304 , ROOM::ROOM304 });				//304ȣ ��
	pGameObject[(int)OBJ::SECRETDOOR]->SetObj({ INFO_ID::TO_SECRET, DOOR_, OBJ::SECRETDOOR, ROOM::SECRETROOM });		//��� ��
	pGameObject[(int)OBJ::INTRO303]->SetObj({ INFO_ID::TO_303, DOOR_, OBJ::INTRO303,  ROOM::INTRO_303 });		//��Ʈ�� 303ȣ ��

	pGameObject[(int)OBJ::ESCAPE]->SetObj({ INFO_ID::TO_ESC, ESC_, OBJ::ESCAPE });					//Ż�ⱸ
#pragma endregion

#pragma region Item �̸� ����
	LPCSTR names[(int)UI::UINUM] =
	{
		"",
		"",
		"",

		"",
		"",

		"����",
		"SD ī��",
		"Į",
		"����ٷ���",
		"�絿��",
		"�� ����",
	};

	for (int i = 0; i < (int)UI::UINUM; i++)
	{
		pItemName[i] = names[i];
	}
#pragma endregion

}

void GameData::ResetData()
{
#pragma region ��������Ʈ �ִϸ��̼� ����
	//��� �ִ� ����
	for (int i = 0; i < (int)BG::BGNUM; i++)
	{
		if (pBGSpr[i]->AniMAXFrm <= 1)	continue;

		pBGSpr[i]->AniTime = 0.0f;
		pBGSpr[i]->AniFrm = 0;
		pBGSpr[i]->AniState = 0;
	}

	//������Ʈ �ִ� ����
	for (int i = 0; i < (int)OBJ::OBJNUM; i++)
	{
		if (pObjSpr[i]->AniMAXFrm <= 1)	continue;

		pObjSpr[i]->AniTime = 0.0f;
		pObjSpr[i]->AniFrm = 0;
		pObjSpr[i]->AniState = 0;
	}

	//UI �ִ� ����
	for (int i = 0; i < (int)UI::UINUM; i++)
	{
		if (pUISpr[i]->AniMAXFrm <= 1)	continue;

		pUISpr[i]->AniTime = 0.0f;
		pUISpr[i]->AniFrm = 0;
		pUISpr[i]->AniState = 0;
	}

	//�÷��̾� �ִ� ����
	for (int i = 0; i < (int)PLAYER::STATENUM; i++)
	{
		if (pPlayerSpr[i]->AniMAXFrm <= 1)	continue;

		pPlayerSpr[i]->AniTime = 0.0f;
		pPlayerSpr[i]->AniFrm = 0;
		pPlayerSpr[i]->AniState = 0;
	}

	//���� �ִ� ����
	for (int i = 0; i < (int)MONSTER::STATENUM; i++)
	{
		if (pMonsterSpr[i]->AniMAXFrm <= 1)	continue;

		pMonsterSpr[i]->AniTime = 0.0f;
		pMonsterSpr[i]->AniFrm = 0;
		pMonsterSpr[i]->AniState = 0;
	}

	//���� ������Ʈ ����
	for (int i = 0; i < (int)OBJ::OBJNUM; i++)
	{
		pGameObject[i]->m_Active = true;
	}

	pGameObject[(int)OBJ::BUCKET]->SetObj({ INFO_ID::SEARCH_BUCKET, ITEM_, OBJ::BUCKET });			//�絿��
	pGameObject[(int)OBJ::CHARM]->SetObj({ INFO_ID::SEARCH_CHARM, ITEM_, OBJ::CHARM });				//����
	pGameObject[(int)OBJ::HANGDEAD]->SetObj({ INFO_ID::SEARCH_HANGDEAD, ITEM_, OBJ::HANGDEAD });	//�� �Ŵ� ��ü
	pGameObject[(int)OBJ::BOOK]->SetObj({ INFO_ID::SEARCH_DIARY, ITEM_, OBJ::BOOK });				//��� ����
	pGameObject[(int)OBJ::SWITCH]->SetObj({ INFO_ID::INTER_SWITCH, ITEM_, OBJ::SWITCH });			//���� ����ġ
	pGameObject[(int)OBJ::BAG]->SetObj({ INFO_ID::SEARCH_BAG, ITEM_, OBJ::BAG });					//����
	pGameObject[(int)OBJ::DEADBODY]->SetObj({ INFO_ID::SEARCH_DEADGIRL, ITEM_, OBJ::DEADBODY });	//��ü(Į)		
	pGameObject[(int)OBJ::NOTEBOOK]->SetObj({ INFO_ID::SEARCH_COMPUTER, ITEM_, OBJ::NOTEBOOK });	//å��(��ǻ��)	
	pGameObject[(int)OBJ::CAMERA]->SetObj({ INFO_ID::SEARCH_CAMERA, ITEM_, OBJ::CAMERA });			//�Կ����
	pGameObject[(int)OBJ::ALTAR]->SetObj({ INFO_ID::SEARCH_ALTAR, ITEM_, OBJ::ALTAR });				//����
	pGameObject[(int)OBJ::TOILET]->SetObj({ INFO_ID::SEARCH_TOILET, ITEM_, OBJ::TOILET });			//ȭ���
	pGameObject[(int)OBJ::FIREHYDRANT]->SetObj({ INFO_ID::SEARCH_FIREHOSE, ITEM_, OBJ::FIREHYDRANT });	//��ȭ��
	pGameObject[(int)OBJ::BOARD]->SetObj({ INFO_ID::SEARCH_BOARD, ITEM_, OBJ::BOARD });				//�Խ���
	pGameObject[(int)OBJ::VENT]->SetObj({ INFO_ID::SEARCH_VENT, ITEM_, OBJ::VENT });				//ȯǳ��

	pGameObject[(int)OBJ::CANDLE_FIRE_R]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::CANDLE_FIRE_R });				//�к�
	pGameObject[(int)OBJ::CANDLE_FIRE_L]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::CANDLE_FIRE_L });				//�к�
	pGameObject[(int)OBJ::MAGICCIRCLE]->SetObj({ INFO_ID::SEARCH_VENT, NONE_, OBJ::MAGICCIRCLE });				//������

	pGameObject[(int)OBJ::DOOR]->SetObj({ INFO_ID::TO_HALLWAY, DOOR_, OBJ::DOOR, ROOM::HALLWAY });					//������(����)
	pGameObject[(int)OBJ::DOOR301]->SetObj({ INFO_ID::TO_301, DOOR_, OBJ::DOOR301, ROOM::ROOM301 });				//301ȣ ��
	pGameObject[(int)OBJ::DOOR302]->SetObj({ INFO_ID::TO_302, DOOR_, OBJ::DOOR302, ROOM::ROOM302 });				//302ȣ ��
	pGameObject[(int)OBJ::DOOR303]->SetObj({ INFO_ID::TO_303, DOOR_, OBJ::DOOR303, ROOM::ROOM303 });				//303ȣ ��
	pGameObject[(int)OBJ::DOOR304]->SetObj({ INFO_ID::TO_304, DOOR_, OBJ::DOOR304 , ROOM::ROOM304 });				//304ȣ ��
	pGameObject[(int)OBJ::SECRETDOOR]->SetObj({ INFO_ID::TO_SECRET, DOOR_, OBJ::SECRETDOOR, ROOM::SECRETROOM });		//��� ��
	pGameObject[(int)OBJ::INTRO303]->SetObj({ INFO_ID::TO_303, DOOR_, OBJ::INTRO303,  ROOM::INTRO_303 });		//��Ʈ�� 303ȣ ��

	pGameObject[(int)OBJ::ESCAPE]->SetObj({ INFO_ID::TO_ESC, ESC_, OBJ::ESCAPE });
#pragma endregion
}