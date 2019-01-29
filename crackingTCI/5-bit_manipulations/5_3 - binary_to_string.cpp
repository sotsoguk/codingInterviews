#include <iostream>
#include <bitset>
#include <string>
using namespace std;


int main(int argc, char *argv[]) {
		double a = 0;
		cout << std::bitset<32>(a)<<endl;
		// int is a 32 bit type
		// take odd numbers and shift left 	0x55555555
		// take even bits and shift left 	0xaaaaaaaa
		char numBits = 0;
		double divisor = 1.0;
		std::string binaryDouble = std::string("0.");
		//std::cout<<__DBL_EPSILON__<<endl;
		while (numBits <32 & (a>__DBL_EPSILON__)) {
			divisor /= 2.0;
			numBits++;
			if (a>=divisor){
				a -= divisor;
				binaryDouble += '1';
			}
			else
				binaryDouble += '0';
		}
		if (numBits >= 32)
			cout <<"ERROR: Not precise: ";
		cout <<binaryDouble<<endl;
}