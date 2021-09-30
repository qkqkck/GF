#include "SDL.h"
#include "TextureManager.h"

class Game
{
public:
	Game() {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
  void prepare();
  {
    TextureManager::Instance()->Load
  }

private:
	SDL_Window* m_pwindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	TextureManager m_textureManager;
	int m_currentFrame;
};