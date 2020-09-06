#ifndef LIST_TYPE_THREATS_H_
#define LIST_TYPE_THREATS_H_
#include"base_object.h"
#include"threats_object.h"
#include<vector>

const int Y0_BANG = HEIGHT_SCREEN - 89 - FLASTFROM;
const int Y0_CAY = HEIGHT_SCREEN - 120 - FLASTFROM;
const int Y0_DA = HEIGHT_SCREEN - 73 - FLASTFROM;
const int Y0_THUNG_GO = HEIGHT_SCREEN - 101 - FLASTFROM;
const int Y0_XUONG_RONG = HEIGHT_SCREEN - 111 - FLASTFROM;
const int Y0_XUONG_RONG_2 = HEIGHT_SCREEN - 96 - FLASTFROM;
const int Y0_XUONG_RONG_3 = HEIGHT_SCREEN - 44 - FLASTFROM;
const int Y0_CAY_2 = HEIGHT_SCREEN - 88 - FLASTFROM;
const int Y0_COVID_1 = HEIGHT_SCREEN - 100-183 - FLASTFROM;
const int Y0_COVID_2 = HEIGHT_SCREEN - 100 -94- FLASTFROM;
const int Y0_COVID_3 = HEIGHT_SCREEN - 100 - 85 - FLASTFROM;
const int Y0_HOPDOI = HEIGHT_SCREEN - 101- FLASTFROM;
const int Y0_DACAY = HEIGHT_SCREEN - 110 - FLASTFROM;

class list_type_threats_ :public threats_object_ {
private:
	vector<threats_object_> list_type_threats;
	
public:
	enum type_threats_
	{
		XUONG_RONG = 1,
		XUONG_RONG_2,
		BANG,
		TANG_DA,
		CAY,
		HOP,
	};


	bool make_list_threats_();
	vector<threats_object_> get_list_threats_() { return list_type_threats; }

	void move_list_threats(const int& x_rand, const int& x_border, const int& y_border);
};

#endif // !LIST_TYPR_THREATS_H_

