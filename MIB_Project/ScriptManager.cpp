#include "pch.h"

ScriptManager::ScriptManager()
{
	m_Index = 0;
}

ScriptManager::~ScriptManager()
{

}

void ScriptManager::Init()
{
#pragma region ��ũ��Ʈ
#pragma region Intro
	//1
	m_Index = (int)SCR_ID::STORY_INTRO_1;
	std::vector<Script> scr;
	scr.push_back({ "[ppppp-]", SCR_COLOR::GREY });
	scr.push_back({ "��, �󹫴�." });
	scr.push_back({ "[�� ���� ����?]", SCR_COLOR::GREY });
	scr.push_back({ "�����Ͻ� ���� �����߽��ϴ�. ���� �۾� �غ��ϰ� �ڷ��� ���Դϴ�." });
	scr.push_back({ "[��ħ���� �߿��� ���̴�, �Ǽ� ����. �� �����ϰ� �ʹٸ�?]", SCR_COLOR::GREY });
	scr.push_back({ "�ơ� ��! �ּ��� ���ϰڽ��ϴ�!!" });
	scr.push_back({ "[���� �����ϴ� �� ���� ����. �׷� ���´�.]", SCR_COLOR::GREY });
	scr.push_back({ "[��-.]", SCR_COLOR::GREY });
	Add(scr);

	//2
	scr.push_back({ "��¥ �ð� �����̳�. �����ϴ� ���� ���̱�." });
	scr.push_back({ "�� �濡 �� ����� �ڴµ�." });
	scr.push_back({ "���� �ӹ� ���� 303ȣ��� �߾���?" });
	scr.push_back({ "303ȣ�� ����." });
	Add(scr);

	//3
	scr.push_back({ "���� ����ġ�� ����.", SCR_COLOR::GREY });
	scr.push_back({ "��ħ���� �߿��� ���̶�� ������ ���� �����. ����." });
	scr.push_back({ "��. �ϴ� �� �� ���ϱ" });
	Add(scr);

	//4
	scr.push_back({ "�Ҹ���ġ�� �Ҹ��� �鸰��...", SCR_COLOR::GREY });
	scr.push_back({ "����, �̰� ���� �Ҹ���?" });
	Add(scr);
#pragma endregion

#pragma region Story_1
	//1
	m_Index = (int)SCR_ID::STORY_1_1;
	scr.push_back({ "�ۿ��� �� �Ҹ�������... ������ Ȯ���غ��߰ھ�." });
	Add(scr);

	//2
	scr.push_back({ "���� �ɸ� �� ������..." });
	scr.push_back({ "���� �� ���� ������ ã�ƺ��߰ھ�." });
	Add(scr);

	//3
	scr.push_back({ "���縦 �����.", SCR_COLOR::GREY });
	scr.push_back({ "����, �̰Ÿ� �ǰ���. ì�ܿ��� ���߾�." });
	Add(scr);

	//4
	scr.push_back({ "�ϳ�...��..." });
	scr.push_back({ "��!!!" });
	scr.push_back({ "����, ���ȴ�!" });
	scr.push_back({ "�̰� �ѹ��ߴٰ� �η����ٴϡ�. �߱����� �� ��¼�ھ�." });
	scr.push_back({ "������ ���縦 ���ȴ�.", SCR_COLOR::GREY });
	Add(scr);
#pragma endregion

#pragma region Story_2
	//1
	m_Index = (int)SCR_ID::STORY_2_1;
	scr.push_back({ "��ü ���� �ɷ� �ִ� �ž�?" });
	scr.push_back({ "!!!!!" });
	scr.push_back({ "���� �̷��� ��ü����?" });
	scr.push_back({ "..." });
	scr.push_back({ "����, ���� ��� ���ư��� �ž�... �ϴ� ��ȭ�� �˷��ߴµ��� �� ��ȣ�� �� �� ����?" });
	scr.push_back({ "�� �� ����. �ϴ� ��󱸷� ����." });
	Add(scr);

	//2
	scr.push_back({ "���� �̰� �� �� �̷�? �� �����ݾ�?" });
	scr.push_back({ "!!!!!" });
	scr.push_back({ "����, �ϴ� ������ �������߰ھ�!" });
	scr.push_back({ "���� ���� ���� ã�ƾ� �Ѵ�!", SCR_COLOR::GREY });
	Add(scr);
#pragma endregion

#pragma region Story_3
	//1
	m_Index = (int)SCR_ID::STORY_3_1;
	scr.push_back({ "�湮�� ������ �ݾҴ�.", SCR_COLOR::GREY });
	scr.push_back({ "��...��..." });
	scr.push_back({ "�Ҹ��� �־�����.", SCR_COLOR::GREY });
	scr.push_back({ "������� �� ������ ����... ���� ������ ����?" });
	scr.push_back({ "��... ���⿡�� ��ü��..." });
	Add(scr);

	//2
	scr.push_back({ "���� �ٷ��̸� �����.", SCR_COLOR::GREY });
	scr.push_back({ "�� ������� �����ΰ� ������  ��¼�ٰ���" });
	scr.push_back({ "�ٵ�....�� �ӿʿ� ���踦 �ް� �ִ� ����??" });
	Add(scr);

	//3
	scr.push_back({ "�� ���� �߿� �´� �� �̰ǰ�?" });
	scr.push_back({ "���� �ٷ��̸� ����ߴ�.", SCR_COLOR::GREY });
	Add(scr);
#pragma endregion

#pragma region Story_4
	//1
	m_Index = (int)SCR_ID::STORY_4_1;
	scr.push_back({ "�ġ� �ơ� ���⵵ ����� �׾��ݾ�?" });
	Add(scr);

	//2
	scr.push_back({ "���� ������ �ִ١� ������ ���ܳ��� ����̴�.", SCR_COLOR::GREY });
	scr.push_back({ "<���� ��ȭ�Ǿ���. ���� �׺��� �� �غ� �ƴ�.",SCR_COLOR::RED });
	scr.push_back({ "�� ����� �� ���̴�.�� �Ӹ��� â��, â������>",SCR_COLOR::RED });
	scr.push_back({ "��... ����? �� �Ӹ��� ���� Į��... ������ �ǰ�?" });
	Add(scr);

	//3
	scr.push_back({ "Į�� �����.", SCR_COLOR::GREY });
	scr.push_back({ "���� ���ؼ� �������� ���� ��ư�����, ��� �� ���� �ְ���." });
	Add(scr);

	//4
	scr.push_back({ "�� ������ ��ǻ�ʹ�." });
	scr.push_back({ "���� ��� ���� �� �ִ� �� ������." });
	scr.push_back({ "�۾� ��Ʈ���� ���� ���ε� �� �� �ִٰ� �� �־�." });
	scr.push_back({ "<3�� ������ ��� ��ƼĿ> �� �ִ�." });
	scr.push_back({ "�� ���, ��Ʈ���ӿ��� ����." });
	Add(scr);

	//5
	scr.push_back({ "SD ī�带 �����.", SCR_COLOR::GREY });
	scr.push_back({ "[�ߴ� �Կ���]�� �� �޸� Ĩ�� ��ǻ�ͷ� ����� ���� ���� ������?" });
	Add(scr);

	//6
	scr.push_back({ "SD ī�带 ����ߴ�.", SCR_COLOR::GREY });
	scr.push_back({ "�Կ�����: XX�� XX�� X3�� AM 02 : 44" });
	scr.push_back({ "\"��! �ܵ�����! ���ʰ���! ���̺� ������ ��� ��Ҹ� ã�Ҿ�!\"" });
	scr.push_back({ "\"���� ����� XX�� ���� ������ ���� ����̰� ��!���� ��� �´�.����!\"" });
	scr.push_back({ "\"��� ���? ���̺� �ŵ����� õ�� ����� �־� ���� ���� �־�. ����� 301ȣ ������?\"" });
	scr.push_back({ "\"�� 3�� �ڹ��赵 �ɷ��־�...�����...��ȭ���� ������ �ϳ���...\"" });
	scr.push_back({ "\"�� ����� ������ ��ȭ���� ���� ���ɡ�. ��! ��ŵ� ���� (�ݷ��� ���ư��� ī�޶� ����)(����)\"" });
	scr.push_back({ "��������", SCR_COLOR::GREY });
	scr.push_back({ "��ȭ������ 301ȣ�� ���õ� �� �ִٴ� �ǰ�." });
	scr.push_back({ "��ȭ������ ������." });
	Add(scr);
#pragma endregion

#pragma region Story_5
	//1
	m_Index = (int)SCR_ID::STORY_5_1;
	scr.push_back({ "��ȭ���� ������.", SCR_COLOR::GREY });
	scr.push_back({ "�̰� ���󿡼� ���� ��ȭ���̱�." });
	scr.push_back({ "��� Ȯ���� ����?" });
	Add(scr);

	//2
	scr.push_back({ "�� ���� ���� �� �������� ��?" });
	scr.push_back({ "�� ���ٱͰ� ���衦?" });
	scr.push_back({ "�� ���踦 �����.", SCR_COLOR::GREY });
	scr.push_back({ "... 301ȣ�� ������." });
	Add(scr);

	//3
	scr.push_back({ "�����. �� �ڹ��谡 �̷��� ����?" });
	scr.push_back({ "ù ��° �ڹ��踦 Ǯ����.", SCR_COLOR::GREY });
	Add(scr);

	//4
	scr.push_back({ "�� ��° �ڹ��踦 Ǯ����.", SCR_COLOR::GREY });
	scr.push_back({ "���� �ϳ� ���Ҵ�..." });
	Add(scr);

	//5
	scr.push_back({ "������ �ڹ���� ���� ������, �� �̷��� ������?" });
	Add(scr);

	//6
	scr.push_back({ "!!!!!" });
	scr.push_back({ "��, �� ��, �� ���̾�?" });
	scr.push_back({ "������, ����...!!! ����!!" });
	scr.push_back({ "���ݸ� �� �غ��� ���� �� ������...!", SCR_COLOR::GREY });
	scr.push_back({ "�� ���� ���� [�����̽� ��Ÿ]", SCR_COLOR::GREY });
	Add(scr);

	//7
	scr.push_back({ "���ư���... ����... ���ݸ� ��!!!" });
	Add(scr);

	//8
	scr.push_back({ "�� ���� ���� [�����̽� ��Ÿ]", SCR_COLOR::GREY });
	Add(scr);

	//9
	scr.push_back({ "������ �ڹ��踦 Ǯ����.", SCR_COLOR::GREY });
	scr.push_back({ "�ƴ�!!" });
	Add(scr);
#pragma endregion

#pragma region Story_6
	//1
	m_Index = (int)SCR_ID::STORY_6_1;
	scr.push_back({ "������ ������ �۱Ͱ� �ֱ�." });
	scr.push_back({ "\"���� ���� ���� ������ �������� �����ڵ��� �� �����." });
	scr.push_back({ "������ ���θ��� �庮�� ������ ������ ���� ���� ����������.\"" });
	scr.push_back({ "������ ������......" });
	Add(scr);

	//2
	scr.push_back({ "�� �絿�̸� �����." , SCR_COLOR::GREY });
	scr.push_back({ "�� �絿�̴� ���� ���� ���� �� ������." });
	Add(scr);

	//3
	scr.push_back({ "���� �� �絿�̸� �����.", SCR_COLOR::GREY });
	scr.push_back({ "������ ������� ���� �ƴұ�?" });
	scr.push_back({ "�ٵ� ������ �� ������ �ǳ����� ����? ���򵵡�" });
	Add(scr);

	//4
	scr.push_back({ "������ ���� �� �絿�̸� ����ߴ�." , SCR_COLOR::GREY });
	scr.push_back({ "�� ���� ���� �˰� �ֳ��� ��� ���ڰ�." });
	Add(scr);

	//5
	scr.push_back({ "�������� ��Ƴ����� ������ ���� �巯����.", SCR_COLOR::GREY });
	scr.push_back({ "����. �� �̰� ���� ���ΰ�" });
	Add(scr);
#pragma endregion

#pragma region Story_7
	//1
	m_Index = (int)SCR_ID::STORY_7_1;
	scr.push_back({ "������ ����, ������ ������ �� ����������" });
	scr.push_back({ "���� �Ǹ������� ���� ��ҷα�." });
	Add(scr);

	//2
	scr.push_back({ "�̷��� ������ Ȳǳ���� ������ ���°ǰ�?" });
	Add(scr);

	//3
	scr.push_back({ "���� ���� ���ϰ� �ְ��� �� �޸� �ִ�." });
	scr.push_back({ "<<�̹����� ���� ���� �ڴ� ���� �ʾҴ�. �� �������� ���͹��ȴ١�",SCR_COLOR::RED });
	scr.push_back({ "���� Ż���� ���� ������ ���� ��������,",SCR_COLOR::RED });
	scr.push_back({ "�Ű��� â�� ���� ����, �� ������ Į���� ������ Ǯ�� �����.>>",SCR_COLOR::RED });
	scr.push_back({ "������ Ǫ�� ������ Į��? �װŶ�顦" });
	Add(scr);

	//4
	scr.push_back({ "Į�� ���ܿ� �ȾҴ�.",SCR_COLOR::GREY });
	scr.push_back({ "<<������ ��������, ������ ȥ������ ���Ѵ�.",SCR_COLOR::RED });
	scr.push_back({ "�������� ��ȭ�� �� ���� ���� ��� ������ ���� ���� �� �ִ� ��, �����.>>" ,SCR_COLOR::RED });
	Add(scr);

	//5
	scr.push_back({ "���� ������ �� �Ҹ��� ����.",SCR_COLOR::GREY });	//�ڼ��� ��û
	scr.push_back({ "!!!" });
	scr.push_back({ "�� �����ڽ��̡� ������!" });
	Add(scr);

	//6
	scr.push_back({ "��, ���� �ۺ��̴�." });
	scr.push_back({ "��󱸰� ���ȴ�.", SCR_COLOR::GREY });
	Add(scr);
#pragma endregion

#pragma region Story_End
	m_Index = (int)SCR_ID::STORY_END_1;
	scr.push_back({ "��� ���� ���� ����, �� �ڷ� ������ �Һ��� ���� ���Դ�.", SCR_COLOR::GREY });
	scr.push_back({ "�׿� �Բ� ������ ����� �ݴ�� ��׷������ �ٱ��� ���Ҹ��� ���ϰ� ��ȴ�.", SCR_COLOR::GREY });
	scr.push_back({ "[ppppp-]", SCR_COLOR::GREY });
	scr.push_back({ "����... ��, �󹫴�!" });
	scr.push_back({ "�� �Ͼ�� Ȯ���Ϸ� ��ȭ�� �� �׷��� �涱�ŷ�?", SCR_COLOR::GREY });
	scr.push_back({ "�� ���� �ٻ� ���� �־����ϴ�. �ڼ��� �ǡ�" });
	scr.push_back({ "...", SCR_COLOR::GREY });
	scr.push_back({ "..." });
	scr.push_back({ "��Ȯ���ϰ� ó���߳�?", SCR_COLOR::GREY });
	scr.push_back({ "�޴����� ó���߽��ϴٸ��� ���� ���󺸴� �ʹ� ���� ���ļ� ���� �� �߽��ϴ�." });
	scr.push_back({ "�����۵��� �� �׷����� ������ ��¥ ���� ���� �׺в��� ���Ŵٸ顦", SCR_COLOR::GREY });
	scr.push_back({ "�׷��� �ȴٸ�� ���� �ϱ� �������鵵 ���� ���� �ʰڽ��ϱ�, ����." });
	scr.push_back({ "�ű� ���� �����鿡 �ñ�� ���� ������ �ü��� ������ ��. �׷�.", SCR_COLOR::GREY });
	scr.push_back({ "��! �˰ڽ���...!" });
	scr.push_back({ "[��-.]", SCR_COLOR::GREY });
	scr.push_back({ "��. �ٷ� ���������¡�" });
	scr.push_back({ "�׷�... �� ����?" });
	scr.push_back({ "�ű⿡.", SCR_COLOR::RED });
	Add(scr);

	scr.push_back({ "[��ȹ] ����� & ������" });
	scr.push_back({ "[��Ʈ] ������ & ������" });
	scr.push_back({ "[���α׷���] ��ȿ�� & �ֹΰ�" });
	scr.push_back({ "[Team - MILKTEA]" });
	scr.push_back({ "�÷��� ���ּż� �����մϴ�." });
	Add(scr);
#pragma endregion

#pragma region ��ȣ�ۿ�
	m_Index = (int)SCR_ID::INTER_BOOK;
	scr.push_back({ "��������� �ִ�.", SCR_COLOR::GREY });
	scr.push_back({ "�����������" });
	scr.push_back({ "XX��XX��X1��.�̻� ��." });
	scr.push_back({ "XX��XX��X2��.�̻� ��, ������ ���� ������ �̻��ϴ�." });
	scr.push_back({ "XX��XX��X3��.�̻� ��, ���� ���Ѻ��� ������ ���." });
	scr.push_back({ "XX��XX��X4��.�� ���� ������ ���θ� �ʹ�.������ ������ ���Ѻ��� ������ ���." });
	scr.push_back({ "XX��XX��X2��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��," });
	scr.push_back({ "�̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��," });
	scr.push_back({ "�̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��," });
	scr.push_back({ "�̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��," });
	scr.push_back({ "�̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��," });
	scr.push_back({ "�̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��, �̻� ��." });
	scr.push_back({ "XX�� XX�� X1��. ���ù��� �ڰ� ��Ÿ����, �׺в��� ���ƿ��ø���.", SCR_COLOR::RED });
	Add(scr);

	m_Index = (int)SCR_ID::INTER_BOARD;
	scr.push_back({ "...\"[��ũƼ ������]" });
	scr.push_back({ "1. �ҿ� �� �� 80-100ml�� �ְ� ���δ�." });
	scr.push_back({ "2. ���� ������ ȫ������ ���緮(4-6g) �ִ´�." });
	scr.push_back({ "3. 2-3�� �� ���� �췯������ ���� 80-200ml�� �ְ� ��ҷ� õõ�� �����." });
	scr.push_back({ "4. ȫ���� ���������� ������ ���� ���� ���� ���� ������ �ɷ��� �ϼ�." });
	scr.push_back({ "[By Team_MilkTea]\"..." });
	scr.push_back({ "...�̰� ����?" });
	Add(scr);
#pragma endregion

#pragma region Event
	//1
	m_Index = (int)SCR_ID::EVENT_MESSAGE_1;
	scr.push_back({ "�ϴ� ��󱸺��� ���� �� ������." });
	Add(scr);

	//2
	scr.push_back({ "������ �ʴ´�." });
	Add(scr);

	//3
	scr.push_back({ "����...! ���� �� ��...! ������ ���鼭 ���峵��...!?" });
	Add(scr);

	//4
	scr.push_back({ "���� ������ ���峵��." });
	scr.push_back({ "�ƹ����� �ٽ� �� ���� ���� �� ����..." });
	Add(scr);
#pragma endregion


#pragma region �⺻ �޼���
	//1
	m_Index = (int)SCR_ID::NORMAL_1;
	scr.push_back({ "���� �� ���Ѱ� �ʿ���." });
	Add(scr);

	//2
	scr.push_back({ "���� �� ���� �� ����." });
	Add(scr);

	//3
	scr.push_back({ "���⿡ ����� �� ����." });
	Add(scr);

	//4
	scr.push_back({ "���⼭ �� �� ���� ����." });
	Add(scr);

	//5
	scr.push_back({ "ȭ��� ���� �ѹ� �����ϱ�. �ۿ� ����� ������ ������" });
	Add(scr);

	//DebugMode
	scr.push_back({ "[Debug Cheat Mode]" });
	Add(scr);
#pragma endregion
#pragma endregion

#pragma region ����
	LPCSTR info[] =
	{
		"���� �����ϱ� [�����̽� ��]",
		"�� �Ŵ޸� ��ü �����ϱ� [�����̽� ��]",
		"���� �����ϱ� [�����̽� ��]",
		"���� ���� ��ü �����ϱ� [�����̽� ��]",
		"�Կ� ��� �����ϱ� [�����̽� ��]",
		"��ǻ�� �����ϱ� [�����̽� ��]",
		"��ȭ�� �����ϱ� [�����̽���]",
		"���� �����ϱ� [�����̽� ��]",
		"�� �絿�� �����ϱ� [�����̽� ��]",
		"ȭ��� �����ϱ� [�����̽� ��]",
		"���� �����ϱ� [�����̽� ��]",
		"ȯǳ�� �����ϱ� [�����̽� ��]",
		"�Խ��� �����ϱ� [�����̽� ��]",

		"����ġ ��ȣ�ۿ� [�����̽� ��]",
		"��� �� ��ȣ�ۿ� [�����̽� ��]",
		"��� ��� ��ȣ�ۿ� [�����̽� ��]",
		"��ǻ�� ��ȣ�ۿ� [�����̽� ��]",
		"ȭ��� ��ȣ�ۿ� [�����̽� ��]",
		"���� ��ȣ�ۿ� [�����̽� ��]",

		"������ �̵� [�����̽� ��]",
		"301ȣ�� �̵� [�����̽� ��]",
		"302ȣ�� �̵� [�����̽� ��]",
		"303ȣ�� �̵� [�����̽� ��]",
		"304ȣ�� �̵� [�����̽� ��]",
		"����� ������ �̵� [�����̽� ��]",
		"��� Ż�� [�����̽� ��]",
	};

	for (int i = 0; i < (int)INFO_ID::INFONUM; i++)
	{
		m_Info[i] = info[i];
	}
#pragma endregion
}

void ScriptManager::Add(std::vector<Script>& scr)
{
	if (m_Index >= (int)SCR_ID::IDNUM) return;

	m_Scripts[m_Index++] = scr;
	scr.clear();
}

void ScriptManager::AddScripts(std::vector<Script>& user, SCR_ID id)
{
	std::vector<Script> Scr = m_Scripts[(int)id];
	int size = Scr.size();
	for (int i = 0; i < size; i++)
	{
		user.push_back(Scr[size - 1 - i]);
	}
}

void ScriptManager::AddInfo(LPCSTR& user, INFO_ID id)
{
	user = m_Info[(int)id];
}