#include "Sprite.h"

namespace engine
{

	Sprite* Sprite::create(int w, int h, int frames, int speed, std::string path) {
		return new Sprite(w, h, frames, speed, path);
	}

	void Sprite::animate()
	{
		src_rect.x = src_rect.w * static_cast<int>((SDL_GetTicks() / speed) % num_frames);
	}

	Sprite::Sprite(int w, int h, int frames, int m_speed, std::string path) : curr_frame(0), src_rect{ 0,0,w,h } {
		num_frames = frames;
		speed = m_speed;
		texture = IMG_LoadTexture(sys_ren.get_ren(), path.c_str());
	}

	Sprite::~Sprite() {
		cleanup(texture);
	}

	void Sprite::draw(SDL_Rect& dst_rect, SDL_Rect& camera) {
		if (num_frames > 1)
			animate();
		SDL_Rect r{ dst_rect.x - camera.x, dst_rect.y - camera.y, dst_rect.w, dst_rect.h };
		SDL_RenderCopy(sys_ren.get_ren(), texture, &src_rect, &r);
	}

}
