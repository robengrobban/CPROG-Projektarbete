#include <SDL.h>
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Level.h"

namespace engine {

	class GameObject {

	public:
		virtual void mouse_down(const SDL_Event&) = 0;
		virtual void mouse_up(const SDL_Event&) = 0;
		virtual void key_down(const SDL_Event&) = 0;
		virtual void key_up(const SDL_Event&) = 0;

		virtual void tick() = 0;
		virtual void draw() const = 0;

		const SDL_Rect& get_rect() const { return rect; }
		const bool is_solid() const { return solid; } //For the time being, should return if objects should stop when colliding.

		//Boundarys for the object
		const int get_left() const;
		const int get_right() const;
		const int get_top() const;
		const int get_bottom() const;

		//Boundarys after next tick.
		virtual const int get_next_left() const = 0;
		virtual const int get_next_right() const = 0;
		virtual const int get_next_top() const = 0;
		virtual const int get_next_bottom() const = 0;

		virtual void handle_collision(GameObject&) = 0;

		void rect_add_x(int);
		void rect_add_y(int);

		virtual ~GameObject() {}

	protected:
		GameObject(int x, int y, int w, int h, Level* my_level, bool solid);
		
	private:
		Level* my_level;

		bool solid; //For the time being
		SDL_Rect rect;

		GameObject(const GameObject&) = delete; // For the time being
		const GameObject& operator=(const GameObject&) = delete; // For the time being

	};


}

#endif