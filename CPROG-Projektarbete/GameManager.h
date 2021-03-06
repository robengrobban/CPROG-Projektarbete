#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <SDL.h>
#include "LevelManager.h"

namespace engine {

	class GameManager {
		public:
			GameManager(int, int);
			~GameManager();

			void run();

			LevelManager& get_level_manager();
			void set_level_manager(LevelManager&);
			void change_level(int);
			SDL_Rect* get_camera() { return &camera; }

		protected:

		private:
			LevelManager* level_manager;
			SDL_Rect camera;

			//Screen dimension constants
			const int SCREEN_WIDTH = 640;
			const int SCREEN_HEIGHT = 480;

			GameManager(const GameManager&) = delete;
			const GameManager& operator=(const GameManager&) = delete;
	};

}
#endif