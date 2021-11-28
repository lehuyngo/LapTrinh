#include "BaseObj.h"
#include"Common_Function.h"

BO::BO()
{
	rect.x = 0;
	rect.y = 0;
	p_obj = NULL;
}
BO::~BO()
{
	if (p_obj != NULL)
	{
		SDL_FreeSurface(p_obj);
	}
}
void BO::Show(SDL_Surface* des)
{
	if (p_obj != NULL)
	{
		ComFunc::ApplySurface(p_obj, des, rect.x, rect.y);
	}
}
bool BO::LoadImg(const char* file_name)
{
	p_obj = ComFunc::LoadImage(file_name);
	if (p_obj == NULL) return false;
	return true;
}
/*void SetRect(const int& x, const  int& y) { rect.x = x, rect.y = y; }
SDL_Rect getRect() const { return rect; }
SDL_Surface* getObj() { return p_obj; }*/