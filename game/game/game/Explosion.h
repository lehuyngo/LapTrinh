#ifndef EXPLOSION_H_
#define EXPLOSION_H_
#include"BaseObj.h"
#include"Common_Function.h"
const int EX_WIDTH = 165;
const int EX_HEIGHT = 165;
class ExplosionObj :public BO
{
private:
	int frame_;
	SDL_Rect clip[4];
public:
	ExplosionObj();
	~ExplosionObj();
	void set_clip();
	void set_frame(int fr) { frame_ = fr; }
	void move();
	void showEX(SDL_Surface* des);
};
#endif // !EXPLOSION_H_
