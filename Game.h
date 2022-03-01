#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
class Game
{
public:
	Game(); //���캯����������ΪĳЩ��Ա�������ó�ʼֵ
	~Game(); //��ÿ��ɾ���������Ķ���ʱִ��
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };

private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* playTex;
	SDL_Rect srcR, destR;

};

