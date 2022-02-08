#pragma once
#include <vector>
class World
{
public:
	World();
	virtual ~World();

	void SpawnActor(class Actor* NewActor);
	void DestroyActor(class Actor* DestroyActor);

	void Tick();
	void Render();
	void Input();
	void beginPlay();

	const std::vector<class Actor*>& GetAcorList() { return ActorList; }

protected:
	std::vector<class Actor*> ActorList;

};

