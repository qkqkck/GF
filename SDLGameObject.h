#pragma once
#include "SDL.h"
#include "LoaderParams.h"
#include "GameObject.h"
#include "Vector2D.h"

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
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	int m_Renderer;
	std::string m_textureID;
};