#include "Amo.h"
AmoObject::AmoObject()
{
	rect.x = 0;
	rect.y = 0;
	x_val_ = 0;
	y_val_ = 0;
	is_move_ = 0;
	amo_type_ = NONE;
	damge = 2;
}
AmoObject::~AmoObject()
{}

void AmoObject::HandleInputAction(SDL_Event events, SDL_Rect rect_obj)
{

}
void AmoObject::HandleMove(const int x_boder, const int y_border,const int d)
{
	rect.x +=d;
	if ((rect.x > x_boder) ||(rect.x<0))
	{
		is_move_ = false;
	}
}