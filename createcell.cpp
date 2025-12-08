#include <iostream>
#include <vector>
#include <map>

using namespace std;

int cell_create(void){
	int current_slots = 0, wanted_slots, read_input;
	
	while (read_input != 0){
		cout << "there are currently " << current_slots << " slots in your inventory." << endl;
		cin << read_input;
		wanted_slots = read_input + current_slots;
		for (int i = current_slots + 1; i != wanted_slots; current_slots++){
			inventory.push_back({});
			current_slots = i;
		}
		cout << "Done!" << endl;
		cout << "Total slots: " << current_slots << endl;
		cout << "Wanted slots: " << wanted_slots << endl;
		wanted_slots = 0;
	}
	
}

int main(void){
	vector <vector<int>> inventory;
	cell_create();
	
	for (int i = 0; 0 != sizeof(inventory); ++i){
		cout << i
	}
	return 0;
}