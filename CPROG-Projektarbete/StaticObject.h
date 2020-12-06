#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "GameObject.h"

namespace engine {

	class StaticObject : public GameObject {

	public:
		static StaticObject* create(int x, int y, int w, int h);

		void tick();
		void draw() const;

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