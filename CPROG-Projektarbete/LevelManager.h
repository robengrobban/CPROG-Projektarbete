#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H
#include "Level.h"
#include <vector>

namespace engine {

	class LevelManager {

	public:
		static LevelManager* create();

		~LevelManager();

	protected:
		LevelManager();

	private:
		std::vector<Level*> levels;
		int current_level;

		LevelManager(const LevelManager&) = delete; // For the time being
		const LevelManager& operator=(const LevelManager&) = delete; // For the time being

	};

}

#endif