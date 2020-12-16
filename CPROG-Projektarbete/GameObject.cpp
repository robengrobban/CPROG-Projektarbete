#include "GameObject.h"

namespace engine {

	GameObject::GameObject(int x, int y, int w, int h, bool solid) :rect{ x,y,w,h }, solid(solid)
	{

	}

	const int GameObject::get_left() const { return rect.x; }
	const int GameObject::get_right() const { return rect.x + rect.w; }
	const int GameObject::get_top() const { return rect.y; }
	const int GameObject::get_bottom() const { return rect.y + rect.h; }

	void GameObject::rect_add_x(int x) {
		rect.x += x;
	}
	void GameObject::rect_add_y(int y) {
		rect.y += y;
	}

	const Level& GameObject::get_level() const {
		return *this->level;
	}

	void GameObject::assign_level(Level& level) {
		this->level = &level;
	}

	GameObject::~GameObject() {
		delete this->sprite;
	}

}

