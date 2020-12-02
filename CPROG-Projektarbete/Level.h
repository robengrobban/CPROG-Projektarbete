#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "GameObject.h"

namespace engine {

	class Level {

		public:
			static Level* create();

			void tick_level();
			void draw_level();

			void add_object(GameObject&);
			void remove_object(GameObject&);

			~Level();

		protected:
			Level();

		private:
			std::vector<GameObject*> game_objects;
			std::vector<GameObject*> to_remove;

			void internal_object_cleanup();

			Level(const Level&) = delete; // For the time being
			const Level& operator=(const Level&) = delete; // For the time being

	};

}

#endif