#include "json.h"
#include <string>
#include <fstream>
#include "picojson.h"

Json::Json(std::string input_file_name)
{
	this->input_file_name = input_file_name;
}

std::string Json::GetString(std::string key)
{
	std::string path = input_file_name;
	std::ifstream file;
	file.open(path.c_str());

	if (file.fail()) {
	}

	std::istreambuf_iterator<char> first(file);
	std::istreambuf_iterator<char> last;
	std::string json_str(first, last);

	picojson::value json;
	std::string err;
	picojson::parse(json, json_str.begin(), json_str.end(), &err);

	picojson::object &o = json.get<picojson::object>();

	std::string string = o[key].get<std::string>();

	return string;
}

picojson::array Json::GetArray(std::string key)
{
	std::string path = input_file_name;
	std::ifstream file;
	file.open(path.c_str());

	if (file.fail()) {
	}

	std::istreambuf_iterator<char> first(file);
	std::istreambuf_iterator<char> last;
	std::string json_str(first, last);

	picojson::value json;
	std::string err;
	picojson::parse(json, json_str.begin(), json_str.end(), &err);

	picojson::object &o = json.get<picojson::object>();

	picojson::array &array = o[key].get<picojson::array>();

	return array;
}
