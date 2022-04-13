#pragma once

#include "..//MIB_Engine/MIBEngine.h"
#include "..//MIB_Engine/MIBEngineDefine.h"

class Unit : public MIBObject
{
#pragma region ������ & �Ҹ���
public:
	Unit();
	virtual ~Unit();
#pragma endregion

#pragma region ����
public:
	float m_Speed;			//���� �ӵ�
	int m_Direct;			//���� ����

	MIBSprite** m_Spr;		//���� ��������Ʈ(���º�)
#pragma endregion

#pragma region �Լ�
public:
	virtual void Initialize();
	virtual void Move();	//���� �̵� �Լ�
#pragma endregion
};