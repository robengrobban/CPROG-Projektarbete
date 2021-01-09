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
			int get_screen_w() const { return SCREEN_W; };
			int get_screen_h() const { return SCREEN_H; };
			void play_music(const char music_path[]);
			void pause_music();
			void resume_music();

		protected:

		private:
			const int SCREEN_W;
			const int SCREEN_H;
			SDL_Window* sdl_win;
			SDL_Renderer* sdl_ren;
			Mix_Chunk* music;
	};

	extern SystemRenderer sys_ren;
}
#endif