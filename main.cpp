#include "Game.h" //키 입력 실습
#include "iostream"
#include "SDL.h"
#include "InputHandler.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
    if (TheGame::Instance()->init("Game class", 100, 100, 640, 480, false))
    {
        Uint32 frameStart, frameTime;
        while (TheGame::Instance()->running())
        {
            frameStart = SDL_GetTicks(); //while문이 한 번 돌때마다 그 한번이 언제 시작되는지 저장하는 변수
            TheGame::Instance()->handleEvents(); //키입력
            TheGame::Instance()->update(); //정보의 변화를 처리
            TheGame::Instance()->render(); // 업데이트한 것들을 처리 출력
            frameTime = SDL_GetTicks() - frameStart; // frameTime은 위에있는 Game에 대한 while문 처리들이 얼마만에 실행 되었는지 저장하는 변수
            if (frameTime < DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    }
    else
    {
        std::cout << "game init failure" << SDL_GetError() << "\n";
        return -1;
    }
    TheGame::Instance()->clean();
    TheInputHandler::Instance()->clean();
    return 0;

}