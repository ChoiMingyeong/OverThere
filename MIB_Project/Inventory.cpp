#include "pch.h"
#include "Inventory.h"

Inventory::Inventory()
{
	// 인벤 슬롯 초기화
	for (int i = 0; i < MAX_; i++)
	{
		m_Slot[i] = EMPTY_;
	}

	m_EquipIndex = 0;
	m_ItemNum = 0;
}

Inventory::~Inventory()
{

}

void Inventory::InvenInit()
{
	// 인벤 슬롯 초기화
	for (int i = 0; i < MAX_; i++)
	{
		m_Slot[i] = EMPTY_;
	}

	m_EquipIndex = 0;
	m_ItemNum = 0;
}

void Inventory::ChangeEquip()
{
	++m_EquipIndex %= MAX_;	//갖고있는 아이템 슬롯 내에서만 왔다갔다 함
}

void Inventory::GetItem(int item)
{
	if (m_ItemNum == MAX_) return;	//인벤에 빈 칸이 없으면 함수 종료

	m_Slot[m_ItemNum] = item;
	m_ItemNum++;
}

int Inventory::UseItem()
{
	if (m_ItemNum <= 0) return EMPTY_;	//갖고있는 아이템이 없으면 함수 종료

	//아이템 사용
	int item = m_Slot[m_EquipIndex];
	m_Slot[m_EquipIndex] = EMPTY_;
	m_ItemNum--;

	//아이템 앞으로 밀기
	for (int i = 1; i < MAX_; i++)
	{
		if (m_Slot[i] != EMPTY_)
		{
			int index = i;
			while (m_Slot[index - 1] == EMPTY_)
			{
				m_Slot[index - 1] = m_Slot[index];
				m_Slot[index] = EMPTY_;
			}
		}
	}

	return item;
}

int Inventory::CheckItem()
{
	return m_Slot[m_EquipIndex];
}

int Inventory::GetItemInfo(int index)
{
	return m_Slot[index];
}
