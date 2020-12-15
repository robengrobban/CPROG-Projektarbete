#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "GameObject.h"
#include "CollisionManager.h"


namespace engine {

	class MovingObject : public GameObject {

		public:

			//static MovingObject* create(int x, int y, int w, int h, bool solid = true);

			virtual void tick() {};
			void draw() const;

			virtual void mouse_down(const SDL_Event&) {};
			virtual void mouse_up(const SDL_Event&) {};
			virtual void key_down(const SDL_Event&) {};
			virtual void key_up(const SDL_Event&) {};

			const int get_next_left() const;
			const int get_next_right() const;
			const int get_next_top() const;
			const int get_next_bottom() const;

			virtual void handle_collision(GameObject&) {};
			void resolve_phys_collision(GameObject&, CollisionManager&);

			virtual ~MovingObject();

		protected:
			MovingObject(int x, int y, int w, int h, bool solid);
			
			void do_movement();
			
			int velocity_x;
			int velocity_y;

		private:
			MovingObject(const MovingObject&) = delete; // For the time being
			const MovingObject& operator=(const MovingObject&) = delete; // For the time being
			SDL_Texture* textureImage;
			
	};

}
#endif