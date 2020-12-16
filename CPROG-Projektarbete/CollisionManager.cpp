#include "CollisionManager.h"

namespace engine {

	/// <summary>
	/// Checks if player will collide with a set of objects in next tick or not.
	/// </summary>
	/// <param name="objects">Objects to check collision against.</param>
	/// <param name="player">The player that can collide with the objects</param>
	/// <returns>True if any collision occured, else false.</returns>
	void CollisionManager::handle_next_collision(GameObject& obj, std::vector<GameObject*>& objects) const
	{
		for (int i = 0; i < objects.size(); i++)
		{
			if (next_tick_collides(obj, *objects[i]))
			{
				obj.on_collision(*objects[i]);
			}
		}
	}

	/// <summary>
	/// Checks if an object is within the level.
	/// </summary>
	/// <param name="o">Object to check.</param>
	/// <param name="width">Level width.</param>
	/// <param name="height">Level height</param>
	/// <returns>True if within, else false.</returns>
	bool CollisionManager::within_level(GameObject& o, int width, int height) const
	{
		return (o.get_left() >= 0 && o.get_right() <= width && o.get_top() >= 0 && o.get_bottom() <= height);
	}

	/// <summary>
	/// Checks if there is any collision between two sets of boundarys.
	/// </summary>
	/// <returns>True if collision, else false.</returns>
	bool CollisionManager::collides(const int a_left, const int a_right, const int a_top, const int a_bottom,
		const int b_left, const int b_right, const int b_top, const int b_bottom) const
	{
		//If a is not outside b on all sides (e.g. a top below b bottom), there is collision.
		if (!((b_bottom <= a_top) || (b_top >= a_bottom) || (b_right <= a_left) || (b_left >= a_right)))
		{
			return true;
		}
		else return false;
	}

	/// <summary>
	/// Checks if there is any collision downwards for one object to another.
	/// </summary>
	/// <returns>True if collision, else false.</returns>
	bool CollisionManager::collides_down(GameObject & obj1, GameObject& obj2) const
	{
		//if collides if obj1 is put 1 step down.
		if (!((obj2.get_bottom() <= obj1.get_next_top() + 1) || (obj2.get_top() >= obj1.get_bottom() + 1) ||
			(obj2.get_right() <= obj1.get_left()) || (obj2.get_left() >= obj1.get_right())))
		{
			return true;
		}
		else return false;
	}

	/// <summary>
	/// Checks if there is any collision if adding x velocity.
	/// </summary>
	/// <returns>True if collision, else false.</returns>
	bool CollisionManager::collides_x(const GameObject& a, const GameObject& b, const int vel_x) const
	{
		if (collides(a.get_left() + vel_x, a.get_right() + vel_x, a.get_top(), a.get_bottom(), b.get_left(), b.get_right(), b.get_top(), b.get_bottom()))
		{
			return true;
		}
		else return false;
	}

	/// <summary>
	/// Checks if there is any collision if adding y velocity.
	/// </summary>
	/// <returns>True if collision, else false.</returns>
	bool CollisionManager::collides_y(const GameObject& a, const GameObject& b, const int vel_y) const
	{
		if (collides(a.get_left(), a.get_right(), a.get_top() + vel_y, a.get_bottom() + vel_y, b.get_left(), b.get_right(), b.get_top(), b.get_bottom()))
		{
			return true;
		}
		else return false;
	}

	/// <summary>
	/// Checks if two objects will collide next tick.
	/// </summary>
	/// <param name="a">First object.</param>
	/// <param name="b">Second object.</param>
	/// <returns>True if collision, else false.</returns>
	bool CollisionManager::next_tick_collides(GameObject& a, GameObject& b) const
	{
		return collides(a.get_next_left(), a.get_next_right(), a.get_next_top(), a.get_next_bottom(),
			b.get_next_left(), b.get_next_right(), b.get_next_top(), b.get_next_bottom());
	}

	const CollisionManager col_man;
}

