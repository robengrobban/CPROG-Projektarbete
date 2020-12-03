#include "Level.h"
#include "ViewableObject.h"

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
		for ( GameObject* object : this->game_objects ) {
			object->tick();
		}

		this->internal_object_cleanup();
	}

	void Level::draw_level() const {
		for ( GameObject* object : this->game_objects ) {
			if ( ViewableObject* viewable = dynamic_cast<ViewableObject*>(object) ) {
				viewable->draw();
			}
		}
	}

	void Level::add_object(GameObject& object) {
		this->game_objects.push_back(&object);
	}

	void Level::remove_object(GameObject& object) {
		this->to_remove.push_back(&object);
	}

	Level::~Level() {

		for ( GameObject* object : this->game_objects ) {
			delete object;
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

		for ( GameObject* object : this->to_remove ) {
			delete object;
		}
		this->to_remove.clear();

	}

}

