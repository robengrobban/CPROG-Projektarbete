#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>

namespace engine {

	class Level; // Forward declaration

	class GameObject {

	public:
		virtual void mouse_down(const SDL_Event&) {};
		virtual void mouse_up(const SDL_Event&) {};
		virtual void key_down(const SDL_Event&) {};
		virtual void key_up(const SDL_Event&) {};

		virtual void tick() = 0;
		virtual void draw() const = 0;

		const SDL_Rect& get_rect() const { return rect; }
		const bool is_solid() const { return solid; }

		//Boundarys for the object
		const int get_left() const;
		const int get_right() const;
		const int get_top() const;
		const int get_bottom() const;

		virtual const int get_elasticity() const { return 0; }

		virtual void set_gravity(int) {};

		//Boundarys after next tick.
		virtual const int get_next_left() const = 0;
		virtual const int get_next_right() const = 0;
		virtual const int get_next_top() const = 0;
		virtual const int get_next_bottom() const = 0;

		virtual void on_collision(GameObject&) = 0;

		void rect_add_x(int);
		void rect_add_y(int);

		const Level& get_level() const;
		void assign_level(Level&);

		virtual ~GameObject() {}

	protected:
		GameObject(int x, int y, int w, int h, bool solid);
		
	private:
		bool solid; //For the time being
		SDL_Rect rect;
		Level* level;
		Sprite* sprite;

		GameObject(const GameObject&) = delete; // For the time being
		const GameObject& operator=(const GameObject&) = delete; // For the time being

	};


}

#endif