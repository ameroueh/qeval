#include "utils.h"
#include "stdint.h"
#include <bitset>
#include <iostream>
using namespace std;

Vec16us vectorize16(uint16_t number) {
	uint16_t array[16];
	for(int i=0; i!=16; i++)
		array[i] = number;
	Vec16us ret;
	ret.load(array);
	return ret;
}

void unVectorize16(Vec16us vector, uint16_t* output) {
	vector.store(output);
}

void unVectorize32(Vec32uc vector, uint8_t* output) {
	vector.store(output);
}

void unVectorize8(Vec8ui vector, uint32_t* output) {
	vector.store(output);
}


int strToCard(char* s)
{
    int height, suit;
    if (s[0] == '2') height = 0;
    else if (s[0] == '3') height = 1;
    else if (s[0] == '4') height = 2;
    else if (s[0] == '5') height = 3;
    else if (s[0] == '6') height = 4;
    else if (s[0] == '7') height = 5;
    else if (s[0] == '8') height = 6;
    else if (s[0] == '9') height = 7;
    else if (s[0] == 'T') height = 8;
    else if (s[0] == 'J') height = 9;
    else if (s[0] == 'Q') height = 10;
    else if (s[0] == 'K') height = 11;
    else if (s[0] == 'A') height = 12;
    /*else
        throw CardError("Unrecognised card height");*/

    if (s[1] == 'h') suit = 0;
    else if (s[1] == 'd') suit = 1;
    else if (s[1] == 'c') suit = 2;
    else if (s[1] == 's') suit = 3;
    /*else
        throw CardError("Unrecognised card suit");*/

    return 13*suit+height;
}

int parseCards(char* string, int* cards)
{


    int i = 0;

    for (i = 0; string[i] != ']'; ++i) {

    }


	int total_cards = i / 3;

    for (int j = 0; j < total_cards; ++j)
        cards[j] = strToCard(&string[j*3+1]);


    return total_cards;
}

uint64_t getKey(int* cards) {
	uint64_t key = 0;
	for(int i=0; i!=7; i++) {
		key |= (1ll << cards[i]);
	}
	return key;
}

void printVector(Vec16us v) {
	uint16_t data[16];
	v.store(data);
	for(int i=0; i!=16; i++)
		cout << bitset<32>(data[i]) << endl;
}

void printVector(Vec4q v) {
	uint64_t data[4];
	v.store(data);
	for(int i=0; i!=4; i++)
		cout << bitset<64>(data[i]) << endl;
}

void printVector(Vec8ui v) {
	uint32_t data[8];
	v.store(data);
	for(int i=0; i!=8; i++)
		cout << bitset<32>(data[i]) << endl;
}