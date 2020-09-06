#ifndef SPRITE_RUN_H_
#define SPRITE_RUN_H_
#include"main_object.h"

class sprite_run_ :public main_object_ {
private:
	int frame_;
	SDL_Rect frame_clip_[NUMBER_SPRITE];
public:
	sprite_run_();
	~sprite_run_();

	void set_frame_(const int& number) { frame_ = number; }
	void set_frame_clip_(SDL_Surface* des, const int& i_);

};

#endif // !SPRITE_RUN_H_
