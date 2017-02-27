/*
	Frazer Bayley
	assignment4/ caesar.hpp
	Last Updated: 2/3/16
*/
#ifndef DATE_HPP_
#define DATE_HPP_

#include "cipher.hpp"

class DateCipher : public Cipher {
public:
	DateCipher();
	 ~DateCipher();
	 std::string setDate( std::string &text );
	 std::string getKey( std::string &text );
	 std::string encrypt( std::string &text );
	 std::string decrypt( std::string &text );
	 std::string myDate;	//hardcoded date
};

#endif /* DATE_HPP_ */