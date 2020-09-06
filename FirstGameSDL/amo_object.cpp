#include"amo_object.h"

Amo_object_::Amo_object_() {
	int x_val_=0;
	int y_val_=0;
	bool is_move_=false;
	int type_amo_=NONE;
}
Amo_object_ ::~Amo_object_() {
	//to do
}

void Amo_object_::Handle_Move(const int &x_border,const int &y_border) {
	if (is_move_ == true) {
		Rect_.x += 20;
		if (Rect_.x > x_border) {
			is_move_ = false;
		}
	}
	
}
void Amo_object_::Handle_Input_Events() {

}

void Amo_object_::set_is_move(const bool& is_Move) {
	is_move_ = is_Move;
}
void Amo_object_::set_type_amo(const int& type_Amo) {
	type_amo_ = type_Amo;
}
