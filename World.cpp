#include "World.h"
#include"Actor.h"

World::World()
{

}

World::~World()
{
	//c++ 14
	// UE4
	//for (int i = 0; i < ActorList.size(); ++i)
	//{
	//	ActorList[i];
	//	ActorList[i] = nullptr;
	//}

	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	////for (std::_Vector_iterator<Actor*>::iterator_category iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	delete *iter
	//	*iter = nullptr;
	//}

	//range for
	for (auto CurrentWorld : ActorList)
	{
		delete CurrentWorld;
		CurrentWorld = nullptr;
	}
	ActorList.clear();
}

void World::SpawnActor(Actor* NewActor)
{
	ActorList.push_back(NewActor);
}

void World::DestroyActor(Actor* DestroyActor)
{
	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	if (*iter == DestroyActor)
	//	{
	//		delete* iter;
	//		*iter = nullptr;

	//		//important
	//		iter = ActorList.erase(iter);
	//		break;
	//	}
	//}
	//auto DestroyIter = find(ActorList.begin(), ActorList.end(), DestroyActor);
	//ActorList.erase(DestroyIter);

	//자료 구조 Actor 리스트에서 관리 리스트에서 삭제
	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	//메모리에서 실제로 삭제
	delete DestroyActor;
	DestroyActor = nullptr;
}

void World::Tick(SDL_Event& MyEvent)
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Tick(MyEvent);
	}
}

void World::Render(SDL_Renderer* MyRenderer)
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Render(MyRenderer);
	}
}


void World::BeginPlay()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->BeginPlay();
	}
}
