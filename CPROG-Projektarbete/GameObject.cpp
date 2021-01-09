
#include "GameObject.h"
#include <iostream>
#include <SDL_image.h>
#include "SystemRenderer.h"
#include "Cleanup.h"


namespace engine {

	GameObject::GameObject(int x, int y, int w, int h, bool solid) : dst_rect{ x,y,w,h }, sprites(), curr_anim(0), solid(solid), level(nullptr)
	{
	}

	void GameObject::draw(){
		sprites[curr_anim]->draw(dst_rect);
	}

	const int GameObject::get_left() const { return dst_rect.x; }
	const int GameObject::get_right() const { return dst_rect.x + dst_rect.w; }
	const int GameObject::get_top() const { return dst_rect.y; }
	const int GameObject::get_bottom() const { return dst_rect.y + dst_rect.h; }

	void GameObject::rect_add_x(int x) {
		dst_rect.x += x;
	}
	void GameObject::rect_add_y(int y) {
		dst_rect.y += y;
	}

	void GameObject::add_sprite( int num_frames, int anim_speed, std::string path){
		sprites.push_back(Sprite::create(dst_rect.w, dst_rect.h, num_frames, anim_speed, path));
	}

	void GameObject::set_animation(int sprite_no) {
		curr_anim = sprite_no;
	}

	void GameObject::animate() {
		sprites[curr_anim]->animate();
	}

	const Level& GameObject::get_level() const {
		return *this->level;
	}

	void GameObject::assign_level(Level& level) {
		this->level = &level;
	}

	GameObject::~GameObject() {
		for (Sprite* s : this->sprites) {
			delete s;
		}
		this->sprites.clear();
	}
}

