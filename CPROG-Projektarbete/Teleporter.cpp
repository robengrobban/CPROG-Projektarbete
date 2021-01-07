#include "Teleporter.h"
#include "LevelManager.h"

namespace demo {

	Teleporter* Teleporter::create(int x, int y, int w, int h, int n) {
		return new Teleporter(x, y, w, h, n);
	}

	Teleporter::Teleporter(int x, int y, int w, int h, int n) : StaticObject(x, y, w,h, true, 0), next_level(n){}

	void Teleporter::on_collision(GameObject& other) { 
		if ( Player* p = dynamic_cast<Player*>(&other) ) {
			this->get_level().get_level_manager().change_level(next_level);
		}
	}

}