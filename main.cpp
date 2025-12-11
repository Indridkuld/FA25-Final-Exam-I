#include <iostream>
#include <fstream>
#include <map> 
#include <string>   

using namespace std;

void printInRange(const map<string, int>&, int low, int high);

int main() {
    map<string, int> airportCounts; 

    ifstream infile("Data.txt");
    if (!infile) {
        cerr << "Unable to open file Data.txt";
        return 1;
    }
    string destinationCode, originCode ;

    while(infile >> originCode >> destinationCode) {
        airportCounts[originCode]++; 
        airportCounts[destinationCode]++;
    }
    infile.close();

    cout << "All Airport Traffic Counts:\n";
    for (const auto& entry : airportCounts) { // Range-based for loop
        cout << entry.first << " " << entry.second << endl;
    }
    // find the busiest airport by traffic count 
    int highestCount = 0;
    string busiestAirport;

    for (const auto& entry : airportCounts) {
        if (entry.second > highestCount) {
            highestCount = entry.second;
            busiestAirport = entry.first;
        }
    }
    cout << "\nBusiest Airport(s) with count " << highestCount << ": \n";
    cout << busiestAirport << " " << highestCount << endl;

    // print airports in specified ranges
    printInRange(airportCounts, 5, 8); 
    printInRange(airportCounts, 9, 12); 


    return 0; 
}
// Function to print airports with traffic counts in the specified range
void printInRange(const map<string, int>& airportCounts, int low, int high) {
    cout << "\nAirports with traffic in range [" << low << ", " << high << "]:\n";
    for (const auto& entry : airportCounts) {
        if (entry.second >= low && entry.second <= high) {
            cout << entry.first << " " << entry.second << endl;
        }
    }
}