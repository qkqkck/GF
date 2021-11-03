#pragma once
#include "SDL.h"
#include "LoaderParams.h"
#include "GameObject.h"
#include "Vector2D.h"

//SDLGameObject를 상속받는 모든 객체들의 흐름 제어하는 상위 클래스
//따라서 상속받는 모든 자식들은 SDLGameObject의 함수들을 다 써야함

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {}
	virtual ~SDLGameObject() {}

protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};