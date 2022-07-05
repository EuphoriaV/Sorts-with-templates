#pragma once
#include <iostream>
struct phonebook
{
	std::string surname;
	std::string name;
	std::string fathersName;
	long long number;
};
int compare(phonebook a, phonebook b);
bool operator>(phonebook a, phonebook b);
bool operator<(phonebook a, phonebook b);
