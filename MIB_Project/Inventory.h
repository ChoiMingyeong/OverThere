#pragma once
#define EMPTY_	-1		// �� ������
#define MAX_	3		// �κ��丮 ũ��

class Inventory
{
#pragma region ������ & �Ҹ���
public:
	Inventory();
	~Inventory();
#pragma endregion

#pragma region ��� ����
private:
	int m_Slot[MAX_];		// �κ��丮 ����(MAX_ ũ��)
	int m_ItemNum;			// ������ �ִ� ������ ����
#pragma endregion

#pragma region ��� �Լ�
public:
	int m_EquipIndex;		// ���� �ε���
	//�κ��丮 �ʱ�ȭ
	void InvenInit();
	//���� �ε��� ����
	void ChangeEquip();
	//������ ȹ��
	void GetItem(int item);
	//������ ���
	int UseItem();
	//���� ������ üũ
	int CheckItem();
	//������ ���� ���
	int GetItemInfo(int index);
#pragma endregion
};

