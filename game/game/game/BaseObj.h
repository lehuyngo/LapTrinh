
#ifndef BASE_OBJ_H_
#define BASE_OBJ_H_
#include "Common_Function.h"
class BO
{
public:
	BO();
	~BO();
	void Show(SDL_Surface* des);
	bool LoadImg(const char* file_name);
	void SetRect(const int& x,const  int& y) { rect.x = x, rect.y = y; }
	SDL_Rect getRect() const { return rect; }
	SDL_Surface* getObj() { return p_obj; }
protected:
	SDL_Rect rect;
	SDL_Surface* p_obj;
};
#endif // !BASEOJ_H_

