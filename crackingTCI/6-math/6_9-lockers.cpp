#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;


int main(int argc, char *argv[]) {
	int doorsnum = 10000;
	//vector<int> numBoys(simRuns,0);
	// init random generator
	//false = closed
	vector<bool> doors(doorsnum,false);
	for (int i = 1; i<= doorsnum; i++){
		//toggle doors
		for (int j=(i-1); j<doorsnum;j+=i)
			doors.at(j) = !doors.at(j);
	}
	for (int i = 0; i<doorsnum;i++)
		if (doors.at(i))
			cout <<i+1<<"\t";
	//cout << "GNP "<<getNextPrime(sieve, 11) <<endl;
}