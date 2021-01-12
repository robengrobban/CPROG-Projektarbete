#include "Enemy.h"
#include "StaticObject.h"
#include "Player.h"
#include "LevelManager.h"

namespace demo {

	Enemy* Enemy::create(int x, int y, int w, int h, bool solid) {
		return new Enemy(x, y, w, h, solid);
	}

	Enemy::Enemy(int x, int y, int w, int h, bool solid)
		: MovingObject(x, y, w, h, solid), movement_speed(3) {
		//set_image_path("c:/images/gubbe.bmp");
	}

	void Enemy::tick() {

		this->calculate_movement();

		this->default_collision_executor();

		this->do_movement();

	}

	void Enemy::calculate_movement() {
		velocity_x = movement_speed;
	}

	void Enemy::on_collision(GameObject& obj) {
		
		if ( Player* p = dynamic_cast<Player*>(&obj) ) {
			if ( p->get_bottom() <= this->get_top() ) {
				this->get_level().get_level_manager().get_current_level().remove_object(*this);
			}
			else {
				p->die();
			}
		}
		else if (obj.is_solid()) {
			if (obj.get_bottom() == this->get_bottom() && obj.get_right() < this->get_right()) {
				movement_speed = 3;
			}
			else if (obj.get_bottom() == this->get_bottom() && obj.get_left() > this->get_left()) {
				movement_speed = -3;
			}
		}
	}

}
