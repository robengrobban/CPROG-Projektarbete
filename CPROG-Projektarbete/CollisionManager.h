#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include "GameObject.h"


namespace engine {
	class CollisionManager {
	public:
		void handle_next_collision(GameObject&, std::vector<GameObject*>&) const;
		bool collides_x(GameObject&, GameObject&, int) const;
		bool collides_y(GameObject&, GameObject&, int) const;
		bool within_level(GameObject&, int, int) const;
	private:
		bool collides(int, int, int, int, int, int, int, int) const;
		bool next_tick_collides(GameObject&, GameObject&) const;
	};
	extern CollisionManager col_man;
}
#endif
