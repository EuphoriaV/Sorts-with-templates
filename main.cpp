#include "phonebook.h"
#include "quicksort.h"
#include "return_codes.h"
#include <fstream>
#include <iostream>
#include <new>
std::ifstream& operator>>(std::ifstream& in, phonebook& pb)
{
	in >> pb.surname >> pb.name >> pb.fathersName >> pb.number;
	return in;
}
std::ofstream& operator<<(std::ofstream& out, phonebook& pb)
{
	out << pb.surname << " " << pb.name << " " << pb.fathersName << " " << pb.number;
	return out;
}
template< typename T, bool isDescending >
int readSortPrint(std::ifstream& in, size_t n, char* name)
{
	T* arr = new (std::nothrow) T[n];
	if (arr == NULL)
	{
		return -1;
	}
	std::ofstream out(name);
	if (!out.is_open())
	{
		delete[] arr;
		return -2;
	}
	for (size_t i = 0; i < n; i++)
	{
		in >> arr[i];
	}
	quicksort< T, isDescending >(arr, n);
	for (size_t i = 0; i < n; i++)
	{
		out << arr[i] << "\n";
	}
	delete[] arr;
	out.close();
	return 0;
}
int main(int argc, char** argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "Wrong number of arguments");
		return ERROR_INVALID_PARAMETER;
	}
	std::ifstream in(argv[1]);
	if (!in.is_open())
	{
		fprintf(stderr, "Couldn't open input file");
		return ERROR_FILE_NOT_FOUND;
	}
	std::string type;
	std::string descending;
	in >> type;
	int intType = type == "int" ? 1 : (type == "float" ? 2 : 3);
	in >> descending;
	bool isDescending = (descending == "descending") ? true : false;
	size_t n;
	in >> n;
	int res;
	switch (intType)
	{
	case 1:
	{
		if (isDescending)
		{
			res = readSortPrint< int, true >(in, n, argv[2]);
		}
		else
		{
			res = readSortPrint< int, false >(in, n, argv[2]);
		}
		break;
	}
	case 2:
	{
		if (isDescending)
		{
			res = readSortPrint< double, true >(in, n, argv[2]);
		}
		else
		{
			res = readSortPrint< double, false >(in, n, argv[2]);
		}
		break;
	}
	case 3:
	{
		if (isDescending)
		{
			res = readSortPrint< phonebook, true >(in, n, argv[2]);
		}
		else
		{
			res = readSortPrint< phonebook, false >(in, n, argv[2]);
		}
	}
	}
	in.close();
	if (res == -1)
	{
		fprintf(stderr, "Couldn't allocate memory");
		return ERROR_NOT_ENOUGH_MEMORY;
	}
	if (res == -2)
	{
		fprintf(stderr, "Couldn't open/create output file");
		return ERROR_FILE_NOT_FOUND;
	}
	return ERROR_SUCCESS;
}
