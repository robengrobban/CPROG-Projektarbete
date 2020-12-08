#include <SDL.h>
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

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

		virtual ~GameObject() {}

	protected:
		GameObject(int x, int y, int w, int h);
		SDL_Rect rect;
	private:
		bool solid; //For the time being

		GameObject(const GameObject&) = delete; // For the time being
		const GameObject& operator=(const GameObject&) = delete; // For the time being

	};


}

#endif