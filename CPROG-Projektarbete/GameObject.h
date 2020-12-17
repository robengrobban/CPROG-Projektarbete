#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include<string>

namespace engine {

	class Level; // Forward declaration

	class GameObject {

	public:
		virtual void mouse_down(const SDL_Event&) {};
		virtual void mouse_up(const SDL_Event&) {};
		virtual void key_down(const SDL_Event&) {};
		virtual void key_up(const SDL_Event&) {};

		virtual void tick() = 0;
		virtual void draw() = 0;

		//const SDL_Rect& get_rect() const { return dstRect; }
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

		void set_image_path(std::string);

		void addAnimation(int nFrame, int mSpeed);
		void removeAnimation() { animated = false; }

		//std::string& get_image_path() const { return image_path; }
	   // SDL_Texture* get_texture_Image() const { return textureImage; }


		const Level& get_level();
		void assign_level(Level&);

		~GameObject() {
			SDL_DestroyTexture(textureImage);
		}
	protected:
		GameObject(int x, int y, int w, int h, bool solid);
		SDL_Rect dstRect;
		SDL_Rect srcRect;
		bool animated = false;
		int frame = 1;
		int speed = 1000;
		std::string  image_path;
		SDL_Texture* textureImage;
	private:
		bool solid; //For the time being


		Level* level;

		GameObject(const GameObject&) = delete; // For the time being
		const GameObject& operator=(const GameObject&) = delete; // For the time being


	};


}

#endif