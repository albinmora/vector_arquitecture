/*
 * decoder.hpp
 *
 *  Created on: May 12, 2019
 *      Author: albin
 */

#ifndef INCLUDE_DECODER_DECODER_HPP_
#define INCLUDE_DECODER_DECODER_HPP_

#include <vector>
#include <stdint.h>

class Decoder {
public:
	void decoder(
			uint32_t  instruction,
			uint8_t   &opt,
			uint8_t   &rs,
			uint8_t   &rt,
			uint8_t   &rd,
			uint16_t  &inm);
private:
};



#endif /* INCLUDE_DECODER_DECODER_HPP_ */
