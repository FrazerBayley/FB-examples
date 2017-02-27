/*
 * Frazer Bayley
 * CIS 314/ Fall 2015/ Lab 3
 * Assigned Project
 *
 * This programs simulates the actions of a direct cache. The program takes
 * a file of 32 bit HEX addresses and then place them in a 8 line cache. 
 * Program displaysthe state of the cache as well as the hit and miss ratios.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
#include <math.h>

void runProgram();
void displayCache();
void initializeCache();
void initializeMEM();
void addToCache();
int compareStringsMin();
int compareStringsMax();
char* getBinVal();
char* getBinPart();
int convertToDecimal();
void convertToBase();
char* substring();
void displayStats();

int LINECOUNT = 0;
int HITS = 0;
int MISSES = 0;
char cache[32][29]; //(32 = # of lines * # of data entries per line)(28 = length of largest char[])
char MEM[16][11];

int main(void) {
	int x;
	printf("If you would like to run 10 addresses type 10.\nIf you would like to run ALL addresses type 1.\n");
	scanf("%d", &x);
	runProgram(x);
	return 0;
}

void runProgram(int n){
	
	FILE *inFile;
	inFile = fopen("address.txt", "r"); //opens address.txt located in same file
	char inputError;	
	char word[10];		
	
	initializeCache(cache);
	
	initializeMEM(MEM);

	while(inputError != EOF) {	//while the line being read is valid or present
    	inputError = fscanf(inFile, "%s\n", word);	//retrieves a char[] line by line
    	LINECOUNT++;
	}

	fclose(inFile);	//close address.txt

	char hexAddresses[LINECOUNT][10];	//creates an array of length linecount with char arrays size 10

	fopen("address.txt", "r");

	if (n == 10){
		LINECOUNT = 10;
	}

	for(int i = 1; i < LINECOUNT; i++) {	
    	fscanf(inFile, "%s", hexAddresses[i]);	//places char[]'s in hexAddresses[]

    	char* arr = hexAddresses[i];
    	int c = arr[8] - '0';
    	char* index = "000";
    	if (c == 0){		//I apologize for all these ifs, I was tying to be smart with my other functions but they werent working.
    		index = "000";	//And I honestly just got tired of getting errors from the compiler
    	}					//I know this isnt good coding
    	if (c == 1){
    		index = "001";
    	}
    	if (c == 2){
    		index = "010";
    	}
    	if (c == 3){
    		index = "011";
    	}
    	if (c == 4){
    		index = "100";
    	}
    	if (c == 5){
    		index = "101";
    	}
    	if (c == 6){
    		index = "110";
    	}
    	if (c == 7){
    		index = "111";
    	}
    	if (c == 8){
    		index = "000";
    	}
    	if (c == 9){
    		index = "001";
    	}
    	if (c == 17){
    		index = "010";
    	}
    	if (c == 18){
    		index = "011";
    	}
    	if (c == 19){
    		index = "100";
    	}
    	if (c == 20){
    		index = "101";
    	}
    	if (c == 21){
    		index = "110";
    	}
    	if (c == 22){
    		index = "111";
    	}

    	char* add = substring(hexAddresses[i], 0, 8);
    	strcat(add, "0");
    	char* addtwo = substring(add, 2, 8);

    	addToCache(cache, index, addtwo, hexAddresses[i], MEM);

    	free(addtwo);
    	free(add);

	}
	fclose(inFile);	//close address.txt
	if (LINECOUNT != 10){
		LINECOUNT--;
	}

	displayStats(LINECOUNT);
	displayCache(cache, MEM);
	
}

void displayCache(char cache[32][29], char MEM[16][11]){
	printf("Index 	Tag  		Valid 	Data\n");
	printf("____________________________________________________________\n");
	printf("%d 	%s 	%s 	MEM[%s : %s]\n", convertToDecimal(cache[0], 2), cache[1], cache[2], MEM[0], MEM[1]);
	printf("%d 	%s 	%s 	MEM[%s : %s]\n", convertToDecimal(cache[4], 2), cache[5], cache[6], MEM[2], MEM[3]);
	printf("%d 	%s 	%s 	MEM[%s : %s]\n", convertToDecimal(cache[8], 2), cache[9], cache[10], MEM[4], MEM[5]);
	printf("%d 	%s 	%s 	MEM[%s : %s]\n", convertToDecimal(cache[12], 2), cache[13], cache[14], MEM[6], MEM[7]);
	printf("%d 	%s 	%s 	MEM[%s : %s]\n", convertToDecimal(cache[16], 2), cache[17], cache[18], MEM[8], MEM[9]);
	printf("%d 	%s 	%s 	MEM[%s : %s]\n", convertToDecimal(cache[20], 2), cache[21], cache[22], MEM[10], MEM[11]);
	printf("%d 	%s 	%s 	MEM[%s : %s]\n", convertToDecimal(cache[24], 2), cache[25], cache[26], MEM[12], MEM[13]);
	printf("%d 	%s 	%s 	MEM[%s : %s]\n", convertToDecimal(cache[28], 2), cache[29], cache[30], MEM[14], MEM[15]);
}

void displayStats(int n){
	printf("Number of Hits: %d\n", HITS);
	printf("Number of Misses: %d\n", MISSES);
	printf("Hit Rate: %d/%d\n", HITS, n);
	printf("Miss Rate: %d/%d\n\n", MISSES, n);
}

void initializeCache(char cache[32][29]){
	for (int i = 0; i < 32; i++){
		int check = i % 4;
		if (check == 0){
			char* binVal = getBinVal(i/4);
			strcpy(cache[i], binVal);
			free(binVal);
		}
		if (check == 2){
			strcpy(cache[i], "0");
		}
		if (check == 1 || check == 3){
			strcpy(cache[i], "        ");
		} 
	}
}

void initializeMEM(char MEM[16][11]){
	for (int i = 0; i < 16; i++){
		strcpy(MEM[i], "          ");
	}
}

void addToCache(char cache[32][29], char* index, char* tag, char* charArray, char addresses[16][11]){
	int indexDec = (convertToDecimal(index, 2));

	if (*cache[(indexDec * 4) + 1] != *tag){
		strcpy(cache[(indexDec * 4) + 1], tag);
		MISSES++;
		strcpy(cache[(indexDec * 4) + 2], "1");
		if (compareStringsMin(charArray, addresses[indexDec * 2]) == 1){
			strcpy(addresses[indexDec * 2], charArray);
		}
		if (compareStringsMax(charArray, addresses[(indexDec * 2) + 1]) == 1){
			strcpy(addresses[(indexDec * 2) + 1], charArray);
		}
	}
	else {
		HITS++;
	}
}

int compareStringsMin(char* firstArray, char* secondArray){
	int flag = 0;

	for (int i = 1; i < 10; i++){
		int firstChar = firstArray[i] - '0';
		int secondChar = secondArray[i] - '0';
		char* eArray = " ";
		int e = eArray[0] - '0';
		if (secondChar == e){
			flag = 1;
			break;
		}
		if (firstChar < secondChar){
			flag = 1;
			break;
		}
		if (secondChar < firstChar){
			break;
		}
	}
	return flag;
}

int compareStringsMax(char* firstArray, char* secondArray){ 
//returns 1 if first address is larger than second address, else returns 0
	int flag = 0;

	for (int i = 1; i < 10; i++){
		int firstChar = firstArray[i] - '0';
		int secondChar = secondArray[i] - '0';
		char* eArray = " ";
		int e = eArray[0] - '0';
		if (secondChar == e){
			flag = 1;
			break;
		}
		if (firstChar > secondChar){
			flag = 1;
			break;
		}
		if (secondChar > firstChar){
			break;
		}
	}
	return flag;
}

char* getBinVal(int n) {
	char out_number[17];
    int bitPlace = 16;
	for (int i = 0; i < 16; i++) {
		out_number[i] = '0';
	}
	out_number[bitPlace--] = '\0';

    convertToBase(n, out_number, &bitPlace, 2);
    
    return substring(out_number, 13, 16);
}

int convertToDecimal(char x[17], int y){	//converts any even base from 2 to 16 to decimal
	
	int outcome = -1;
	int len = strlen(x) - 1;
	int flag = 0;
	
	if (y >= 2 && y <= 16){
		int sum = 0;
		for (int i = 0; x[i] != '\0'; i++) {

			//gets the ASCII value for the given char
			int intValue = x[i] - '0';

			if (intValue >= 0 && intValue <= 9){
				if (intValue >= y){
					printf("The character %c exceeds base %d.\n", x[i], y);
					flag = 1;
					break;
				}
				else {
					int a = intValue * pow(y, len);		//int * 2^(len - n)
					sum = sum + a;
					len = len - 1;
				}
			}

			if (intValue > 9 && intValue < 17){
				printf("The character entered (%c) does not follow base %d logic.\n", x[i], y);
				flag = 1;
				break;
			}
			
			if (intValue >= 17 && intValue <= 22){
				if (intValue - 7 >= y){
					printf("The character %c exceeds base %d.\n", x[i], y);
					flag = 1;
					break;
				}
				else {
					intValue = intValue - 7;
					int a = intValue * pow(y, len);
					sum = sum + a;
					len = len - 1;
				}
			}

			if (intValue > 22){
				printf("The character %c exceeds base %d.\n", x[i], y);
				flag = 1;
				break;
			}
		}
		outcome = sum;
	}
	if (flag == 0){
		return outcome;
	}
	else{
		return -1;
	}
}

void convertToBase(int decimal, char *out_number, int *bitPlace, int base){ 
//converts decimal value to any base

    int quotient; 
    int remain;
    char ch;
    
    quotient = decimal / base;
	remain   = decimal % base;

	if (remain >= 0 && remain <= 9){
		ch = remain + '0';
	}
	if (remain >= 10 && remain <= 15){
		remain = remain + 7;
		ch = remain + '0';
	}
   
    out_number[(*bitPlace)--] = ch;
    
   
	if (quotient != 0) {
		convertToBase(quotient, out_number, bitPlace, base);
	}
 }

char* substring(char *charArray, int begin, int end){
    return strndup(charArray + begin, end);
}


