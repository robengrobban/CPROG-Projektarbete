#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include <vector>
#include "GameObject.h"


namespace engine {
	class CollisionManager {
	public:
		void handle_next_collision(GameObject&, std::vector<GameObject*>&);
		bool collides_x(GameObject&, GameObject&, int);
		bool collides_y(GameObject&, GameObject&, int);
		bool within_level(GameObject&, int, int);
	private:
		bool collides(int, int, int, int, int, int, int, int);
		bool next_tick_collides(GameObject&, GameObject&);
	};

	extern CollisionManager col_man;
}
#endif
