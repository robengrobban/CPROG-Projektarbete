#include "SystemRenderer.h"

namespace URMengine {

	SystemRenderer::SystemRenderer() {

	}

	SystemRenderer::~SystemRenderer() {

	}

	SDL_Renderer* SystemRenderer::get_ren() const {
		return this->sdl_ren;
	}

	SystemRenderer sys_ren;
}
