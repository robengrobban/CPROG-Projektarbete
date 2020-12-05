#include "CollisionManager.h"

namespace engine {

	/// <summary>
	/// Checks if player will collide with a set of objects in next tick or not.
	/// </summary>
	/// <param name="objects">Objects to check collision against.</param>
	/// <param name="player">The player that can collide with the objects</param>
	/// <returns>True if any collision occured, else false.</returns>
	bool CollisionManager::next_tick_collides(std::vector<GameObject*>& objects, ControllableObject& player)
	{
		int left_a, right_a, top_a, bottom_a;

		//---------------WAITING FOR IMPLEMENTION
		/*int left_b = p.get_next_left_pos();
		int right_b = p.get_next_right_pos();
		int top_b = p.get_next_top_pos();
		int bottom_b = p.get_next_bottom_pos();*/

		for (int i = 0; i < objects.size(); i++)
		{
			//---------------WAITING FOR IMPLEMENTATION
			/*left_a = objects[i]->get_left();
			right_a = objects[i]->get_right();
			top_a = objects[i]->get_top();
			bottom_a = objects[i]->get_bottom();*/

			//---------------WAITING FOR IMPLEMENTATION
			/*if (((bottom_a < top_b) || (top_a > bottom_b) || (right_a < left_b) || (left_a > right_b)) == false)
			{
				return true;
			}*/
		}
		return false;
	}
}

