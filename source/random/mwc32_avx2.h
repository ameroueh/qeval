#ifndef __MWC32AVX2__
#define __MWC32AVX2__
#include "stdint.h"
#include "ranvec1.h"
#include <iostream>
using namespace std;

template<uint32_t width> 

class MWC64AVX2 {
	public:
		uint32_t operator()();
		typedef uint32_t result_type;
		uint32_t max() const;
		uint32_t min() const;
		
		MWC32AVX2 ();
		~MWC32AVX2 ();
private:
	    const uint32_t _width = width; //bit width (1,2,4,8,16,32)
		const uint32_t _mask = 0xffffffff >> (32 - width); 

		
		Ranvec1 _rgen; //The vectorized random number generator
		uint32_t _vector[8]; //Stores the random vector
		uint32_t _i; //Between 0 and 7 - to acces the elements of the vector
		uint32_t _j; //Between 0 and 32/width - to access the sub elements
		void generate(); //Generates a new random vector

};

template<uint32_t width>
uint32_t MWC32AVX2<width> :: operator()() {
	if(_i == 7 && _j == 32/width) {
		generate();
	}
	
	if(_j == 32/width) {
		++i;
	}
	
	uint32_t ret = _vector[i] & (0xffffffff >> (32-width));
	_vector >>= width;
	++_j;
	
	return ret;
}

template<uint32_t width>
void MWC32AVX2<width> :: generate() {
	_rgen.random256b().store(_vector);
	_i = 0;
	_j = 0;
}

template<uint32_t width>
uint32_t MWC32AVX2<width> :: min() const {
	return 0;
}

template<uint32_t width>
uint32_t MWC32AVX2<width>  :: max() const {
	return 0xffffffff >> (32-width);
}

template<uint32_t width>
MWC32AVX2<pool_size> :: MWC32AVX2 ():_i(0), _rgen(Ranvec1(1)) {
	_rgen.init(0);
	generate();
}

template<uint32_t width>
MWC32AVX2<pool_size> :: ~MWC32AVX2 () {
}

#endif