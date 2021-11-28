#include"ThreatObj.h"
Threat::Threat()
{
	rect.x = SCREEN_WIDTH;
	rect.y = SCREEN_HEIGHT;
	rect.w = WIDTH_THREAT;
	rect.h = HEIGHT_THREAT;
	x_val_ = 0;
	y_val_ = 0;
	hp = 2;

}
Threat::~Threat()
{
	if (amo_list.size() > 0)
	{
		for (int i = 0; i < amo_list.size(); i++)
		{
			AmoObject* p_amo = amo_list.at(i);
			if (p_amo != NULL)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
		amo_list.clear();
	}
}
void Threat::Move(const int& x_, const int& y_)
{
	rect.x -= x_val_;
	if (rect.x < 0)
	{
		rect.x = SCREEN_WIDTH;
		int rand_y = rand() % 400;
		if (rand_y > SCREEN_HEIGHT - 200)
		{
			rand_y = SCREEN_HEIGHT * 0.3;
		}
		rect.y = rand_y;
	}
	
}
void Threat::Input(SDL_Event events)
{
	
}
void Threat::initAmo(AmoObject* p_amo)
{
	if (p_amo)
	{
		bool ret = p_amo->LoadImg("sphere2.png");
		if (ret)
		{
			p_amo->set_is_move(true);
			p_amo->Set_W_H(WIDTH_AMO_SPHERE, HEIGHT_AMO_SPHERE);
			p_amo->set_type(AmoObject::SPHERE);
			p_amo->SetRect(rect.x, rect.y + rect.h * 0.5);
			amo_list.push_back(p_amo);
		}
	}
}
void Threat::makeAmo(SDL_Surface* des, const int& x_lim, const int& y_lim)
{
	for (int i = 0; i < amo_list.size(); i++)
	{
		AmoObject* p_amo = amo_list.at(i);

		if (p_amo)
		{
			if (p_amo->get_is_move())
			{
				p_amo->Show(des);
				p_amo->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT, -8);
			}
			else
			{
				p_amo->set_is_move(true);
				p_amo->SetRect(rect.x, rect.y + rect.h * 0.5);
			}
		}
	}
}
void Threat::reset(const int& x_boder)
{
	rect.x = x_boder;
	int rand_y = rand() % 400;
	if (rand_y > SCREEN_HEIGHT - 200)
	{
		rand_y = SCREEN_HEIGHT * 0.3;
	}
	rect.y = rand_y;
	for (int i = 0; i < amo_list.size(); i++)
	{
		AmoObject* p_amo = amo_list.at(i);
		if (p_amo)
		{
			resetAmo(p_amo);
		}
	}
}
void Threat::resetAmo(AmoObject* p_amo)
{
	p_amo->SetRect(rect.x, rect.y + rect.h * 0.5);
}
void Threat::removeAmo(const int& idx)
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