#include "JsonParser.h"

namespace engine {

	/// <summary>
	/// Takes a path to a Json file and returns a pointer to a vector of Level object pointers.
	/// </summary>
	/// <param name="path">Path to the Json containing project data.</param>
	/// <returns>Pointer to vector of level pointers.</returns>
	std::vector<Level*>* JsonParser::load_levels(std::string path)
	{
		std::ifstream file(path.c_str());
		std::string json_string;
		json_string.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

		JObject project = JObject(json_string);
		std::vector<JObject> j_levels = project.get_array("Levels");
		std::vector<Level*>* levels = new std::vector<Level*>();

		for (JObject j_level : j_levels)
		{
			Level* level = Level::create(j_level["Name"]);
			for (JObject sprite : j_level.get_array("Levels")) {

				GameObject* obj = StaticObject::create(
					stoi(sprite["X"]),
					stoi(sprite["Y"]),
					stoi(sprite["W"]),
					stoi(sprite["H"]),
					std::string(sprite["Solid"]) == "true" ? true : false,
					stoi(sprite["Elasticity"])
				);
				std::string id = sprite["SpriteID"];
				std::vector<JObject> paths = project.get_array("Paths");
				std::string path = paths[0][id];
				obj->set_image_path(path);

				level->add_object(*obj);
			}
			levels->push_back(level);
		}
		return levels;
	}
}
