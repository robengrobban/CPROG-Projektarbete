#include "GameManager.h"
#include "SystemRenderer.h"
#include "LevelManager.h"
#include "Level.h"
#include "GameObject.h"
#include "ViewableObject.h"
#include "StaticObject.h"
#include "MovingObject.h"
#include "ControllableObject.h"

using namespace std;
using namespace engine;

int main(int argc, char** argv) {
	// Test for Level and LevelManager
	LevelManager* lm = LevelManager::create();

	Level* l1 = Level::create("Level 1");
	Level* l2 = Level::create("Level 2");
	Level* l3 = Level::create("Level 3");
	Level* l4 = Level::create("Level 4");
	Level* l5 = Level::create("Level 5");

	lm->add_level(*l1);
	lm->add_level(*l2);
	lm->add_level(*l3);
	lm->add_level(*l4);
	lm->add_level(*l5);

	lm->print_debug();

	lm->remove_level(3);
	lm->remove_level(*l5);

	lm->print_debug();

	GameObject* go1 = StaticObject::create();
	GameObject* go2 = StaticObject::create();
	GameObject* go3 = StaticObject::create();
	GameObject* go4 = StaticObject::create();
	GameObject* go5 = StaticObject::create();

	l1->add_object(*go1);
	l1->add_object(*go2);
	l1->add_object(*go3);
	l1->add_object(*go4);
	l1->add_object(*go5);

	l1->print_debug();

	l1->remove_object(*go1);
	l1->remove_object(*go2);

	l1->print_debug();

	l1->tick_level();

	l1->print_debug();

	// End Test
	GameManager* game_manager = new GameManager();
	game_manager->run();
	delete game_manager;
	return 0;
}