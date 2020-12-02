#include "Level.h"

namespace engine {

	Level* Level::create() {
		return new Level();
	}

	Level::Level() : game_objects() {

	}

	void Level::tick_level() {
		// TODO: Tick every object

		this->internal_object_cleanup();
	}

	void Level::draw_level() {

	}

	void Level::add_object(GameObject& object) {
		this->game_objects.push_back(&object);
	}

	void Level::remove_object(GameObject& object) {
		this->to_remove.push_back(&object);
	}

	Level::~Level() {

		std::vector<GameObject*>::iterator it = this->game_objects.begin();
		while (it != this->game_objects.end() ) {
			delete *it;
			++it;
		}
		this->game_objects.clear();

	}

	void Level::internal_object_cleanup() {

		std::vector<GameObject*>::iterator it = this->to_remove.begin();
		while (it != this->to_remove.end()) {

			std::vector<GameObject*>::iterator it_internal = this->game_objects.begin();
			while (it_internal != this->game_objects.end()) {
				if (it_internal == it) {
					
					delete* it_internal;
					it_internal = game_objects.erase(it_internal);

				}
				else {
					++it_internal;
				}
			}

			++it;

		}

		it = this->to_remove.begin();
		while (it != this->to_remove.end()) {
			
			delete* it;

		}
		this->to_remove.clear();

	}

}

