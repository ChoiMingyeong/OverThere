///
/// MIB_Engine : WinAPI 엔진
/// 제작자 : 최민경 & 임효빈
/// 제작일시 : 2020 - 11 - 15
/// 

#include "pch.h"
#include "framework.h"
#include "MIBEngine.h"

#pragma comment(lib, "msimg32.lib")
#pragma region 생성자 & 소멸자
MIBEngine::MIBEngine()
{
	m_hMainDC = nullptr;
	m_BackBuffer = nullptr;
	m_ElaspedTime = 0;
	m_StartTimestemp = LARGE_INTEGER();
	m_EndTimestemp = LARGE_INTEGER();
	m_FPS = 0;
	m_Frequency = 0;
	m_ScreenHeight = 0;
	m_ScreenWidth = 0;
	m_TargetElaspedTime = 0.0f;
}

MIBEngine::~MIBEngine()
{

}
#pragma endregion

#pragma region 메인 이벤트 함수
void MIBEngine::Initialize(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight)
{
	m_hMainDC = GetDC(hWnd);
	m_ScreenWidth = screenWidth + 1;
	m_ScreenHeight = screenHeight + 1;

	m_BackBuffer = CreateCompatibleDC(m_hMainDC);
	SelectObject(m_BackBuffer, CreateCompatibleBitmap(m_hMainDC, m_ScreenWidth, m_ScreenHeight));

	//윈도우 크기 얻기.
	RECT wrc;
	GetWindowRect(hWnd, &wrc);
	int width = wrc.right - wrc.left;
	int height = wrc.bottom - wrc.top;

	//내부 클라이언트 크기 얻기.
	RECT crc;
	GetClientRect(hWnd, &crc);

	//두 크기의 차이(윈도우 '틀', 메뉴, 타이틀 의 사이즈...)를 구합니다.
	int xgap = width - crc.right + 1;
	int ygap = height - crc.bottom + 1;

	//보정된 윈도우 사이즈...
	width += xgap;
	height += ygap;

	//새로이 크기를 조정합니다.
	MoveWindow(hWnd, wrc.left, wrc.top, width, height, TRUE);

	// dTime 초기화
	Time_Initialize();
}

void MIBEngine::Update()
{
	ColliedCheck();
}

void MIBEngine::BeginRender()
{
	//백버퍼 초기화 화면을 검은색으로 그리기 위한 설정
	HBRUSH _newBrush, _oldBrush;
	_newBrush = CreateSolidBrush(RGB(0,0,0));
	_oldBrush = (HBRUSH)SelectObject(m_BackBuffer, _newBrush);

	//백버퍼를 초기화한다.
	Rectangle(m_BackBuffer, 0, 0, m_ScreenWidth, m_ScreenHeight);

	//브러쉬를 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldBrush);
	DeleteObject(_newBrush);
}

void MIBEngine::EndRender()
{
	//백버퍼의 내용을 메인 DC에 출력한다.
	BitBlt(m_hMainDC, 0, 0, m_ScreenWidth, m_ScreenHeight, m_BackBuffer, 0, 0, SRCCOPY);
}

