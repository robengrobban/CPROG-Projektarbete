#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SystemRenderer.h"
#include "Cleanup.h"

namespace engine 
{
	class Sprite
	{
		public:
			static Sprite* create(int, int, int, int, std::string);
			void animate();
			void draw(SDL_Rect&, SDL_Rect&);
			~Sprite();

		protected:
			Sprite(int, int, int, int, std::string);

		private:
			bool animated;
			int speed;
			int num_frames;
			int curr_frame;
			SDL_Rect src_rect;
			SDL_Texture* texture;
			Sprite(const Sprite&) = delete; // For the time being
			const Sprite& operator=(const Sprite&) = delete; // For the time being
	};
}

#endif