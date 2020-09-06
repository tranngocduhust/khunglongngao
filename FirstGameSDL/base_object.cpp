#include"base_object.h"

base_object_::base_object_() {

	Image_ = NULL;

}
base_object_::~base_object_() {
	//to do;
}

bool base_object_::Load_Image_(string file_path) {

	Image_ = SDL_commonFunction::Load_Image(file_path);
	if (Image_ == NULL) {
		return false;
	}
	return true;
}

void base_object_::Show_Image_(SDL_Surface* des) {
	if (Image_ != NULL) {
		Rect_ = SDL_commonFunction::Apply_Image(Image_, des, Rect_.x, Rect_.y);
	}

}
void base_object_::Show_Clip_(SDL_Surface* des, SDL_Rect& offs) {
	if (Image_ != NULL) {
		Rect_ = SDL_commonFunction::Apply_clip(Image_, des, offs, Rect_.x, Rect_.y);
	}
}
void base_object_::set_Rect_(const int& x, const int& y) {
	Rect_.x = x;
	Rect_.y = y;
}