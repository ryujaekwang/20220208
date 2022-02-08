#include "Wall.h"

Wall::Wall()
{
	X = 0;
	Y = 0;
	Shape = '*';
}

Wall::Wall(int NewX, int NewY)
{
	SetAcorLocation(NewX, NewY);
	Shape = '*';
}

Wall::~Wall()
{
}
