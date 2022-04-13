#pragma once
#include "pch.h"
#include "AABB.h"

class MIBSprite
{
#pragma region 생성자 & 소멸자
public:
	/*MIBSprite();
	~MIBSprite();*/
#pragma endregion

#pragma region 변수
public:
	// 가장 중요한 비트맵 핸들
	HBITMAP m_hBitmap;

	// 스프라이트가 로드 될 dc
	HDC m_MemDC;

	// 스프라이트의 부가 정보
	int m_Width;		// 폭
	int m_Height;		// 높이 
	int KeyColor;		// 키 컬러
	POINT m_Center;		// 스프라이트 중점
	POINT m_OrgPos;		// 스프라이트를 그릴 보정값

	int AniState = 0;		// 애니메이션 현재 상태값(Idle, Walk 등..)
	int AniMAXState = 1;	// 애니메이션의 상태 개수
	float AniTime = 0.0f;	// 애니메이션이 재생된 시간
	int AniFrm = 0;			// 애니메이션의 현재 프레임
	int AniMAXFrm = 1;		// 애니메이션의 프레임 수
	float AniSpeed = 1;		// 애니메이션의 속도

#pragma endregion

#pragma region 함수
	void SetSpriteInfo();
	void SetAnim(int maxfrm = 1, int maxstate = 1, float speed = 1);	// 애니메이션 값 세팅(기본값1, 1, 1)
	void AnimPlay(float dTime);	//애니메이션 플레이

	POINT const GetCenterFromPos(POINT pos);
#pragma endregion

};

class MIBObject
{
#pragma region 생성자 & 소멸자
public:
	MIBObject();
	MIBObject(MIBEngine* pEngine);
	virtual ~MIBObject();
#pragma endregion

#pragma region 변수
public:
	POINT m_pos;			// 오브젝트 위치
	bool m_Active = true;			// 그리냐 안그리냐

	MIBSprite* m_pSpr;		// 오브젝트의 스프라이트
	AABB m_AABB;			// 오브젝트의 충돌 박스

	std::vector<MIBObject*> m_hitobjs;	// 자신과 충돌한 오브젝트 벡터
#pragma endregion

#pragma region 함수
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