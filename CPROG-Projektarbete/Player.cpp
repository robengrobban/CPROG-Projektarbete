#include "Player.h"

namespace demo {

	Player* Player::create(int x, int y, int w, int h, bool solid) {
		return new Player(x, y, w, h, solid);
	}

	Player::Player(int x, int y, int w, int h, bool solid)
		: MovingObject(x, y, w, h, solid) {

	}

	void Player::tick() {
		
		const engine::Level& level = get_level();
		std::vector<GameObject*> objects = level.get_game_objects();
		
		for (engine::GameObject* obj : objects) {
			if ( obj != this ) {
				this->resolve_phys_collision(*obj, engine::col_man);
			}
		}
		
		this->do_movement();

	}

	void Player::mouse_down(const SDL_Event& event) {

	}
	
	void Player::mouse_up(const SDL_Event& event) {
		
	}

	void Player::key_down(const SDL_Event& event) {
		const Uint8* keys = SDL_GetKeyboardState(NULL);
		if ( keys[SDL_SCANCODE_W] ) {
			velocity_y = -3;
		}
		if (keys[SDL_SCANCODE_S]) {
			velocity_y = 3;
		}
		if (keys[SDL_SCANCODE_A]) {
			velocity_x = -3;
		}
		if (keys[SDL_SCANCODE_D]) {
			velocity_x = 3;
		}
	}

	void Player::key_up(const SDL_Event& event) {
		velocity_x = 0;
		velocity_y = 0;
	}

	void Player::handle_collision(GameObject& obj) {
		std::cout << "Jag krockade!" << std::endl;
	};

}


