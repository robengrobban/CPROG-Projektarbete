#include "GameObject.h"
#include <SDL_image.h>
#include "SystemRenderer.h"
namespace engine {

	GameObject::GameObject(int x, int y, int w, int h, bool solid) :dstRect{ x,y,w,h }, srcRect{ 0,0,w,h }, solid(solid), level(nullptr), image_path("c:/images/test-image.png")
	{
		textureImage = IMG_LoadTexture(sys_ren.get_ren(), image_path.c_str());

	}

	const int GameObject::get_left() const { return dstRect.x; }
	const int GameObject::get_right() const { return dstRect.x + dstRect.w; }
	const int GameObject::get_top() const { return dstRect.y; }
	const int GameObject::get_bottom() const { return dstRect.y + dstRect.h; }

	void GameObject::rect_add_x(int x) {
		dstRect.x += x;
	}
	void GameObject::rect_add_y(int y) {
		dstRect.y += y;
	}

	void GameObject::set_image_path(std::string path)
	{
		image_path = path;
		textureImage = IMG_LoadTexture(sys_ren.get_ren(), image_path.c_str());

	}

	void GameObject::addAnimation(int nFrame, int mSpeed)
	{
		animated = true;
		frame = nFrame;
		speed = mSpeed;
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / mSpeed) % nFrame);
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

