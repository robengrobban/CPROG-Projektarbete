#include "GameManager.h"
#include "SystemRenderer.h"

using namespace std;
using namespace engine;

int main(int argc, char** argv) {
	GameManager* game_manager = new GameManager();
	game_manager->run();
	delete game_manager;
	return 0;
}