#include "MyEngine.h"
#include "World.h"
#include <fstream>
#include"Wall.h"
#include"Player.h"
#include"Goal.h"
#include<iostream>

//MyEngine::MyEngine()
//{
//	CurrentWorld = new World();
//	bIsRunning = true;
//}

MyEngine::MyEngine(std::string Title, std::string LevelName, int Width, int Height)
{
	CurrentWorld = new World();
	bIsRunning = true;

	LoadLevel(LevelName);

	Init(Title, Width, Height);
}

MyEngine::~MyEngine()
{
	delete CurrentWorld;
	CurrentWorld = nullptr;
	bIsRunning = false;

	Term();
}

void MyEngine::Init(std::string Title, int Width, int Height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL_Init Error :" << SDL_GetError() << std::endl;
	
	}
	SDL_Window* MyWindow = SDL_CreateWindow(Title.c_str(), 100, 100, Width, Height, SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	if (MyRenderer == nullptr)
	{
		std::cout << "can't Create renderer :" << SDL_GetError() << std::endl;
		
	}
}

void MyEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

}
void MyEngine::Run()
{

	BeginPlay();
	while(bIsRunning)
	{
		Input();
		Tick();
		Render();
	}





	//while (bISRunnig)
	//{
	//	//Input
	//	SDL_PollEvent(&MyEvent);

	//	switch (MyEvent.type)
	//	{
	//		case SDL_QUIT:
	//			bISRunnig = false;
	//			break;
	//		case SDL_KEYDOWN:
	//			cout << SDL_GetKeyName(MyEvent.key.keysym.sym) << "Ű ������" << endl;
	//			switch (MyEvent.key.keysym.sym)
	//			{
	//			case SDLK_q:
	//				bISRunnig = false;
	//				break;
	//			}
	//			break;
	//		case SDL_MOUSEBUTTONDOWN:
	//			cout << (MyEvent.button.button == SDL_BUTTON_LEFT) << "���콺 ��ư ������" << endl;
	//			cout << '(' << MyEvent.button.x << "." << MyEvent.button.y << ')' << endl;
	//			break;
	//	}
}

void MyEngine::Stop()
{
	bIsRunning = false;
}

void MyEngine::SpawnActor(Actor* NewActor)
{
	CurrentWorld->SpawnActor(NewActor);
}

void MyEngine::DestroyActor(Actor* DestroyActor)
{
	CurrentWorld->DestroyActor(DestroyActor);
}

void MyEngine::LoadLevel(std::string LoadMapName)
{
	std::ifstream MapFile(LoadMapName);

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
	//�������� �⺻ ó�� �ϴ� �̺�Ʈ
	switch (MyEvent.type)
	{
	case SDL_QUIT:
		bIsRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_q:
			bIsRunning = false;
			break;
		}
		break;
	}

	CurrentWorld->Tick();
}

void MyEngine::Render()
{
	//�׸� ����Ʈ �غ�
	//PreRender(�׸� �غ�, �׸� ��ü ��ġ)

	CurrentWorld->Render();

	//GPU�� �׷���
	//Render
	SDL_RenderPresent(MyRenderer);
}

void MyEngine::Input()
{
	//Input
	SDL_PollEvent(&MyEvent);

	CurrentWorld->Input();
}
