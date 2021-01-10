#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include "GameObject.h"


namespace engine {
	const class CollisionManager {
	public:
		void handle_next_collision(GameObject&, std::vector<GameObject*>&) const;
		bool collides_down(const GameObject&, const GameObject&) const;
		bool collides_x(const GameObject&, const GameObject&, const int) const;
		bool collides_y(const GameObject&, const GameObject&, const int) const;
		bool within_level(GameObject&, int, int) const;
		CollisionManager() = default;

	private:
		bool collides(const int, const int, const int, const int, const int, const int, const int, const int) const;
		bool next_tick_collides(GameObject&, GameObject&) const;

		CollisionManager(const CollisionManager&) = delete;
		const CollisionManager operator=(const CollisionManager&) = delete;
	};
	const extern CollisionManager col_man;
}
#endif
