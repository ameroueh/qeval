#ifndef __UTILS__
#define __UTILS__
#include "vectorclass/vectorclass.h"


Vec16us vectorize16(uint16_t);
void unVectorize16(Vec16us, uint16_t*);
void unVectorize32(Vec32uc, uint8_t*);
void unVectorize8(Vec8ui, uint32_t*);
int strToCard(char* );
int parseCards(char* , int*);
uint64_t getKey(int* );
void printVector(Vec16us);
void printVector(Vec4q);
void printVector(Vec8ui);
#endif
