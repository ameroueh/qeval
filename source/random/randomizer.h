#ifndef __RANDOMIZER__
#define __RANDOMIZER__
#include "stdint.h"
#include "vectorclass.h"
#include "ranvec1.h"
class Randomizer {
public:
	void generateRandomCards(uint64_t* output, uint64_t size);
	
	Randomizer();
	private:
		Ranvec1 _rgen;
};
#endif