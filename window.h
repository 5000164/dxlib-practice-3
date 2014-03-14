#ifndef window_h
#define window_h

#include <string>

class Window {
	int background_color[3];
	int font_size;
public:
	Window();
	Window(int, int, int);
	Window(int, int, int, std::string, int);
};

#endif
