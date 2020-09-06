#include"sprite_run.h"

sprite_run_::sprite_run_() {
	frame_ = NUMBER_SPRITE;

}
sprite_run_ ::~sprite_run_() {
	// to do
}

void sprite_run_::set_frame_clip_(SDL_Surface* des, const int& i_) {
	frame_clip_[0].x = 0;
	frame_clip_[0].y = 0;
	frame_clip_[0].w = WIDTH_SPRITE;
	frame_clip_[0].h = HEIGHT_SPRITE;

	frame_clip_[1].x = 0;
	frame_clip_[1].y = 0;
	frame_clip_[1].w = WIDTH_SPRITE;
	frame_clip_[1].h = HEIGHT_SPRITE;

	frame_clip_[2].x = WIDTH_SPRITE;
	frame_clip_[2].y = 0;
	frame_clip_[2].w = WIDTH_SPRITE;
	frame_clip_[2].h = HEIGHT_SPRITE;

	frame_clip_[3].x = WIDTH_SPRITE;
	frame_clip_[3].y = 0;
	frame_clip_[3].w = WIDTH_SPRITE;
	frame_clip_[3].h = HEIGHT_SPRITE;

	frame_clip_[4].x = WIDTH_SPRITE * 2;
	frame_clip_[4].y = 0;
	frame_clip_[4].w = WIDTH_SPRITE;
	frame_clip_[4].h = HEIGHT_SPRITE;

	frame_clip_[5].x = WIDTH_SPRITE * 2;
	frame_clip_[5].y = 0;
	frame_clip_[5].w = WIDTH_SPRITE;
	frame_clip_[5].h = HEIGHT_SPRITE;

	frame_clip_[6].x = WIDTH_SPRITE * 3;
	frame_clip_[6].y = 0;
	frame_clip_[6].w = WIDTH_SPRITE;
	frame_clip_[6].h = HEIGHT_SPRITE;

	frame_clip_[7].x = WIDTH_SPRITE * 3;
	frame_clip_[7].y = 0;
	frame_clip_[7].w = WIDTH_SPRITE;
	frame_clip_[7].h = HEIGHT_SPRITE;

	frame_clip_[8].x = WIDTH_SPRITE * 4;
	frame_clip_[8].y = 0;
	frame_clip_[8].w = WIDTH_SPRITE;
	frame_clip_[8].h = HEIGHT_SPRITE;

	frame_clip_[9].x = WIDTH_SPRITE * 4;
	frame_clip_[9].y = 0;
	frame_clip_[9].w = WIDTH_SPRITE;
	frame_clip_[9].h = HEIGHT_SPRITE;

	frame_clip_[10].x = WIDTH_SPRITE * 5;
	frame_clip_[10].y = 0;
	frame_clip_[10].w = WIDTH_SPRITE;
	frame_clip_[10].h = HEIGHT_SPRITE;

	frame_clip_[11].x = WIDTH_SPRITE * 5;
	frame_clip_[11].y = 0;
	frame_clip_[11].w = WIDTH_SPRITE;
	frame_clip_[11].h = HEIGHT_SPRITE;

	frame_clip_[12].x = WIDTH_SPRITE * 6;
	frame_clip_[12].y = 0;
	frame_clip_[12].w = WIDTH_SPRITE;
	frame_clip_[12].h = HEIGHT_SPRITE;

	frame_clip_[13].x = WIDTH_SPRITE * 6;
	frame_clip_[13].y = 0;
	frame_clip_[13].w = WIDTH_SPRITE;
	frame_clip_[13].h = HEIGHT_SPRITE;

	frame_clip_[14].x = WIDTH_SPRITE * 7;
	frame_clip_[14].y = 0;
	frame_clip_[14].w = WIDTH_SPRITE;
	frame_clip_[14].h = HEIGHT_SPRITE;

	frame_clip_[15].x = WIDTH_SPRITE * 7;
	frame_clip_[15].y = 0;
	frame_clip_[15].w = WIDTH_SPRITE;
	frame_clip_[15].h = HEIGHT_SPRITE;
	Show_Clip_(des, frame_clip_[i_]);
}