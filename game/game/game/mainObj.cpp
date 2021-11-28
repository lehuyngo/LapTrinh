#include"mainObj.h"

MainObj::MainObj()
{
	rect.x = 0;
	rect.y = 0;
	rect.w = WIDTH_MAIN_OBJECT;
	rect.h = HEIGH_MAIN_OBJECT;
	x_val = 0;
	y_val = 0;
	hp = 10;
}
MainObj::~MainObj()
{
	
}
void MainObj::HandleInput(SDL_Event event)
{
	if (event.type ==SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			// Todo
			y_val -= HEIGH_MAIN_OBJECT / 6;
			break;
		case SDLK_DOWN:
			y_val += HEIGH_MAIN_OBJECT / 6;
			break;
		case SDLK_LEFT:
			x_val -= WIDTH_MAIN_OBJECT / 6;
			break;
		case SDLK_RIGHT:
			x_val += WIDTH_MAIN_OBJECT / 6;
			break;
		}
	}
	else if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			// Todo
			y_val += HEIGH_MAIN_OBJECT / 6;
			break;
		case SDLK_DOWN:
			y_val -= HEIGH_MAIN_OBJECT / 6;
			break;
		case SDLK_LEFT:
			x_val += WIDTH_MAIN_OBJECT / 6;
			break;
		case SDLK_RIGHT:
			x_val -= WIDTH_MAIN_OBJECT / 6;
			break;
		}
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		AmoObject* p_amo = new AmoObject();
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			p_amo->Set_W_H(WIDTH_AMO_LASER, HEIGHT_AMO_LASER);
			p_amo->LoadImg("laser.png");
			p_amo->set_type(AmoObject::LASER);
		}
		else if(event.button.button==SDL_BUTTON_RIGHT)
		{
			p_amo->Set_W_H(WIDTH_AMO_SPHERE, HEIGHT_AMO_SPHERE);
			p_amo->LoadImg("sphere.png");
			p_amo->set_type(AmoObject::SPHERE);
		}
		p_amo->SetRect(this->rect.x +this->rect.w-25, this->rect.y + this->rect.h-7);
		p_amo->set_is_move(true);
		amo_list.push_back(p_amo);
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{

	}
}
void MainObj::HandleMove()
{
	rect.x += x_val;
	if (rect.x < 0|| rect.x+WIDTH_MAIN_OBJECT>SCREEN_WIDTH)
	{
		rect.x -= x_val;
	}
	rect.y += y_val;
	if (rect.y<0 || rect.y + HEIGH_MAIN_OBJECT>SCREEN_HEIGHT-200)
	{
		rect.y -= y_val;
	}

}
void MainObj::makeAmo(SDL_Surface* g_screen)
{
	for (int i = 0; i < amo_list.size(); i++)
	{
		
		AmoObject* p_amo = amo_list.at(i);
		if (p_amo != NULL)
		{
			if (p_amo->get_is_move())
			{
				p_amo->Show(g_screen);
				p_amo->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT, 20);

			}
			else
			{
				if (p_amo != NULL)
				{
					amo_list.erase(amo_list.begin() + i);
	
					delete p_amo;
					p_amo = NULL;
				}
			}
		}
	}
}
void MainObj::removeAmo(const int& idx)
{
	
		for (int i = 0; i < amo_list.size(); i++)
		{
			if ((amo_list.size() > 0) && (idx < amo_list.size()))
			{
				AmoObject* p_amo = amo_list.at(idx);
				amo_list.erase(amo_list.begin() + idx);
				if (p_amo != NULL)
				{
					delete p_amo;
					p_amo = NULL;
				}
			}
		}
	
}