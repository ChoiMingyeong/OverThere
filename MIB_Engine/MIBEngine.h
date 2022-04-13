#pragma once
#include <vector>

class MIBSprite;
class MIBObject;

class MIBEngine
{
#pragma region ������  & �Ҹ���
public:
	//������
	MIBEngine();
	//�Ҹ���
	~MIBEngine();
#pragma endregion

#pragma region ���� �̺�Ʈ�Լ�
public:
	//�ʱ�ȭ �Լ�. ���� ���۽� �� ���� ����
	void Initialize(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight);

	//������Ʈ �Լ�. ���� ���� �Լ�(�浹 ��)�� �����Ѵ�.
	void Update();

	//Render�� �����ϴ� �Լ�. ����۸� �ʱ�ȭ���ش�.
	void BeginRender();
	//����DC�� ����۸� �׷��ִ� �Լ�.
	void EndRender();

	//���� ��ο��� sprite�� �ε��ϴ� �Լ�.
	void LoadSprite(MIBSprite* sprite, const wchar_t* filePath);
	//���ϴ� ��ġ�� ����ۿ� sprite�� �׸��� �Լ�.
	void DrawSprite(MIBSprite* sprite, POINT pos, bool iscenter);
#pragma endregion

#pragma region GDI
	//GDI ����
public:
	int m_Scroll = 0;		//��ũ���� �ϱ� ���� �������

	bool m_DrawCollider = false;		//�ݶ��̴� �׸��� üũ(����׿�)

private:
	HDC m_hMainDC;		// ȭ�鿡 �׸��� ���� ����̽� ���ؽ�Ʈ �ڵ�
	HDC m_BackBuffer;	// ���� ���۸��� ����ϱ� ���� SubDC

	int m_ScreenWidth;	//��ũ�� �ʺ�
	int m_ScreenHeight;	//��ũ�� ����

public:
	// p1���� p2���� ������ �׷��ִ� �Լ�.
	void DrawLine(POINT p1, POINT p2);
	// p1(Left, Top)�������� p2(Right, Bottom)���� �簢���� �׷��ִ� �Լ�.
	void DrawRectangle(POINT p1, POINT p2);
	// center ��ǥ�� �߽����� �ʺ�(width)�� ����(height)�� ���� �簢���� �׷��ִ� �Լ�.
	void DrawRectangle(POINT center, int width, int height);
	// center ��ǥ�� �߽����� �ʺ�(width)�� ����(height)�� ���� �簢���� �׷��ִ� �Լ�.(�� ����)
	void DrawRectangle(POINT center, int width, int height, COLORREF pencolor, COLORREF brushcolor);
	// p1(Left, Top)�������� p2(Right, Bottom)���� Ÿ���� �׷��ִ� �Լ�.
	void DrawEllipse(POINT p1, POINT p2);
	// center ��ǥ�� �߽����� ������(radius)�� ���� ���� �׷��ִ� �Լ�.
	void DrawCircle(POINT center, int radius);

	// ������ �簢���� �׷��ִ� �Լ�. p1(Left, Top)�������� p2(Right, Bottom)���� �簢���� �׷��ش�.
	void DrawDebugRectangle(POINT p1, POINT p2, COLORREF color);
	// ������ �簢���� �׷��ִ� �Լ�. center ��ǥ�� �߽����� �ʺ�� ���̸� ���� �簢���� �׷��ش�.
	void DrawDebugRectangle(POINT center, int width, int height, COLORREF color);
	// ������ ������ �׷��ִ� �Լ�. center ��ǥ�� �߽����� ������(radius)�� ���� ���� �׷��ش�.
	void DrawDebugCircle(POINT center, int radius, COLORREF color);

	// ���ڿ��� pos�� ��ġ�� ����ϴ� �Լ�.
	bool DrawTextFormat(POINT pos, COLORREF color, int size, LPCSTR pch, ...);
	bool DrawTextFormat(POINT pos, COLORREF color, LPCSTR pch, ...);
#pragma endregion

#pragma region �浹ó��
public:
	std::vector<MIBObject*> m_objs;	//�浹 ó���� �˻��� ��� ������Ʈ

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
	// dTime �ʱ�ȭ
	void Time_Initialize();
	// dTime ���� �ð��� �ڴ´�.
	void StartTimestamp();
	// dTime�� �ٽ� �������� ���ƿ��� ���� �ð�
	void EndTimestamp();
	// dTime�� �����Լ����� ���Լ����� �ɸ� �ð�
	void CheckTime();
	// �ɸ��ð� / �ѹ� ���� Ƚ��
	float GetElaspedTimeSec() const;
	// �ɸ� �ð��� �ʰ��Ǹ� ������ �ѱ��
	bool FPSCheck();
#pragma endregion
};