#include <iostream>
#include <map>
#include <fstream>
#include <set>

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

	// MILESTONE 2
	int max = 0;
	for (auto airport : airports) {
		if (airport.second > max)
			max = airport.second;
	}

	set<string> maxAirports;
	for (auto airport : airports) {
		if (airport.second == max)
			maxAirports.insert(airport.first);
	}

	cout << endl << "Busiest airport(s) with count " << max << ':' << endl;
	for (auto airport : maxAirports) {
		cout << airport << ' ' << max << endl;
	}

	return 0;
}