#include "StaticObject.h"

#include <SDL_image.h>
#include "SystemRenderer.h"


namespace engine {

	StaticObject* StaticObject::create(int x, int y, int w, int h, bool solid) {
		return new StaticObject(x, y, w, h, solid);
	}

	void StaticObject::draw()
	{
		if (animated) {
			addAnimation(frame, speed);
			SDL_RenderCopy(sys_ren.get_ren(), textureImage, &srcRect, &dstRect);
		}
		else
		{
			SDL_RenderCopy(sys_ren.get_ren(), textureImage, NULL, &dstRect);

		}
	}

	StaticObject::StaticObject(int x, int y, int w, int h, bool solid)
		: GameObject(x, y, w, h, solid)
	{

	}

	const int StaticObject::get_next_left() const { return get_left(); }
	const int StaticObject::get_next_right() const { return get_right(); }
	const int StaticObject::get_next_top() const { return get_top(); }
	const int StaticObject::get_next_bottom() const { return get_bottom(); }

	StaticObject::~StaticObject()
	{

	}

}
