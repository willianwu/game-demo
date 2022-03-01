#include "Game.h"
#include "TexManager.h"
using namespace std;




Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems intialized!..." << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) {
			cout << "Window created" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "renderer created" << endl;

		}
		isRunning = true;
	}
		
	else {
		isRunning = false;
	}
	playTex = TexManager::LoadTexture("asset/pixelman.png", renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;

	}
}

void Game::update()
{
	count++;
	destR.h = 32;
	destR.w = 32;
	destR.x = count;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//this is where we would add stuff to render
	SDL_RenderCopy(renderer, playTex,NULL,&destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}



