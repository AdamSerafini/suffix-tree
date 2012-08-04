#include <iostream>
#include "TestSuite.h"
#include <fstream>

using namespace std;

//define TESTING to run tests
#define TESTING
//define GENERATE to generate simulated reads
//#define GENERATE
//define MAIN for normal program execution
//#define MAIN

#ifdef MAIN
int main() {
	cout << "Normal program execution.." << endl;
	cout << sizeof(short int) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(char) << endl;
	cin.get();
}
#endif

#ifdef GENERATE
int main() {
	cout << "Generating reads..." << endl;
	

	std::ifstream infile;
	std::ofstream outfile;
	std::string full_sequence;
	infile.open("Swinepox_NC_003389_complete.FASTA");
	if (infile) {
		std::string line;
		
		getline(infile, line);
		while (getline(infile, line))
			full_sequence += line;
	}
	outfile.open("SWINEPOX_SIMULATED_READS.txt");
	for (int i = 0; i < 100000; i++) {
		outfile << "> SWINEPOX SIMULATED READ " << i << std::endl;
		outfile << full_sequence.substr(rand() % (full_sequence.length() - 36 + 1), 36) << std::endl;
	}

	cout << full_sequence.length();
	cin.get();

}
#endif
#ifdef TESTING
int main() {
	EXECUTE_TEST_SUITE();
}
#endif
