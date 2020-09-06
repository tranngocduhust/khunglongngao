#include"threats_object.h"

threats_object_::threats_object_() {
	x_threats_ = 0;
	y_threats_ = 0;
	speed_threats_ = 0;
	is_move_ = true;
}
threats_object_ ::~threats_object_() {
	//to do
}
void threats_object_::Handle_Move_Threats(const int& x_border, const int& y_border) {
	Rect_.x -= speed_threats_;
	if (Rect_.x <= 0) {
		Rect_.x = WIDTH_SCREEN + SPACE_THREATS;
		is_move_ = false;
	}
}
