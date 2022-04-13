#pragma once

#include "..//MIB_Engine/MIBEngine.h"
#include "..//MIB_Engine/MIBEngineDefine.h"

class Unit : public MIBObject
{
#pragma region 생성자 & 소멸자
public:
	Unit();
	virtual ~Unit();
#pragma endregion

#pragma region 변수
public:
	float m_Speed;			//유닛 속도
	int m_Direct;			//유닛 방향

	MIBSprite** m_Spr;		//유닛 스프라이트(상태별)
#pragma endregion

#pragma region 함수
public:
	virtual void Initialize();
	virtual void Move();	//유닛 이동 함수
#pragma endregion
};