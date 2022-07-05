#pragma once
#include <algorithm>
#include <random>
template< typename T, bool isDescending >
bool compare(T a, T b)
{
	if ((isDescending && a > b) || (!isDescending && a < b))
	{
		return 1;
	}
	return 0;
}
template< typename T, bool isDescending >
size_t pivot(T* arr, size_t l, size_t r)
{
	size_t pivot = l + (rand() % (r - l + 1));
	std::swap(arr[l], arr[pivot]);
	size_t count = l + 1;
	for (size_t i = l + 1; i <= r; i++)
	{
		if (compare< T, isDescending >(arr[i], arr[l]))
		{
			std::swap(arr[i], arr[count]);
			count++;
		}
	}
	count--;
	std::swap(arr[l], arr[count]);
	return count;
}
template< typename T, bool isDescending >
void quicksortImpl(T* arr, size_t l, size_t r)
{
	while (l < r)
	{
		size_t q = pivot< T, isDescending >(arr, l, r);
		if (q - l < r - q)
		{
			quicksortImpl< T, isDescending >(arr, l, q);
			l = q + 1;
		}
		else
		{
			quicksortImpl< T, isDescending >(arr, q + 1, r);
			r = q;
		}
	}
}
template< typename T, bool isDescending >
void quicksort(T* arr, size_t n)
{
	srand(time(NULL));
	quicksortImpl< T, isDescending >(arr, 0, n - 1);
}
