#include "Game.h"
#include "TextureManager.h"

SDL_Window* m_pWindow = 0;
SDL_Renderer* m_pRenderer = 0;
bool m_bRunning = false;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if (m_pRenderer != 0)
            {
                if (!TheTextureManager::Instance()->load("Assets/background2.png", "background", m_pRenderer))
                {
                    return false; //배경
                }

                if (!TheTextureManager::Instance()->load("Assets/Cat140.png", "Cat", m_pRenderer))
                {
                    return false; //고양이
                }

                if (!TheTextureManager::Instance()->load("Assets/Bird.png", "Bird", m_pRenderer))
                {
                    return false; //새
                }

                if (!TheTextureManager::Instance()->load("Assets/Tile3.png", "Tile", m_pRenderer))
                {
                    return false; //맵 타일
                }

                if (!TheTextureManager::Instance()->load("Assets/Space3.png", "Space", m_pRenderer))
                {
                    return false; //맵 공간
                }
                if (!TheTextureManager::Instance()->load("Assets/Apple.png", "Apple", m_pRenderer))
                {
                  return false; //사과
                }

            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    m_bRunning = true;
    return true;
}


void Game::objectMove()
{
    //고양이 점프
    m_currentFrame = (SDL_GetTicks() / 200);
    
    //고양이 앞으로 이동
    
    if (CatX <= 0)
        CatSpeed = 0.3;

    //고양이 화면 끝에서 반대로 이동
    else if (CatX + CatSpeed >= 640 - CatSize)

        CatSpeed = -0.3;
        CatX += CatSpeed;

    //새를 회전
    BirdRotate = (SDL_GetTicks() % 1 == 0 ? BirdRotate -2 : BirdRotate);

    //사과 튕기기
    AppleX += AppleSpeedX;
    AppleY += AppleSpeedY;
    
    int hitX = 10;
	  int hitY = 10;
	  int hitW = AppleH;
	  int hitH = AppleW;
    int TopX = AppleX + hitX;
    int TopY = AppleY + hitY;
    if ((TopX + hitW) >= 660 || TopX <= 0)
        AppleSpeedX *= -1;
    if ((TopY + hitH) >= 500 || TopY <= 0)
        AppleSpeedY *= -1;
}

void Game::update()
{
  objectMove();

  SDL_RenderPresent(m_pRenderer); 
}
void Game::render()
{

    SDL_RenderClear(m_pRenderer);
    
    //배경 이미지
    TheTextureManager::Instance()->draw("background", 0, 0, 640, 480, m_pRenderer, SDL_FLIP_NONE);

    //360도 회전하는 새
    TheTextureManager::Instance()->drawbird("Bird", BirdX, BirdY, BirdW, BirdH, BirdRotate, m_pRenderer);
    
    //좌우로 이동하는 고양이
    TheTextureManager::Instance()->drawFrame("Cat", CatX, CatY, CatSize, CatSize, 0, m_currentFrame % 3, m_pRenderer, CatSpeed >0 ?  SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    
    //맵 구현
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            if (map[x][y] == 0)
            {
                TheTextureManager::Instance()->draw("Space", 640 - (19 - x) * SpaceSize, 480 - (19 - y) * SpaceSize, SpaceSize, SpaceSize, m_pRenderer, SDL_FLIP_NONE);
            }
            else if (map[x][y] == 1)
            {
                TheTextureManager::Instance()->draw("Tile", 640 - (19 - x) * 5, 480 - (19 - y) * TileSize, TileSize, TileSize, m_pRenderer, SDL_FLIP_NONE);
            }
        }
    }

    //사과
    TheTextureManager::Instance()->draw("Apple", AppleX, AppleY, 40, 50, m_pRenderer, AppleSpeedY <= -1 ?  SDL_FLIP_VERTICAL : SDL_FLIP_NONE);


}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}