#include "converter.h"
#include "stdint.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
void Converter :: generateCards() {
	if(_cards) {
		for(int i=0; i!=52; i++) {
		_cards[i] = (1ll << i) + (1ll <<(52+(i/13)*3));
		}
	}
}

Converter :: Converter() {
	_cards = new uint64_t [52];
	generateCards();
	generateMaps();
}

Converter :: ~Converter() {
	delete [] _cards;
}

uint64_t Converter :: getKey7x52(uint64_t input) const {
	uint64_t ret = 0;
	for(int i=0; i!=7; i++) {
		ret += _cards[input & 0xff];
		input >>= 8;
	}
	return ret;
} 

void Converter :: getKey7x52(uint64_t* input, uint64_t* output, uint64_t size) const {
	for(int i=0; i!=size; i++)
		output[i] = getKey7x52(input[i]);
}

uint64_t Converter :: getKeyArray(uint64_t* array) const {
	uint64_t key = 0;
	for(int i=0; i!=7; i++) {
		key += _cards[array[i]];
	}
	return key;
}

void Converter :: generateMaps() {
	_char_to_height['2'] = 0;
	_char_to_height['3'] = 1;
	_char_to_height['4'] = 2;
	_char_to_height['5'] = 3;
	_char_to_height['6'] = 4;
	_char_to_height['7'] = 5;
	_char_to_height['8'] = 6;
	_char_to_height['9'] = 7;
	_char_to_height['T'] = 8;
	_char_to_height['J'] = 9;
	_char_to_height['Q'] = 10;
	_char_to_height['K'] = 11;
	_char_to_height['A'] = 12;
	
	_char_to_suit['h'] = 0;
	_char_to_suit['d'] = 1;
	_char_to_suit['c'] = 2;
	_char_to_suit['s'] = 3;
}

uint64_t Converter :: getKeyString(string str)  {
	stringstream ss(str);
	string card;
	uint64_t key = 0;
	while(ss >> card)
		key += _cards[_char_to_height[card[0]] + 13*_char_to_suit[card[1]]];
	return key;
}