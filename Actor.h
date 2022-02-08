#pragma once
class Actor
{
public:
	
	//�����ε�, ������ �����ε�
	Actor();
	Actor(int NewX, int NewY);



		virtual ~Actor();

		virtual void Tick();
		virtual void Render();
		virtual void BeginPlay();

		inline virtual void SetAcorLocation(int X, int Y);
		inline virtual void SetShape(char NewShape);
		inline virtual char GetShape() { return Shape; }
		inline virtual int GetX() { return X; }
		inline virtual int GetY() { return Y; }





protected:
		int X;
		int Y;
		char Shape;






};

