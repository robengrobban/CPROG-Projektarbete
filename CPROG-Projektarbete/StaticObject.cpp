#include "StaticObject.h"

#include <SDL_image.h>
#include "SystemRenderer.h"


namespace engine {

	StaticObject* StaticObject::create(int x, int y, int w, int h, bool solid) {
		return new StaticObject(x, y, w, h, solid);
	}

	void StaticObject::draw() const
	{
		SDL_RenderCopy(sys_ren.get_ren(), textureImage, NULL, &get_rect());
	}

	StaticObject::StaticObject(int x, int y, int w, int h, bool solid) :GameObject(x, y, w, h, solid)
	{
		textureImage = IMG_LoadTexture(sys_ren.get_ren(), "c:/images/test-image.png");
	}

	const int StaticObject::get_next_left() const { return get_left(); }
	const int StaticObject::get_next_right() const { return get_right(); }
	const int StaticObject::get_next_top() const { return get_top(); }
	const int StaticObject::get_next_bottom() const { return get_bottom(); }

	StaticObject::~StaticObject()
	{
		SDL_DestroyTexture(textureImage);

	}

}
