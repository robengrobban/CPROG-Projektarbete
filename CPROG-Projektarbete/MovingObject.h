#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "GameObject.h"


namespace engine {

	class MovingObject : public GameObject {

		public:

			static MovingObject* create(int x, int y, int w, int h);

			virtual void tick() {}; // Empty, child object will fill it, = 0 later when we have a prototype
			void draw() const;

			virtual void mouse_down(const SDL_Event&) {};
			virtual void mouse_up(const SDL_Event&) {};
			virtual void key_down(const SDL_Event&) {};
			virtual void key_up(const SDL_Event&) {};

			~MovingObject();

		protected:
			MovingObject(int x, int y, int w, int h);

		private:

			MovingObject(const MovingObject&) = delete; // For the time being
			const MovingObject& operator=(const MovingObject&) = delete; // For the time being
			SDL_Texture* textureImage;

	};

}

#endif