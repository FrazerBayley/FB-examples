#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "directory.h"

int main(){

	const int NAME_LENGTH = 16;		//set max length of name (adjustable) (if adjust change struct too)
	const int NUMBER_LENGTH = 14;		//set max length of phone number XXX-XXX-XXXX
	int counter = 1;
	int flag = 1;

	while (flag == 1){
		printf("\nPlease choose an option:\n");	//print interface
		printf("1. Insert a new entry.\n");
		printf("2. Delete an entry.\n");
		printf("3. Display current directory.\n");
		printf("4. Exit.\n");
		printf("Option: ");

		int option = 0;
		scanf("%d", &option);

		if (option == 1){	//add name and number
			char name[NAME_LENGTH]; 	
			char phone_number[NUMBER_LENGTH];
			getName(name, NAME_LENGTH); 	//get name
			getPhoneNumber(phone_number, NUMBER_LENGTH); //get phone number
			addContact(name, phone_number, counter);	//add contact to linked list
			counter++;
			printf("\n");
		}
		if (option == 2){	//delete contact
			int n = 0;
			printf("\nCurrent Directory:\n");
			displayDirectory();	//display curent directory
			printf("\n");
			printf("Enter the index of the contact you would like to delete: ");
			scanf("%d", &n);
			deleteContact(n);	//delete
			counter--;
			printf("\nAltered Directory:\n");
			displayDirectory();	//display new directory
			printf("\n");
		}
		if (option == 3){	//display current directory
			printf("\nCurrent Directory:\n");
			displayDirectory();
			printf("\n");
		}
		if (option == 4){	//exit loop
			printf("\nExiting...\n\n");
			flag = 0;
		}
	}
	return 0;
}