#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <SDL.h>
#include "LevelManager.h"

namespace engine {

	class GameManager {
		public:
			GameManager();
			~GameManager();

			void run();

			LevelManager& get_level_manager();
			void set_level_manager(LevelManager&);
			void change_level(int);

		protected:

		private:
			LevelManager* level_manager;
			
	};

}
#endif