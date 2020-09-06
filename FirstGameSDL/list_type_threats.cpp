#include"list_type_threats.h"

bool list_type_threats_::make_list_threats_() {
	threats_object_ tem_threats;
	bool test;
	test = tem_threats.Load_Image_("banghieu.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_BANG);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("cay.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_CAY);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("da.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_DA);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("thunggo.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_THUNG_GO);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("xuongrong.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_XUONG_RONG);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("xuongrong2.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_XUONG_RONG_2);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("xuongrong3.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_XUONG_RONG_3);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("cay2.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_CAY_2);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("covid1.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_COVID_1);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("covid1.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_COVID_2);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("covid2.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_COVID_3);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("hopdoi.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_HOPDOI);
	list_type_threats.push_back(tem_threats);

	test = tem_threats.Load_Image_("dacay.png");
	if (test == false) { return false; }
	tem_threats.set_Rect_y(Y0_DACAY);
	list_type_threats.push_back(tem_threats);

	return true;
}
void list_type_threats_::move_list_threats(const int& x_rand, const int& x_border, const int& y_border) {
	list_type_threats.at(x_rand).Handle_Move_Threats(x_border, y_border);
}