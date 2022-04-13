#pragma once

#include <vector>

#include "Unit.h"
#include "EnumDefine.h"
#include "AudioManager.h"

class Inventory;

class Player : public Unit
{
#pragma region 생성자 & 소멸자
public:
	Player();
	virtual ~Player();
#pragma endregion

#pragma region 멤버변수
public:
	int m_State = 0;		//플레이어 상태
	MIBSprite* m_Spr[(int)PLAYER::STATENUM] = {0,};		//플레이어 스프라이트(상태별)
	Inventory* m_pInven;	//인벤토리
	bool m_Dead;

	//맵 이동 제한 체크용
	int m_Limit = 1280;
#pragma endregion

#pragma region 함수
public:
	virtual void Initialize(MIBSprite* sprites[]);	//초기화
	virtual void Reset();		//리셋
	virtual void Move();		//이동

	virtual void Draw(MIBEngine* pEngine);		//그리기

	void CollCheck(MIBObject* objs[]);		//상호작용
#pragma endregion
};