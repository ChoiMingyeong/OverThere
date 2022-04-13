#include "pch.h"
#include "Inventory.h"

Inventory::Inventory()
{
	// �κ� ���� �ʱ�ȭ
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
	// �κ� ���� �ʱ�ȭ
	for (int i = 0; i < MAX_; i++)
	{
		m_Slot[i] = EMPTY_;
	}

	m_EquipIndex = 0;
	m_ItemNum = 0;
}

void Inventory::ChangeEquip()
{
	++m_EquipIndex %= MAX_;	//�����ִ� ������ ���� �������� �Դٰ��� ��
}

void Inventory::GetItem(int item)
{
	if (m_ItemNum == MAX_) return;	//�κ��� �� ĭ�� ������ �Լ� ����

	m_Slot[m_ItemNum] = item;
	m_ItemNum++;
}

int Inventory::UseItem()
{
	if (m_ItemNum <= 0) return EMPTY_;	//�����ִ� �������� ������ �Լ� ����

	//������ ���
	int item = m_Slot[m_EquipIndex];
	m_Slot[m_EquipIndex] = EMPTY_;
	m_ItemNum--;

	//������ ������ �б�
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
