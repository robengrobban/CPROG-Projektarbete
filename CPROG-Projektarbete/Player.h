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

			void set_camera(SDL_Rect*);
			void move_camera();
			void tick();

			void mouse_down(const SDL_Event&);
			void mouse_up(const SDL_Event&);
			void key_down(const SDL_Event&);
			void key_up(const SDL_Event&);

			void decide_anim();

			void accelerate(int);
			void decelerate(int vel);
			void on_collision(GameObject&);

			void die();

			~Player() {}

		protected:
			Player(int x, int y, int w, int h, bool solid);
			

		private:
			SDL_Rect* camera;
			int screen_w;
			int screen_h;
			bool moving;
			const int MAX_MOV_SPEED;
			int movement_speed;
			bool on_ground;
			void calculate_movement();
			void jump();

	};

}

#endif