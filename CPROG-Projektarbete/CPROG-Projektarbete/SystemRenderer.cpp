#include "SystemRenderer.h"

namespace engine {

	SystemRenderer::SystemRenderer() {

	}

	SystemRenderer::~SystemRenderer() {

	}

	SDL_Renderer* SystemRenderer::get_ren() const {
		return this->sdl_ren;
	}

	SystemRenderer sys_ren;
}
