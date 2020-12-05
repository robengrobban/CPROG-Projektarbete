#include "Level.h"

namespace engine {

	Level* Level::create(std::string name) {
		return new Level(name);
	}

	Level::Level(std::string n) : game_objects(), to_remove(), name(n) {

	}

	std::string Level::get_name() const {
		return this->name;
	}

	void Level::tick_level() {
		for (GameObject* object : this->game_objects) {
			object->tick();
		}

		this->internal_object_cleanup();
	}

	void Level::draw_level() const {
		for (GameObject* object : this->game_objects) {
			object->draw();
		}
	}

	void Level::add_object(GameObject& object) {
		this->game_objects.push_back(&object);
	}

	void Level::remove_object(GameObject& object) {
		this->to_remove.push_back(&object);
	}

	Level::~Level() {

		for (GameObject* object : this->game_objects) {
			delete object;
		}
		this->game_objects.clear();

	}

	void Level::internal_object_cleanup() {

		for (GameObject* object : this->to_remove) {

			std::vector<GameObject*>::iterator it = this->game_objects.begin();
			while (it != this->game_objects.end()) {

				if (*it == object) {
					delete* it;
					it = this->game_objects.erase(it);
				}
				else {
					++it;
				}

			}

		}
		this->to_remove.clear();

	}

}

