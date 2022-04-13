#include "pch.h"

//MIBSprite::MIBSprite()
//{
//}
//
//MIBSprite::~MIBSprite()
//{
//}

void MIBSprite::SetSpriteInfo()
{
	SelectObject(m_MemDC, m_hBitmap);

	// 비트맵 정보에서 원하는 값만 변수에 저장
	BITMAP _bitmap;
	GetObject(m_hBitmap, sizeof(BITMAP), &_bitmap);
	m_Width = _bitmap.bmWidth;
	m_Height = _bitmap.bmHeight;
	KeyColor = RGB(255, 0, 255);
	m_Center = { m_Width / 2, m_Height / 2 };
	m_OrgPos = { m_Center.x, m_Height };
	DeleteObject(m_hBitmap);
}

void MIBSprite::SetAnim(int maxfrm, int maxstate, float speed)
{
	AniMAXFrm = maxfrm;
	AniMAXState = maxstate;
	AniSpeed = 1 / speed;

	m_Width /= AniMAXFrm;
	m_Height /= AniMAXState;
}

POINT const MIBSprite::GetCenterFromPos(POINT pos)
{
	return { pos.x - m_Center.x, pos.y - m_Center.y };
}

void MIBSprite::AnimPlay(float dTime)
{
	AniTime += dTime;

	if (AniTime > ((1.0f / (float)AniMAXFrm) * AniSpeed))	//1초당 7프레임의 속도 경과후..
	{
		AniTime = 0.0f;
		++AniFrm %= AniMAXFrm;
	}
}

MIBObject::MIBObject()
{
	m_pos = { 0,0 };

	m_pSpr = nullptr;
}

MIBObject::MIBObject(MIBEngine* pEngine)
{
	m_pos = { 0,0 };
	m_pSpr = nullptr;
	pEngine->m_objs.push_back(this);
}

MIBObject::~MIBObject()
{

}

void MIBObject::SetSprite(MIBSprite* pSpr)
{
	m_pSpr = pSpr;
	m_AABB.SetAABB(pSpr->m_Width, pSpr->m_Height, pSpr->m_Center);
}

void MIBObject::Draw(MIBEngine* pEngine)
{
	if (m_pSpr == nullptr) return;

	RECT pos = GetWorldAABB();

	pos.left += pEngine->m_Scroll;
	pos.right += pEngine->m_Scroll;

	if (m_Active)
	{
		pEngine->DrawSprite(m_pSpr, { pos.left, pos.top }, false);
		if (pEngine->m_DrawCollider)
			pEngine->DrawDebugRectangle({ pos.left,pos.top }, { pos.right, pos.bottom }, RGB(0, 255, 0));
	}
}


RECT MIBObject::GetWorldAABB()
{
	RECT _worldAABB = m_AABB.GetAABB();

	_worldAABB.left += m_pos.x;
	_worldAABB.right += m_pos.x;
	_worldAABB.top += m_pos.y;
	_worldAABB.bottom += m_pos.y;

	return _worldAABB;
}

bool MIBObject::IsCollied(MIBObject* pObj)
{
	//active가 false면 체크 안함
	if (pObj->m_Active == false) return false;

	RECT source = GetWorldAABB();
	RECT target = pObj->GetWorldAABB();

	// x 축의 영역이 겹친다.
	if (source.left < target.right
		&& target.left < source.right)
	{
		if (source.top < target.bottom
			&& target.top < source.bottom)
		{
			return true;
		}
	}
	return false;
}

void MIBObject::Reset()
{
}
