#include"menu_game.h"

menu_game_::menu_game_() {
	//
}
menu_game_ ::~menu_game_() {
	//
}

int menu_game_::Handle_Move_Mouse_(SDL_Surface* des, TTF_Font* font) {
	g_Image = SDL_commonFunction::Load_Image("menu3.png");
	if (g_Image == NULL) {
		return 1;
	}
	const int NUMBER_TEXT_MENU = 4;
	text_object_ type_menu_[NUMBER_TEXT_MENU];

	type_menu_[0].set_name_text("START GAME");
	type_menu_[0].set_color_text_(text_object_::BROWN);
	type_menu_[0].set_Rect_(536, 184);

	type_menu_[1].set_name_text("TUTORIAL");
	type_menu_[1].set_color_text_(text_object_::BROWN);
	type_menu_[1].set_Rect_(570, 267);

	type_menu_[2].set_name_text("ABOUT");
	type_menu_[2].set_color_text_(text_object_::BROWN);
	type_menu_[2].set_Rect_(601, 348);

	type_menu_[3].set_name_text("QUIT");
	type_menu_[3].set_color_text_(text_object_::BROWN);
	type_menu_[3].set_Rect_(616, 431);

	SDL_Event events_;
	int xc;
	int yc;
	int test_menu_ = 10;

	while (true)
	{
		SDL_commonFunction::Apply_Image(g_Image, des, 0, 0);
		for (size_t j = 0; j < NUMBER_TEXT_MENU; j++)
		{
			type_menu_[j].show_text_on_screen(font, des);
		}
		while (SDL_PollEvent(&events_))
		{
			switch (events_.type)
			{
			case SDL_QUIT:
				return 3;
				break;
			case SDL_MOUSEMOTION:
				xc = events_.motion.x;
				yc = events_.motion.y;
				for (size_t k = 0; k < NUMBER_TEXT_MENU; k++)
				{
					if (SDL_commonFunction::check_colision_menu(type_menu_[k].Get_Rect(), xc, yc) == true) {
						type_menu_[k].set_color_text_(text_object_::ORANGE);
						type_menu_[k].show_text_on_screen(font, des);
					}
					else {
						type_menu_[k].set_color_text_(text_object_::BROWN);
						type_menu_[k].show_text_on_screen(font, des);
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				xc = events_.button.x;
				yc = events_.button.y;
				for (size_t kj = 0; kj < NUMBER_TEXT_MENU; kj++)
				{
					if (SDL_commonFunction::check_colision_menu(type_menu_[kj].Get_Rect(), xc, yc) == true) {
						if (kj == 1||kj==2) {
							if (kj == 1) {
								// to do;
								test_menu_=Show_Tutorial_(des, font);
								if (test_menu_ == 0) {
									continue;
								}
								else if (test_menu_ == 5) {
									return 3;
								}
							}
							else if (kj == 2) {
								//to do;
								test_menu_ = About_game_(des, font);
								if (test_menu_ == 0) {
									continue;
								}
								else if (test_menu_ == 5) {
									return 3;
								}
							}
						}
						else {
							return kj;
						}
					}

				}
				break;

			case SDL_KEYUP:
				if (events_.key.keysym.sym == SDLK_ESCAPE) {
					return 3;
				}
				break;
			default:
				break;
			}

		}
		SDL_Flip(des);
	}
	return 1;
}

int menu_game_::Show_Tutorial_(SDL_Surface*des,TTF_Font*font) {
	Image_ = SDL_commonFunction::Load_Image("menu_tutorial2.png");
	const int NUMBER_TUTORIAL = 1;
	text_object_ tutorial_[NUMBER_TUTORIAL];
	
	tutorial_[0].set_color_text_(text_object_::ORANGE);
	tutorial_[0].set_name_text("RETURN");
	tutorial_[0].set_Rect_(685, 192);
	SDL_Event Eventss_;
	int xc_;
	int yc_;
	while (true)
	{
		SDL_commonFunction::Apply_Image(Image_, des, 0, 0);
		for (size_t tt = 0; tt < NUMBER_TUTORIAL; tt++)
		{
			tutorial_[tt].show_text_on_screen(font, des);
		}
		while (SDL_PollEvent(&Eventss_))
		{
			switch (Eventss_.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				xc_ = Eventss_.button.x;
				yc_ = Eventss_.button.y;
				for (size_t tr = 0; tr < NUMBER_TUTORIAL; tr++)
				{
					if (SDL_commonFunction::check_colision_menu(tutorial_[tr].Get_Rect(),xc_,yc_)==true)
					{
						return tr;
					}
				}
				break;
			case SDL_MOUSEMOTION:
				xc_ = Eventss_.motion.x;
				yc_ = Eventss_.motion.y;
				for (size_t tr = 0; tr < NUMBER_TUTORIAL; tr++)
				{
					if (SDL_commonFunction::check_colision_menu(tutorial_[tr].Get_Rect(), xc_, yc_) == true)
					{
						tutorial_[tr].set_color_text_(text_object_::BROWN);
						tutorial_[tr].show_text_on_screen(font,des);
					}
					else
					{
						tutorial_[tr].set_color_text_(text_object_::ORANGE);
						tutorial_[tr].show_text_on_screen(font, des);
					}
				}
				break;

			case SDL_QUIT:
				return 5;
				break;
			default:
				break;
			}
		}
		SDL_Flip(des);
	}
	return 1;
}
int menu_game_::About_game_(SDL_Surface* des, TTF_Font* font) {
	Image_ = SDL_commonFunction::Load_Image("about.png");
	const int NUMBER_TUTORIAL = 1;
	text_object_ tutorial_[NUMBER_TUTORIAL];

	tutorial_[0].set_color_text_(text_object_::ORANGE);
	tutorial_[0].set_name_text("RETURN");
	tutorial_[0].set_Rect_(685, 192);
	SDL_Event Eventss_;
	int xc_;
	int yc_;
	while (true)
	{
		SDL_commonFunction::Apply_Image(Image_, des, 0, 0);
		for (size_t tt = 0; tt < NUMBER_TUTORIAL; tt++)
		{
			tutorial_[tt].show_text_on_screen(font, des);
		}
		while (SDL_PollEvent(&Eventss_))
		{
			switch (Eventss_.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				xc_ = Eventss_.button.x;
				yc_ = Eventss_.button.y;
				for (size_t tr = 0; tr < NUMBER_TUTORIAL; tr++)
				{
					if (SDL_commonFunction::check_colision_menu(tutorial_[tr].Get_Rect(), xc_, yc_) == true)
					{
						return tr;
					}
				}
				break;
			case SDL_MOUSEMOTION:
				xc_ = Eventss_.motion.x;
				yc_ = Eventss_.motion.y;
				for (size_t tr = 0; tr < NUMBER_TUTORIAL; tr++)
				{
					if (SDL_commonFunction::check_colision_menu(tutorial_[tr].Get_Rect(), xc_, yc_) == true)
					{
						tutorial_[tr].set_color_text_(text_object_::BROWN);
						tutorial_[tr].show_text_on_screen(font, des);
					}
					else
					{
						tutorial_[tr].set_color_text_(text_object_::ORANGE);
						tutorial_[tr].show_text_on_screen(font, des);
					}
				}
				break;

			case SDL_QUIT:
				return 5;
				break;
			default:
				break;
			}
		}
		SDL_Flip(des);
	}
	return 1;
}

int menu_game_::Game_over(SDL_Surface* des, TTF_Font* font,const int &mark,const int &time) {
	const int NUMBER_BUTTON_GAME_OVER_ = 5;
	text_object_ button_[NUMBER_BUTTON_GAME_OVER_];
	
	
	button_[0].set_name_text("PLAY AGAIN");
	button_[0].set_color_text_(text_object_::BROWN);
	button_[0].set_Rect_(479, 326);

	button_[1].set_name_text("QUIT");
	button_[1].set_color_text_(text_object_::BROWN);
	button_[1].set_Rect_(536, 419);

	string score_ = "SCORE: " + to_string(mark);
	button_[2].set_name_text(score_);
	button_[2].set_color_text_(text_object_::ORANGE);
	button_[2].set_Rect_(394, 215);

	button_[3].set_name_text("GAME OVER");
	button_[3].set_color_text_(text_object_::ORANGE);
	button_[3].set_Rect_(483, 144);

	string time_="TIME: " + to_string(time);
	button_[4].set_name_text(time_);
	button_[4].set_color_text_(text_object_::ORANGE);
	button_[4].set_Rect_(707, 215);

	SDL_Event Event_game_over_;
	int xov_;
	int yov_;
	while (true)
	{
		for (size_t ov = 0; ov < NUMBER_BUTTON_GAME_OVER_; ov++)
		{
			button_[ov].show_text_on_screen(font, des);
		}
		while (SDL_PollEvent(&Event_game_over_))
		{
			switch (Event_game_over_.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				xov_ = Event_game_over_.button.x;
				yov_ = Event_game_over_.button.y;
				for (size_t check_ov = 0; check_ov < NUMBER_BUTTON_GAME_OVER_-3; check_ov++)
				{
					if (SDL_commonFunction::check_colision_menu(button_[check_ov].Get_Rect(), xov_, yov_) == true) {
						return check_ov;
					}
				}
				break;
			case SDL_MOUSEMOTION:
				xov_ = Event_game_over_.motion.x;
				yov_ = Event_game_over_.motion.y;
				for (size_t check_ov = 0; check_ov < NUMBER_BUTTON_GAME_OVER_ - 3; check_ov++)
				{
					if (SDL_commonFunction::check_colision_menu(button_[check_ov].Get_Rect(), xov_, yov_) == true) {
						button_[check_ov].set_color_text_(text_object_::ORANGE);
						button_[check_ov].show_text_on_screen(font, des);
					}
					else {
						button_[check_ov].set_color_text_(text_object_::BROWN);
						button_[check_ov].show_text_on_screen(font, des);
					}
				}
				break;
			case SDL_QUIT:
				return 1;
				break;
			default:
				break;
			}
		}
		SDL_Flip(des);
	}
	return 4;
}