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
	INFO_ID m_info = INFO_ID::INFONUM;		//정보 문구
	int m_Type = NONE_;			//타입(0: 문, 1:상호작용 템, 2:비상구)
	OBJ m_Item = OBJ::OBJNUM;			//아이템 넘버 or 방 문
	ROOM m_Room = ROOM::ROOMNUM;		//방 넘버
};

class GameObject :public MIBObject
{
private:
	ObjInfo m_Info;		//정보
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