void MIBEngine::LoadSprite(MIBSprite* sprite, const wchar_t* filePath)
{
	//포인터 null 체크
	if (sprite == nullptr)	
	{
		return;
	}

	// 메인 dc와 호환되는 메모리 dc를 생성함
	sprite->m_MemDC = CreateCompatibleDC(m_hMainDC);

	// 특정 함수를 사용해서 비트맵을 로드함(비트맵 핸들을 가져옴)
	sprite->m_hBitmap = (HBITMAP)LoadImage(NULL, filePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	// sprite에 값 세팅
	sprite->SetSpriteInfo();
}

void MIBEngine::DrawSprite(MIBSprite* sprite, POINT pos, bool iscenter)
{
	POINT pt = pos;
	if (iscenter)
		pt = sprite->GetCenterFromPos(pt);

	//BitBlt(m_BackBuffer, pt.x, pt.y, sprite->m_Width, sprite->m_Height, sprite->m_MemDC, 0, 0, SRCCOPY);
	TransparentBlt(m_BackBuffer, pt.x, pt.y, sprite->m_Width, sprite->m_Height,
		sprite->m_MemDC, sprite->m_Width * sprite->AniFrm, sprite->m_Width * sprite->AniState, sprite->m_Width, sprite->m_Height, sprite->KeyColor);
}
#pragma endregion

#pragma region GDI
void MIBEngine::DrawLine(POINT p1, POINT p2)
{
	MoveToEx(m_BackBuffer, p1.x, p1.y, NULL);
	LineTo(m_BackBuffer, p2.x, p2.y);
}

void MIBEngine::DrawRectangle(POINT p1, POINT p2)
{
	Rectangle(m_BackBuffer, p1.x, p1.y, p2.x, p2.y);
}

void MIBEngine::DrawRectangle(POINT center, int width, int height)
{
	Rectangle(m_BackBuffer, center.x - (width /2), center.y - (height /2),
		center.x + (width /2), center.y + (height /2));
}

void MIBEngine::DrawRectangle(POINT center, int width, int height, COLORREF pencolor, COLORREF brushcolor)
{
	//사각형 내부 색을 위한 Brush 설정
	HBRUSH _newBrush, _oldBrush;
	_newBrush = CreateSolidBrush(brushcolor);
	_oldBrush = (HBRUSH)SelectObject(m_BackBuffer, _newBrush);

	//사각형 선 색을 위한 Pen 설정
	HPEN _newPen, _oldPen;
	_newPen = CreatePen(PS_SOLID, 1, pencolor);
	_oldPen = (HPEN)SelectObject(m_BackBuffer, _newPen);

	Rectangle(m_BackBuffer, center.x - (width /2), center.y - (height /2),
		center.x + (width /2), center.y + (height /2));

	//브러쉬를 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldBrush);
	DeleteObject(_newBrush);

	//펜을 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldPen);
	DeleteObject(_newPen);
}

void MIBEngine::DrawEllipse(POINT p1, POINT p2)
{
	Ellipse(m_BackBuffer, p1.x, p1.y, p2.x, p2.y);
}

void MIBEngine::DrawCircle(POINT center, int radius)
{
	Ellipse(m_BackBuffer, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}

void MIBEngine::DrawDebugRectangle(POINT p1, POINT p2, COLORREF color)
{
	//빈 사각형을 그리기 위한 Brush 설정
	HBRUSH _newBrush, _oldBrush;
	_newBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	_oldBrush = (HBRUSH)SelectObject(m_BackBuffer, _newBrush);

	//사각형 선 색을 위한 Pen 설정
	HPEN _newPen, _oldPen;
	_newPen = CreatePen(PS_SOLID, 1, color);
	_oldPen = (HPEN)SelectObject(m_BackBuffer, _newPen);

	//사각형 그리기
	DrawRectangle(p1, p2);

	//브러쉬를 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldBrush);
	DeleteObject(_newBrush);

	//펜을 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldPen);
	DeleteObject(_newPen);
}

void MIBEngine::DrawDebugRectangle(POINT center, int width, int height, COLORREF color)
{
	//빈 사각형을 그리기 위한 Brush 설정
	HBRUSH _newBrush, _oldBrush;
	_newBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	_oldBrush = (HBRUSH)SelectObject(m_BackBuffer, _newBrush);

	//사각형 선 색을 위한 Pen 설정
	HPEN _newPen, _oldPen;
	_newPen = CreatePen(PS_SOLID, 1, color);
	_oldPen = (HPEN)SelectObject(m_BackBuffer, _newPen);

	//사각형 그리기
	DrawRectangle(center, width, height);

	//브러쉬를 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldBrush);
	DeleteObject(_newBrush);

	//펜을 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldPen);
	DeleteObject(_newPen);
}

void MIBEngine::DrawDebugCircle(POINT center, int radius, COLORREF color)
{
	//빈 사각형을 그리기 위한 Brush 설정
	HBRUSH _newBrush, _oldBrush;
	_newBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	_oldBrush = (HBRUSH)SelectObject(m_BackBuffer, _newBrush);

	//사각형 선 색을 위한 Pen 설정
	HPEN _newPen, _oldPen;
	_newPen = CreatePen(PS_SOLID, 1, color);
	_oldPen = (HPEN)SelectObject(m_BackBuffer, _newPen);

	//사각형 그리기
	DrawCircle(center, radius);

	//브러쉬를 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldBrush);
	DeleteObject(_newBrush);

	//펜을 원래대로 돌리고 해제
	SelectObject(m_BackBuffer, _oldPen);
	DeleteObject(_newPen);
}

bool MIBEngine::DrawTextFormat(POINT pos, COLORREF color, int size, LPCSTR pch, ...)
{
	HFONT font = CreateFont(size, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	HFONT oldfont = (HFONT)SelectObject(m_BackBuffer, font);

	char* buffer;
	int len;

	va_list ap;			// 현재 읽고 있는 번지를 기억
	va_start(ap, pch);	// ap 포인터 변수가 첫번째 가변인수를 가리키도록 초기화

	len = _vscprintf(pch, ap) + 1;
	buffer = new char[len];

	vsprintf_s(buffer, len, pch, ap);
	va_end(ap);

	SetBkMode(m_BackBuffer, TRANSPARENT);
	SetTextColor(m_BackBuffer, color);
	SetTextAlign(m_BackBuffer, TA_CENTER);
	TextOutA(m_BackBuffer, pos.x, pos.y - 10, buffer, (int)strlen(buffer));

	delete[] buffer;

	SelectObject(m_BackBuffer, oldfont);
	DeleteObject(font);

	return true;
}

bool MIBEngine::DrawTextFormat(POINT pos, COLORREF color, LPCSTR pch, ...)
{
	char* buffer;
	int len;

	va_list ap;			// 현재 읽고 있는 번지를 기억
	va_start(ap, pch);	// ap 포인터 변수가 첫번째 가변인수를 가리키도록 초기화

	len = _vscprintf(pch, ap) + 1;
	buffer = new char[len];

	vsprintf_s(buffer, len, pch, ap);
	va_end(ap);

	SetBkMode(m_BackBuffer, TRANSPARENT);
	SetTextColor(m_BackBuffer, color);
	SetTextAlign(m_BackBuffer, TA_CENTER);
	TextOutA(m_BackBuffer, pos.x, pos.y - 10, buffer, (int)strlen(buffer));

	delete[] buffer;

	return true;
}
#pragma endregion


void MIBEngine::ColliedCheck()
{
	int size = m_objs.size();
	for (int i = 0; i < size; i++)
	{
		m_objs[i]->m_hitobjs.clear();

		for (int j = 0; j < size; j++)
		{
			if (m_objs[i] != m_objs[j]
				&& m_objs[i]->IsCollied(m_objs[j]))
			{
				m_objs[i]->m_hitobjs.push_back(m_objs[j]);
			}
		}
	}
}

#pragma region dTime

void MIBEngine::Time_Initialize()
{
	LARGE_INTEGER _Frequency;

	QueryPerformanceFrequency(&_Frequency);

	m_Frequency = _Frequency.QuadPart;

	m_FPS = 60.0f;
	m_TargetElaspedTime = 1.0f / m_FPS;
}

void MIBEngine::StartTimestamp()
{
	QueryPerformanceCounter(&m_StartTimestemp);
}

void MIBEngine::EndTimestamp()
{
	QueryPerformanceCounter(&m_EndTimestemp);
}

void MIBEngine::CheckTime()
{
	m_ElaspedTime = m_EndTimestemp.QuadPart - m_StartTimestemp.QuadPart;
}

float MIBEngine::GetElaspedTimeSec() const
{
	return ((float)m_ElaspedTime / (float)m_Frequency) * 1000.0f;
}

bool MIBEngine::FPSCheck()
{
	EndTimestamp();
	CheckTime();

	if ((m_TargetElaspedTime)*1000.0f < GetElaspedTimeSec())
	{
		StartTimestamp();

		return true;
	}
	return false;
}

#pragma endregion

