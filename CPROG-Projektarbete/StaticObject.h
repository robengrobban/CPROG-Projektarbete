#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "GameObject.h"

namespace engine {

	class StaticObject : public GameObject {

	public:
		static StaticObject* create(int x, int y, int w, int h);

		virtual void tick() {}; // Empty, child object will fill it, = 0 later when we have a prototype
		void draw() const;

		// Does not care about key or mouse events
		void mouse_down(const SDL_Event&) {};
		void mouse_up(const SDL_Event&) {};
		void key_down(const SDL_Event&) {};
		void key_up(const SDL_Event&) {};

		~StaticObject();

	protected:
		StaticObject(int x, int y, int w, int h);

	private:

		StaticObject(const StaticObject&) = delete; // For the time being
		const StaticObject& operator=(const StaticObject&) = delete; // For the time being

		SDL_Texture* textureImage;
	};

}

#endif