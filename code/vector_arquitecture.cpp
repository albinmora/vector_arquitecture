//============================================================================
// Name        : vector_arquitecture.cpp
// Author      : Albin
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdint.h>

#include "include/functional_units/alu.h"
#include "include/registers/registers.hpp"

using namespace std;

#define REG vector<vector<char>> {RO,R1}

int main() {
	char s = 00;
	char y;

	vector<uint8_t> input_write_value = {1,2,3,4};
	vector<uint8_t> output_read1(4);
	vector<uint8_t> output_read2(4);

    Reg_File registers;
    registers.register_vertorial(
    		true,
			0,
			0,
			0,
			0,
			0,
			input_write_value,
		    output_read1,
			output_read2);

    registers.register_vertorial(
        		true,
    			0,
    			0,
    			1,
    			0,
    			0,
    			input_write_value,
    		    output_read1,
    			output_read2);

    registers.register_vertorial(
            		false,
        			0,
        			1,
        			1,
        			0,
        			0,
        			input_write_value,
        		    output_read1,
        			output_read2);

    printf("Array A Values valud %d %d %d %d \n",output_read1[0],output_read1[1],output_read1[2],output_read1[3]);
    printf("Array A Values valud %d %d %d %d \n",output_read2[0],output_read2[1],output_read2[2],output_read2[3]);

	Alu(output_read1[0], output_read2[0],s,y);
	printf("Y valud %d \n",y);
	Alu(output_read1[1], output_read2[1],s,y);
	printf("Y valud %d \n",y);
	Alu(output_read1[2], output_read2[2],s,y);
	printf("Y valud %d \n",y);
	Alu(output_read1[3], output_read2[3],s,y);
	printf("Y valud %d \n",y);

	return 0;
}
