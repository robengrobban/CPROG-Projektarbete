#include <vector>
#include "ControllableObject.h"
#include "ViewableObject.h"
#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H
namespace engine {
	class CollisionManager {
	public:
		bool next_tick_collides(std::vector<ViewableObject*>&, ControllableObject&);
	private:
	};
}
#endif
