#ifndef __CONVERTER__
#define __CONVERTER__
#include "stdint.h"
#include <string>
#include <map>
#include <string>
/***************************************************************************************************
 * 
 * Converter - Converts hands from a specific format to the one required by QEval
 * 
 * uint64_t getKey7x52(uint64_t cards) const;
 * 		Given a key formatted as seven consecutive 8bit integers in [0,51], returns a 
 * 		correctly formatted key (see qeval.h for a description of the format).
 * void getKey7x52(uint64_t* cards, uint64_t* keys,uint64_t size) const;
 * 		Batch processing version of the above function.
 * void getKeyArray(uint64_t* array) const
 * 		Returns a key given an array of 7 integers in [0,51]
 * void getKeyString(string s)
 * 		Returns a correctly formatted key given human-readable string
 * 
 * *************************************************************************************************/

class Converter {
	public:
		uint64_t getKey7x52(uint64_t) const; 
		void getKey7x52(uint64_t*, uint64_t*,uint64_t size) const; 
		uint64_t getKeyArray(uint64_t*) const;
		uint64_t getKeyString(std::string) ;
		Converter();
		~Converter();
	private:
		
		uint64_t* _cards;
		void generateCards(); 
		
		std::map<char, int> _char_to_height;
		std::map<char, int> _char_to_suit;
		void generateMaps();
};
#endif