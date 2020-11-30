#ifndef CLEANUP_H
#define CLEANUP_H

#include <utility>
#include <SDL.h>
#include <SDL_mixer.h>

/*
 Recurse through the list of arguments to clean up, cleaning up
 the first one in the list each iteration.
 */
template<typename T, typename... Args>
void cleanup(T* t, Args&&... args) {
	cleanup(t);
	cleanup(std::forward<Args>(args)...);
}
/*
 * Specializations to free the passed argument in main cleanup function.
 * Checks if param is nullptr.
 */
template<>
inline void cleanup<SDL_Window>(SDL_Window* win) {
	if (!win) {
		return;
	}
	SDL_DestroyWindow(win);
}
template<>
inline void cleanup<SDL_Renderer>(SDL_Renderer* ren) {
	if (!ren) {
		return;
	}
	SDL_DestroyRenderer(ren);
}
template<>
inline void cleanup<SDL_Texture>(SDL_Texture* tex) {
	if (!tex) {
		return;
	}
	SDL_DestroyTexture(tex);
}
template<>
inline void cleanup<SDL_Surface>(SDL_Surface* surf) {
	if (!surf) {
		return;
	}
	SDL_FreeSurface(surf);
}
template<>
inline void cleanup<Mix_Chunk>(Mix_Chunk* music) {
	if (!music) {
		return;
	}
	Mix_FreeChunk(music);
}

#endif

