#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
  handleInput();
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	//m_acceleration.setX(1);
	SDLGameObject::update();
}

void Enemy::handleInput()
{
  if (TheInputHandler::Instance()->getMouseButtonState(0))
  {
    printf("shoot\n");
  }
  Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
  m_velocity = (*vec - m_position) / 100;
  
  if (m_velocity.getX() < -0.05)
  {
    flip = SDL_FLIP_HORIZONTAL;
  }
  else if (m_velocity.getX() > 0.05)
  {
    flip = SDL_FLIP_NONE;
  }
}