#pragma once

#include "EnumDefine.h"

class GameData
{
public:
	//��������Ʈ
	MIBSprite* pBGSpr[(int)BG::BGNUM];		//��� ��������Ʈ
	MIBSprite* pObjSpr[(int)OBJ::OBJNUM];	//������Ʈ ��������Ʈ
	MIBSprite* pUISpr[(int)UI::UINUM];		//UI ��������Ʈ

	MIBSprite* pPlayerSpr[(int)PLAYER::STATENUM];		//�÷��̾� ��������Ʈ
	MIBSprite* pMonsterSpr[(int)MONSTER::STATENUM];		//���� ��������Ʈ

	//���� ������Ʈ
	GameObject* pGameObject[(int)OBJ::OBJNUM];	//���� ������Ʈ
	//������ �̸�
	LPCSTR pItemName[(int)UI::UINUM];
	
public:
	//���� ������ �ε�
	void LoadData(MIBEngine* pEngine);
	//���� ������ ����
	void ResetData();
};