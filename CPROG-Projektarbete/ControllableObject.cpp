#include "ControllableObject.h"

namespace engine {

	ControllableObject* ControllableObject::create(int x, int y, int w, int h) {
		return new ControllableObject(x, y, w, h);
	}

	void ControllableObject::tick() {

	}

	void ControllableObject::draw() const {

	}

	ControllableObject::ControllableObject(int x, int y, int w, int h) :GameObject(x, y, w, h) {

	}

	ControllableObject::~ControllableObject() {

	}


}

