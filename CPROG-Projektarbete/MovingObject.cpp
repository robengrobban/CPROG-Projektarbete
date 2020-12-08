#include "MovingObject.h"

namespace engine {

	MovingObject* MovingObject::create(int x, int y, int w, int h) {
		return new MovingObject(x, y, w, h);
	}

	void MovingObject::draw() const {
		SDL_RenderCopy(sys_ren.get_ren(), textureImage, NULL, &get_rect());

	}

	MovingObject::MovingObject(int x, int y, int w, int h) :GameObject(x, y, w, h) {
		textureImage = IMG_LoadTexture(sys_ren.get_ren(), "c:/images/test-image.png");

	}

	const int MovingObject::get_next_left() const { return get_left() + velocity_x; }
	const int MovingObject::get_next_right() const { return get_right() + velocity_x; }
	const int MovingObject::get_next_top() const { return get_top() + velocity_y; }
	const int MovingObject::get_next_bottom() const { return get_bottom() + velocity_y; }

	//Stops this object next to the object it collides with.
	void MovingObject::move_back(GameObject& obj, CollisionManager& m) {

		//Only if both are solid, might be put in the "handle_collision" method implemented in derived objects instead.
		if (this->is_solid() && obj.is_solid()) {
			if (m.collides_x(*this, obj, velocity_x))
			{
				int moveX = velocity_x > 0 ? 1 : -1;
				velocity_x = 0;
				while (!m.collides_x(*this, obj, moveX))
					this->rect.x += moveX;
			}
			else if (m.collides_y(*this, obj, velocity_x))
			{
				int moveY = velocity_y > 0 ? 1 : -1;
				velocity_y = 0;
				while (!m.collides_y(*this, obj, moveY))
					this->rect.y += moveY;
			}
		}
		
	}

	MovingObject::~MovingObject() {

	}
}

