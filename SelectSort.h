#include <algorithm>
#ifndef SELECTSORT_H_
#define SELECTSORT_H_

template <typename T>
void SelectSort(T ar[],int n,bool (*prior)(T const&,T const&))
{
	for(int i = 0;i < n;++i)
	{
		int index = i;
		for(int j = i + 1;j < n;++j)
			if(prior(ar[j],ar[index]))
				index = j;
		std::swap(ar[index],ar[i]);
	}
}

#endif