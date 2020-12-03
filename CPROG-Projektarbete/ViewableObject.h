#ifndef VIEWABLE_OBJECT_H
#define VIEWABLE_OBJECT_H
#include "GameObject.h"

namespace engine {

	class ViewableObject : public GameObject {

		public:

			virtual void draw() const = 0;

			virtual ~ViewableObject() {}

		protected:
			ViewableObject();

		private:

			ViewableObject(const ViewableObject&) = delete; // For the time being
			const ViewableObject& operator=(const ViewableObject&) = delete; // For the time being

	};

}

#endif