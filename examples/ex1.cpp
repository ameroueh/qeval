#include "qeval_avx2.h"
#include "interpreter.h"
#include "converter.h"
#include "interpreter.h"
#include <string>
#include <iostream>
#include <bitset>
#include "time.h"

using namespace std;

int main() {
	QEvalAVX2 eval;
	Converter conv;
	Interpreter inter;
	
	string str;
	cout << "Please enter a 7 card hand: " << endl;
	getline(cin,str);
	cout << inter.toString(eval.score(conv.getKeyString(str))) << endl;
}
