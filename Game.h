#include "SDL.h"

class Game
{
public:
	Game() {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void objectMove();
  void update();
	void render();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
public:
	
	int m_currentFrame;

	//맵
	int map[19][19] = {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					           1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					           1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,
					           1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
					           1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,
					           1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
					           1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,
					           1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,
					           1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,
					           1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,
					           1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
					           1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,
					           1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,
					           1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,
					           1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,
					           1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,
					           1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
					           1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,
					           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int TileSize = 5;
	int SpaceSize = 5;

	//고양이
	float CatX = 0;
	int CatY = 360;
	int CatSize = 140;
	float CatSpeed = 0.1;

	//새
	int BirdX = 200;
	int BirdY = 100;
	int BirdW = 50;
	int BirdH = 50;
	int BirdRotate = 0;

  //사과
  int AppleX = 0;
  int AppleY = 0;
  int AppleW = 50;
  int AppleH = 40;
	int hitX = 10;
	int hitY = 10;
	int hitW = AppleH;
	int hitH = AppleW;
	int velocityX = -1;
	int velocityY = -1;

	bool m_bRunning;

};