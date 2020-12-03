#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

namespace engine {

	class GameObject {

		public:

			virtual void tick() = 0;

			virtual ~GameObject() {}

		protected:
			GameObject();

		private:

			GameObject(const GameObject&) = delete; // For the time being
			const GameObject& operator=(const GameObject&) = delete; // For the time being

	};


}

#endif