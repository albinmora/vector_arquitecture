/*
 * decoder.cpp
 *
 *  Created on: May 12, 2019
 *      Author: albin
 */

#include "../../include/decoder/decoder.hpp"

void Decoder::decoder(
		uint32_t  instruction,
		uint8_t   &opt,
		uint8_t   &rs,
		uint8_t   &rt,
		uint8_t   &rd,
		uint16_t  &inm){

	uint32_t mask_opt  = 0b11111100000000000000000000000000;
	uint32_t mask_rs   = 0b00000011111000000000000000000000;
	uint32_t mask_rt   = 0b00000000000111110000000000000000;
	uint32_t mask_rd   = 0b00000000000000001111100000000000;
	uint32_t mask_inm  = 0b00000000000000001111111111111111;

	opt = (instruction & mask_opt) >> 26;
	rs  = (instruction & mask_rs)   >> 21;
	rt  = (instruction & mask_rt)   >> 16;
	rd  = (instruction & mask_rd)   >> 11;
	inm  = (instruction & mask_inm);
}



