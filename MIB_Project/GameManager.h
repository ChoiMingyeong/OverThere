#pragma once

#include <Windows.h>

#pragma region 값 Define
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

#pragma region 키 입력
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

#pragma region 전방선언
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
	MIBEngine* pEngine;	//게임 엔진

	GameData* pGD;			//스프라이트 & 오브젝트 데이터
	ScriptManager* pSM;		//스크립트 데이터

	AudioManager* pAM;

	Player* pPlayer;		//Player
	POINT PlayerSavePos;	//Player 위치값 저장

	Monster* pMonster;		//Monster

	SCENE NowScene;		//현재 씬
	ROOM NowRoom;		//현재 방

	LPCSTR InfoText = "";			//오브젝트 설명
	std::vector<Script> Scripts;	//저장할 스크립트
	Script NowScript = { "" };		//스크립트

	ObjInfo NowInfo;	//현재 충돌한 오브젝트 정보

	bool DebugMode;		//디버그 정보 표시

	int title_cursor;	//타이틀 커서

	int cur_key;		//방금 누른 키 상태
	int pre_key;		//이전 누른 키 상태

	int GameState;		//게임 아이템 획득 & 사용 상태
	long StoryState;	//스토리 진행 상태
	float waitTime;		//게임 대기 시간
	bool waitScript;

public:
	void Init(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight);	//초기화
	void ResetData();		//데이터 리셋하는 함수

	void KeyInput();		//키 입력 함수
	bool GetKey(int key);	//키 입력 여부 체크

	bool IsGame(int state);		//게임 상태 확인
	bool IsStory(long state);	//스토리 상태 확인
	bool IsItem(UI item);		//아이템 체크
	void SetGame(int state);	//게임 상태 완료
	void SetStory(long state);	//스토리 상태 완료
	bool IsAniFrm(OBJ target, OBJ id);
	void AniPlay(OBJ id);

	void SoundPlay(AUDIO id, float v = 1.0f);
	void SoundPause(AUDIO id);
	void BGMPlay(AUDIO id, float v = 1.0f);
	void BGMStop(AUDIO id);

	void ScriptOut();	//스크립트 출력
	void AddScripts(SCR_ID id);	//출력할 스크립트 추가하기
	void AddInfo(INFO_ID id);	//출력할 정보 추가하기
	void ResetInfo();
	bool IsWait();		//남은 스크립트 있을 때 true
	void ResetScript();
	void ClearScripts() { Scripts.clear(); }

	void Update();		//인게임 업데이트(키 체크, waitTime 체크 등등...)
	void SystemCheck();
	bool FPSCheck() { return pEngine->FPSCheck(); }
	bool IsWaitScript() { return waitScript; }
	bool IsWaitTime() { return waitTime > 0.0f; }
	void SetAniFrm(OBJ id, int frm);	//오브젝트 애니 프레임 스테이트 변경
	void SetAniFrm(UI id, int frm);		//UI 애니 프레임 스테이트 변경
	void RoomSet();		//방 세팅시 변경될 것들에 대한 함수

	void AddObj(OBJ id);
	void SetObj(OBJ id, POINT pos);
	void OnSavePos();
	void ChangeSavePos(int x);
	void PushUnits();

	void ChangeEquip();	//장비 변경
	void UseItem();		//장착 아이템 사용
	void GetItem(UI id);		//아이템 획득
	void PlayerMove();	//이동
	void MonsterMove();	//몬스터 이동
	void HitObj();		//오브젝트 충돌시 이벤트
	void MoveDoor();	//문 이동
	void Interaction();	//상호작용
	void Scroll();		//화면 스크롤
	bool IsDead();		//플레이어 죽었냐?

	void DrawBegin();
	void DrawBG(BG bg, POINT pos = { 0,0 }, bool center = false);		//배경 그리기(지정)
	void DrawBG(int pos = 200);		//배경 그리기
	void DrawObj();		//오브젝트 그리기
	void DrawUnit();	//유닛 그리기(플레이어 & 몬스터)
	void DrawUI();		//UI 그리기
	void DrawEnd();

	void Release();		//메모리 릴리즈

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