#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureID)
{
  GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
  GameObject::draw(pRenderer);
}

void Player::update()
{
  //m_x -= 1;
    if(m_x >= 640-128)
  m_childSpeed= -1;
  else if(m_x + m_childSpeed <= 0)
  m_childSpeed = 1;
  m_x += m_childSpeed;
}