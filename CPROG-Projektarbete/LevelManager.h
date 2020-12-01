#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H
#include "Level.h"
#include <map>
#include <iostream> // Debug purposes

namespace engine {

	class LevelManager {

		public:
			static LevelManager* create();

			void tick_current_level();
			void draw_current_level();

			int add_level(Level&);
			void assign_level(int, Level&);
			void change_level(int);

			//int get_level_number(Level&); // There is no == operator at the moment
			void remove_level(int);

			Level& get_current_level() const;
			int get_current_level_number() const;

			~LevelManager();

		protected:
			LevelManager();

		private:
			std::map<int, Level*> levels;
			int current_level;

			void rearrange_levels();

			LevelManager(const LevelManager&) = delete; // For the time being
			const LevelManager& operator=(const LevelManager&) = delete; // For the time being

	};

}

#endif