#ifndef CONTROLLABLE_OBJECT_H
#define CONTROLLABLE_OBJECT_H
#include "ViewableObject.h"

namespace engine {

	class ControllableObject : public ViewableObject {

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