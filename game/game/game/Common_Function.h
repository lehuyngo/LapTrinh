
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include<windows.h>
#include<string>
#include<SDL_image.h>
#include<SDL.h>
static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Event g_even;
static SDL_Surface* g_object;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

namespace ComFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void ApplySurface2(int x,int y, SDL_Surface* source, SDL_Surface* des);
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
	int MakeRandomPostY();
	void CleanUp();
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y);
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y);
}


#endif // !COMMON_FUNCTION_H_
