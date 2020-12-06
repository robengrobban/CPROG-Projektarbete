#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "GameObject.h"


namespace engine {

	class MovingObject : public GameObject {

		public:

			static MovingObject* create(int x, int y, int w, int h);

			void tick();
			void draw() const;

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