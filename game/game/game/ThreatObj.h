#ifndef THREAT_OBJ_H_
#define THREAT_OBJ_H_
#include"Common_Function.h"
#include"BaseObj.h"
#include"Amo.h"
#include<vector>
#define WIDTH_THREAT 80
#define HEIGHT_THREAT 33
class Threat :public BO
{
public:
	Threat();
	~Threat();
	void Move(const int& x_, const int& y_);
	void Input(SDL_Event events);

	void set_x(const int& val) { x_val_ = val; }
	void set_y(const int& val) { y_val_ = val; }
	int get_x() { return x_val_; }
	int get_y() { return y_val_; }
	void initAmo(AmoObject* p_amo);
	void makeAmo(SDL_Surface* des,const int& x_lim,const int& y_lim);
	void setAmoList(std::vector<AmoObject*> amolist) { amo_list = amolist; }
	std::vector<AmoObject*> GetAmolist() const { return amo_list; }

	void reset(const int& x_boder);
	void resetAmo(AmoObject* p_amo);
	int getHP() { return hp; }
	void setHP(int damge) { hp -= damge; }


	void removeAmo(const int& idx);
private:
	int x_val_, y_val_,hp;

	std::vector<AmoObject*> amo_list;
};
#endif // !THREAT_OBJ_H_

