#pragma once

#include "Unit.h"

//���漱��
class Player;

class Monster : public Unit
{
#pragma region ������ & �Ҹ���
public:
	Monster();
	virtual ~Monster();
#pragma endregion

#pragma region �������
public:
	int m_State = 0;
	MIBSprite* m_Spr[(int)MONSTER::STATENUM] = { 0, };
	Player* m_Player;		//�÷��̾�
	float m_WaitTime = 0;
	bool m_IsWait = false;
#pragma endregion


#pragma region �Լ�
public:
	virtual void Initialize(MIBSprite* spr[], Player* p);
	virtual void Move();
	virtual void Draw(MIBEngine* pEngine);

	virtual void Reset();
#pragma endregion
};
