#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include "GameObject.h"
#include <iostream> // Debug purposes

namespace engine {

	class Level {

		public:
			static Level* create(std::string);

			std::string get_name() const;

			void tick_level();
			void draw_level() const;

			void add_object(GameObject&);
			void remove_object(GameObject&);

			void print_debug() const {
				std::cout << "\tVALUE\n";
				for (auto itr = this->game_objects.begin(); itr != this->game_objects.end(); ++itr) {
					std::cout << "\t" << *itr << '\n';
				}
			}

			~Level();

		protected:
			Level(std::string);

		private:
			std::vector<GameObject*> game_objects;
			std::vector<GameObject*> to_remove;
			std::string name;

			void internal_object_cleanup();

			Level(const Level&) = delete; // For the time being
			const Level& operator=(const Level&) = delete; // For the time being

	};

}

#endif