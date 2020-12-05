#include "StaticObject.h"

namespace engine {

	StaticObject* StaticObject::create(int x, int y, int w, int h) {
		return new StaticObject(x, y, w, h);
	}

	void StaticObject::tick() {

	}

	void StaticObject::draw() const {

	}

	StaticObject::StaticObject(int x, int y, int w, int h) :GameObject(x, y, w, h) {

	}

	StaticObject::~StaticObject() {

	}

}

