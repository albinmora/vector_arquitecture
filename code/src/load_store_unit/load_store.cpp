/*
 * load_store.cpp
 *
 *  Created on: May 12, 2019
 *      Author: albin
 */

#include "../../include/load_store_unit/load_store.hpp"

void LoadStore::load_store(
		Reg_File        &registers,
		bool            store,
		uint8_t         index_memory,
		uint8_t         index_array,
		vector<uint8_t> write_value)
{
	DataMemory       dmemory;
	vector<uint8_t>  copy_value1(4);
	vector<uint8_t>  copy_value2(4);
	vector<uint8_t>  copy_value3(4);
	vector<uint8_t>  copy_value4(4);
	vector<uint8_t>  copy_value(4);

	vector<uint8_t> input_write_value = {1,2,3,4};
	vector<uint8_t> output_read1(4);
	vector<uint8_t> output_read2 = {10,10,10,10};

	if(store){
		// Store mode
		for(uint32_t i = 0; i < registers.R16; i += 16){
			registers.register_vertorial(
					false,
					index_array,
					0,
					0,
					i,
					0,
					copy_value1,
					copy_value1,
					copy_value);

			registers.register_vertorial(
								false,
								index_array,
								0,
								0,
								i + 4,
								0,
								copy_value2,
								copy_value2,
								copy_value);

			registers.register_vertorial(
								false,
								index_array,
								0,
								0,
								i + 8,
								0,
								copy_value3,
								copy_value3,
								copy_value);

			registers.register_vertorial(
								false,
								index_array,
								0,
								0,
								i + 12,
								0,
								copy_value4,
								copy_value4,
								copy_value);

			dmemory.dmem1(true, index_memory, copy_value1, input_write_value);
			dmemory.dmem2(true, index_memory, copy_value2, input_write_value);
			dmemory.dmem3(true, index_memory, copy_value3, input_write_value);
			dmemory.dmem4(true, index_memory, copy_value4, input_write_value);

			index_memory ++;
		}


	}else{

		// Load mode
		for(uint32_t i = 0; i < registers.R16; i += 16){
			dmemory.dmem1(false, index_memory, copy_value1, copy_value1);
			dmemory.dmem2(false, index_memory, copy_value2, copy_value2);
			dmemory.dmem3(false, index_memory, copy_value3, copy_value3);
			dmemory.dmem4(false, index_memory, copy_value4, copy_value4);

			registers.register_vertorial(
					true,
					0,
					0,
					index_array,
					i,
					0,
					copy_value1,
					copy_value,
					copy_value);

			registers.register_vertorial(
								true,
								0,
								0,
								index_array,
								i + 4,
								0,
								copy_value2,
								copy_value,
								copy_value);

			registers.register_vertorial(
								true,
								0,
								0,
								index_array,
								i + 8,
								0,
								copy_value3,
								copy_value,
								copy_value);

			registers.register_vertorial(
								true,
								0,
								0,
								index_array,
								i + 12,
								0,
								copy_value4,
								copy_value,
								copy_value);

			index_memory ++;
		}
	}
}


