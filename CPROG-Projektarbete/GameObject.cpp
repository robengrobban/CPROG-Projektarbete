#include "GameObject.h"

namespace engine {

	GameObject::GameObject(int x, int y, int w, int h) :rect{ x,y,w,h }
	{

	}
	// caused by destructor 
	//Severity	Code	Description	Project	File	Line	Suppression State
	//Error	C2084	function 'engine::GameObject::~GameObject(void)' already has a body	CPROG - Projektarbete	C : \Users\Max\source\repos\robengrobban\CPROG - Projektarbete\CPROG - Projektarbete\GameObject.cpp	10

	GameObject::~GameObject()
	{
	}


}

