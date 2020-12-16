#ifndef SPRITE_H
#define SPRITE_H

#include "GameObject.h"
#include "StaticObject.h"

namespace engine 
{

	class Sprite
	{

		public:
			static Sprite* create();

			void draw() const;

			~Sprite();

		protected:
			Sprite();

		private:
			Sprite(const Sprite&) = delete; // For the time being
			const Sprite& operator=(const Sprite&) = delete; // For the time being

	};

}


#endif