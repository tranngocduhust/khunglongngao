#include"common_function.h"

SDL_Surface* SDL_commonFunction::Load_Image(string file_path) {
	SDL_Surface* Image = NULL;
	SDL_Surface* Optimize = NULL;
	Image = IMG_Load(file_path.c_str());
	if (Image != NULL) {
		Optimize = SDL_DisplayFormat(Image);
		Uint32 color_key = SDL_MapRGB(Optimize->format, 0, 255, 255);
		SDL_SetColorKey(Optimize, SDL_SRCCOLORKEY, color_key);
		SDL_FreeSurface(Image);
	}
	return Optimize;
}
SDL_Rect SDL_commonFunction::Apply_Image(SDL_Surface* str, SDL_Surface* des, const int& x, const int& y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(str, NULL, des, &offset);
	return offset;
}
SDL_Rect SDL_commonFunction::Apply_clip(SDL_Surface* str, SDL_Surface* des, SDL_Rect& offs, const int& x, const int& y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(str, &offs, des, &offset);
	return offset;
}
void SDL_commonFunction::Clean_up(SDL_Surface* des) {
	SDL_FreeSurface(des);
}

bool SDL_commonFunction::check_collision(const SDL_Rect& offset_a, const SDL_Rect& offset_b,const int &spt) {

	const int left_a = offset_a.x+32;
	const int right_a = offset_a.x + offset_a.w-50;
	const int top_a = offset_a.y+21;
	const int button_a = offset_a.y + offset_a.h-7;

	const int left_b = offset_b.x;
	const int right_b = offset_b.x + offset_b.w;
	const int top_b = offset_b.y;
	const int button_b = offset_b.y + offset_b.h;

	if (right_a >= left_b && right_a < left_b + spt&&button_a>top_b&&top_a<button_b) {
		return true;
	}
	if (left_a <= right_b && left_a >right_b - spt && button_a>top_b && top_a < button_b) {
		return true;
	}

	if (offset_a.y <= 0) {
		return true;
	}
	return false;
}
bool SDL_commonFunction::Check_mark(const SDL_Rect& offset_a, const SDL_Rect& offset_b,const int&spt) {
	const int left_a = offset_a.x + 32;
	const int right_a = offset_a.x + offset_a.w - 50;

	const int top_a = offset_a.y + 21;
	const int button_a = offset_a.y + offset_a.h - 7;
	
	const int left_b = offset_b.x;
	const int right_b = offset_b.x + offset_b.w;

	const int top_b = offset_b.y;
	const int button_b = offset_b.y + offset_b.h;
	
	if (right_a>=left_b&&right_a<left_b+ spt) {
		return true;
	}

	return false;
}

bool SDL_commonFunction::check_colision_menu( const SDL_Rect& rect, const int& x, const int& y) {
	if (x >= rect.x && x <= rect.x + rect.w && y > rect.y && y < rect.y + rect.h) {
		return true;
	}
	return false;
}