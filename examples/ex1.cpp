#include "qeval_avx2.h"
#include "interpreter.h"
#include "converter.h"
#include "interpreter.h"
#include <string>
#include <iostream>
#include <bitset>
#include "randomizer.h"
#include "time.h"

using namespace std;

int main() {
	/*
	QEvalAVX2 eval;
	Converter conv;
	Interpreter inter;
	
	string str;
	cout << "Please enter a 7 card hand: " << endl;
	getline(cin,str);
	cout << inter.toString(eval.score(conv.getKeyString(str))) << endl; */
	
	Randomizer randomizer;
	uint64_t size = 100000000;
	
	
	uint64_t* volatile cards =  new uint64_t[size];
	clock_t t1 = clock();
	randomizer.generateRandomCards(cards,size);
	clock_t t2 = clock();
	cout << "Time taken: " << ((float) t2 - (float) t1) / ((float) CLOCKS_PER_SEC )<< endl;

	/*for(int i=0; i!=16; ++i) {
		cout << bitset<64>(cards[i]) << endl;
	}*/
}
