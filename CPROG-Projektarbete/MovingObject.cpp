#include "MovingObject.h"
#include <SDL_image.h>
#include "SystemRenderer.h"


namespace engine {

	MovingObject* MovingObject::create(int x, int y, int w, int h, int velocity_x, int velocity_y, bool solid) {
		return new MovingObject(x, y, w, h, velocity_x, velocity_y, solid);
	}

	void MovingObject::draw() const {
		SDL_RenderCopy(sys_ren.get_ren(), textureImage, NULL, &get_rect());

	}

	MovingObject::MovingObject(int x, int y, int w, int h, int velocity_x, int velocity_y, bool solid) 
		:GameObject(x, y, w, h, solid), velocity_x(velocity_x), velocity_y(velocity_y) {

		textureImage = IMG_LoadTexture(sys_ren.get_ren(), "c:/images/test-image.png");

	}


	const int MovingObject::get_next_left() const { return get_left() + velocity_x; }
	const int MovingObject::get_next_right() const { return get_right() + velocity_x; }
	const int MovingObject::get_next_top() const { return get_top() + velocity_y; }
	const int MovingObject::get_next_bottom() const { return get_bottom() + velocity_y; }

	//Stops this object next to the object it collides with.
	void MovingObject::resolve_phys_collision(GameObject& obj, CollisionManager& m) {

		//Only if both are solid, might be put in the "handle_collision" method implemented in derived objects instead.
		if (this->is_solid() && obj.is_solid()) {
			if (m.collides_x(*this, obj, this->velocity_x))
			{
				int moveX = this->velocity_x > 0 ? 1 : -1;
				this->velocity_x = 0;
				while (!m.collides_x(*this, obj, moveX))
					this->rect.x += moveX;
			}
			else if (m.collides_y(*this, obj, this->velocity_x))
			{
				int moveY = this->velocity_y > 0 ? 1 : -1;
				this->velocity_y = 0;
				while (!m.collides_y(*this, obj, moveY))
					this->rect.y += moveY;
			}
		}
	}

	MovingObject::~MovingObject() {

	}
}

