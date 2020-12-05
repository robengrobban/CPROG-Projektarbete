#ifndef CONTROLLABLE_OBJECT_H
#define CONTROLLABLE_OBJECT_H
#include "GameObject.h"

namespace engine {

	class ControllableObject : public GameObject {

	public:
		static ControllableObject* create(int x, int y, int w, int h);

		void tick();
		void draw() const;

		~ControllableObject();

	protected:
		ControllableObject(int x, int y, int w, int h);

	private:

		ControllableObject(const ControllableObject&) = delete; // For the time being
		const ControllableObject& operator=(const ControllableObject&) = delete; // For the time being

	};

}

#endif