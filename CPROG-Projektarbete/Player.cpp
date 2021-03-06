#include "Player.h"
#include "LevelManager.h"

namespace demo {

	Player* Player::create(int x, int y, int w, int h, bool solid) {
		return new Player(x, y, w, h, solid);
	}
	int Player::lives = 5;
	Player::Player(int x, int y, int w, int h, bool solid)
		: MovingObject(x, y, w, h, solid), on_ground(false), moving(false), MAX_MOV_SPEED(8), movement_speed(0), prev_dir(1) {
		
	}

	void Player::tick() {

		this->decide_anim();
		this->calculate_movement();
		this->check_within_level();
		this->default_collision_executor();
		this->check_fall_oob();
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
		if (lives > 0) {
			lives--;
			velocity_x = 0;
			velocity_y = 0;
			reset_pos();
		}
		else
			this->get_level().get_level_manager().get_current_level().remove_object(*this);
	}

	void Player::decide_anim() {
		const Uint8* keys = SDL_GetKeyboardState(NULL);
		if (!keys[SDL_SCANCODE_D] && !keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_D] && keys[SDL_SCANCODE_A]) {
			moving = false;
			if (prev_dir > 0)
				set_animation(0);
			else set_animation(1);
		}
		else if (keys[SDL_SCANCODE_D]) {
			moving = true;
			movement_speed = 1;
			set_animation(3);
		}
		else if (keys[SDL_SCANCODE_A]) {
			moving = true;
			movement_speed = -1;
			set_animation(2);
		}
		if (!this->on_ground) {
			if (prev_dir > 0)
				set_animation(4);
			else
				set_animation(5);
		}
	}

	void Player::mouse_down(const SDL_Event& event) {}
	void Player::mouse_up(const SDL_Event& event) {}
	
	void Player::key_down(const SDL_Event& event) {

		int key_num = event.key.keysym.sym;
		if ( key_num == 97 ) { // A
			prev_dir = -1;
		}
		if ( key_num == 100 ) { // D
			prev_dir = 1;
		}
		if (key_num == SDLK_SPACE) {
			jump();
		}
		decide_anim();
	}

	void Player::key_up(const SDL_Event& event) {}

	bool Player::check_within_level() {
		if (this->get_right() > get_level().get_width() || this->get_left() < 0)
		{
			int moveX = this->get_right() + 20 > get_level().get_width() ? -1 : 1;
			this->velocity_x = 0;
			while (this->get_right() > get_level().get_width() || this->get_left() < 0) {
				this->rect_add_x(moveX);
			}
			return true;
		}
		return false;
	}

	void Player::check_fall_oob() {
		if (this->get_top() > get_level().get_height())
			die();
	}

	void Player::on_collision(GameObject& obj) {
		if (velocity_y == 0 && engine::col_man.collides_down(*this, obj)) {
			on_ground = true;
		}
	}
}


