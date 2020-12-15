#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "GameObject.h"
#include <iostream>

namespace engine {

	class StaticObject : public GameObject {

	public:
		static StaticObject* create(int x, int y, int w, int h, bool solid = true);

		virtual void tick() {};
		void draw() const;

		const int get_next_left() const;
		const int get_next_right() const;
		const int get_next_top() const;
		const int get_next_bottom() const;

		virtual void handle_collision(GameObject&) { std::cout << "Någon krockade med Static!" << std::endl; };

		~StaticObject();

	protected:
		StaticObject(int x, int y, int w, int h, bool solid);

	private:

		StaticObject(const StaticObject&) = delete; // For the time being
		const StaticObject& operator=(const StaticObject&) = delete; // For the time being

		SDL_Texture* textureImage;
	};

}

#endif