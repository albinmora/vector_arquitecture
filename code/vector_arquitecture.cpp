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
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>

#include "include/functional_units/alu.h"
#include "include/registers/registers.hpp"
#include "include/memory/data_memory.hpp"
#include "include/load_store_unit/load_store.hpp"
#include "include/decoder/decoder.hpp"

using namespace std;

#define REG vector<vector<char>> {RO,R1}

int main() {
	char s = 00;
	char y, y1, y2, y3;

	FILE    *fp;
	char     ch;

	string          inst_url;
	string          instruction_str;
	uint32_t        instruction;

	uint8_t         opt;
	uint8_t         rs;
	uint8_t         rt;
	uint8_t         rd;
	uint16_t         inm;

	vector<uint8_t> input_write_value = {1,2,3,4};
	vector<uint8_t> output_read1(4);
	vector<uint8_t> output_read2 = {10,10,10,10};

    Reg_File        registers;
    LoadStore       load_store_uinit;
    Decoder         decoder_unit;

	registers.R16 = 32;

	inst_url = "/home/albin/vector_arquitecture/code/src/memory/"
	    		"instruction_memfile.dat";

	fp = fopen(inst_url.c_str(), "r"); // read mode

	if (fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	while((ch = fgetc(fp)) != EOF){

		if(ch == '\n'){
			if(instruction_str != ""){
				instruction = (int)stoul(instruction_str.c_str(),nullptr,16);

				decoder_unit.decoder(instruction,opt,rs, rt, rd, inm);

				switch (opt) {
					case 11:
						// Store
						load_store_uinit.load_store(
								registers,
								true,
								inm,
								rs,
								output_read1);
						break;
					case 10:
						// Load
						load_store_uinit.load_store(
								registers,
								false,
								inm,
								rs,
								output_read1);

						break;
					default:
						for(uint32_t i = 0; i < registers.R16; i+=4){
							registers.register_vertorial(
									false,
									rs,
									rt,
									rd,
									0,
									0,
									output_read2,
									output_read1,
									output_read2);

							Alu(output_read1[0], output_read2[0],s,y);
							Alu(output_read1[1], output_read2[1],s,y1);
							Alu(output_read1[2], output_read2[2],s,y2);
							Alu(output_read1[3], output_read2[3],s,y3);

							printf("Alu add v1[%d]=%d + v1[%d]= %d, res %d \n",i,
									output_read1[0], i, output_read2[0],  y);
							printf("Alu add v1[%d]=%d + v1[%d]= %d, res %d \n",i+1
									, output_read1[1], i, output_read2[1],  y1);
							printf("Alu add v1[%d]=%d + v1[%d]= %d, res %d \n",i + 2,
									output_read1[2], i, output_read2[2],  y2);
							printf("Alu add v1[%d]=%d + v1[%d]= %d, res %d \n",i + 3,
									output_read1[3], i, output_read2[3],  y3);

							input_write_value = {(uint8_t)y3, (uint8_t)y2, (uint8_t)y1, (uint8_t)y};
							registers.register_vertorial(
									true,
									rs,
									rt,
									rd,
									i,
									0,
									input_write_value,
									output_read1,
									output_read2);
						}

						break;
				}

			}

			instruction_str = "";
		}else{
			instruction_str += ch;
		}
	}

	fclose(fp);

	return 0;
}
