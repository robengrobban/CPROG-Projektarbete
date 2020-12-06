#ifndef RENDERER_H
#define RENDERER_H
#include <SDL.h>
#include <SDL_mixer.h>

namespace engine {
	class SystemRenderer {
		public:
			SystemRenderer();
			~SystemRenderer();

			SDL_Renderer* get_ren() const;
			void play_music(const char music_path[]);
			void pause_music();
			void resume_music();

		protected:

		private:
			SDL_Window* sdl_win;
			SDL_Renderer* sdl_ren;
			Mix_Chunk* music;
	};

	extern SystemRenderer sys_ren;
}
#endif