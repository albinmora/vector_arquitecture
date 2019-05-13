/*
 * load_store.hpp
 *
 *  Created on: May 12, 2019
 *      Author: albin
 */

#ifndef INCLUDE_LOAD_STORE_UNIT_LOAD_STORE_HPP_
#define INCLUDE_LOAD_STORE_UNIT_LOAD_STORE_HPP_

#include <vector>
#include <stdint.h>
#include "../registers/registers.hpp"
#include "../memory/data_memory.hpp"

class LoadStore {
public:
    void load_store(
    		Reg_File        &registers,
    		bool            store,
    		uint8_t         index_memory,
    		uint8_t         index_array,
    		vector<uint8_t> write_value);

private:
};



#endif /* INCLUDE_LOAD_STORE_UNIT_LOAD_STORE_HPP_ */
