#pragma once

#include <vector>

#include "Unit.h"
#include "EnumDefine.h"
#include "AudioManager.h"

class Inventory;

class Player : public Unit
{
#pragma region ������ & �Ҹ���
public:
	Player();
	virtual ~Player();
#pragma endregion

#pragma region �������
public:
	int m_State = 0;		//�÷��̾� ����
	MIBSprite* m_Spr[(int)PLAYER::STATENUM] = {0,};		//�÷��̾� ��������Ʈ(���º�)
	Inventory* m_pInven;	//�κ��丮
	bool m_Dead;

	//�� �̵� ���� üũ��
	int m_Limit = 1280;
#pragma endregion

#pragma region �Լ�
public:
	virtual void Initialize(MIBSprite* sprites[]);	//�ʱ�ȭ
	virtual void Reset();		//����
	virtual void Move();		//�̵�

	virtual void Draw(MIBEngine* pEngine);		//�׸���

	void CollCheck(MIBObject* objs[]);		//��ȣ�ۿ�
#pragma endregion
};