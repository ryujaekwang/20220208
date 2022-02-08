#include "MyEngine.h"
#include "World.h"
#include <fstream>
#include"Wall.h"
#include"Player.h"
#include"Goal.h"
#include<iostream>

MyEngine::MyEngine()
{
	CurrentWorld = new World();
	bIsRunning = true;
}

MyEngine::~MyEngine()
{
	delete CurrentWorld;
	CurrentWorld = nullptr;
	bIsRunning = false;
}

void MyEngine::Run()
{

	//1 Frame
	BeginPlay();
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void MyEngine::Stop()
{
	bIsRunning = false;
}

void MyEngine::SpawnActor(class Actor* NewActor)
{
	CurrentWorld->SpawnActor(NewActor);
}

void MyEngine::DestroyActor(class Actor* DestroyActor)
{
	CurrentWorld->DestroyActor(DestroyActor);
}

void MyEngine::LoadLevel(std::string MapName)
{
	std::ifstream MapFile(MapName);

	int X = 0;
	int Y = 0;

	while (!MapFile.eof())
	{
		char ReadData = MapFile.get();
		switch (ReadData)
		{
		case '\n':
			X = 0;
			Y++;
			continue;
		case'*':
			SpawnActor(new Wall(X, Y));
			break;
		case'P':
			SpawnActor(new Player(X, Y));
			break;
		case'G':
			SpawnActor(new Goal(X, Y));
			break;
		}
		X++;

	}
	MapFile.close();
}

void MyEngine::SaveLevel(std::string SaveMapName)
{

	std::ofstream WriteFile(SaveMapName);

	int MaxX = -99999;
	int MaxY = -99999;


	std::vector<Actor*> ActorList = CurrentWorld->GetAcorList();


		//���� ū ��ǥ�� ���� �ϱ�
		for (auto SelectedActor : ActorList)
		{
			if (MaxX <= SelectedActor->GetX())
			{
				MaxX = SelectedActor->GetX();
			}
			if (MaxY <= SelectedActor->GetY())
			{
				MaxY = SelectedActor->GetY();
			}
		}

		bool bIsWrite = false;

		for(int Y = 0; Y <= MaxY; ++Y)
		{
			for (int X = 0; X <= MaxX; ++X)
			{
				//��ü ����
				for (auto SelectedActor : ActorList)
				{
					if (SelectedActor->GetX() == X && SelectedActor->GetY() == Y)
					{
						WriteFile.put(SelectedActor->GetShape());
						bIsWrite = true;
						break;
					}
				}
				//��ĭ����
				if (bIsWrite == false)
				{
					WriteFile.put(' ');
				}

				bIsWrite = false;
			}
			//�� �ٲ�
			WriteFile.put('\n');
		}

	//std::cout << MaxX << std::endl;
	//std::cout << MaxY << std::endl;


	WriteFile.close();



}

void MyEngine::BeginPlay()
{
	CurrentWorld->beginPlay();
}

void MyEngine::Tick()
{
	CurrentWorld->Tick();
}

void MyEngine::Render()
{
	CurrentWorld->Render();
}

void MyEngine::Input()
{
	CurrentWorld->Input();
}
