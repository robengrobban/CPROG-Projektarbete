#ifndef CONTROLLABLE_OBJECT_H
#define CONTROLLABLE_OBJECT_H
#include "GameObject.h"

namespace engine {

	class ControllableObject : public GameObject {

		public:
			static ControllableObject* create();

			void tick();
			void draw() const;

			~ControllableObject();

		protected:
			ControllableObject();

		private:

			ControllableObject(const ControllableObject&) = delete; // For the time being
			const ControllableObject& operator=(const ControllableObject&) = delete; // For the time being

	};

}

#endif