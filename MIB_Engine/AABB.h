#pragma once

//�࿡ ���� �Ǿ� �ִ� �浹 �簢��
class AABB
{
#pragma region ������ & �Ҹ���

public:
	AABB();
	~AABB();
#pragma endregion

#pragma region ����
private:
	RECT m_BoundingVolume;

	//�߽�
	POINT m_CenterPos;

	int m_Width;	// ��
	int m_Height;	// ����
#pragma endregion

#pragma region �Լ�
public:
	void SetAABB(int width, int height, POINT center);
	RECT GetAABB() { return m_BoundingVolume; };
#pragma endregion

};

