#include "JsonParser.h"
#include "Teleporter.h"
#include "MovingPlatform.h"
#include "Enemy.h"
using namespace engine;

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
		file.close();

		JObject project = JObject(json_string);
		std::vector<JObject> j_levels = project.get_array("Levels");
		std::vector<Level*>* levels = new std::vector<Level*>();

		for (JObject j_level : j_levels)
		{
			Level* level = Level::create(j_level["Name"]);
			std::string color = j_level["BackgroundColor"];
			if (color[0] == '#')
			{
				uint8_t r = std::strtoul(color.substr(3, 2).c_str(), 0, 16);
				uint8_t g = std::strtoul(color.substr(5, 2).c_str(), 0, 16);
				uint8_t b = std::strtoul(color.substr(7, 2).c_str(), 0, 16);
				level->add_bg_color(SDL_Color{ r,g,b });
			}
			else level->add_bg_color(SDL_Color{ 0,0,0 });
			for (JObject game_obj : j_level.get_array("Levels")) {

				GameObject* obj = get_obj(game_obj);
				
				if (obj != nullptr)
				{
					std::string id = game_obj["SpriteID"];
					std::vector<JObject> paths = project.get_array("Paths");
					std::string path = paths[0][id];
					obj->add_sprite(1, 100, path);

					level->add_object(*obj);
				}
			}
			levels->push_back(level);
		}
		return levels;
	}

	GameObject* JsonParser::get_obj(JObject& game_obj)
	{
		switch (stoi(game_obj["Type"]))
		{
		case 0:
			return StaticObject::create(
				stoi(game_obj["X"]),
				stoi(game_obj["Y"]),
				stoi(game_obj["W"]),
				stoi(game_obj["H"]),
				std::string(game_obj["Solid"]) == "true" ? true : false,
				stoi(game_obj["Elasticity"])
			);
		case 1:
			return demo::Teleporter::create(
				stoi(game_obj["X"]),
				stoi(game_obj["Y"]),
				stoi(game_obj["W"]),
				stoi(game_obj["H"]),
				stoi(game_obj["LevelTo"])
			);
		case 2:
			return demo::MovingPlatform::create(
				stoi(game_obj["X"]),
				stoi(game_obj["Y"]),
				stoi(game_obj["W"]),
				stoi(game_obj["H"]),
				stoi(game_obj["SpeedR"]),
				stoi(game_obj["SpeedU"])
			);
		case 3:
			return demo::Enemy::create(
				stoi(game_obj["X"]),
				stoi(game_obj["Y"]),
				stoi(game_obj["W"]),
				stoi(game_obj["H"]),
				stoi(game_obj["LevelTo"])
			);
		default: return nullptr;
		}
	}
}
