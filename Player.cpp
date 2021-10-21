#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  /*if(m_x >= 640-128)
  m_childSpeed= -1;
  else if(m_x + m_childSpeed <= 0)
  m_childSpeed = 1;
  m_x += m_childSpeed;
  */
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);
}

void Player::clean(){}