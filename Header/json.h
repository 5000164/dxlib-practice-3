#ifndef json_h
#define json_h

#include <string>
#include "../Library/picojson.h"

namespace json {

class Json {
public:
  Json(std::string);
  void Init();

  std::string GetString(std::string);

private:
  std::string input_file;
  picojson::value v;
  std::string err;
};

}

#endif
