#include <iostream>
#include <windows.h>
#include <limits>
#include <map>
#include <string>
using namespace std;
using Inventory = std::multimap<std::string, int>;

void createcell();
int menu();
int current_slots = 0, wanted_slots;

int is_cmd_valid(void){
	if (!(cin.fail())){
		
		return 0;
	} 
	system("cls");
	cout << "Invalid input! Please enter an integer.\n";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 1;
}

Inventory inventory; //initiate dynamic container

int main(){
	menu();
}

int menu(void){
	int cmd;
	cout << "Inventory management system.";
	while (1){
		Sleep(1500);
		cout << "\nCommands:\n1. Create cell\n2. Read\n3. Update cell\n4. Delete cell.\nEnter \"0\" to terminate program.\n>";
		cin >> cmd;
		if (is_cmd_valid())
			continue;
		
		system("cls");
		cout << "Command read: " << cmd << endl;//debug. 
		switch (cmd){
			case 0: return 0;
			case 1: createcell(); break;
			case 2: //func_Read
			case 3: //func_Update
			case 4: cout << "B)\n"; break; //debug. replace later with func_Delete
			default: cout << "Invalid input!\n"; break;
		}
	}
}

void createcell(void){	
	int read_input = -1;
	
	while (read_input != 0){
		std::cout << "there are currently " << current_slots << " slots in your inventory." << std::endl;
		std::cout << "Insert how many?" << std::endl << "> ";
		std::cin >> read_input;
		if (is_cmd_valid()){
			read_input = -1;
			continue;
		}
		if (read_input < 0){
			read_input = -1;
			continue;
		}
		wanted_slots = read_input + current_slots; //Debug. How many TOTAL slots user wants. If different from ACTUAL total slots IF something goes wrong.
		
		//create empty cells with a key type string, value of int.
		for (int i = 0; i != read_input; i++, current_slots++){
			inventory.insert({"Empty cell", 0});
		}
		std:: cout << "Done!" << std::endl << "Wanted slots: " << wanted_slots << std::endl;
		wanted_slots = 0;
	
		//print created empty cells
		for (const auto& pair : inventory){
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
		/*
		 * This for loop basically says: "For every key/value pair in inventory, call it pair", where pair.first is the key (string in our example) and pair.secon is the value.
		 *const -- SO that we read the data, not modify it.
		 *auto -- multimap is actually std::pair<const std::string, std::vector<int>>, auto *lets compiler figure it out, lol.
		 *& to avoid copying the pair
		 */
	}
}