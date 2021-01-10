#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "GameObject.h"
#include <iostream>

namespace engine {

	class StaticObject : public GameObject {

		public:
			static StaticObject* create(int x, int y, int w, int h, bool solid = true, int elasticity = 0);

			virtual void tick() {};

			const int get_next_left() const;
			const int get_next_right() const;
			const int get_next_top() const;
			const int get_next_bottom() const;

			const int get_elasticity() const;
			void set_elasticity(int);

			virtual void on_collision(GameObject&) {};

			virtual ~StaticObject();

		protected:
			StaticObject(int x, int y, int w, int h, bool solid, int elasticity);

		private:
			int elasticity;

			StaticObject(const StaticObject&) = delete;
			const StaticObject& operator=(const StaticObject&) = delete;

	};

}

#endif