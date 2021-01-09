#include "GameManager.h"
#include "SystemRenderer.h"

#define FPS 60;

namespace engine {

	GameManager::GameManager(int width, int height) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height), camera{ 0, 0, width, height } {
		this->level_manager = LevelManager::create();
	}

	GameManager::~GameManager() {
		delete this->level_manager;
	}

	LevelManager& GameManager::get_level_manager() {
		return *this->level_manager;
	}
	
	void GameManager::set_level_manager(LevelManager& new_manager) {
		delete this->level_manager;
		this->level_manager = &new_manager;
	}

	void GameManager::change_level(int level) {
		this->level_manager->change_level(level);
	}

	/// <summary>
	/// Starts the game loop.
	/// </summary>
	void GameManager::run() {
		bool running = true;

		const int tick_interval = 1000 / FPS;
		Uint32 next_tick;
		int delay;
		do {
			next_tick = SDL_GetTicks() + tick_interval;

			// Read events
			SDL_Event event;
			while ( SDL_PollEvent(&event) ) {
				switch (event.type) {
					case SDL_QUIT:
						running = false;
						break;
					default:
						this->level_manager->forward_event(event);
				}
			}

			// Tick every Game Object
			this->level_manager->tick_current_level();

			// Draw frame
			SDL_Color bgc = this->level_manager->get_bg_color();
			SDL_SetRenderDrawColor(sys_ren.get_ren(), bgc.r, bgc.g, bgc.b, 255);
			SDL_RenderClear(sys_ren.get_ren());
			this->level_manager->draw_current_level(camera, SCREEN_WIDTH, SCREEN_HEIGHT);

			// Present frame
			SDL_RenderPresent(sys_ren.get_ren());

			// Calculate delay to cap frame rate
			delay = next_tick - SDL_GetTicks();
			if ( delay > 0 ) {
				SDL_Delay(delay);
			}
		} while (running);
	}
}
