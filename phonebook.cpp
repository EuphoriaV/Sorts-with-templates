#include "phonebook.h"
int compare(phonebook a, phonebook b)
{
	if (a.surname.compare(b.surname))
	{
		return a.surname.compare(b.surname);
	}
	else if (a.name.compare(b.name))
	{
		return a.name.compare(b.name);
	}
	else if (a.fathersName.compare(b.fathersName))
	{
		return a.fathersName.compare(b.fathersName);
	}
	else if (a.number > b.number)
	{
		return 1;
	}
	else if (a.number < b.number)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
bool operator>(phonebook a, phonebook b)
{
	return compare(a, b) == 1;
}
bool operator<(phonebook a, phonebook b)
{
	return compare(a, b) == -1;
}
