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

			void handle_collision(GameObject&);

			~Player() {}

		protected:
			Player(int x, int y, int w, int h, bool solid);
			

		private:


	};

}



#endif