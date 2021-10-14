#include "SDL.h"
#include "GameObject.h"
#include "Player.h"
#include "vector"

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

private:
	SDL_Window* m_pwindow;
	SDL_Renderer* m_pRenderer;
  int m_currentFrame;
	bool m_bRunning;
  
  std::vector<GameObject*> m_gameObjects; 
};