#include <stdio.h>
#include <windows.h>

int menu(void){
	printf("Inventory management system.\n");
	int cmd;
	int is_cmd_valid();
	while (1){
		Sleep(1500);
		printf("Commands:\n1. Create cell\n2. Read\n3. Update cell\n4.Delete cell.\nEnter \"0\" to terminate program.\n>");
		
		if (is_cmd_valid(scanf("%d", &cmd)))
			continue;
		
		system("cls");
		printf("Command read: %d\n", cmd);//debug. 
		switch (cmd){
			case 0: return 0;
			case 1: //func_Create
			case 2: //func_Read
			case 3: //func_Update
			case 4: printf("B)\n"); break; //debug. replace later with func_Delete
			default: printf("Invalid input!\n"); break;
		}
	}
}

int is_cmd_valid(int x){
	if (x != 1){
		system("cls");
		printf("Invalid input!");
		while (getchar() != '\n');
		return 1;
	} else {
		return 0;
	}
}

int main (void){
	menu();
return 0;
	
}
