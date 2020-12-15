#include "LevelManager.h"
#include <stdexcept>
#include <string>
#include <iostream>

namespace engine {

	LevelManager* LevelManager::create() {
		return new LevelManager();
	}

	LevelManager::LevelManager() : levels(), current_level(0) {
		
	}

	void LevelManager::tick_current_level() {
		try {
			this->levels.at(this->current_level)->tick_level();
		}
		catch (std::out_of_range e) {
			std::cout << "Cannot tick current level, out of range: " << e.what() << std::endl;
		}
	}

	void LevelManager::draw_current_level() const {
		try {
			this->levels.at(this->current_level)->draw_level();
		}
		catch (std::out_of_range e) {
			std::cout << "Cannot draw current level, out of range: " << e.what() << std::endl;
		}
	}

	int LevelManager::add_level(Level& level) {
		int next_level = this->levels.size();
		this->levels.insert({next_level, &level});
		return next_level;
	}

	void LevelManager::assign_level(int number, Level& level) {
		if ( number >= this->levels.size() && number >= 0 ) {
			throw std::out_of_range(std::string("Level access out of range, there is no index " + number));
		}
		else {
			Level* old_level = this->levels[number];
			this->levels[number] = &level;
			delete old_level;
		}
	}

	void LevelManager::change_level(int number) {
		if (number >= this->levels.size() && number >= 0) {
			throw std::out_of_range(std::string("Level access out of range, there is no index " + number));
		}
		else {
			this->current_level = number;
		}
	}

	void LevelManager::remove_level(int number) {
		if (number >= this->levels.size()) {
			throw std::out_of_range(std::string("Level access out of range, there is no index " + number));
		}
		else {
			Level* level = this->levels[number];
			this->levels.erase(number);
			delete level;
			this->rearrange_levels();
		}
	}

	void LevelManager::remove_level(Level& level) {
		std::map<int, Level*>::iterator it = this->levels.begin();
		while (it != this->levels.end()) {

			if ( it->second == &level ) {
				it = this->levels.erase(it);
				delete &level;
			}
			else {
				++it;
			}

		}
		this->rearrange_levels();
	}

	Level& LevelManager::get_current_level() const {
		return *(this->levels.at(this->current_level));
	}

	int LevelManager::get_current_level_number() const {
		return this->current_level;
	}

	void LevelManager::forward_event(const SDL_Event& event) {
		this->get_current_level().forward_event(event);
	}

	LevelManager::~LevelManager() {
		std::map<int, Level*>::iterator it = this->levels.begin();
		while (it != this->levels.end()) {
			delete it->second;
			++it;
		}
		this->levels.clear();
	}

	void LevelManager::rearrange_levels() {
		this->current_level = 0;
		int new_level_number = 0;

		std::map<int, Level*>::iterator it = this->levels.begin();
		while (it != this->levels.end()) {

			if ( it->first != new_level_number ) {
				Level* level = it->second;
				it = this->levels.erase(it);
				this->levels.insert({ new_level_number, level });
			}
			else {
				++it;
			}

			++new_level_number;			
		}
	}

}
