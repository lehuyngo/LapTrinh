#ifndef MAIN_OBJ_H_
#define MAIN_OBJ_H_

#include"Common_Function.h"
#include"BaseObj.h"
#include<vector>
#include"Amo.h"
#define WIDTH_MAIN_OBJECT 80
#define HEIGH_MAIN_OBJECT 46
class MainObj:public BO
{
public:
	MainObj();
	~MainObj();
	void HandleInput(SDL_Event event);
	void HandleMove();
	void setAmoList(std::vector<AmoObject*> amolist) { amo_list=amolist; }
	std::vector<AmoObject*> GetAmolist() const { return amo_list; }
	void makeAmo(SDL_Surface* g_screen);
	void removeAmo(const int& idx);
	void setHP(int damge) { hp -= damge;  }
	int getHP() { return hp; }
private:
	int x_val;
	int y_val;
	int hp;
	std::vector<AmoObject*> amo_list;

};
#endif // !MIAN_OBJ_H_
