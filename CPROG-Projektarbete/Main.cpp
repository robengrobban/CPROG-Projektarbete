#include "GameManager.h"
#include "SystemRenderer.h"
#include "LevelManager.h"
#include "Level.h"
#include "GameObject.h"
#include "StaticObject.h"
#include "MovingObject.h"
#include "Player.h"
#include "JsonParser.h"

using namespace std;
using namespace engine;
using namespace demo;

//Declarations, to not have to scroll down to Main for setup methods to work.
void autoSetup(LevelManager*);
void manualSetup(LevelManager*);


int main(int argc, char** argv) {

	GameManager* game_manager = new GameManager();
	LevelManager* lm = &game_manager->get_level_manager();
	autoSetup(lm);

	game_manager->run();
	delete game_manager;
	return 0;
}





//Temporary method for testing setup with loading level from json.
void autoSetup(LevelManager* lm)
{
	GameObject* player = Player::create(0, 0, 64, 128);
	player->set_gravity(1);
	player->set_image_path("c:/CPROG-Assets/images/mario_sheet.png");
	player->addAnimation(3, 100);

	JsonParser* parser = new JsonParser();
	vector<Level*>* levels(parser->load_levels("C:/CPROG-Assets/project.json"));
	delete(parser);
	for (Level* level : *levels) {
		lm->add_level(*level);
	}

	Level* l1 = levels->at(0);
	l1->add_object(*player);

	l1->print_debug();
	l1->tick_level();
	l1->print_debug();
}

//Temporary method for testing setup with manually created levels and objects.
void manualSetup(LevelManager* lm) {
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

	go7->set_image_path("c:/images/donkey.png");
	go8->set_image_path("c:/images/mario_sheet.png");
	go8->addAnimation(3, 100);
	go8->removeAnimation();

	GameObject* player = Player::create(0, 0, 64, 128);
	player->set_gravity(1);
	player->set_image_path("c:/CPROG-Assets/images/mario_sheet.png");
	player->addAnimation(3, 100);

	GameObject* player2 = Player::create(400, 462, 64, 128);
	player2->set_gravity(1);
	player2->set_image_path("c:/CPROG-Assets/images/mario_sheet.png");
	player2->addAnimation(3, 100);

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

	//Ground
	for (int i = 0; i < 1280; i += 50) {
		l1->add_object(*StaticObject::create(i, 590, 50, 50));
	}

	//Bouncepad
	l1->add_object(*StaticObject::create(550, 540, 50, 50, true, 80));
	l1->add_object(*StaticObject::create(600, 540, 50, 50, true, 80));

	l1->add_object(*player2);

	l1->print_debug();

	l1->remove_object(*go1);
	l1->remove_object(*go2);

	l1->print_debug();

	l1->add_object(*player);

	l1->print_debug();

	l1->tick_level();

	l1->print_debug();
}