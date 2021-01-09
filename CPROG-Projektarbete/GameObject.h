#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include<string>
#include <vector>
#include "Sprite.h"

namespace engine {

	class Level; // Forward declaration
	class Sprite; // Forward declaration

	class GameObject {

	public:
		virtual void mouse_down(const SDL_Event&) {};
		virtual void mouse_up(const SDL_Event&) {};
		virtual void key_down(const SDL_Event&) {};
		virtual void key_up(const SDL_Event&) {};

		virtual void tick() = 0;
		void draw(SDL_Rect&);

		const bool is_solid() const { return solid; }

		//Boundarys for the object
		const int get_left() const;
		const int get_right() const;
		const int get_top() const;
		const int get_bottom() const;
		const int get_width() const;
		const int get_height() const;

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

		void add_sprite(int num_frames, int anim_speed, std::string path);

		void set_animation(int);
		void animate();

	   // SDL_Texture* get_texture_Image() const { return textureImage; }

		const Level& get_level() const;
		void assign_level(Level&);

		virtual ~GameObject();
			
		
	protected:
		GameObject(int x, int y, int w, int h, bool solid);
		SDL_Rect dst_rect;
	private:
		bool solid;

		Level* level;
		int curr_anim;
		std::vector<Sprite*> sprites;

		GameObject(const GameObject&) = delete; // For the time being
		const GameObject& operator=(const GameObject&) = delete; // For the time being
	};
}

#endif