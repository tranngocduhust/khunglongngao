#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include"common_function.h"
class base_object_ {
protected:
	SDL_Surface* Image_;
	SDL_Rect Rect_;
public:
	base_object_();
	~base_object_();

	bool Load_Image_(string file_path);
	void Show_Image_(SDL_Surface* des);
	void Show_Clip_(SDL_Surface* des, SDL_Rect& offs);

	void set_Rect_(const int& x, const int& y);
	SDL_Rect Get_Rect() { return Rect_; }

	void set_Rect_x(const int& x) { Rect_.x = x; }
	int get_Rect_x() { return Rect_.x; }

	void set_Rect_y(const int& y) { Rect_.y = y; }
	int get_Rect_y() { return Rect_.y; }
};
#endif // !BASE_OBJECT_H_
