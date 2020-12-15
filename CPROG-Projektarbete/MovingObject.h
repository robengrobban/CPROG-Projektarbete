#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "GameObject.h"
#include <iostream> // Debug purposes
#include "CollisionManager.h"


namespace engine {

	class MovingObject : public GameObject {

		public:

			static MovingObject* create(int x, int y, int w, int h, Level* my_level, bool solid = true);

			virtual void tick() {}; // Empty, child object will fill it, = 0 later when we have a prototype
			void draw() const;

			virtual void mouse_down(const SDL_Event&) {};
			virtual void mouse_up(const SDL_Event&) {};
			virtual void key_down(const SDL_Event&) {};
			virtual void key_up(const SDL_Event&) {};

			const int get_next_left() const;
			const int get_next_right() const;
			const int get_next_top() const;
			const int get_next_bottom() const;

			virtual void handle_collision(GameObject&) {}; // Empty, child object will fill it, = 0 later when we have a prototype
			void resolve_phys_collision(GameObject&, CollisionManager&);

			~MovingObject();

		protected:
			MovingObject(int x, int y, int w, int h, Level* my_level, bool solid);

		private:

			MovingObject(const MovingObject&) = delete; // For the time being
			const MovingObject& operator=(const MovingObject&) = delete; // For the time being
			SDL_Texture* textureImage;
			int velocity_x;
			int velocity_y;
	};

}
#endif