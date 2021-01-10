#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include "Level.h"
#include <map>
#include <iostream> // Debug purposes

namespace engine {

	const class LevelManager {

		public:
			static LevelManager* create();

			void tick_current_level();
			void draw_current_level(SDL_Rect& camera, int, int) const;

			int add_level(Level&);
			void assign_level(int, Level&);
			void change_level(int);

			void remove_level(int);
			void remove_level(Level&);
			
			Level& get_current_level() const;
			int get_current_level_number() const;
			SDL_Color get_bg_color() const;

			void forward_event(const SDL_Event&);

			void print_debug() const {
				std::cout << "\tKEY\tELEMENT" << std::endl;
				for (auto it = this->levels.begin(); it != this->levels.end(); ++it) {
					std::cout << "\t" << it->first << '\t' << it->second << std::endl;
				}
				std::cout << std::endl;
			}

			~LevelManager();

		protected:
			LevelManager();

		private:
			std::map<int, Level*> levels;
			int current_level;

			void rearrange_levels();

			LevelManager(const LevelManager&) = delete;
			const LevelManager& operator=(const LevelManager&) = delete;

	};

}

#endif