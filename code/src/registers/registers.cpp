/*
 * RegFile.cpp
 *
 * Created on: May 8, 2019
 * Author: albin
 */

#include "../../include/registers/registers.hpp"

Reg_File::Reg_File()
{
	/*
	 * Init the vector register with size 8
	 */
	R0 = register_v(64);
	R1 = register_v(64);
	R2 = register_v(64);
	R3 = register_v(64);
	R4 = register_v(64);
	R5 = register_v(64);
	R6 = register_v(64);
	R7 = register_v(64);

	R8 = 0;
	R9 = 0;
	R10 = 0;
	R11 = 0;
	R12 = 0;
	R13 = 0;
	R14 = 0;
	R15 = 0;

	R16 = 0;
	R17 = 0;


	// Create a bank register that contain all before registers
	REG_BANK_V = {R0, R1, R2, R3, R4, R5, R6, R7};
	REG_BANK_S = {R8, R9, R10, R11, R12, R13, R14, R15, R16, R17};
}

void Reg_File::register_vertorial(
		bool            we,
		uint8_t         index_read1,
		uint8_t         index_read2,
		uint8_t         index_write1,
		uint8_t         init_pos,
		uint8_t         input_read_value,
		vector<uint8_t> input_write_value,
		vector<uint8_t> &output_read1,
		vector<uint8_t> &output_read2)
{
	//uint8_t register_index = R17;
	if(we){
		// Wirite mode
		if(index_write1 < 8){
			REG_BANK_V[index_write1][init_pos]     = input_write_value[0];
			REG_BANK_V[index_write1][init_pos + 1] = input_write_value[1];
			REG_BANK_V[index_write1][init_pos + 2] = input_write_value[2];
			REG_BANK_V[index_write1][init_pos + 3] = input_write_value[3];
		}else{
			REG_BANK_S[index_write1] = input_write_value[0];
		}
	}else{
		if(index_write1 < 8){
			// Output 1
			output_read1[0] = (index_read1 == 0b11111111) ? input_read_value :
					REG_BANK_V[index_read1][init_pos];
			output_read1[1] = (index_read1 == 0b11111111) ? input_read_value :
					REG_BANK_V[index_read1][init_pos + 1];
			output_read1[2] = (index_read1 == 0b11111111) ? input_read_value :
					REG_BANK_V[index_read1][init_pos + 2];
			output_read1[3] = (index_read1 == 0b11111111) ? input_read_value :
					REG_BANK_V[index_read1][init_pos + 3];

			// Output 2
			output_read2[0] = (index_read2 == 0b11111111) ? input_read_value :
					REG_BANK_V[index_read2][init_pos];
			output_read2[1] = (index_read2 == 0b11111111) ? input_read_value :
					REG_BANK_V[index_read2][init_pos + 1];
			output_read2[2] = (index_read2 == 0b11111111) ? input_read_value :
					REG_BANK_V[index_read2][init_pos + 2];
			output_read2[3] = (index_read2 == 0b11111111) ? input_read_value :
					REG_BANK_V[index_read2][init_pos + 3];
		}else{
			output_read1[0] = (index_read1 == 0b11111111) ? input_read_value :
					REG_BANK_S[index_read1];
			output_read2[0] = (index_read2 == 0b11111111) ? input_read_value :
					REG_BANK_S[index_read2];

		}
	}


}


