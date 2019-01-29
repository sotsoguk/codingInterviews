#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int a = 15;
	int b = 16;
	
	// check number of different bits
	int diff = a ^ b;
	int cnt=0;
	// count number of 1s
	for (int c=a^b; c != 0; c=c&(c-1))
		cnt ++;
//	while (diff ){
//		if (diff & 1)
//			cnt++;
//		diff >>= 1;
//	}
	cout<<cnt<<endl;
	cout <<diff<<endl;
}