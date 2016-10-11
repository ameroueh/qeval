#include "interpreter.h"
#include <string>
#include "stdint.h"
#include <bitset>

using std::string;

string Interpreter :: toString(uint64_t score) const {
	switch(score >> 26) {
		case 0:
			return string("High card") + " " + parseCards(score & 0x1fff);
		case 1:
			return string("Pair") + " " + parseCards((score >> 13) & 0x1fff) + "| " + parseCards((score & 0x1fff));
		case 2:
			return string("Two pairs") + " " + parseCards((score >> 13) & 0x1fff) + "| " + parseCards((score & 0x1fff));
		case 3: 
			return string("Three of a kind") + " " + parseCards((score >> 13) & 0x1fff) + "| " + parseCards((score & 0x1fff));
		case 4: 
			return string("Straight") + " " + parseCards(1ll << ((score & 0x1fff)-1));
		case 5:
			return string("Flush") + " " + parseCards(score & 0x1fff);
		case 6:
			return string("Full house") + " " + parseCards((score >> 13) & 0x1fff) + " " + parseCards((score & 0x1fff));
		case 7:
			return string("Four of a kind") + " " + parseCards((score >> 13) & 0x1fff) + "| " + parseCards((score & 0x1fff));
		case 8:
			return string("Straight flush") + " " + parseCards(1ll << ((score & 0x1fff)-1));
		default:
			break;
	}
}

string Interpreter :: parseCard(uint8_t card) const {
	string str;
	switch(card) {
		case 2:
			return string("2");
		case 3:
			return string("3");
		case 4:
			return string("4");
		case 5:
			return string("5");
		case 6:
			return string("6");
		case 7:
			return string("7");
		case 8:
			return string("8");
		case 9:
			return string("9");
		case 10:
			return string("T");
		case 11:
			return string("J");
		case 12:
			return string("Q");
		case 13:
			return string("K");
		case 14:
			return string("A");
		default:
			break;
	}
}

string Interpreter :: parseCards(uint16_t card) const {
	string str;
	for(int i=14; i!= 1; --i) {
		if(card & 0x1000)
			str += parseCard(i) + " ";
		card <<= 1;
	}
	return str;
}