#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "GameObject.h"
#include "CollisionManager.h"
#include <SDL_image.h>
#include "SystemRenderer.h"
#include "Level.h"
#include <string>

namespace engine {

	class MovingObject : public GameObject {

		public:

			//static MovingObject* create(int x, int y, int w, int h, bool solid = true);

			virtual void tick() {};
			void draw()  ;
		//	void set_image(std::string ) ;

			virtual void mouse_down(const SDL_Event&) {};
			virtual void mouse_up(const SDL_Event&) {};
			virtual void key_down(const SDL_Event&) {};
			virtual void key_up(const SDL_Event&) {};

			const int get_next_left() const;
			const int get_next_right() const;
			const int get_next_top() const;
			const int get_next_bottom() const;

			void set_gravity(int);

			virtual void on_collision(GameObject&) {};
			virtual void resolve_phys_collision(GameObject&, const CollisionManager&);

			virtual ~MovingObject();
			//SDL_Rect desrect; //animation test
			
		protected:
			MovingObject(int x, int y, int w, int h, bool solid);
			
			virtual void do_movement();
			virtual void calculate_movement() {};
			void default_collision_executor();
			
			int velocity_x;
			int velocity_y;

		private:
			const int MAX_GRAVITY = 30;
			int gravity;
			bool on_ground;

			bool check_collides_x(GameObject&, const CollisionManager&);
			bool check_collides_y(GameObject&, const CollisionManager&);

			MovingObject(const MovingObject&) = delete; // For the time being
			const MovingObject& operator=(const MovingObject&) = delete; // For the time being
			
	};

}
#endif