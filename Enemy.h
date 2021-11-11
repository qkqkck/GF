#pragma once
#include "SDL.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
  void handleInput();
	virtual void clean() {};
};