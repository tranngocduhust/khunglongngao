#include"main_object.h"

main_object_::main_object_() {
	x_val_ = 0;
	y_val_ = 0;
	t = 0;
	v0_ = 0;
	is_jum = false;
	x0 = HEIGHT_SCREEN;
}
main_object_ ::~main_object_() {
	// to do;
}
void main_object_::Handle_Input_Event_(SDL_Event& Event_) {
	if (Event_.type == SDL_MOUSEBUTTONDOWN) {
		if (Event_.button.button == SDL_BUTTON_LEFT) {
			is_jum = true;
			x0 = Rect_.y;
			t = 0;
		}
	}
	else if (Event_.type == SDL_MOUSEBUTTONUP) {
		
	}
	else if (Event_.type == SDL_KEYDOWN) {
		// to do
		
	}
	else if (Event_.type == SDL_KEYUP) {
		// to do
	}
}
void main_object_::Handle_Move_() {
	if (is_jum == true) {
		t = t + 1;
		Rect_.y = x0 - v0_ * t + 0.5 * G_ * t * t;
		if (Rect_.y >= Y0_) {
			Rect_.y = Y0_;
			t = 0;
			is_jum = false;
		}
	}

}