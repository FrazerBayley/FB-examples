#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getName(char* name, int nl){
	/*
		Gets the name of the contact from the user and makes 
		sure it is can fit in the char array.
	*/

	int boolean = 1;	//acts as flag to stop while loop

	while (boolean == 1){
		
    	printf("Enter a name: ");
    	fgets(name, nl, stdin);		//gets an input from the user 

   		if (name[strlen(name) -1] != '\n'){		//if the last char in array is not equal to newline call
        	int dropped = 0;		

        	while (fgetc(stdin) != '\n'){	//while char is not equal to newline call
            	dropped++;
        	}

        	if (dropped > 0){ 
            	printf("The name you entered was over the limit by %d characters. Try again.\n", dropped);
        	}

    	}
    	else {
        	if (name[0] == '\n'){	//checks to see if entry is blank, therefore not an entry
        		printf("You entered nothing. Try again.\n");
        	}
        	else{
        		name[strlen(name) -1] = '\0'; //breaks loop when correct input is given
        		boolean = 0;   
        	}    
    	}
	}
}

void getPhoneNumber(char* phone_number, int nl){
	/*
		Gets the phone number  of the contact from the user and makes 
		sure it is can fit in the char array as well as meets the standards 
		of a phone number
	*/

	int boolean = 1;
	char temp[nl];		//temporary array to hold chars before checks

	while (boolean == 1){
		
    	printf("Enter a phone number (XXX-XXX-XXXX): ");
    	fgets(temp, nl, stdin);

   		if (temp[strlen(temp) -1] != '\n'){		
        	int dropped = 0;

        	while (fgetc(stdin) != '\n'){
            	dropped++;
        	}

        	if (dropped > 0){ 
            	printf("The phone number you entered was over the limit by %d characters. Try again.\n", dropped);
        	}

    	}
    	else {
        	if (temp[0] == '\n'){
        		printf("You entered nothing. Try again.\n");
        	}
        	else{
        		temp[strlen(temp) -1] = '\0'; 

        		for (int i = 0; i < nl; i++){
        			int ch = temp[i] - '0';			//turns char to ASCII value
        			if (ch < 0 || ch > 9){			//if ASCII value is not between 1 and 9
        				if (temp[i] != '-' && temp[i] != '\n' && temp[i] != '\0'){	//if char is not equal to a -, newline or null char
        					printf("The number you entered contains an invalid chararcter: %c\n", temp[i]);
        					boolean = 1;
        					break;		//break loop
        				}
        			}
        			phone_number[i] = temp[i];
        			boolean = 0;  
        		}
        	}    
    	}
	}
}

typedef struct Contact {		//defines the struct contact
		int ID;				//holds index
		char cname[16];  	//holds name 
		char cnumber[14];		//holds phone number
		struct Contact* next;		//pointer to next Contact
	} contact;

contact* head;		//head of linked list
contact* tail;		//tail of linked list
	
void addContact(char* name, char* phone_number, int count){
	/*
		
	*/

	if (count == 1){	//first contact addition
		head = (contact*)malloc(sizeof(contact));	//allocates memory for head Contact
		tail = head;		//tail is the same as head for first contact
	}
	else {	//every other contact addition
		tail->next = (contact*)malloc(sizeof(contact));	//allocate memory for tails next contact
		tail = tail->next;	//tail now equals the next contact to old tail
	}
	(*tail).ID = count;			//get index
	strcpy((*tail).cname, name);			//input name of contact
	strcpy((*tail).cnumber, phone_number);		//input phone number of contact
	tail->next = NULL;	//make next contact to tail null
}

void displayDirectory(){

	contact* current;	//create a scope to look at contacts

	current = head;	//put scope on first contact in list

	while(current != NULL){		//while scope is still looking at contacts
		printf("%d. %s, %s\n", current->ID, current->cname, current->cnumber);	
		current = current->next;	//shift scope to next contact in list
	}
	free(current);	//deallocate current
}

void deleteContact(int n){

	contact *current, *temp;	//creat a scope, and temporary contact holder

	current = head;	//set scope to start of list

	if (current->ID == n){		//if the head contact index is equal to int inputed 
		head = current->next;	//head equal the next contacts to its current position
		free(current);	//deallocate old head node

		current = head; //move scope to head
		while (current != NULL){	//while current is looking at valid contacts 
			current->ID = current->ID - 1;	//decrement index by one
			current = current->next;	//move to next contact
		}
		free(current);	//deallocate scope
	}
	else{	//the head contact is not the contact to be deleted
		while ((current != NULL) && (current->ID != n)){	
		//while there are still contacts and index is not equal it input
			temp = current;	//keep track of last contact seen by scope
			current = current->next;	//move scope forward
			if (current == NULL){	//if scope reaches end of list
				printf("No match found, deletion canceled.\n");
			}
			else if (current->ID == n){	//contacts index is equal to input
				temp->next = current->next;	//set temp contacts next pointer to the next pointer of current
				free(current);

				current = temp->next;	//set current to next contact beyond temp

				while (current != NULL){	//while there are still valid contacts
					current->ID = current->ID - 1;	//decrement index by 1
					current = current->next;	//move on
				}
				free(current);
			}
		}
	}
}