/*
 * rectange.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: staircd
 */

#include "rectangle.h"

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int Rectangle::area()
{
	return width*height;
}

Rectangle::Rectangle()
{
	height = 0;
	width = 0;
}
