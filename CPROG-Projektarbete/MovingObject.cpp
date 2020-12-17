#include "MovingObject.h"


namespace engine {



	void MovingObject::draw() {


		if (animated) {
			addAnimation(frame, speed);
			SDL_RenderCopy(sys_ren.get_ren(), textureImage, &srcRect, &dstRect);
		}
		else {
			SDL_RenderCopy(sys_ren.get_ren(), textureImage, NULL, &dstRect);

		}

	}



	MovingObject::MovingObject(int x, int y, int w, int h, bool solid)
		: GameObject(x, y, w, h, solid), velocity_x(0), velocity_y(0) {

	}


	const int MovingObject::get_next_left() const { return get_left() + velocity_x; }
	const int MovingObject::get_next_right() const { return get_right() + velocity_x; }
	const int MovingObject::get_next_top() const { return get_top() + velocity_y; }
	const int MovingObject::get_next_bottom() const { return get_bottom() + velocity_y; }

	//Stops this object next to the object it collides with.
	void MovingObject::resolve_phys_collision(GameObject& obj, const CollisionManager& m) {

		//Only if both are solid, might be put in the "handle_collision" method implemented in derived objects instead.
		if (this->is_solid() && obj.is_solid()) {
			bool collision = false;

			if (this->velocity_x >= this->velocity_y) {
				bool tmp1 = check_collides_x(obj, m);
				bool tmp2 = check_collides_y(obj, m);
				collision = tmp1 || tmp2;
			}
			else {
				bool tmp1 = check_collides_y(obj, m);
				bool tmp2 = check_collides_x(obj, m);
				collision = tmp1 || tmp2;
			}

			if (collision) {
				this->handle_collision(*this);
				obj.handle_collision(*this);
			}
		}
	}

	bool MovingObject::check_collides_x(GameObject& obj, const CollisionManager& m) {
		if (m.collides_x(*this, obj, this->velocity_x))
		{
			int moveX = this->velocity_x > 0 ? 1 : -1;
			this->velocity_x = 0;
			while (!m.collides_x(*this, obj, moveX))
				this->rect_add_x(moveX);
			return true;
		}
		return false;
	}
	bool MovingObject::check_collides_y(GameObject& obj, const CollisionManager& m) {
		if (m.collides_y(*this, obj, this->velocity_y))
		{
			int moveY = this->velocity_y > 0 ? 1 : -1;
			this->velocity_y = 0;
			while (!m.collides_y(*this, obj, moveY))
				this->rect_add_y(moveY);
			return true;
		}
		return false;
	}

	void MovingObject::do_movement() {
		this->rect_add_x(velocity_x);
		this->rect_add_y(velocity_y);
	}

	void MovingObject::standard_collision() {
		const Level& level = get_level();
		std::vector<GameObject*> objects = level.get_game_objects();

		for (GameObject* obj : objects) {
			if (obj != this) {
				this->resolve_phys_collision(*obj, engine::col_man);
			}
		}
	}

	MovingObject::~MovingObject() {

	}
}

