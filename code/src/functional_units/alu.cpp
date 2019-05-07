/*
 * alu.cpp
 *
 *  Created on: May 5, 2019
 *      Author: albin
 */

#include "../../include/functional_units/alu.h"

Alu::Alu(char a, char b, char s, char  &y){
	/*
	 * Do: ADD
	 * D1: SUB
	 * D2: AND
	 * D3: OR
	 */
	char D0;
	char D1;
	char D2;
	char D3;

	Add addFU(a,b,D0);
	Sub subFU(a,b,D1);
	And andFU(a,b,D2);
	Or	orFU(a,b,D3);

	Mux4x1 mux(D0, D1, D2, D3, s, y);

}
