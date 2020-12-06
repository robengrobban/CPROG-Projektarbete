#include "StaticObject.h"
#include <SDL_image.h>

namespace engine {

	StaticObject* StaticObject::create(int x, int y, int w, int h) {
		return new StaticObject(x, y, w, h);
	}

	void StaticObject::tick() {

	}

	void StaticObject::draw() const
	{
		SDL_RenderCopy(sys_ren.get_ren(), testImage, NULL, &getRect());


	}

	StaticObject::StaticObject(int x, int y, int w, int h) :GameObject(x, y, w, h)
	{


		testImage = IMG_LoadTexture(sys_ren.get_ren(), "c:/images/test-image.png");


	}

	StaticObject::~StaticObject()
	{
		SDL_DestroyTexture(testImage);

	}

}

