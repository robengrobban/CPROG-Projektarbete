#include "StaticObject.h"

#include <SDL_image.h>
#include "SystemRenderer.h"


namespace engine {

	StaticObject* StaticObject::create(int x, int y, int w, int h, bool solid,int elasticity) {
		return new StaticObject(x, y, w, h, solid, elasticity);
	}

	void StaticObject::draw()
	{
		if (animated) {
			addAnimation(frame, speed);
			SDL_RenderCopy(sys_ren.get_ren(), textureImage, &srcRect, &dstRect);
		}
		else
		{
			SDL_RenderCopy(sys_ren.get_ren(), textureImage, NULL, &dstRect);

		}
	}

	StaticObject::StaticObject(int x, int y, int w, int h, bool solid, int elasticity)
		: GameObject(x, y, w, h, solid), elasticity(elasticity)
	{

	}

	const int StaticObject::get_next_left() const { return get_left(); }
	const int StaticObject::get_next_right() const { return get_right(); }
	const int StaticObject::get_next_top() const { return get_top(); }
	const int StaticObject::get_next_bottom() const { return get_bottom(); }

	const int StaticObject::get_elasticity() const
	{
		return elasticity;
	}

	//Sets elasticity (if moving objects bounde off). 100 = bounce back at same speed, 0 = no bounce.
	void StaticObject::set_elasticity(int value)
	{
		if (elasticity < 0)
			elasticity = 0;
		else if (elasticity > 100)
			elasticity = 100;
		else
			elasticity = value;
	}

	StaticObject::~StaticObject()
	{

	}

}
