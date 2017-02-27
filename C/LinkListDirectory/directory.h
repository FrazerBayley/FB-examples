#ifndef DIRECTORY_H_
#define DIRECTORY_H_

void getName(char* name, const int nl);

void getPhoneNumber(char* phone_number, const int nl);

void addContact(char* name, char* phone_number, int count);

void displayDirectory();

void deleteContact(int n);

#endif /* DIRECTORY_H_ */