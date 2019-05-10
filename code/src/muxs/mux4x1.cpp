/*
 * mux4x1.cpp
 *
 *  Created on: May 7, 2019
 *      Author: albin
 */
#include "../../include/muxs/mux4x1.hpp"

mux4x1::mux4x1(char d0, char d1, char d2, char d3, char s, char &y){
	switch (s) {
		case 00:
            y = d0;
			break;
		case 01:
			y = d1;
			break;
		case 10:
			y = d2;
			break;
		case 11:
			y = d3;
			break;
		default:
			break;
	}
}



