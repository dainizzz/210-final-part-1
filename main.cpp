#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main() {
	// MILESTONE 1
	map <string, int> airports;
	string origin, destination;
	ifstream infile;

	infile.open("210-final-1-FA25.txt");
	if (infile.good()) {
		while (infile >> origin >> destination) {
			auto search = airports.find(origin);
			if (search == airports.end())
				airports.insert(make_pair(origin, 1));
			else
				search->second++;

			search = airports.find(destination);
			if (search == airports.end())
				airports.insert(make_pair(destination, 1));
			else
				search->second++;
		}
	}else {
		cout << "Error opening file" << endl;
		exit(2);
	}
	infile.close();

	cout << "All airport traffic counts:" << endl;
	for (auto airport : airports) {
		cout << airport.first << ": " << airport.second << endl;
	}

	return 0;
}