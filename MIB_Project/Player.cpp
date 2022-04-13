#include "pch.h"

#include "Inventory.h"
#include "Player.h"

Player::Player()
{
	m_pInven = new Inventory();
}

Player::~Player()
{

}

void Player::Initialize(MIBSprite* sprites[])
{
	for (int i = 0; i < (int)PLAYER::STATENUM; i++)
	{
		m_Spr[i] = sprites[i];
	}
	
	Reset();
}

void Player::Reset()
{
	m_Speed = 10.5f;
	m_Dead = false;
	m_pInven->InvenInit();
}

void Player::Move()
{
	int move = 0;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		move -= m_Speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		move += m_Speed;
	}

	if (move == 0)
	{
		m_State = (int)PLAYER::IDLE_L + m_Direct;
	}
	else if (move > 0)
	{
		m_State = (int)PLAYER::RUN_R;
		m_Direct = 1;
	}
	else
	{
		m_State = (int)PLAYER::RUN_L;
		m_Direct = 0;
	}

	//콜라이더 설정!
	SetSprite(m_Spr[m_State]);

	//move 가능한지 검사
	if (m_pos.x + move > 0 && m_pos.x + (m_Spr[(int)PLAYER::IDLE_L + m_Direct]->m_Width) * 2 + move < m_Limit)
	{
		m_pos.x += move;
	}

	//sound test
	if (m_State == (int)PLAYER::RUN_R || m_State == (int)PLAYER::RUN_L)
	{
		if (m_pSpr->AniTime == 0.0f)
		{
			switch (m_pSpr->AniFrm)
			{
			case 1:
				AudioManager::GetInstance()->Play("run");
				break;

			case 3:
				AudioManager::GetInstance()->Play("run");
				break;
			}
		}
	}
}

void Player::Draw(MIBEngine* pEngine)
{
	if (pEngine == nullptr) return;

	RECT pos = GetWorldAABB();

	pos.left += pEngine->m_Scroll;
	pos.right += pEngine->m_Scroll;

	pEngine->DrawSprite(m_Spr[m_State], { pos.left,pos.top }, false);
	if (pEngine->m_DrawCollider)
		pEngine->DrawDebugRectangle({ pos.left,pos.top }, { pos.right, pos.bottom }, RGB(0, 255, 0));
}

void Player::CollCheck(MIBObject* objs[])
{
	//부딫힌 오브젝트가 있을 때
	if (m_hitobjs.size() <= 0)	return;

	//몬스터랑 부딫혔는지 체크
	for (int i = 0; i < m_hitobjs.size(); i++)
	{
		/*if (m_hitobjs[i] == g_pMonster)
		{
			return;
		}*/
	}
}