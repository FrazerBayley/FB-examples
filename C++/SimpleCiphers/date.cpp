/*
	Frazer Bayley
	assignment4/ date.cpp
	Last Updated: 2/3/16
*/
//#include <iostream>
//#include <fstream>

//#include "ioutils.hpp"
#include "cipher.hpp"
#include "date.hpp"

// Single-argument constructor
DateCipher::DateCipher() : Cipher(), myDate("12/18/46"){ //hardcoded date to use as the cipher
	// Nothing else to do in the constructor
};

// Destructor
DateCipher::~DateCipher() {
}

std::string
DateCipher::setDate( std::string &inputDate) { //removes the back slashes from the date
    std::string date = inputDate;
    std::string::size_type len = date.length();

    for (int i = 0; i != len; ++i){
        if (date[i] < '0' || date[i] > '9'){
            if (i + 1 < len){ //if next index is not null
                for (int j = i; j != len; ++j){
                    date[j] = date[j + 1];
                }
            } else {
                date[i] = '\0';
            }
        }
    }
    return date;
}

std::string
DateCipher::getKey( std::string &inputText ){   //creates a string of numbers that
                                                // correspond to chars of the input string
    DateCipher dateCipher;
    std::string date = dateCipher.setDate(this->myDate);
    std::string::size_type dateLen = date.length() - 2;
    std::string key = inputText;
    std::string::size_type keyLen = key.length() - 2;

    int counter = 0;
    for (int i = 0; i != keyLen; ++i){
        if (key[i] != ' '){
            key[i] = date[counter % dateLen];
            counter++;
        }
    }
    return key;
}

std::string
DateCipher::encrypt( std::string &inputText ) { //converts string to encrypted string
	std::string text = inputText;
	std::string::size_type len = text.length() - 2;
    DateCipher dateCipher;
    std::string key = dateCipher.getKey(text);

    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i != len; i++){
        if (text[i] >= 'a' && text[i] <= 'z'){
            for (int j = 0; j != lowercase.length(); j++){
                if (text[i] == lowercase[j]){
                    text[i] = lowercase[(j + (key[i] - '0')) % 26];
                    break;                    
                }
            }
        } else if (text[i] >= 'A' && text[i] <= 'Z'){
            for (int k = 0; k != lowercase.length(); k++){
                if (text[i] == capital[k]){
                    text[i] = capital[(k + (key[i] - '0')) % 26]; 
                    break;
                }
            }
        }
    }
	return text;
}

std::string
DateCipher::decrypt( std::string &inputText ) { //removes the encryption and returns string to original
	std::string text = inputText;
	std::string::size_type len = text.length() - 2;

    DateCipher dateCipher;
    std::string key = dateCipher.getKey(text);

    std::string lowercase = "zyxwvutsrqponmlkjihgfedcba";
    std::string capital = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    for (int i = 0; i != len; i++){
        if (text[i] >= 'a' && text[i] <= 'z'){
            for (int j = 0; j != lowercase.length(); j++){
                if (text[i] == lowercase[j]){
                    text[i] = lowercase[(j + (key[i] - '0')) % 26];
                    break;                    
                }
            }
        } else if (text[i] >= 'A' && text[i] <= 'Z'){
            for (int k = 0; k != lowercase.length(); k++){
                if (text[i] == capital[k]){
                    text[i] = capital[(k + (key[i] - '0')) % 26]; 
                    break;
                }
            }
        }
    }
	
	return text;
}

/*
int main(int argc, const char *argv[]){

	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted, key;
	input = io.readFromStream();
	std::cout << "Original text:" << std::endl << input;

	DateCipher dateCipher;
	encrypted = dateCipher.encrypt(input);
	std::cout << "Encrypted text:" << std::endl << encrypted;

	decrypted = dateCipher.decrypt(encrypted);
	std::cout << "Decrypted text:" << std::endl << decrypted;

	return 0;
}
*/