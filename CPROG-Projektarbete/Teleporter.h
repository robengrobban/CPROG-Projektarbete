#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "StaticObject.h"
#include "Player.h"

namespace demo {

	const class Teleporter : public engine::StaticObject {
		public:
			static Teleporter* create(int x, int y, int w, int h, int n);

			void on_collision(GameObject&);

			~Teleporter() {};

		protected:
			Teleporter(int x, int y, int w, int h, int n);

		private:
			int next_level;

			Teleporter(const Teleporter&) = delete;
			const Teleporter& operator=(const Teleporter&) = delete;

	};

}

#endif