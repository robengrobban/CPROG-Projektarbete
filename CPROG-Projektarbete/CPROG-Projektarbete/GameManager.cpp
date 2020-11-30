#include "GameManager.h"

#define FPS 60;

namespace engine {

	GameManager::GameManager() {

	}

	GameManager::~GameManager() {

	}

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
				}
			}




			delay = next_tick - SDL_GetTicks();
			if ( delay > 0 ) {
				SDL_Delay(delay);
			}
		} while (running);

	}

}
