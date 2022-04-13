#pragma once

//축에 정렬 되어 있는 충돌 사각형
class AABB
{
#pragma region 생성자 & 소멸자

public:
	AABB();
	~AABB();
#pragma endregion

#pragma region 변수
private:
	RECT m_BoundingVolume;

	//중심
	POINT m_CenterPos;

	int m_Width;	// 폭
	int m_Height;	// 높이
#pragma endregion

#pragma region 함수
public:
	void SetAABB(int width, int height, POINT center);
	RECT GetAABB() { return m_BoundingVolume; };
#pragma endregion

};

