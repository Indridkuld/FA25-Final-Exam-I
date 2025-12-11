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

    int highestCount = 0;
    string busiestAirport;



    return 0; 
}