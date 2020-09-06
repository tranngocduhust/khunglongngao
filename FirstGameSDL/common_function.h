#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<Windows.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<iostream>
using namespace std;
#undef main
//Image
static SDL_Surface* g_Screen = NULL;
static SDL_Surface* g_Image = NULL;
static SDL_Surface* Icon_ = NULL;
static SDL_Event g_Events;

////Audio
static Mix_Chunk* g_Punch = NULL;
static Mix_Chunk* g_Ting = NULL;
static Mix_Music* g_Ting_2 = NULL;

//SCREEN
const int WIDTH_SCREEN = 1300;
const int HEIGHT_SCREEN = 600;
const int BPP = 32;
const int SPEED_BACKGROUND = 5;
const int FLASTFROM = 78;
const int BUTTON_SPRITE = 8;
const int FPS = 80;
//SPRITE
const int NUMBER_SPRITE = 16;
const int WIDTH_SPRITE = 180;
const int HEIGHT_SPRITE = 200;

const int X0_ = 450;
const int Y0_ = HEIGHT_SCREEN-HEIGHT_SPRITE- FLASTFROM+ BUTTON_SPRITE;
const int V0_ = 34;
const int G_ = 2;

//THREATS
const int NUMBER_TYPE_THREATS_ = 13;

const int WIDTH_THREATS_ = 108;
const int HEIGHT_THREATS_ = 110;

const int SPACE_THREATS = 600;
const int NUMBER_THREATS = 3;
const int X0_THREATS_ = 1300;
const int Y0_THREATS_ = HEIGHT_SCREEN - HEIGHT_THREATS_ - FLASTFROM;
const int SPEED_THREATS_ = 13;


namespace SDL_commonFunction {
	SDL_Surface* Load_Image(string file_path);
	SDL_Rect Apply_Image(SDL_Surface* str, SDL_Surface* des, const int& x, const int& y);
	SDL_Rect Apply_clip(SDL_Surface* str, SDL_Surface* des, SDL_Rect& offs, const int& x, const int& y);

	void Clean_up(SDL_Surface* des);
	bool check_collision(const SDL_Rect& offset_a, const SDL_Rect& offset_b, const int& spt);

	bool Check_mark(const SDL_Rect& offset_a, const SDL_Rect& offset_b, const int& spt);
    
	bool check_colision_menu( const SDL_Rect& rect, const int& x, const int& y);
}


#endif //COMMON_FUNCTION_H_!