#include "pch.h"
#include "Monster.h"

Monster::Monster()
{

}

Monster::~Monster()
{

}

void Monster::Initialize(MIBSprite* spr[], Player* p)
{
	for (int i = 0; i < (int)MONSTER::STATENUM; i++)
	{
		m_Spr[i] = spr[i];
	}

	m_Player = p;
	
	Reset();
}

void Monster::Move()
{
	// 자동으로 움직임
	if (m_pos.x < m_Player->m_pos.x)
	{
		m_Direct = 1;
		m_State = (int)MONSTER::RUN_R;
	}
	else
	{
		m_Direct = -1;
		m_State = (int)MONSTER::RUN_L;
	}

	//콜라이더 설정!
	SetSprite(m_Spr[m_State]);

	m_pos.x += m_Direct * m_Speed;

	//sound test
	if (m_pSpr->AniTime == 0.0f
		&& m_pSpr->AniFrm == 3)
	{
		AudioManager::GetInstance()->Play("1", 0.4f);
	}
}

void Monster::Draw(MIBEngine* pEngine)
{
	if (pEngine == nullptr) return;

	RECT pos = GetWorldAABB();

	pos.left += pEngine->m_Scroll;
	pos.right += pEngine->m_Scroll;

	if (m_Active)
	{
		pEngine->DrawSprite(m_Spr[m_State], { pos.left,pos.top }, false);
		if (pEngine->m_DrawCollider)
			pEngine->DrawDebugRectangle({ pos.left,pos.top }, { pos.right, pos.bottom }, RGB(0, 255, 0));
	}
}

void Monster::Reset()
{
	m_State = 0;
	m_Active = false;
	m_Speed = 10.4f;
}