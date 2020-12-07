#include <vector>
#include "MovingObject.h"

#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H
namespace engine {
	class CollisionManager {
	public:
		bool next_tick_collides(std::vector<GameObject*>&, MovingObject&);
	private:
	};
}
#endif
