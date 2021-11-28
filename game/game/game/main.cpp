#include "Common_Function.h"
#include"mainObj.h"
#include"ThreatObj.h"
#include"Explosion.h"
#undef main

//hàm nhận tên của ảnh, đọc ảnh và trả về kiểu SDL_Surface
bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
	{
		return false;
	}
	return true;
}


int main(int arc, char* argv[])
{
	int bkgr_x = 0;
	bool is_quit = false;
	if (Init() == false)
		return 0;

	g_bkground =ComFunc::LoadImage("bg600.png");
	if (g_bkground == NULL)
	{
		return 0;
	}

	//make mainObject
	MainObj plane_obj;
	plane_obj.SetRect(100, 200);
	bool ret=plane_obj.LoadImg("plane_fly.png");
	if (!ret)
	{
		return 0;
	}
	// tao vu no
	ExplosionObj exp_main;
	ret = exp_main.LoadImg("exp_main.png");

	if (ret == false) return 0;
	exp_main.set_clip();
	//make threat
	Threat* list_threat = new Threat[3];
	for(int t=0;t<3;t++)
	{
		Threat* p_threat = (list_threat+t);
		if (p_threat)
		{
			ret = p_threat->LoadImg("threat.png");
			if (!ret)
			{
				return 0;
			}
			int rand_y = rand() % 400;
			if (rand_y > SCREEN_HEIGHT - 200)
			{
				rand_y = SCREEN_HEIGHT * 0.3;
			}

			p_threat->SetRect(SCREEN_WIDTH + t * 400, rand_y);
			p_threat->set_x(3);


			AmoObject* p_amo = new AmoObject();
			p_threat->initAmo(p_amo);
		}
	
	}
	
	while (!is_quit)
	{
		while (SDL_PollEvent(&g_even))
		{
			if (g_even.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			plane_obj.HandleInput(g_even);

		}

		//apply background
		bkgr_x -= 2;
		ComFunc::ApplySurface(g_bkground, g_screen, bkgr_x, 0);
		ComFunc::ApplySurface(g_bkground, g_screen, bkgr_x + SCREEN_WIDTH, 0);
		if (bkgr_x <= -SCREEN_WIDTH)
		{
			bkgr_x = 0;
		}
		plane_obj.HandleMove();
		plane_obj.Show(g_screen);
		plane_obj.makeAmo(g_screen);
		
		//run threat
		for (int tt = 0; tt < 3; tt++)
		{
			Threat* p_threat = (list_threat + tt);
			if (p_threat)
			{
				p_threat->Move(SCREEN_WIDTH, SCREEN_HEIGHT); 
				p_threat->Show(g_screen);
				
				p_threat->makeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
				
				if (SDL_Flip(g_screen) == -1)
					return 0;
			}
			
			bool is_col = ComFunc::CheckCollision(plane_obj.getRect(), p_threat->getRect());  // kiem tra trung may bay dich
			//kiem tra trung dan dich
			std::vector<AmoObject*> amo_threat_list = p_threat->GetAmolist();
			for (int aThreat = 0; aThreat < amo_threat_list.size(); aThreat++)
			{
				AmoObject* p_threat_amo = amo_threat_list.at(aThreat);
				if (p_threat_amo)
				{
					bool is_col_2 = ComFunc::CheckCollision(p_threat_amo->getRect(), plane_obj.getRect());
					if (is_col_2)
					{
						plane_obj.setHP(2);
						p_threat->removeAmo(aThreat);
						AmoObject* p_amo = new AmoObject();
						p_threat->initAmo(p_amo);
					}
				}
			}
			if ((is_col)||(plane_obj.getHP()<=0))
			{
				for (int ex = 0; ex < 4; ex++)
				{
					int x_pos = (plane_obj.getRect().x + plane_obj.getRect().w * 0.5) - EX_WIDTH * 0.5;
					int y_pos = (plane_obj.getRect().y + plane_obj.getRect().h * 0.5) - EX_HEIGHT * 0.5;
					exp_main.set_frame(ex);
					exp_main.SetRect(x_pos, y_pos);
					exp_main.showEX(g_screen);
					SDL_Delay(100);

					if (SDL_Flip(g_screen) == -1)
						return 0;
					
				}
				if (MessageBox(NULL, L"GAME OVER", L"INFO", MB_OK) == IDOK)
				{
					delete[] list_threat;
					ComFunc::CleanUp();
					SDL_Quit();
					return 1;
				}
			}
			std::vector<AmoObject*> amo_list = plane_obj.GetAmolist();
			for (int a = 0; a < amo_list.size(); a++)
			{
				AmoObject* p_amo = amo_list.at(a);
				if (p_amo)
				{
					bool is_col_threat = ComFunc::CheckCollision(p_amo->getRect(), p_threat->getRect());
					// kiem tra va cham giua dan maybay va threat
					if (is_col_threat)
					{
						p_threat->reset(SCREEN_WIDTH+tt*400);
						plane_obj.removeAmo(a);
					}
				}
			}
			
		}
		


		if (SDL_Flip(g_screen) == -1)
			return 0;
	}
	delete[] list_threat;
	ComFunc::CleanUp();
	SDL_Quit();
	return 1;
}