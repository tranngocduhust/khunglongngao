#ifndef THREATS_OBJECT_H_
#define THREATS_OBJECT_H_
#include"base_object.h"

class threats_object_ :public base_object_ {
protected:
	int x_threats_;
	int y_threats_;
	int speed_threats_;
	bool is_move_;


public:

	threats_object_();
	~threats_object_();

	void set_speed_threats_(const int& spe) { speed_threats_ = spe; }

	void set_x_threats_(const int& x) { x_threats_ = x; }
	int get_x_vala_() { return x_threats_; }

	void set_y_threats_(const int& y) { y_threats_ = y; }
	int get_y_val() { return y_threats_; }

	void Handle_Move_Threats(const int& x_border, const int& y_border);

	void set_is_move(const bool& is_move) { is_move_ = is_move; }
	bool get_is_move() { return is_move_; }

};

#endif // !THREATS_OBJECT_H_

