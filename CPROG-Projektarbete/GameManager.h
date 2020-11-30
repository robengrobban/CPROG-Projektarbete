#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <SDL.h>

namespace engine {

	/// <summary>
	/// Runs the game loop.
	/// </summary>
	class GameManager {
		public:
			GameManager();
			~GameManager();

			void run();

		protected:

		private:
			
	};

}
#endif