#include <iostream>
#include <bitset>
using namespace std;
int main(int argc, char *argv[]) {
		int a = 313521;
		cout << std::bitset<32>(a)<<endl;
		// int is a 32 bit type
		// take odd numbers and shift left 	0x55555555
		// take even bits and shift left 	0xaaaaaaaa
		int b = 0;
		b = ((a & 0xaaaaaaaa) >> 1) | ((a & 0x55555555) <<1);
		cout <<std::bitset<32>(b)<<endl;
		cout << (a&3)<<endl;
}