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

		this->levelbounds_coll();
		this->default_collision_executor();
		this->move_cargo();
		this->calculate_movement();
		
		this->do_movement();
	}

	void MovingPlatform::calculate_movement() {
		velocity_x = m_speed_x;
		velocity_y = m_speed_y;
	}

	void MovingPlatform::move_cargo()
	{
		if (cargo != nullptr && engine::col_man.touching(*this, *cargo)) {
			if (Player* p = dynamic_cast<Player*>(cargo)) {
				if (p->can_move(m_speed_x, m_speed_y, *this))
				{
					if (p->get_bottom() <= this->get_top()) {
						p->rect_add_x(m_speed_x);
						p->rect_add_y(m_speed_y);
					}
				}
				else {
					if (engine::col_man.collides_y(*cargo, *this, 1) || engine::col_man.collides_y(*cargo, *this, -1))
						m_speed_y = -m_speed_y;
					else 
						m_speed_x = -m_speed_x;
				}
			}
		}
	}

	bool MovingPlatform::levelbounds_coll() {
		bool coll = false;
		if (this->get_left() < 0 || this->get_right() > 1600) {
			m_speed_x = abs(m_speed_x);
			coll = true;
		}
		else if (this->get_left() < 0 || this->get_right() > 1600) {
			m_speed_x = -(abs(m_speed_x));
			coll = true;
		}
		if (this->get_top() < 0) {
			m_speed_y = abs(m_speed_y);
			coll = true;
		}
		else if (this->get_bottom() > 960) {
			m_speed_y = -(abs(m_speed_y));
			coll = true;
		}
		return coll;
	}

	void MovingPlatform::on_collision(GameObject& obj) {
		if (Player* p = dynamic_cast<Player*>(&obj)) {
			cargo = &obj;
		}
		else if (obj.is_solid()) {
			if (obj.get_right() < this->get_right()) {
				m_speed_x = (abs(m_speed_x));
			}
			else if (obj.get_left() > this->get_left()) {
				m_speed_x = -(abs(m_speed_x));
			}
			if (obj.get_top() > this->get_top()) {
				m_speed_y = -(abs(m_speed_y));
			}
			else if (obj.get_bottom() < this->get_bottom()) {
				m_speed_y = (abs(m_speed_y));
			}
		}
	}
}