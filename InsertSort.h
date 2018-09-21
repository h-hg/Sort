
#include <algorithm>
#ifndef INSERTSORT_H_
#define INSERTSORT_H_
//swap insertsort
template <typename T>
void InsertSort(T ar[],int n,bool (*prior)(T const&,T const&))
{
	for(int i = 1;i < n;++i)
		for(int j = i; j > 0 && prior(ar[j],ar[j-1]);--j)
			std::swap(ar[j],ar[j-1]);
}

//move swap insertsort
template <typename T>
void InsertSort_move(T ar[],int n,bool (*prior)(T const&,T const&))
{

	for(int i = 1;i < n;++i)
	{
		int j = i;
		auto foo = ar[i];
		for(; j > 0 && prior(foo,ar[j-1]);--j)
			ar[j] = ar[j-1];
		ar[j] = foo;
	}
}
#endif