#include <iostream>
using namespace std;

int main() {
    string A;
    string B;
    string C;
    string D;  // Strings to be inputted declaration
    string E;
    string F;
    string G;
    string H;
    cout << "Please enter 4 words/items: " << endl;
    cin >> A >> B >> C >> D;
    cout << "First table inputted successfully. please input 4 more words/items for table two." << endl;
    cin >> E >> F >> G >> H;
    string letters[2][4] = { //There are two tables being indexed. the second bracket following the first is a sub-array of the first table.
      { A, B, C, D }, //This is the first table which is 0 
      { E, F, G, H } //This is the second table which is 1
    };

    cout << letters[0][3] << " "; //First table being accessed
    cout << letters[1][3] << endl;//Second table being accessed
    return 0;
}