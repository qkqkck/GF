#include <SDL.h>
#include <iostream>



SDL_Window* g_pwindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_pRunning = false;
int lastTime = 0, currentTime; // 색변환시간

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)

{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pwindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    if (g_pwindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer (g_pwindow, -1, 0);
    }
  }
  else
  {
    return false;
  }

  SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 0, 255);

  return true;
}

void changeColor()
{
  
    currentTime = SDL_GetTicks();

    if (currentTime > lastTime + 1000)

    {
       SDL_SetRenderDrawColor(g_pRenderer, rand() % 255, rand() % 255, rand() % 255, 255);

      lastTime = currentTime;

    }

}

void update()
{
  
  changeColor();

}


void render()
{
  
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
  
}

int main(int argc, char* argb[])
{
  if(init("Breaking UP HelloSDL",
  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,480,
  SDL_WINDOW_SHOWN))
  {
    g_pRunning = true;
  }
  else
  {
    return 1;
  }
  {

    while(g_pRunning)

    {

    update(); //업데이트
    render(); //출력

    }

  }

  SDL_Quit();

  return 0;
}
