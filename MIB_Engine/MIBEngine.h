#pragma once
#include <vector>

class MIBSprite;
class MIBObject;

class MIBEngine
{
#pragma region 생성자  & 소멸자
public:
	//생성자
	MIBEngine();
	//소멸자
	~MIBEngine();
#pragma endregion

#pragma region 메인 이벤트함수
public:
	//초기화 함수. 게임 시작시 한 번만 실행
	void Initialize(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight);

	//업데이트 함수. 물리 관련 함수(충돌 등)를 실행한다.
	void Update();

	//Render를 시작하는 함수. 백버퍼를 초기화해준다.
	void BeginRender();
	//메인DC에 백버퍼를 그려주는 함수.
	void EndRender();

	//파일 경로에서 sprite를 로드하는 함수.
	void LoadSprite(MIBSprite* sprite, const wchar_t* filePath);
	//원하는 위치의 백버퍼에 sprite를 그리는 함수.
	void DrawSprite(MIBSprite* sprite, POINT pos, bool iscenter);
#pragma endregion

#pragma region GDI
	//GDI 변수
public:
	int m_Scroll = 0;		//스크롤을 하기 위한 멤버변수

	bool m_DrawCollider = false;		//콜라이더 그리기 체크(디버그용)

private:
	HDC m_hMainDC;		// 화면에 그리기 위한 디바이스 컨텍스트 핸들
	HDC m_BackBuffer;	// 더블 버퍼링을 사용하기 위한 SubDC

	int m_ScreenWidth;	//스크린 너비
	int m_ScreenHeight;	//스크린 높이

public:
	// p1부터 p2까지 라인을 그려주는 함수.
	void DrawLine(POINT p1, POINT p2);
	// p1(Left, Top)에서부터 p2(Right, Bottom)까지 사각형을 그려주는 함수.
	void DrawRectangle(POINT p1, POINT p2);
	// center 좌표를 중심으로 너비(width)와 높이(height)를 정한 사각형을 그려주는 함수.
	void DrawRectangle(POINT center, int width, int height);
	// center 좌표를 중심으로 너비(width)와 높이(height)를 정한 사각형을 그려주는 함수.(색 포함)
	void DrawRectangle(POINT center, int width, int height, COLORREF pencolor, COLORREF brushcolor);
	// p1(Left, Top)에서부터 p2(Right, Bottom)까지 타원을 그려주는 함수.
	void DrawEllipse(POINT p1, POINT p2);
	// center 좌표를 중심으로 반지름(radius)을 정한 원을 그려주는 함수.
	void DrawCircle(POINT center, int radius);

	// 디버깅용 사각형을 그려주는 함수. p1(Left, Top)에서부터 p2(Right, Bottom)까지 사각형을 그려준다.
	void DrawDebugRectangle(POINT p1, POINT p2, COLORREF color);
	// 디버깅용 사각형을 그려주는 함수. center 좌표를 중심으로 너비와 높이를 정한 사각형을 그려준다.
	void DrawDebugRectangle(POINT center, int width, int height, COLORREF color);
	// 디버깅용 원형을 그려주는 함수. center 좌표를 중심으로 반지름(radius)을 정한 원을 그려준다.
	void DrawDebugCircle(POINT center, int radius, COLORREF color);

	// 문자열을 pos의 위치에 출력하는 함수.
	bool DrawTextFormat(POINT pos, COLORREF color, int size, LPCSTR pch, ...);
	bool DrawTextFormat(POINT pos, COLORREF color, LPCSTR pch, ...);
#pragma endregion

#pragma region 충돌처리
public:
	std::vector<MIBObject*> m_objs;	//충돌 처리를 검사할 모든 오브젝트

public:
	void ColliedCheck();
#pragma endregion

#pragma region dTime
public:
	__int64 m_Frequency;
	__int64 m_ElaspedTime;

	LARGE_INTEGER m_StartTimestemp;
	LARGE_INTEGER m_EndTimestemp;

	float m_FPS;
	float m_TargetElaspedTime;

public:
	// dTime 초기화
	void Time_Initialize();
	// dTime 시작 시간을 박는다.
	void StartTimestamp();
	// dTime이 다시 원점으로 돌아왔을 때의 시간
	void EndTimestamp();
	// dTime이 시작함수부터 끝함수까지 걸린 시간
	void CheckTime();
	// 걸린시간 / 한번 도는 횟수
	float GetElaspedTimeSec() const;
	// 걸린 시간이 초과되면 프레임 넘기기
	bool FPSCheck();
#pragma endregion
};