#include "Actor.h"
#include <iostream>
#include "Util.h"

Actor::Actor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
}

Actor::Actor(int NewX, int NewY)
{
	SetAcorLocation(NewX, NewY);
}

Actor::~Actor()
{
}

void Actor::Tick()
{
}

void Actor::Render()
{
	//static ��� �Լ�
	Util::GotoXY(GetX(), GetY());

	std::cout << GetShape() << std::endl;
}

void Actor::BeginPlay()
{
}

inline void Actor::SetAcorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}

inline void Actor::SetShape(char NewShape)
{
	Shape = NewShape;

}
