/*
	Frazer Bayley
	assignment4/ test-date.cpp
	Last Updated: 2/3/16
*/
#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "date.hpp"

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