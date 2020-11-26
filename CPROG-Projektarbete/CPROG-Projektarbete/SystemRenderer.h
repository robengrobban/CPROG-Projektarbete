#ifndef RENDERER_H
#define RENDERER_H
#include <SDL.h>

namespace URMengine {
	class SystemRenderer {
		public:
			SystemRenderer();
			~SystemRenderer();

			SDL_Renderer* get_ren() const;

		protected:

		private:
			SDL_Window* sdl_win;
			SDL_Renderer* sdl_ren;

	};

	extern SystemRenderer sys_ren;
}



#endif