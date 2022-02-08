#include<iostream>
#include"MyEngine.h"
#include"SDL.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc, char* argv[])
	{

	MyEngine* PlayEngine = new MyEngine("Maze game", "Level01.map", 800, 600);
	PlayEngine->Run();

	delete PlayEngine;
	PlayEngine = nullptr;


	//bool bISRunnig = true;



		////그릴 리스트 준비
		////PreRender(그릴 준비, 그릴 물체 배치)
		//SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0xff);
		//SDL_RenderClear(MyRenderer);
		//
		////빨간색 선 그리기
		//SDL_SetRenderDrawColor(MyRenderer, 0xff, 0, 0, 128);
		//SDL_RenderDrawLine(MyRenderer, 100, 100, 200, 200);
		//
		////녹색 사각형 그리기
		//SDL_SetRenderDrawColor(MyRenderer, 0x00, 0xff, 0, 0);
		//SDL_Rect MyRect = { 100, 100, 200, 200 };
		//SDL_RenderDrawRect(MyRenderer, &MyRect);

		////파란색 채워진 사각형 그리기
		//SDL_SetRenderDrawColor(MyRenderer, 0x00, 0x0, 0xff, 0);
		//SDL_Rect MyRect2 = { 300, 200, 200, 200 };
		//SDL_RenderFillRect(MyRenderer, &MyRect);

		//노란색 원 그리기

	/*	int Radius = 100;
		int PositionX = 400;
		int PositionY = 400;
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0x00, 0);
		int OldX = sin(3.14f / 180.0f * 0.0f) * Radius;
		int OldY = cos(3.14f / 180.0f * 0.0f) * Radius;*/

		//for (int Angle = 1; Angle < 360; ++Angle)
		//{
		//	int X1 = OldX;
		//	int Y1 = OldY;
		//	int X2 = sin(3.14f / 180.0f * Angle)* Radius;
		//	int Y2 = cos(3.14f / 180.0f * Angle)* Radius;

		//	SDL_RenderDrawLine(MyRenderer, X1+PositionX, Y1+ PositionY, X2+PositionX, Y2+PositionY);

		//	OldX = X2;
		//	OldY = Y2;


		//SDL_SetRenderDrawColor(MyRenderer, 128, 128, 128, 0);
		//int Radius = 250;
		//int PositionX = 400;
		//int PositionY = 400;

		//	for (int Angle = 0; Angle <= 180; ++Angle)
		//	{
		//		int X1 = sin(3.14f / 180.0f * Angle) * Radius;
		//		int Y1 = cos(3.14f / 180.0f * Angle) * Radius;
		//		int X2 = sin(3.14f / 180.0f * (360-Angle)) * Radius;
		//		int Y2 = cos(3.14f / 180.0f * (360-Angle)) * Radius;

		//		SDL_RenderDrawLine(MyRenderer, X1 + PositionX, Y1 + PositionY, X2 + PositionX, Y2 + PositionY);




			return 0;

	}
