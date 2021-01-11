#ifndef ENEMY_H
#define ENEMY_H

#include "MovingObject.h"

namespace demo {

	class Enemy : public engine::MovingObject {
		public:
			static Enemy* create(int x, int y, int w, int h, bool solid = true);

			void tick();

			void on_collision(GameObject&);

			~Enemy() {}

		protected:
			Enemy(int x, int y, int w, int h, bool solid);

		private:
			int movement_speed;

			void calculate_movement();

			Enemy(const Enemy&) = delete;
			const Enemy operator=(const Enemy&) = delete;

	};

}

#endif