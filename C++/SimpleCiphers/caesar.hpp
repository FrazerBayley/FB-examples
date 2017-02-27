/*
	Frazer Bayley
	assignment4/ caesar.hpp
	Last Updated: 2/1/16
*/
#ifndef CAESAR_HPP_
#define CAESAR_HPP_

#include "cipher.hpp"

class CaesarCipher : public Cipher {
public:
	CaesarCipher();
	~CaesarCipher();
	std::string encrypt( std::string &text );
	std::string decrypt( std::string &text );
};

#endif /* CAESAR_HPP_ */