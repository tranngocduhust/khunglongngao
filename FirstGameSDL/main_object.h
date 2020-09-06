#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_
#include"base_object.h"


const int WIDTH_OBJECT_ = 100;
const int HEIGHT_OBJECT_ = 80;

class main_object_ :public base_object_ {
protected:
	int x_val_;
	int y_val_;
	int t;
	int v0_;
	bool is_jum;
	int x0;
public:
	main_object_();
	~main_object_();

	void Handle_Input_Event_(SDL_Event& Event_);
	void Handle_Move_();
	void Set_v0_(const int& v) { v0_ = v; }
};

#endif // !MAIN_OBJECT_H_

