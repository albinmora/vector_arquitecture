/*
 * register_vs.hpp
 *
 *  Created on: May 8, 2019
 *      Author: albin
 */

#ifndef INCLUDE_register_vS_register_vS_HPP_
#define INCLUDE_register_vS_register_vS_HPP_

#include <vector>
#include <stdint.h>

#define register_v      vector<uint8_t>
#define register_s      uint32_t
#define register_bank_v vector<vector<uint8_t>>
#define register_bank_s vector<uint32_t>

using namespace std;

class Reg_File {
	public:
	  // Constructor
	  Reg_File();

	  // Reg File driver
      void register_vertorial(
    		  bool            we,
			  uint8_t         index_read1,
			  uint8_t         index_read2,
			  uint8_t         index_write1,
			  uint8_t         init_pos,
			  uint8_t         input_read_value,
			  vector<uint8_t> input_write_value,
			  vector<uint8_t> &output_read1,
			  vector<uint8_t> &output_read2);

      // System reserved registers
      register_s R16;  //Vector Length Register
      register_s R17;  //Vector Register index

      register_bank_v REG_BANK_V;
      register_bank_s REG_BANK_S;


	private:
      // Vector Registers
	  register_v R0;
	  register_v R1;
	  register_v R2;
	  register_v R3;
	  register_v R4;
	  register_v R5;
	  register_v R6;
	  register_v R7;

	  // Scalar Registers General Purpose
	  register_s R8;
	  register_s R9;
	  register_s R10;
	  register_s R11;
	  register_s R12;
	  register_s R13;
	  register_s R14;
	  register_s R15;

};

#endif /* INCLUDE_register_vS_register_vS_HPP_ */
