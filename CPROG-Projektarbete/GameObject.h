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

		const SDL_Rect& getRect() const { return rect; }

		virtual ~GameObject() {}

	protected:
		GameObject(int x, int y, int w, int h);
		SDL_Rect rect;

	private:


		GameObject(const GameObject&) = delete; // For the time being
		const GameObject& operator=(const GameObject&) = delete; // For the time being

	};


}

#endif