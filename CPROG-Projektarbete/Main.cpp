#include "GameManager.h"
#include "SystemRenderer.h"
#include "LevelManager.h"
#include "Level.h"
#include "GameObject.h"
#include "StaticObject.h"
#include "MovingObject.h"
#include "Player.h"

using namespace std;
using namespace engine;
using namespace demo;

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

	GameObject* go1 = StaticObject::create(50, 0, 50, 50);
	GameObject* go2 = StaticObject::create(50, 0, 50, 50);

	GameObject* go3 = StaticObject::create(50, 0, 50, 50);
	GameObject* go4 = StaticObject::create(50, 50, 50, 50);
	GameObject* go5 = StaticObject::create(50, 100, 50, 50);
	GameObject* go6 = StaticObject::create(50, 250, 50, 50);
	GameObject* go7 = StaticObject::create(100, 250, 50, 50);
	GameObject* go8 = StaticObject::create(100, 100, 50, 50);

	GameObject* player = Player::create(0, 0, 50, 50);


	l1->add_object(*go1);
	l1->add_object(*go2);
	l1->add_object(*go3);
	l1->add_object(*go4);
	l1->add_object(*go5);
	l1->add_object(*go6);
	l1->add_object(*go7);
	l1->add_object(*go8);

	l1->add_object(*StaticObject::create(0, 200, 50, 50));
	l1->add_object(*StaticObject::create(150, 250, 50, 50));
	l1->add_object(*StaticObject::create(150, 100, 50, 50));
	l1->add_object(*StaticObject::create(250, 100, 50, 50));
	l1->add_object(*StaticObject::create(250, 250, 50, 50));
	l1->add_object(*StaticObject::create(250, 150, 50, 50));
	l1->add_object(*StaticObject::create(300, 150, 50, 50));
	l1->add_object(*StaticObject::create(150, 300, 50, 50));
	l1->add_object(*StaticObject::create(150, 50, 50, 50));

	l1->add_object(*player);


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