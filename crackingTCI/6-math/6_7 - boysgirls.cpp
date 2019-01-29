#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

int runSimulation(double p = 0.5){
	int numBoys = 0;
	bool girl = false;
	while (!girl){
		double gen = (double) rand() / RAND_MAX;
		//cout <<gen<<",";
		if (gen <= p) numBoys++;
		else girl = true;
	}
	return numBoys;
}

int main(int argc, char *argv[]) {
	int simRuns = 1000000;
	//vector<int> numBoys(simRuns,0);
	// init random generator
	srand(time(NULL));
	int numBoys = 0;
	for (int i=0;i<simRuns;i++){
		numBoys += runSimulation(0.5);
		
	}
	cout <<numBoys<<endl;
	cout << ((double) numBoys) / (numBoys+simRuns)<<endl;
	//cout << "GNP "<<getNextPrime(sieve, 11) <<endl;
}