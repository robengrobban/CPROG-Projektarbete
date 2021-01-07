#include "MovingPlatform.h"
#include "StaticObject.h"
#include "Player.h"
#include "LevelManager.h"

namespace demo {

	MovingPlatform* MovingPlatform::create(int x, int y, int w, int h, int x_speed, int y_speed, bool solid) {
		return new MovingPlatform(x, y, w, h, x_speed, y_speed, solid);
	}

	MovingPlatform::MovingPlatform(int x, int y, int w, int h, int x_speed, int y_speed, bool solid)
		: MovingObject(x, y, w, h, solid), m_speed_x(x_speed), m_speed_y(y_speed) {
	}

	void MovingPlatform::tick() {

		this->calculate_movement();

		this->default_collision_executor();
		

		this->do_movement();
		this->levelbounds_coll();
	}

	void MovingPlatform::calculate_movement() {
		velocity_x = m_speed_x;
		velocity_y = m_speed_y;
	}

	bool MovingPlatform::levelbounds_coll() {
		bool coll = false;
		if (this->get_left() < 0 || this->get_right() > 1600) {
			m_speed_x = -m_speed_x;
			coll = true;
		}
		if (this->get_top() < 0 || this->get_bottom() > 960) {
			m_speed_y = -m_speed_y;
			coll = true;
		}
		return coll;
	}

	void MovingPlatform::on_collision(GameObject& obj) {
		if (Player* p = dynamic_cast<Player*>(&obj)) {
			if (p->get_bottom() <= this->get_top()) {
				p->rect_add_x(m_speed_x);
				p->rect_add_y(m_speed_y);
			}
		}
		if (obj.is_solid()) {
			if (obj.get_bottom() == this->get_bottom() && obj.get_right() < this->get_right()) {
				m_speed_x = -m_speed_x;
			}
			else if (obj.get_bottom() == this->get_bottom() && obj.get_left() > this->get_left()) {
				m_speed_x = -m_speed_x;
			}
			else if (obj.get_right() == this->get_right() && obj.get_top() > this->get_top()) {
				m_speed_y = -m_speed_y;
			}
			else if (obj.get_right() == this->get_right() && obj.get_bottom() < this->get_bottom()) {
				m_speed_y = -m_speed_y;
			}
		}
	}

}