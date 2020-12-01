#ifndef LEVEL_H
#define LEVEL_H

namespace engine {

	class Level {

		public:
			static Level* create();

			~Level();

		protected:
			Level();

		private:


			Level(const Level&) = delete; // For the time being
			const Level& operator=(const Level&) = delete; // For the time being

	};

}

#endif