#ifndef AMO_H_
#define AMO_H_


#include "common_function.h"
#include "BaseObj.h"
#define WIDTH_AMO_LASER 35
#define HEIGHT_AMO_LASER 5
#define WIDTH_AMO_SPHERE 10
#define HEIGHT_AMO_SPHERE 10

class AmoObject : public BO
{
public:
	enum AmoType
	{
		NONE=0,
		LASER=1,
		SPHERE=2
	};

	AmoObject();
	~AmoObject();

	
	void HandleInputAction(SDL_Event events, SDL_Rect rect_obj);
	void HandleMove(const int x_boder, const int y_border,const int d);

	unsigned int get_type() const { return amo_type_; }
	void set_type(const int& amotype) { amo_type_ = amotype; damge = (int)amotype; }

	bool get_is_move() const { return is_move_; }
	void set_is_move(bool is_move) { is_move_ = is_move; }
	void Set_W_H(const int& W, const int& H) { rect.h = H; rect.w = W; }
	void set_x_val(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }
	int get_x_val() { return x_val_; }
	int get_y_val() { return y_val_; }
	int getDamge() { return damge; }
private:
	int x_val_;
	int y_val_;
	int damge;
	bool is_move_;
	unsigned int amo_type_;
};

#endif // !AMO_H_
