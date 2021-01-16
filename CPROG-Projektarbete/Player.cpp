#include "Player.h"
#include "LevelManager.h"

namespace demo {

	Player* Player::create(int x, int y, int w, int h, bool solid) {
		return new Player(x, y, w, h, solid);
	}

	Player::Player(int x, int y, int w, int h, bool solid)
		: MovingObject(x, y, w, h, solid), on_ground(false), moving(false), MAX_MOV_SPEED(8), movement_speed(0) {
	}

	void Player::tick() {
		this->calculate_movement();
		this->default_collision_executor();
		this->check_within_level();
		this->do_movement();
	}

	void Player::calculate_movement() {
		if (movement_speed != 0)
		{
			if (moving)
				accelerate(movement_speed);
			else if (on_ground && !moving)
				decelerate(movement_speed);
		}
	}

	void Player::accelerate(int vel) {
		if (abs(velocity_x + vel) <= MAX_MOV_SPEED)
			velocity_x += vel;
		else if (abs(velocity_x + vel) > MAX_MOV_SPEED)
			velocity_x = velocity_x < 0 ? -MAX_MOV_SPEED : MAX_MOV_SPEED;
	}

	void Player::decelerate(int vel) {
		if (abs(velocity_x - vel) < abs(velocity_x) && velocity_x * vel > 0) {
			if (abs(velocity_x - vel) > 0)
				velocity_x -= vel;
			else velocity_x = 0;
		}
		else if (velocity_x * vel < 0)
			velocity_x = 0;
	}

	void Player::jump()
	{
		if (on_ground) {
			velocity_y = -18;
			on_ground = false;
		}
	}

	void Player::die() {
		this->get_level().get_level_manager().get_current_level().remove_object(*this);
	}

	void Player::decide_anim() {
		const Uint8* keys = SDL_GetKeyboardState(NULL);
		if (!keys[SDL_SCANCODE_D] && !keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_D] && keys[SDL_SCANCODE_A]) {
			moving = false;
			set_animation(0);
		}
		else if (keys[SDL_SCANCODE_D]) {
			moving = true;
			movement_speed = 1;
			set_animation(2);
		}
		else if (keys[SDL_SCANCODE_A]) {
			moving = true;
			movement_speed = -1;
			set_animation(1);
		}
	}

	void Player::mouse_down(const SDL_Event& event) {}
	void Player::mouse_up(const SDL_Event& event) {}
	
	void Player::key_down(const SDL_Event& event) {
		const Uint8* keys = SDL_GetKeyboardState(NULL);
		int key_num = event.key.keysym.sym;
		if ( key_num == 119 ) { // W
		}
		if ( key_num == 115 ) { // S
		}
		if ( key_num == 97 ) { // A
		}
		if ( key_num == 100 ) { // D
		}
		if (key_num == SDLK_SPACE) {
			jump();
		}
		decide_anim();
	}

	void Player::key_up(const SDL_Event& event) {
		//int key_num = event.key.keysym.sym;
		//if (key_num == 119) { // W
		//	force_up = 0;
		//}
		//if (key_num == 115) { // S
		//	force_down = 0;
		//}
		//if (key_num == 97) { // A
		//	force_left = 0;
		//}
		//if (key_num == 100) { // D
		//	force_right = 0;
		//}
		decide_anim();
	}

	bool Player::check_within_level() {
		if (this->get_right() > get_level().get_width() || this->get_left() < 0)
		{
			int moveX = this->velocity_x > 0 ? -1 : 1;
			this->velocity_x = 0;
			while (this->get_right() > get_level().get_width() || this->get_left() < 0) {
				this->rect_add_x(moveX);
			}
			return true;
		}
		return false;
	}

	void Player::on_collision(GameObject& obj) {
		if (velocity_y == 0 && engine::col_man.collides_down(*this, obj)) {
			on_ground = true;
		}
	}
}


