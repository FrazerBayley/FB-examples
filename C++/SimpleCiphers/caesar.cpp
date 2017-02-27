/*
	Frazer Bayley
	assignment4/ caesar.cpp
	Last Updated: 2/1/16
*/
//#include <iostream>
//#include <fstream>

//#include "ioutils.hpp"
#include "cipher.hpp"
#include "caesar.hpp"

// Single-argument constructor
CaesarCipher::CaesarCipher() : Cipher(){
	// Nothing else to do in the constructor
}

// Destructor
CaesarCipher::~CaesarCipher() {
}

// Overloaded encrypt method
std::string
CaesarCipher::encrypt( std::string &inputText ) {
	std::string text = inputText;
	std::string::size_type len = text.length();
	for (int i = 0; i != len; ++i) {
        if (text[i] >= 'a' && text[i] <= 'x') {
            text[i] = text[i] + 2;
        } else if(text[i] >= 'A' && text[i] <= 'X') {
            text[i] = text[i] + 2;
        } else if(text[i] == 'y' || text[i] == 'Y'){
        	text[i] = ' ';
        } else if(text[i] == 'z'){
        	text[i] = 'a';
        } else if(text[i] == 'Z'){
        	text[i] = 'A';
        } else if(text[i] == ' '){
        	text[i] = 'b';
        }
	}
	return text;
}

std::string
CaesarCipher::decrypt( std::string &text ) {
	std::string outputText = text;
	std::string::size_type len = outputText.length();
	for (int i = 0; i != len; ++i) {
        if (outputText[i] >= 'c' && outputText[i] <= 'z') {
            outputText[i] = outputText[i] - 2;
        } else if(outputText[i] >= 'C' && outputText[i] <= 'Z') {
            outputText[i] = outputText[i] - 2;
        } else if(outputText[i] == ' '){
        	outputText[i] = 'y';
        } else if(outputText[i] == 'a'){
        	outputText[i] = 'z';
        } else if(outputText[i] == 'A'){
        	outputText[i] = 'Z';
        } else if(outputText[i] == 'b'){
        	outputText[i] = ' ';
        }
	}
	return outputText;
}

/*
int main(int argc, const char *argv[]){

	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = io.readFromStream();
	std::cout << "Original text:" << std::endl << input;

	CaesarCipher caesar;
	encrypted = caesar.encrypt(input);
	std::cout << "Encrypted text:" << std::endl << encrypted;

	decrypted = caesar.decrypt(encrypted);
	std::cout << "Decrypted text:" << std::endl << decrypted;

	return 0;
}
*/