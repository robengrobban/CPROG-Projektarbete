#include "MovingObject.h"
#include <SDL_image.h>
#include "SystemRenderer.h"
#include "Level.h"


namespace engine {

	MovingObject* MovingObject::create(int x, int y, int w, int h) {
		return new MovingObject(x, y, w, h);
	}

	void MovingObject::tick() {
		if (rect.y <= 0)
		{
			//Level::remove_object(this);
			//remove
		}
		else
		{
			rect.y--;

		}
	}

	void MovingObject::draw() const {
		SDL_RenderCopy(sys_ren.get_ren(), textureImage, NULL, &getRect());


	}

	MovingObject::MovingObject(int x, int y, int w, int h) :GameObject(x, y, w, h) {
		textureImage = IMG_LoadTexture(sys_ren.get_ren(), "c:/images/test-image.png");


	}

	MovingObject::~MovingObject() {

	}

}

