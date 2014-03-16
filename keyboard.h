#ifndef keyboard_h
#define keyboard_h

#include "dx_lib_wrapper.h"

class Keyboard {
public:
	void InputOnce();
	bool IsPressEsc();
	bool IsPressReturn();
	bool IsPressUp();
	bool IsPressDown();
};

#endif
