#include "SystemRenderer.h"
#include <stdexcept>
#include <string>

namespace engine {

	SystemRenderer::SystemRenderer() {
		// Check for errors at initialization of SDL
		int code = SDL_Init(SDL_INIT_EVERYTHING);
		if ( code == -1 ) {
			throw std::runtime_error(std::string("Initfel: ") + SDL_GetError());
		}

		this->sdl_win = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, 0);
		if ( this->sdl_win == nullptr ) {
			throw std::runtime_error(std::string("Cannot create window: ") + SDL_GetError());
		}

		this->sdl_ren = SDL_CreateRenderer(this->sdl_win, -1, 0);
		if (this->sdl_ren == nullptr) {
			throw std::runtime_error(std::string("Cannot create renderer: ") + SDL_GetError());
		}

	}

	SystemRenderer::~SystemRenderer() {
		
		// Destroy window and renderer
		SDL_DestroyRenderer(this->sdl_ren);
		SDL_DestroyWindow(this->sdl_win);
		SDL_Quit();
	}

	SDL_Renderer* SystemRenderer::get_ren() const {
		return this->sdl_ren;
	}

	SystemRenderer sys_ren;
}
