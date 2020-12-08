#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include <vector>
#include "GameObject.h"


namespace engine {
	class CollisionManager {
	public:
		void handle_next_collision(GameObject&, std::vector<GameObject*>&);
		bool collides(int, int, int, int, int, int, int, int);
		bool collides_x(GameObject&, GameObject&, int);
		bool collides_y(GameObject&, GameObject&, int);
	private:
		bool within_level(GameObject&, int, int);
		bool next_tick_collides(GameObject&, GameObject&);
	};
}
#endif
