#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <vector>
#include <fstream>
#include <string>
#include "Level.h"
#include "JObject.h"
#include "StaticObject.h"

namespace engine {
	class JsonParser
	{
	public:
		std::vector<Level*>* load_levels(std::string path);
		GameObject* get_obj(JObject&);
	};
}
#endif