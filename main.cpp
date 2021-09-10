#include <SDL.h>

SDL_Window* gpwindow = 0;
SDL_Renderer* gpRenderer = 0;
bool gbRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)

{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    gpwindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    if ('gpwindow ! = 0')
    {
      gpRenderer = SDL_CreateRenderer (gpwindow, -1, 0);
    }
  }
  else
  {
    return false;
  }

  SDL_SetRenderDrawColor(gpRenderer, 255, 255, 0, 255);

  return true;
}

void render()
{
  SDL_RenderClear(gpRenderer);
  SDL_RenderPresent(gpRenderer);
  SDL_Delay(5000);
  SDL_Quit();
}

int main(int argc, char* argb[])
{
  if(init("Breaking UP HelloSDL",
  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,480,
  SDL_WINDOW_SHOWN))
  {
    gbRunning = true;
  }
  else
  {
    return 1;
  }
  {
    while(gbRunning)

    render();

  }

  SDL_Quit();

  return 0;
}
