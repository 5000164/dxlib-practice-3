#ifndef json_h
#define json_h

#include <string>
#include "picojson.h"

class Json {
  std::string input_file_name;
public:
  Json(std::string);
  std::string GetString(std::string);
  picojson::array GetArray(std::string);
};

#endif
