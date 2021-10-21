#include"Game.h" //Vector2D 실습

Game* m_game = 0;

int main(int argc, char* argv[])
{
   
    TheGame::Instance()->init("Game class", 100, 100, 640, 480, 0);
    while (TheGame::Instance()->running())
    {
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();
        SDL_Delay(10);
    }
    TheGame::Instance()->clean();
    return 0;

}