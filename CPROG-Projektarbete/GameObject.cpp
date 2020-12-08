#include "GameObject.h"

namespace engine {

	GameObject::GameObject(int x, int y, int w, int h) :rect{ x,y,w,h }
	{

	}

	const int GameObject::get_left() const { return rect.x; }
	const int GameObject::get_right() const { return rect.x + rect.w; }
	const int GameObject::get_top() const { return rect.y; }
	const int GameObject::get_bottom() const { return rect.y + rect.h; }
}

