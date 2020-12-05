#include "MovingObject.h"

namespace engine {

	MovingObject* MovingObject::create(int x, int y, int w, int h) {
		return new MovingObject(x, y, w, h);
	}

	void MovingObject::tick() {

	}

	void MovingObject::draw() const {

	}

	MovingObject::MovingObject(int x, int y, int w, int h) :GameObject(x, y, w, h) {

	}

	MovingObject::~MovingObject() {

	}

}

