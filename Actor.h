#pragma once
#include"SDL.h"

class Actor
{
public:
	
	//�����ε�, ������ �����ε�
	Actor();
	Actor(int NewX, int NewY);



		virtual ~Actor();

		virtual void Tick(SDL_Event& MyEvent);
		virtual void Render(SDL_Renderer* MyRenderer);
		virtual void BeginPlay();

		inline virtual void SetAcorLocation(int NewX, int NewY);
		inline virtual void SetShape(char NewShape);
		inline virtual char GetShape() { return Shape; }
		inline virtual int GetX() { return X; }
		inline virtual int GetY() { return Y; }





protected:
		int X;
		int Y;
		char Shape;
		SDL_Color Color;
		int TileSize = 30;
			 






};

