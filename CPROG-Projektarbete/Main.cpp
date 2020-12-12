#include "GameManager.h"
#include "SystemRenderer.h"
#include "LevelManager.h"
#include "Level.h"
#include "GameObject.h"
#include "StaticObject.h"
#include "MovingObject.h"

using namespace std;
using namespace engine;

int main(int argc, char** argv) {
	GameManager* game_manager = new GameManager();

	LevelManager* lm = &game_manager->get_level_manager();

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

	GameObject* go1 = StaticObject::create(100, 150, 200, 200);
	GameObject* go2 = StaticObject::create(300, 150, 200, 200);
	GameObject* go3 = StaticObject::create(500, 150, 200, 200);
	GameObject* go4 = StaticObject::create(700, 150, 200, 200);
	GameObject* go5 = StaticObject::create(900, 150, 200, 200);

	GameObject* go6 = MovingObject::create(10, 150, 200, 200,0,0);
	GameObject* go7 = MovingObject::create(10, 300, 200, 200,0,0,true);


	l1->add_object(*go1);
	l1->add_object(*go2);
	l1->add_object(*go3);
	l1->add_object(*go4);
	l1->add_object(*go5);
	
	l1->add_object(*go6);
	l1->add_object(*go7);


	l1->print_debug();

	l1->remove_object(*go1);
	l1->remove_object(*go2);

	l1->print_debug();

	l1->tick_level();

	l1->print_debug();


	
	game_manager->run();
	delete game_manager;
	return 0;
}