#include <iostream>
#include <windows.h>
#include <limits>
#include <map>
#include <string>

//defining magic numbers
#define ONE_AND_A_HALF_SECOND 1500
#define ONE_SECOND 1000


using Inventory = std::multimap<std::string, int>; 

Inventory inventory; //initiate dynamic container with multimap
int current_slots = 0, wanted_slots;

//function declaration
void createCell();
int UpdateCell(void);
std::string getItemName(); 
int getWantedItemValue();
void editItemValue(int getWantedItemValue, const std::string& itemName);
std::string newItemName();
void editItemName(const std::string& newName, const std::string& itemName);
void editFirstSingleEmptyCell(int emptyCellValue, const std::string& newName);
int deleteCell();
void deleteSingleCell(const std::string& itemName);
int cin_error(void);
int is_there_errors(int);
void throw_warning(const std::string&);
void printInventory(void);



int main(){
	int cmd;
	std::cout << "Inventory management system.";
	while (1){
		Sleep(ONE_SECOND);
		std::cout << "\nCommands:\n1. Create cell\n2. Read\n3. Update cell\n4. Delete cell.\nEnter \"0\" to terminate program.\n>";
		std::cin >> cmd;
		if (cin_error())
			continue;
		
		system("cls");
		std::cout << "Command read: " << cmd << std::endl;//debug. 
		switch (cmd){
			case 0: return 0;
			case 1: createCell(); break;
			case 2: printInventory(); break;
			case 3: UpdateCell(); break;
			case 4: deleteCell(); break;
			default: std::cout << "Invalid input!\n"; break;
		}
	}
}


void createCell(void){	
	int read_input = -1;
	
	while (read_input != 0){
		std::cout << "There are currently " << current_slots << " slots in your inventory." << std::endl;
		std::cout << "Insert how many? \"0\" to exit" << std::endl << "> ";
		std::cin >> read_input;
		if (cin_error()){
			read_input = -1;
			continue;
		} else if (read_input < 0){
			read_input = -1;
			std::cout << "Invalid. Use positive float(truncated)/integer" << std::endl;
			continue;
		}
		wanted_slots = read_input + current_slots; 
		
		//creates empty cells with a key type string, value of int.
		for (int i = 0; i != read_input; i++, current_slots++){
			inventory.insert({"Empty cell", 0});
		}
		system("cls");
		std:: cout << "Done!" << std::endl << "Wanted slots: " << wanted_slots << std::endl;
		wanted_slots = 0;
	
		printInventory();
	}
	system("cls");
	std::cout << "Going back to main menu..." << std::endl;
}

void printInventory(void){
	std::cout << "there are currently " << current_slots << " slots in your inventory." << std::endl;
	
	for (const auto& pair : inventory){
			std::cout << pair.first << ": " <<pair.second << std::endl;
		}
	/*
		 * This for loop basically says: "For every key/value pair in inventory, call it pair", where pair.first is the key (string in our example) and pair.secon is the value.
		 *const -- SO that we read the data, not modify it.
		 *auto -- multimap is actually std::pair<const std::string, std::vector<int>>, auto *lets compiler figure it out, lol.
		 *& to avoid copying the pair
		 */
}

int UpdateCell(void){
	std::string cellName;
	int editACell;
	while (true){
		system("cls");
		printInventory();
		std::cout << "Edit a (1) empty cell or a (2)specific cell" << std::endl << "\"0\" to leave. " << std::endl << "> ";
		std::cin >> editACell;
		if (is_there_errors(editACell))
			continue;
		
		switch(editACell){
			case 0: system ("cls"); std::cout << "Returning..." << std::endl; return 0;
			case 1: editFirstSingleEmptyCell(getWantedItemValue(), newItemName()); continue;
			case 2: 
				int specificEdit;
				std::cout << "Edit a (1) item name or (2) A amount of items?" << std::endl << "> ";
				std::cin >> specificEdit;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (specificEdit){
					case 0: continue;
					case 1:
					editItemName(newItemName(), getItemName()); continue;
					case 2:
					editItemValue(getWantedItemValue(), getItemName()); continue;
					default: 
					std::cout << system("cls") << "Invalid input!" << std::endl;
					Sleep(ONE_AND_A_HALF_SECOND);
					continue;
				}
			default: std::cout << "Invalid input."<< std::endl; Sleep(ONE_AND_A_HALF_SECOND);break;
		}	
		system("cls");
	}
}

int deleteCell(){
	int read_input;
	while(true){
		printInventory();
		std::cout << "Delete (1) single cell, (2) all Empty cells or (3) All. \"0\" To exit." << std::endl;
		std::cin >> read_input;
		if (is_there_errors(read_input))
			continue;
		switch(read_input){
			case 0: return 0;
			case 1: deleteSingleCell(getItemName()); break;
			case 2:{ size_t removed = inventory.erase("Empty cell"); 
					current_slots -= removed;
					std::cout << "Done!"; return 0;
			}
			case 3: inventory.clear();
					current_slots = 0;
					wanted_slots = 0;
					std::cout << "Done!"; return 0;
		}
	}
}

int cin_error(void){
	if (!(std::cin.fail())){ 
		return 0; //runs if input does not fail
	} //runs if input fais
	system("cls");
	std::cout << "Invalid input! Please enter an integer.\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Sleep(ONE_AND_A_HALF_SECOND);
	return 1;
}

void editFirstSingleEmptyCell(int emptyCellValue, const std::string& newName){
	std::string Empty_cell = "Empty cell";
	auto item = inventory.find(Empty_cell); 		//finds "Empty cell" key in multimap
	if (item != inventory.end()){			 		//if successfull, 
		int oldValue = item->second;				// save old value
		inventory.erase(item);						//deletes the Empty cell
		inventory.insert({newName, emptyCellValue});	//Adds requested name and value	
	} else throw_warning(Empty_cell);
	
}

std::string getItemName(){
	std::string cellName;
	std::cout << "Enter name of item you want to change: ";
	std::getline(std::cin, cellName);
	return cellName;
}

int getWantedItemValue(){
	int WantedItemValue;
	std::cout << "Change amt: ";
	std::cin >> WantedItemValue;
	
	return WantedItemValue;
}
void editItemValue(int toAmt, const std::string& itemName){
	auto range = inventory.equal_range(itemName);		//
		if (range.first != range.second){
			range.first -> second = toAmt;
		}	else throw_warning(itemName);
}

std::string newItemName(){
	std::string NewItem;
	std::cout << "Enter new item name: " << std::endl << "> ";
	std::getline(std::cin, NewItem);
	return NewItem;
	
}

void editItemName(const std::string& newName, const std::string& itemName){
	auto item = inventory.find(itemName);
	if (item != inventory.end()){
		int oldValue = item->second;
		inventory.erase(item);
		inventory.insert({newName, oldValue});
	}	else throw_warning(itemName);
}

void throw_warning(const std::string& item_name){
	system("cls"); 
	std::cout<< "Warning! \""<< item_name << "\" does not exist. Check spelling."<<std::endl;
	Sleep(ONE_AND_A_HALF_SECOND);
}

int is_there_errors(int input){
	if (cin_error())
		return 1;
	else if (input < 0){
		std::cout << "Invalid. Use positive float(truncated)/integer" << std::endl;
		return 1;
		}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}

void deleteSingleCell(const std::string& itemName){
	auto item = inventory.find(itemName);
	if (item != inventory.end()){
		inventory.erase(item);
		current_slots--;
	}	else throw_warning(itemName);
}
