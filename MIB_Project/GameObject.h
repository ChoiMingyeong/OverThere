#pragma once

#include "..//MIB_Engine/MIBEngine.h"
#include "..//MIB_Engine/MIBEngineDefine.h"

#include "EnumDefine.h"

#define NONE_ -1
#define DOOR_ 0
#define ITEM_ 1
#define ESC_  2

struct ObjInfo
{
	INFO_ID m_info = INFO_ID::INFONUM;		//���� ����
	int m_Type = NONE_;			//Ÿ��(0: ��, 1:��ȣ�ۿ� ��, 2:���)
	OBJ m_Item = OBJ::OBJNUM;			//������ �ѹ� or �� ��
	ROOM m_Room = ROOM::ROOMNUM;		//�� �ѹ�
};

class GameObject :public MIBObject
{
private:
	ObjInfo m_Info;		//����
public:
	GameObject()
	{
		m_Info = ObjInfo();
	}
	~GameObject()
	{

	}

	void SetObj(ObjInfo info)
	{
		m_Info = info;
	}
	void GetObj(ObjInfo& info)
	{
		info = m_Info;
	}
};

