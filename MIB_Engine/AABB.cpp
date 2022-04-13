#include "pch.h"
#include "AABB.h"

AABB::AABB()
{

}

AABB::~AABB()
{

}

void AABB::SetAABB(int width, int height, POINT center)
{
	m_Width = width;
	m_Height = height;
	m_CenterPos = center;

	m_BoundingVolume.left = 0;
	m_BoundingVolume.bottom = m_Height;
	m_BoundingVolume.right = m_Width;
	m_BoundingVolume.top = 0;
}
