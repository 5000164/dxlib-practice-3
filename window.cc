#include "window.h"
#include "dx_lib.h"

Window::Window()
{
	background_color[0] = 30;
	background_color[1] = 30;
	background_color[2] = 30;
	SetBackgroundColor(background_color[0], background_color[1], background_color[2]);
}
