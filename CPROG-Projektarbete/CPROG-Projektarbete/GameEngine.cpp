#include "GameEngine.h"

#define FPS 60;

namespace URMengine {

	GameEngine::GameEngine() {

	}

	GameEngine::~GameEngine() {

	}

	void GameEngine::run() {
		bool running = true;

		const int tick_interval = 1000 / FPS;
		Uint32 next_tick;
		int delay;

		do {
			next_tick = SDL_GetTicks() + tick_interval;





			delay = next_tick - SDL_GetTicks();
			if ( delay > 0 ) {
				SDL_Delay(delay);
			}
		} while (running);

	}

}
