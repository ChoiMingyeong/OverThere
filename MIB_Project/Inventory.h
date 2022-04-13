#pragma once
#define EMPTY_	-1		// 빈 아이템
#define MAX_	3		// 인벤토리 크기

class Inventory
{
#pragma region 생성자 & 소멸자
public:
	Inventory();
	~Inventory();
#pragma endregion

#pragma region 멤버 변수
private:
	int m_Slot[MAX_];		// 인벤토리 슬롯(MAX_ 크기)
	int m_ItemNum;			// 가지고 있는 아이템 개수
#pragma endregion

#pragma region 멤버 함수
public:
	int m_EquipIndex;		// 장착 인덱스
	//인벤토리 초기화
	void InvenInit();
	//장착 인덱스 변경
	void ChangeEquip();
	//아이템 획득
	void GetItem(int item);
	//아이템 사용
	int UseItem();
	//장착 아이템 체크
	int CheckItem();
	//아이템 정보 얻기
	int GetItemInfo(int index);
#pragma endregion
};

