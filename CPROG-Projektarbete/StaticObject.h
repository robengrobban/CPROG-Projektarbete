#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "ViewableObject.h"

namespace engine {

	class StaticObject : public ViewableObject {

		public:
			static StaticObject* create();

			void tick();
			void draw() const;

			~StaticObject();

		protected:
			StaticObject();

		private:

			StaticObject(const StaticObject&) = delete; // For the time being
			const StaticObject& operator=(const StaticObject&) = delete; // For the time being

	};

}

#endif