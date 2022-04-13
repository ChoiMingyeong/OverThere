#pragma once

#include "EnumDefine.h"

class GameData
{
public:
	//스프라이트
	MIBSprite* pBGSpr[(int)BG::BGNUM];		//배경 스프라이트
	MIBSprite* pObjSpr[(int)OBJ::OBJNUM];	//오브젝트 스프라이트
	MIBSprite* pUISpr[(int)UI::UINUM];		//UI 스프라이트

	MIBSprite* pPlayerSpr[(int)PLAYER::STATENUM];		//플레이어 스프라이트
	MIBSprite* pMonsterSpr[(int)MONSTER::STATENUM];		//몬스터 스프라이트

	//게임 오브젝트
	GameObject* pGameObject[(int)OBJ::OBJNUM];	//게임 오브젝트
	//아이템 이름
	LPCSTR pItemName[(int)UI::UINUM];
	
public:
	//게임 데이터 로드
	void LoadData(MIBEngine* pEngine);
	//게임 데이터 리셋
	void ResetData();
};