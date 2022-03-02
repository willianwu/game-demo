#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
class Game
{
public:
	Game(); //构造函数，可用于为某些成员变量设置初始值
	~Game(); //在每次删除所创建的对象时执行
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };
	static SDL_Renderer* renderer;

private:
	
	bool isRunning;
	SDL_Window* window;
	
	

};

