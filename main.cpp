#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main() {
	// MILESTONE 1
	map <string, int> airports;
	string origin, destination, temp;
	ifstream infile;

	infile.open("210-final-1-FA25.txt");
	if (infile.good()) {
		while (infile >> origin >> destination) {
			temp = origin + " " + destination;
			auto it = airports.find(temp);
			if (it != airports.end()) {}
		}
	}else {
		cout << "Error opening file" << endl;
		exit(2);
	}

	return 0;
}