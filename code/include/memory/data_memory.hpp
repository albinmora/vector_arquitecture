/*
 * data_memory.h
 *
 *  Created on: May 10, 2019
 *      Author: albin
 */

#ifndef INCLUDE_MEMORY_DATA_MEMORY_HPP_
#define INCLUDE_MEMORY_DATA_MEMORY_HPP_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class DataMemory{
public:
	void dmem1(
			bool            we,
			uint32_t        index,
			vector<uint8_t> write_value,
			vector<uint8_t> &read_value);

	void dmem2(
				bool            we,
				uint32_t        index,
				vector<uint8_t> write_value,
				vector<uint8_t> &read_value);
	void dmem3(
				bool            we,
				uint32_t        index,
				vector<uint8_t> write_value,
				vector<uint8_t> &read_value);
	void dmem4(
				bool            we,
				uint32_t        index,
				vector<uint8_t> write_value,
				vector<uint8_t> &read_value);
private:

};


#endif /* INCLUDE_MEMORY_DATA_MEMORY_HPP_ */
