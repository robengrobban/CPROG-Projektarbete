#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "ViewableObject.h"

namespace engine {

	class MovingObject {

		public:

			static MovingObject* create();

			void tick();
			void draw() const;

			~MovingObject();

		protected:
			MovingObject();

		private:

			MovingObject(const MovingObject&) = delete; // For the time being
			const MovingObject& operator=(const MovingObject&) = delete; // For the time being

	};

}

#endif