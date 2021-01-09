#include "Player.h"
#include "LevelManager.h"

namespace demo {

	Player* Player::create(int x, int y, int w, int h, bool solid) {
		return new Player(x, y, w, h, solid);
	}

	Player::Player(int x, int y, int w, int h, bool solid)
		: MovingObject(x, y, w, h, solid), on_ground(false), force_up(0), force_down(0), force_left(0), force_right(0),
		movement_speed(8) {
	}

	void Player::tick() {

		this->calculate_movement();

		this->default_collision_executor();

		this->do_movement();

	}

	void Player::calculate_movement() {
		velocity_x = force_left + force_right;
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
		if (!keys[SDL_SCANCODE_D] && !keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_D] && keys[SDL_SCANCODE_A])
			set_animation(0);
		else if (keys[SDL_SCANCODE_D])
			set_animation(2);
		else if (keys[SDL_SCANCODE_A])
			set_animation(1);
	}

	void Player::mouse_down(const SDL_Event& event) {

	}
	
	void Player::mouse_up(const SDL_Event& event) {
		
	}

	void Player::key_down(const SDL_Event& event) {
		const Uint8* keys = SDL_GetKeyboardState(NULL);
		int key_num = event.key.keysym.sym;
		if ( key_num == 119 ) { // W
			force_up = -movement_speed;
		}
		if ( key_num == 115 ) { // S
			force_down = movement_speed;
		}
		if ( key_num == 97 ) { // A
			force_left = -movement_speed;
			set_animation(1);
		}
		if ( key_num == 100 ) { // D
			force_right = movement_speed;
			set_animation(2);
		}
		if (key_num == SDLK_SPACE) {
			jump();
		}
		decide_anim();
	}

	void Player::key_up(const SDL_Event& event) {
		int key_num = event.key.keysym.sym;
		if (key_num == 119) { // W
			force_up = 0;
		}
		if (key_num == 115) { // S
			force_down = 0;
		}
		if (key_num == 97) { // A
			force_left = 0;
		}
		if (key_num == 100) { // D
			force_right = 0;
		}
		decide_anim();
	}

	void Player::on_collision(GameObject& obj) {
		if (velocity_y == 0 && engine::col_man.collides_down(*this, obj)) {
			on_ground = true;
		}
	}
}


