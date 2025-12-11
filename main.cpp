#include <iostream>
#include <fstream>
#include <map> 
#include <string>   

using namespace std;

int main() {
    map<string, int> aiportCounts; 

    ifstream infile("Data.txt");
    if (!infile) {
        cerr << "Unable to open file Data.txt";
        return 1;
    }
    string destinationCode, originCode ;

    while(infile >> originCode >> destinationCode) {
        aiportCounts[originCode]++; 
        aiportCounts[destinationCode]++;
    }
    infile.close();

    cout << "Total Airport Traffic Counts:\n";
    for (const auto& entry : aiportCounts) { // Range-based for loop
        cout << entry.first << " " << entry.second << endl;
    }
    // find the busiest airport by traffic count 
    int highestCount = 0;
    string busiestAirport;

    for (const auto& entry : aiportCounts) {
        if (entry.second > highestCount) {
            highestCount = entry.second;
            busiestAirport = entry.first;
        }
    }
    cout << "\nBusiest Airport(s) with count " << highestCount << ": \n";
    cout << busiestAirport << " " << highestCount << endl;

    return 0; 
}