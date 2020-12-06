#include <SDL.h>
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

namespace engine {

	class GameObject {

	public:
		virtual void mouseDown(const SDL_Event&) {}
		virtual void mouseUp(const SDL_Event&) {}
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}

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