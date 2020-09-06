#include"sprite_deal.h"

sprite_deal_::sprite_deal_() {
	int frame_deal_ = NUMBER_FRAME_SPRITE_DEAL_;
}
sprite_deal_ ::~sprite_deal_() {
	;
}

void sprite_deal_::set_frame_clip_deal_(SDL_Surface* des, const int& a) {
	for (size_t fr = 0; fr < NUMBER_FRAME_SPRITE_DEAL_; fr++)
	{
		frame_clip_deal_[fr].x = WIDTH_SPRITE_DEAL_ * fr;
		frame_clip_deal_[fr].y = 0;
		frame_clip_deal_[fr].w = WIDTH_SPRITE_DEAL_;
		frame_clip_deal_[fr].h = HEIGHT_SPRITE_DEAL;
	}
	Show_Clip_(des, frame_clip_deal_[a]);	
}
void sprite_deal_::movetion_deal() {

}