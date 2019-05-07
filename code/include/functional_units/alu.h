/*
 * alu.h
 *
 *  Created on: May 5, 2019
 *      Author: albin
 */

#ifndef INCLUDE_FUNCTIONAL_UNITS_ALU_H_
#define INCLUDE_FUNCTIONAL_UNITS_ALU_H_

#include "../muxs/mux4x1.hpp"
#include "add.h"
#include "and.h"
#include "or.h"
#include "sub.h"

class Alu {
public:
	Alu();

	Alu(char a, char b, char s, char  &y);
};

#endif /* INCLUDE_FUNCTIONAL_UNITS_ALU_H_ */
