#include"common_function.h"
#include"base_object.h"
#include"main_object.h"
#include"sprite_run.h"
#include"threats_object.h"
#include"list_type_threats.h"
#include"sprite_deal.h"
#include"text_object.h"
#include"menu_game.h"
int _test = 5;
TTF_Font* _mark_text = NULL;
TTF_Font* _menu_text = NULL;


bool INIT() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}
	SDL_WM_SetCaption("Ngao Edition", "hello");
	SDL_WM_SetIcon(IMG_Load("icon.png"), NULL);
	g_Screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, BPP, SDL_SWSURFACE);
	if (g_Screen == NULL) {
		return false;
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		return false;
	}
	g_Punch = Mix_LoadWAV("punch.wav");
	g_Ting = Mix_LoadWAV("ting.wav");
	g_Ting_2 = Mix_LoadMUS("ting.wav");
	if (g_Punch == NULL || g_Ting == NULL || g_Ting_2 == NULL) {
		return false;
	}
	if (TTF_Init() == -1) {
		return false;
	}
	_mark_text = TTF_OpenFont("thuphap.ttf", 20);
	_menu_text = TTF_OpenFont("thuphap2.ttf", 60);
	return true;
}
int main(int arc, char* argv[]) {
	//declare common

	do {
		int _rand = 5;
		int _test_ = 10;
		bool is_quit = false;
		int a = 0;
		int _speed_threats = SPEED_THREATS_;
		Uint32 _time_run;
		//
		//declare object common
		sprite_run_ _sprite_run;
		list_type_threats_ _list_threats;
		//Declare SDL 
		int _mark = 0;
		if (INIT() == false) {
			return 1;
		}
		//
		//Load Background
		g_Image = SDL_commonFunction::Load_Image("background4.jpg");
		if (g_Image == NULL) {
			return 1;
		}
		int speed_background = 0;
		//
		//Declare sprite_run

		bool test_sprite_run = _sprite_run.Load_Image_("sprite_run2.png");
		_sprite_run.set_frame_(NUMBER_SPRITE);
		_sprite_run.set_Rect_(X0_, Y0_);
		_sprite_run.Set_v0_(V0_);
		if (test_sprite_run == false) {
			return 1;
		}//
		/// <summary>
		/// declare _tem;


		//

		if (_list_threats.make_list_threats_() == false) { return 1; }
		vector<threats_object_> _threats = _list_threats.get_list_threats_();
		vector<threats_object_> _threatss = _list_threats.get_list_threats_();
		for (size_t th = 0; th < NUMBER_THREATS; th++)
		{
			_rand = 0 + rand() % NUMBER_TYPE_THREATS_;
			_threats.at(th) = _threats[_rand];
			_threats.at(th).set_Rect_x(X0_THREATS_ + th * SPACE_THREATS);
			_threats.at(th).set_speed_threats_(SPEED_THREATS_);
		}
		//declare tem
		threats_object_ _tem;
		int _x_tem;
		//declare sprite deal
		sprite_deal_ _sprite_deal;
		bool _spr = _sprite_deal.Load_Image_("sprite_deal.png");
		if (_spr == false) {
			return 1;
		}
		//declare text mark
		text_object_ _text_mark;
		_text_mark.set_Rect_(500, 20);
		_text_mark.set_color_text_(text_object_::RED);
		//declare text time
		text_object_ _text_time;
		_text_time.set_Rect_(1100, 20);
		_text_time.set_color_text_(text_object_::RED);
		//declare menu game

		menu_game_ _menu;
		int _check = _menu.Handle_Move_Mouse_(g_Screen, _menu_text);
		if (_check == 3) {
			return 1;
		}
		else if (_check == 0) {
			is_quit = false;
		}
		Uint32 _time_start = SDL_GetTicks() / 1000;
		while (!is_quit)
		{
			_time_run = SDL_GetTicks() / 1000 - _time_start;
			if (_mark % 8 == 0) {
				_speed_threats + 3;
			}

			int _timer = SDL_GetTicks();
			speed_background -= SPEED_BACKGROUND;
			if (speed_background <= -WIDTH_SCREEN) {
				speed_background = 0;
			}
			//run Background.
			SDL_commonFunction::Apply_Image(g_Image, g_Screen, speed_background, 0);
			SDL_commonFunction::Apply_Image(g_Image, g_Screen, speed_background + WIDTH_SCREEN, 0);
			//

			while (SDL_PollEvent(&g_Events)) {
				if (g_Events.type == SDL_QUIT) {
					is_quit = true;
					break;
				}
				// Handle input event
				_sprite_run.Handle_Input_Event_(g_Events);//
			}

			//Apply sprite_run_
			_sprite_run.Handle_Move_();
			_sprite_run.set_frame_clip_(g_Screen, a);
			a++;
			if (a >= NUMBER_SPRITE) {
				a = 0;
			}//

			//Handle Move

			for (size_t mv = 0; mv < NUMBER_THREATS; mv++)
			{
				if (_threats[mv].get_is_move() == true) {
					_threats[mv].Handle_Move_Threats(WIDTH_SCREEN, HEIGHT_SCREEN);
					_threats[mv].Show_Image_(g_Screen);

				}

				else if (_threats[mv].get_is_move() == false) {
					_rand = 0 + rand() % NUMBER_TYPE_THREATS_;
					_threats[mv] = _threatss[_rand];

					_threats[mv].set_Rect_x(1900);
					_threats[mv].set_is_move(true);
					_threats[mv].set_speed_threats_(_speed_threats);

				}
				//// Handle collistion
				if (SDL_commonFunction::check_collision(_sprite_run.Get_Rect(), _threats[mv].Get_Rect(), _speed_threats) == true) {
					Mix_PlayChannel(-1, g_Punch, 0);
					_sprite_deal.set_Rect_(X0_ - 100, Y0_);
					for (size_t fr = 0; fr < NUMBER_FRAME_SPRITE_DEAL_; fr++)
					{

						SDL_commonFunction::Apply_Image(g_Image, g_Screen, speed_background, 0);
						SDL_commonFunction::Apply_Image(g_Image, g_Screen, speed_background + WIDTH_SCREEN, 0);
						_threats[mv].Show_Image_(g_Screen);
						if (mv < 2) {
							_threats[mv + 1].Show_Image_(g_Screen);
						}
						if (mv >= 1) {
							_threats[mv - 1].Show_Image_(g_Screen);
						}
						if (mv == 2) {
							_threats[mv - 1].Show_Image_(g_Screen);
							_threats[mv - 2].Show_Image_(g_Screen);
						}
						_sprite_deal.set_frame_clip_deal_(g_Screen, fr);
						SDL_Flip(g_Screen);
						SDL_Delay(80);
					}
					//Handle game over
					int check_game_over = 10;
					check_game_over = _menu.Game_over(g_Screen, _menu_text, _mark, _time_run);
					if (check_game_over == 0)
					{
						is_quit = true;
						_test = 1;
						_test_ = 1;
						break;
					}
					else if (check_game_over == 1) {
						is_quit = true;
						_test = 0;
						_test_ = 1;
						break;
					}

				}
				if (SDL_commonFunction::Check_mark(_sprite_run.Get_Rect(), _threats[mv].Get_Rect(), _speed_threats) == true) {
					Mix_PlayMusic(g_Ting_2, 0);
					_mark += 1;
				}
			}
			if (_test_ != 1) {
				string __mark = "SCORE: ";
				string _mark_int = to_string(_mark);
				string _apply_text = __mark + _mark_int;
				_text_mark.set_name_text(_apply_text);
				_text_mark.show_text_on_screen(_mark_text, g_Screen);

				string __time = "TIME: ";
				string _time_ = to_string(_time_run);
				string _apply_text_ = __time + _time_;
				_text_time.set_name_text(_apply_text_);
				_text_time.show_text_on_screen(_mark_text, g_Screen);
			}
			SDL_Flip(g_Screen);
			int _real_time = SDL_GetTicks() - _timer;
			int frame_pre_second = 1000 / FPS;
			if (_real_time <= frame_pre_second) {
				int _fps = frame_pre_second - _real_time;
				if (_fps >= 0) {
					SDL_Delay(_fps);
				}
			}


		}

	} while (_test);

	//FreeSurface


	SDL_commonFunction::Clean_up(g_Screen);
	SDL_commonFunction::Clean_up(g_Image);
	return 0;
}