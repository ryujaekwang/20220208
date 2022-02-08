#pragma once
#include <vector>
#include "SDL.h"



class World
{
public:
	World();
	virtual ~World();

	void SpawnActor(class Actor* NewActor);
	void DestroyActor(class Actor* DestroyActor);

	void Tick();
	void Render(SDL_Renderer* MyRenderer);
	void Input();
	void BeginPlay();

	const std::vector<class Actor*>& GetAcorList() { return ActorList; }

protected:
	std::vector<class Actor*> ActorList;

};

