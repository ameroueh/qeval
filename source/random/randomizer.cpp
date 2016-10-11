#include "randomizer.h"
#include "vectorclass.h"
#include "stdint.h"
#include <iostream>
#include <bitset>
using namespace std;
void Randomizer :: generateRandomCards(uint64_t* output, uint64_t size) {
	
	
	Vec16us thirteen(13);
	Vec16us three(3);
	Vec4uq one(1);
	Vec4uq mask16(0xffff);
	Vec4uq bit52(0x10000000000000);
	for(uint64_t i = 0; i!= size/16; ++i) {
		Vec8ui rsuit = (__m256i) _rgen.random8i(0,3);
		Vec8ui rheight = (__m256i) _rgen.random8i(0,13);
		rsuit = rsuit << 16;
		rheight = rheight << 16;
		rsuit |= (__m256i) _rgen.random8i(0,3);
		rheight |= (__m256i) _rgen.random8i(0,13);
		
		Vec16us prsuit = (__m256i) rsuit;
		Vec16us prheight = (__m256i) rheight;
 
		Vec16us prindex = prheight + thirteen*prsuit;
		Vec16us prindex2 = three*prsuit;
		
		Vec4uq qindex = (__m256i) prindex;
		Vec4uq qindex2 = (__m256i) prindex2;
		
		Vec4uq card = _mm256_sllv_epi64(one, qindex & mask16);
		card += _mm256_sllv_epi64(bit52, qindex2 & mask16);
		card.store(output);
		qindex = qindex >> 16;
		qindex2 = qindex2 >>16;
		card.store(output);
		
		card = _mm256_sllv_epi64(one, qindex & mask16);
		card += _mm256_sllv_epi64(bit52, qindex2 & mask16);
		card.store(output);
		qindex = qindex >> 16;
		qindex2 = qindex2 >>16;
		card.store(output+4);
		
		card = _mm256_sllv_epi64(one, qindex & mask16);
		card += _mm256_sllv_epi64(bit52, qindex2 & mask16);
		card.store(output);
		qindex = qindex >> 16;
		qindex2 = qindex2 >>16;
		card.store(output+8);
		
		card = _mm256_sllv_epi64(one, qindex & mask16);
		card += _mm256_sllv_epi64(bit52, qindex2 & mask16);
		card.store(output);
		qindex = qindex >> 16;
		qindex2 = qindex2 >>16;
		card.store(output+12);
		
		output +=16;
	} 
	

}

Randomizer :: Randomizer(): _rgen(Ranvec1(1)) {
	_rgen.init(0);
}