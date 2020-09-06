#ifndef SPRITE_DEAL_H_
#define SPRITE_DEAL_H_
#include"base_object.h"

const int NUMBER_FRAME_SPRITE_DEAL_ = 10;
const int WIDTH_SPRITE_DEAL_ =180;
const int HEIGHT_SPRITE_DEAL = 200;

class sprite_deal_ :public base_object_ {
private:
	int frame_deal_;
	SDL_Rect frame_clip_deal_[NUMBER_FRAME_SPRITE_DEAL_];
public:
	sprite_deal_();
	~sprite_deal_();

	void set_frame_deal(const int& fra) { frame_deal_ = fra; }
	void set_frame_clip_deal_(SDL_Surface*des,const int&a);

	void movetion_deal();
};

#endif // !SPRITE_DEAL_H_

