#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "MovingObject.h"
#include "Level.h"
#include "CollisionManager.h"
#include <iostream>

namespace demo {

	class Player : public engine::MovingObject {

		public:
			static Player* create(int x, int y, int w, int h, bool solid = true);

			void tick();

			void mouse_down(const SDL_Event&);
			void mouse_up(const SDL_Event&);
			void key_down(const SDL_Event&);
			void key_up(const SDL_Event&);

			void decide_anim();

			void accelerate(int);
			void decelerate(int vel);
			bool check_within_level();
			void check_fall_oob();
			void on_collision(GameObject&);

			void die();

			~Player() {}

		protected:
			Player(int x, int y, int w, int h, bool solid);
			

		private:
			int lives;
			bool moving;
			const int MAX_MOV_SPEED;
			int movement_speed;
			bool on_ground;
			void calculate_movement();
			void jump();

			Player(const Player&) = delete;
			const Player& operator=(const Player&) = delete;

	};

}

#endif