#pragma once

#include <vector>

#include "EnumDefine.h"

struct Script
{
	LPCSTR script;
	SCR_COLOR color = SCR_COLOR::WHITE;
};

class ScriptManager
{
private:
	std::vector<Script> m_Scripts[(int)SCR_ID::IDNUM];
	LPCSTR m_Info[(int)INFO_ID::INFONUM];
	int m_Index;
public:
	ScriptManager();
	~ScriptManager();

	void Init();
	void Add(std::vector<Script>& scr);
	void AddScripts(std::vector<Script>& user, SCR_ID id);
	void AddInfo(LPCSTR& user, INFO_ID id);
};