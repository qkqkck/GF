#include "SDL.h"
#include "vector"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Game
{
private:
	Game() {}
	static Game* s_pInstance;

public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
			s_pInstance = new Game();
		return s_pInstance;
	}

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	SDL_Renderer* getRenderer() { return m_pRenderer;}
	
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_currentFrame;
	bool m_bRunning;
	std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;