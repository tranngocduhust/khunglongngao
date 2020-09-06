#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_

#include"base_object.h"
#define WIDTH_LASER 35
#define HIEGHT_LASER 5

#define WIDTH_SPHERE 10
#define HIEGHT_SPHERE 10

class Amo_object_ :public base_object {
private:
	int x_val_;
	int y_val_;
	bool is_move_;
	int type_amo_;
public:
	enum amo_type
	{
		NONE,
		LASER,
		SPHERE
	};
	Amo_object_();
	~Amo_object_();
	void Handle_Move(const int& x_border, const int& y_border);
	void Handle_Input_Events();

	void set_is_move(const bool & is_Move);
	bool get_is_move() { return is_move_; }

	void set_type_amo(const int & type_Amo);
	int get_type_amo() { return type_amo_; }
	
	void set_Width_hieght(const int& W, const int& H) { Rect_.w = W, Rect_.h = H; }
};


#endif // !AMO_OBJECT_H_
