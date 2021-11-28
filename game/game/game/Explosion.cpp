#include"Explosion.h"
ExplosionObj::ExplosionObj()
{
	frame_ = 0;
}
ExplosionObj::~ExplosionObj()
{
	
}
void ExplosionObj::set_clip()
{
	clip[0].x = 0;
	clip[0].y = 0;
	clip[0].w = EX_WIDTH;
	clip[0].h = EX_HEIGHT;

	clip[1].x = EX_WIDTH;
	clip[1].y = 0;
	clip[1].w = EX_WIDTH;
	clip[1].h = EX_HEIGHT;

	clip[2].x = EX_WIDTH * 2;
	clip[2].y = 0;
	clip[2].w = EX_WIDTH;
	clip[2].h = EX_HEIGHT;

	clip[3].x = EX_WIDTH * 3;
	clip[3].y = 0;
	clip[3].w = EX_WIDTH;
	clip[3].h = EX_HEIGHT;
}
void ExplosionObj::move()
{

}
void ExplosionObj::showEX(SDL_Surface* des)
{
	if (frame_ >= 4)
	{
		frame_ = 0;
	}
	ComFunc::ApplySurfaceClip(this->p_obj, des,&clip[frame_],rect.x, rect.y);
}