#pragma once
#ifndef MOVING_PLATFORM_H
#define MOVING_PLATFORM_H

#include "MovingObject.h"

namespace demo {

	const class MovingPlatform : public engine::MovingObject {
	public:
		static MovingPlatform* create(int x, int y, int w, int h, int x_speed, int y_speed, bool solid = true);

		void tick();
		void on_collision(GameObject&);
		~MovingPlatform() {}

	protected:
		MovingPlatform(int x, int y, int w, int h, int x_speed, int y_speed, bool solid);

	private:
		int m_speed_x;
		int m_speed_y;

		bool levelbounds_coll();
		void calculate_movement();

		MovingPlatform(const MovingPlatform&) = delete;
		const MovingPlatform operator=(const MovingPlatform&) = delete;

	};

}

#endif

