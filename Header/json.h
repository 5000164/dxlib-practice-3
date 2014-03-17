#ifndef json_h
#define json_h

#include <string>
#include <fstream>
#include "../Library/picojson.h"

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

#endif
