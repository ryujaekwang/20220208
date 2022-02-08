#pragma once
class Actor
{
public:
	
	//오버로딩, 생성자 오버로딩
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

