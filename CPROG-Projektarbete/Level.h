#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include "GameObject.h"
#include "MovingObject.h"
#include <iostream> // Debug purposes

namespace engine {

	const class LevelManager;

	const class Level {

		public:
			static Level* create(std::string, int, int);

			std::string get_name() const;

			void tick_level();
			void draw_level(SDL_Rect&, int, int) const;

			void add_object(GameObject&);
			void remove_object(GameObject&);
			void add_bg_color(SDL_Color);
			SDL_Color get_bg_color() const;
			void set_cam_follow(GameObject&);
			void update_camera(SDL_Rect&, int, int) const;

			void forward_event(const SDL_Event&);

			const std::vector<GameObject*>& get_game_objects() const;

			void print_debug() const {
				std::cout << "\tVALUE" << std::endl;
				for (auto it = this->game_objects.begin(); it != this->game_objects.end(); ++it) {
					std::cout << "\t" << *it << std::endl;
				}
				std::cout << std::endl;
			}

			void set_level_manager(LevelManager*);
			LevelManager& get_level_manager() const;

			~Level();

		protected:
			Level(std::string, int, int);

		private:
			std::string name;
			SDL_Color bg_color;
			const int LEVEL_WIDTH;
			const int LEVEL_HEIGHT;

			GameObject* camera_follow;
			std::vector<GameObject*> game_objects;
			std::vector<GameObject*> to_remove;

			LevelManager* level_manager;

			void internal_object_cleanup();

			Level(const Level&) = delete;
			const Level& operator=(const Level&) = delete;

	};

}

#endif