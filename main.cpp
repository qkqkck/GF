#include <SDL.h>

SDL_Window* gpwindow = 0;
SDL_Renderer* gpRenderer = 0;

int main(int argc, char* args[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    gpwindow = SDL_CreateWindow("Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if ('gpwindow ! = 0')
    {
      gpRenderer = SDL_CreateRenderer (gpwindow, -1, 0);
    }
  }
  else
  {
    return 1;
  }

  SDL_SetRenderDrawColor(gpRenderer, 0, 0, 255, 255);
  SDL_RenderClear(gpRenderer);
  SDL_RenderPresent(gpRenderer);

  SDL_Delay(5000);
  SDL_Quit();


  return 0;
}