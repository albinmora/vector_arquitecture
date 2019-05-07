/*
 * And.cpp
 *
 *  Created on: May 5, 2019
 *      Author: albin
 */

#include "../../include/functional_units/and.h"

And::And(char a, char b, char &y)
{
	y = a & b;
}


