#pragma once
#include "pch.h"
#include "AABB.h"

class MIBSprite
{
#pragma region ������ & �Ҹ���
public:
	/*MIBSprite();
	~MIBSprite();*/
#pragma endregion

#pragma region ����
public:
	// ���� �߿��� ��Ʈ�� �ڵ�
	HBITMAP m_hBitmap;

	// ��������Ʈ�� �ε� �� dc
	HDC m_MemDC;

	// ��������Ʈ�� �ΰ� ����
	int m_Width;		// ��
	int m_Height;		// ���� 
	int KeyColor;		// Ű �÷�
	POINT m_Center;		// ��������Ʈ ����
	POINT m_OrgPos;		// ��������Ʈ�� �׸� ������

	int AniState = 0;		// �ִϸ��̼� ���� ���°�(Idle, Walk ��..)
	int AniMAXState = 1;	// �ִϸ��̼��� ���� ����
	float AniTime = 0.0f;	// �ִϸ��̼��� ����� �ð�
	int AniFrm = 0;			// �ִϸ��̼��� ���� ������
	int AniMAXFrm = 1;		// �ִϸ��̼��� ������ ��
	float AniSpeed = 1;		// �ִϸ��̼��� �ӵ�

#pragma endregion

#pragma region �Լ�
	void SetSpriteInfo();
	void SetAnim(int maxfrm = 1, int maxstate = 1, float speed = 1);	// �ִϸ��̼� �� ����(�⺻��1, 1, 1)
	void AnimPlay(float dTime);	//�ִϸ��̼� �÷���

	POINT const GetCenterFromPos(POINT pos);
#pragma endregion

};

class MIBObject
{
#pragma region ������ & �Ҹ���
public:
	MIBObject();
	MIBObject(MIBEngine* pEngine);
	virtual ~MIBObject();
#pragma endregion

#pragma region ����
public:
	POINT m_pos;			// ������Ʈ ��ġ
	bool m_Active = true;			// �׸��� �ȱ׸���

	MIBSprite* m_pSpr;		// ������Ʈ�� ��������Ʈ
	AABB m_AABB;			// ������Ʈ�� �浹 �ڽ�

	std::vector<MIBObject*> m_hitobjs;	// �ڽŰ� �浹�� ������Ʈ ����
#pragma endregion

#pragma region �Լ�
public:
	virtual void SetSprite(MIBSprite* pSpr);
	virtual void Draw(MIBEngine* pEngine);
	virtual void SetPos(POINT pos) { m_pos = pos; }
	virtual void SetPos(int x) { m_pos.x = x; }

	virtual RECT GetWorldAABB();

	virtual bool IsCollied(MIBObject* pObj);

	virtual void Reset();
#pragma endregion

};