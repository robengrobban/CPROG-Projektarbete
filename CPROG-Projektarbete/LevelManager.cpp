#include "LevelManager.h"
#include <stdexcept>
#include <string>

namespace engine {

	LevelManager* LevelManager::create() {
		return new LevelManager();
	}

	LevelManager::LevelManager() : levels(), current_level(0) {

	}

	void LevelManager::tick_current_level() {
		// Tick the current level
		this->levels.at(this->current_level)->draw_level();
	}

	void LevelManager::draw_current_level() {
		// Draw the current level
		this->levels.at(this->current_level)->draw_level();
	}

	void LevelManager::add_level(Level& level) {
		// Get next level number
		int next_level = this->levels.size();

		// Add new level
		this->levels.insert({next_level, &level});
	}

	void LevelManager::assign_level(int number, Level& level) {
		// Control so that the level number exists
		if ( number >= this->levels.size() ) {
			throw std::out_of_range(std::string("Level access out of range, there is no index " + number));
		}
		else {
			// Get old level
			Level* old_level = this->levels[number];
			
			// Insert new level
			this->levels[number] = &level;

			// Delete old level
			delete old_level;
		}
	}

	void LevelManager::change_level(int number) {
		// Control so that the level number exists
		if ( number >= this->levels.size() ) {
			throw std::out_of_range(std::string("Level access out of range, there is no index " + number));
		}
		else {
			this->current_level = number;
			// TODO : Change the level on screen aswell, not only the number
		}
	}

	/*int LevelManager::get_level_number(Level& level) {
		
		std::map<int, Level*>::iterator it = this->levels.begin();
		int map_index = -1;

		while (it != this->levels.end()) {
			if ( *(it->second) == level ) { // There is no == operator at the moment
				map_index = it->first;
			}
			++it;
		}

		return map_index;

	}*/

	void LevelManager::remove_level(int number) {
		// Control so that the level number exists
		if (number >= this->levels.size()) {
			throw std::out_of_range(std::string("Level access out of range, there is no index " + number));
		}
		else {
			// Get level
			Level* level = this->levels[number];
			
			// Remove entry
			this->levels.erase(number);

			// Delete
			delete level;

			// Rearrange level numbers
			this->rearrange_levels();
		}
	}

	Level& LevelManager::get_current_level() const {
		return *(this->levels.at(this->current_level));
	}

	int LevelManager::get_current_level_number() const {
		return this->current_level;
	}

	LevelManager::~LevelManager() {
		// Delete map
		std::map<int, Level*>::iterator it = this->levels.begin();
		while (it != this->levels.end()) {
			delete it->second;
			++it;
		}
		this->levels.clear();
	}

	void LevelManager::rearrange_levels() {
		// Go through every level and rearrange level number
		this->current_level--;
		int new_level_number = 0;

		std::map<int, Level*>::iterator it = this->levels.begin();
		while (it != this->levels.end()) {

			// Check if rearrange is necesary
			if ( it->first != new_level_number ) {

				// Get the level
				Level* level = it->second;

				// Erase its position
				it = this->levels.erase(it);

				// Put it back in with new key
				this->levels.insert({ new_level_number, level });

			}
			else {
				++it;
			}

			++new_level_number;			
		}
	}

}
