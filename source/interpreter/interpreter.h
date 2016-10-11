#ifndef __INTERPRETER__
#define __INTERPRETER__
#include <string>
#include "stdint.h"

/*************************************************************************************
 * Interpreter - Converts a score into a human-readable string
 *  
 ************************************************************************************/
 
class Interpreter {
	public:
		std::string toString(uint64_t ) const;
	private:
		std::string parseCard(uint8_t) const;
		std::string parseCards(uint16_t) const;
};
#endif