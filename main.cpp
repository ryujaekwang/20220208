#include<iostream>
#include<vector>
#include"SDL.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc, char* argv[])
	{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL_Init Error :"<<SDL_GetError()<< endl;
			return -1;
	}
	SDL_Window* MyWindow = SDL_CreateWindow("First SDL Example", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	if (MyRenderer == nullptr)
	{
		cout << "can't Create renderer :" << SDL_GetError() << endl;
		return -1;
	}




	SDL_Event MyEvent;

	bool bISRunnig = true;

	while (bISRunnig)
	{
		//Input
		SDL_PollEvent(&MyEvent);

		switch (MyEvent.type)
		{
			case SDL_QUIT:
				bISRunnig = false;
				break;
			case SDL_KEYDOWN:
				cout << SDL_GetKeyName(MyEvent.key.keysym.sym) << "Ű ������" << endl;
				switch (MyEvent.key.keysym.sym)
				{
				case SDLK_q:
					bISRunnig = false;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				cout << (MyEvent.button.button == SDL_BUTTON_LEFT) << "���콺 ��ư ������" << endl;
				cout << '(' << MyEvent.button.x << "." << MyEvent.button.y << ')' << endl;
				break;
		}

		//�׸� ����Ʈ �غ�
		//PreRender(�׸� �غ�, �׸� ��ü ��ġ)
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderClear(MyRenderer);
		
		//������ �� �׸���
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0, 0, 128);
		SDL_RenderDrawLine(MyRenderer, 100, 100, 200, 200);
		
		//��� �簢�� �׸���
		SDL_SetRenderDrawColor(MyRenderer, 0x00, 0xff, 0, 0);
		SDL_Rect MyRect = { 100, 100, 200, 200 };
		SDL_RenderDrawRect(MyRenderer, &MyRect);

		//�Ķ��� ä���� �簢�� �׸���
		SDL_SetRenderDrawColor(MyRenderer, 0x00, 0x0, 0xff, 0);
		SDL_Rect MyRect2 = { 300, 200, 200, 200 };
		SDL_RenderFillRect(MyRenderer, &MyRect);

		//����� �� �׸���

		int Radius = 50;
		int PositionX = 350;
		int PositionY = 350;
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0x00, 0);
		int OldX = sin(3.14f / 180.0f * 0.0f) * Radius;
		int OldY = cos(3.14f / 180.0f * 0.0f) * Radius;

		for (int Angle = 1; Angle < 360; ++Angle)
		{
			int X1 = OldX;
			int Y1 = OldY;
			int X2 = sin(3.14f / 180.0f * Angle)* Radius;
			int Y2 = cos(3.14f / 180.0f * Angle)* Radius;

			SDL_RenderDrawLine(MyRenderer, X1+PositionX, Y1+ PositionY, X2+PositionX, Y2+PositionY);
			OldX = X2;
			OldY = Y2;

		}




		//GPU�� �׷���
		//Render
		SDL_RenderPresent(MyRenderer);
	}
	
	
	
	
	
	
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();


			return 0;

	}
