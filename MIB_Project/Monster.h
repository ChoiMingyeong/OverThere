#pragma once

#include "Unit.h"

//전방선언
class Player;

class Monster : public Unit
{
#pragma region 생성자 & 소멸자
public:
	Monster();
	virtual ~Monster();
#pragma endregion

#pragma region 멤버변수
public:
	int m_State = 0;
	MIBSprite* m_Spr[(int)MONSTER::STATENUM] = { 0, };
	Player* m_Player;		//플레이어
	float m_WaitTime = 0;
	bool m_IsWait = false;
#pragma endregion


#pragma region 함수
public:
	virtual void Initialize(MIBSprite* spr[], Player* p);
	virtual void Move();
	virtual void Draw(MIBEngine* pEngine);

	virtual void Reset();
#pragma endregion
};
