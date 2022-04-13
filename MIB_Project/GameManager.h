#pragma once

#include <Windows.h>

#pragma region �� Define
#define MONSTER_Y 285
#define PLAYER_Y 325

#define INFRONTDOOR_X 1140
#define INFRONTSECRETDOOR_X 1000
#define MAINDOOR_POS { 1209, 243 }
#define DOOR301_POS { 150, 243 }
#define DOOR302_POS { 650, 243 }
#define DOOR303_POS { 1350, 243 }
#define DOOR304_POS { 2150, 243 }
#define SECRETDOOR_POS { 1013, 326 }

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define INFO_POS {WINDOW_WIDTH/2, 180}
#define SCRIPTS_POS {WINDOW_WIDTH/2, 540}
#pragma endregion

#pragma region Ű �Է�
#define KEY_UP		0x0001
#define KEY_DOWN	0x0002
#define KEY_ENTER	0x0004
#define KEY_SPACE	0x0008
#define KEY_TAB		0x0010
#define KEY_ESC		0x0020
#define KEY_F8		0x0040
#define KEY_F7		0x0080
#define KEY_F1		0x0100
#pragma endregion

#pragma region ���漱��
class MIBEngine;
class GameData;
class ScriptManager;
class AudioManager;
#pragma endregion

class GameManager
{
public:
	GameManager();
	~GameManager();

private:
	MIBEngine* pEngine;	//���� ����

	GameData* pGD;			//��������Ʈ & ������Ʈ ������
	ScriptManager* pSM;		//��ũ��Ʈ ������

	AudioManager* pAM;

	Player* pPlayer;		//Player
	POINT PlayerSavePos;	//Player ��ġ�� ����

	Monster* pMonster;		//Monster

	SCENE NowScene;		//���� ��
	ROOM NowRoom;		//���� ��

	LPCSTR InfoText = "";			//������Ʈ ����
	std::vector<Script> Scripts;	//������ ��ũ��Ʈ
	Script NowScript = { "" };		//��ũ��Ʈ

	ObjInfo NowInfo;	//���� �浹�� ������Ʈ ����

	bool DebugMode;		//����� ���� ǥ��

	int title_cursor;	//Ÿ��Ʋ Ŀ��

	int cur_key;		//��� ���� Ű ����
	int pre_key;		//���� ���� Ű ����

	int GameState;		//���� ������ ȹ�� & ��� ����
	long StoryState;	//���丮 ���� ����
	float waitTime;		//���� ��� �ð�
	bool waitScript;

public:
	void Init(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight);	//�ʱ�ȭ
	void ResetData();		//������ �����ϴ� �Լ�

	void KeyInput();		//Ű �Է� �Լ�
	bool GetKey(int key);	//Ű �Է� ���� üũ

	bool IsGame(int state);		//���� ���� Ȯ��
	bool IsStory(long state);	//���丮 ���� Ȯ��
	bool IsItem(UI item);		//������ üũ
	void SetGame(int state);	//���� ���� �Ϸ�
	void SetStory(long state);	//���丮 ���� �Ϸ�
	bool IsAniFrm(OBJ target, OBJ id);
	void AniPlay(OBJ id);

	void SoundPlay(AUDIO id, float v = 1.0f);
	void SoundPause(AUDIO id);
	void BGMPlay(AUDIO id, float v = 1.0f);
	void BGMStop(AUDIO id);

	void ScriptOut();	//��ũ��Ʈ ���
	void AddScripts(SCR_ID id);	//����� ��ũ��Ʈ �߰��ϱ�
	void AddInfo(INFO_ID id);	//����� ���� �߰��ϱ�
	void ResetInfo();
	bool IsWait();		//���� ��ũ��Ʈ ���� �� true
	void ResetScript();
	void ClearScripts() { Scripts.clear(); }

	void Update();		//�ΰ��� ������Ʈ(Ű üũ, waitTime üũ ���...)
	void SystemCheck();
	bool FPSCheck() { return pEngine->FPSCheck(); }
	bool IsWaitScript() { return waitScript; }
	bool IsWaitTime() { return waitTime > 0.0f; }
	void SetAniFrm(OBJ id, int frm);	//������Ʈ �ִ� ������ ������Ʈ ����
	void SetAniFrm(UI id, int frm);		//UI �ִ� ������ ������Ʈ ����
	void RoomSet();		//�� ���ý� ����� �͵鿡 ���� �Լ�

	void AddObj(OBJ id);
	void SetObj(OBJ id, POINT pos);
	void OnSavePos();
	void ChangeSavePos(int x);
	void PushUnits();

	void ChangeEquip();	//��� ����
	void UseItem();		//���� ������ ���
	void GetItem(UI id);		//������ ȹ��
	void PlayerMove();	//�̵�
	void MonsterMove();	//���� �̵�
	void HitObj();		//������Ʈ �浹�� �̺�Ʈ
	void MoveDoor();	//�� �̵�
	void Interaction();	//��ȣ�ۿ�
	void Scroll();		//ȭ�� ��ũ��
	bool IsDead();		//�÷��̾� �׾���?

	void DrawBegin();
	void DrawBG(BG bg, POINT pos = { 0,0 }, bool center = false);		//��� �׸���(����)
	void DrawBG(int pos = 200);		//��� �׸���
	void DrawObj();		//������Ʈ �׸���
	void DrawUnit();	//���� �׸���(�÷��̾� & ����)
	void DrawUI();		//UI �׸���
	void DrawEnd();

	void Release();		//�޸� ������

	//Getter
	int GetCursor() { return title_cursor; }
	int GetScene() { return (int)NowScene; }
	int GetRoom() { return (int)NowRoom; }
	ObjInfo GetInfo() { return NowInfo; }
	int GetScriptsSize() { return Scripts.size(); }
	int GetScrollX() { return pEngine->m_Scroll; }
	bool GetWaitScript() { return waitScript; }
	bool GetMonsterActive() { return pMonster->m_Active; }
	int GetPlayerX() { return pPlayer->m_pos.x; }
	float GetMonsterWaitTime() { return pMonster->m_WaitTime; }
	float GetdTime() { return pEngine->GetElaspedTimeSec() * 0.001f; }

	//Setter
	void SetCursor(int val) { title_cursor = val; }
	void SetScene(SCENE s) { NowScene = s; }
	void SetRoom(ROOM r) { NowRoom = r; }
	void SetWaitTime(float time) { waitTime = time; }
	void SetSavePos(POINT pt) { PlayerSavePos = pt; }
	void SetPlayerPos(int x) { pPlayer->SetPos({ x, PLAYER_Y }); }
	void SetScrollX(int x) { pEngine->m_Scroll = x; }
	void SetInfo(OBJ id, ObjInfo info) { pGD->pGameObject[(int)id]->SetObj(info); }
	void SetMonsterActive(bool b) { pMonster->m_Active = b; }
	void SetMonsterPos(int x) { pMonster->SetPos({ x, MONSTER_Y }); }
	void SetMonsterSpeed(float speed) { pMonster->m_Speed = speed; }
	void SetMonsterWait(bool b) { pMonster->m_IsWait = b; }
	void SetMonsterWaitTime(float time) { pMonster->m_WaitTime = time; }
	void SetObjActive(OBJ id, bool b) { pGD->pGameObject[(int)id]->m_Active = b; }
	void SetMonsterState(MONSTER state) { pMonster->m_State = (int)state; }
};