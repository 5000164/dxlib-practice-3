#include "selector.h"
#include "dx_lib_wrapper.h"

Selector::Selector()
{
}

void Selector::Draw(int position_1_x, int position_1_y, int position_2_x, int position_2_y, int position_3_x, int position_3_y, int r, int g, int b)
{
	color_dx = GetColor(r, g, b);
	DrawTriangle(position_1_x, position_1_y, position_2_x, position_2_y, position_3_x, position_3_y, color_dx, FALSE);
}
