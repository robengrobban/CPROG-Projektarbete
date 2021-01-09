#include "Level.h"

namespace engine {

	Level* Level::create(std::string name, int w, int h) {
		return new Level(name, w, h);
	}

	Level::Level(std::string n, int w, int h) : LEVEL_WIDTH(w), LEVEL_HEIGHT(h), game_objects(), to_remove(), name(n) {

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

	void Level::draw_level(SDL_Rect camera) const {
		for ( GameObject* object : this->game_objects ) {
			object->draw(camera);
		}
	}

	void Level::add_object(GameObject& object) {
		object.assign_level(*this);
		this->game_objects.push_back(&object);
	}

	void Level::remove_object(GameObject& object) {
		this->to_remove.push_back(&object);
	}

	void Level::add_bg_color(SDL_Color color)
	{
		bg_color = color;
	}

	SDL_Color Level::get_bg_color() const
	{
		return bg_color;
	}

	void Level::forward_event(const SDL_Event& event) {
		for ( GameObject* object : this->game_objects ) {
			if ( MovingObject* target = dynamic_cast<MovingObject*>(object) ) {
				switch ( event.type ) {
					case SDL_MOUSEBUTTONDOWN:
						target->mouse_down(event);
						break;
					case SDL_MOUSEBUTTONUP:
						target->mouse_up(event);
						break;
					case SDL_KEYDOWN:
						target->key_down(event);
						break;
					case SDL_KEYUP:
						target->key_up(event);
						break;
				}
			}
		}
	}

	const std::vector<GameObject*>& Level::get_game_objects() const {
		return this->game_objects;
	}

	Level::~Level() {

		for ( GameObject* object : this->game_objects ) {
			delete object;
		}
		this->game_objects.clear();

	}

	void Level::set_level_manager(LevelManager* manager) {
		this->level_manager = manager;
	}

	LevelManager& Level::get_level_manager() const {
		return *(this->level_manager);
	}

	void Level::internal_object_cleanup() {

		for (GameObject* object : this->to_remove) {
			
			std::vector<GameObject*>::iterator it = this->game_objects.begin();
			while ( it != this->game_objects.end() ) {

				if ( *it == object ) {
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

