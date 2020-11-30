#include "GameManager.h"
#include "SystemRenderer.h"

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


			// Draw frame
			SDL_SetRenderDrawColor(sys_ren.get_ren(), 0, 0, 0, 255);
			SDL_RenderClear(sys_ren.get_ren());
			// ...

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
