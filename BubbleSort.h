#include <algorithm>
#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

/*template <typename T>
void BubbleSort(T ar[],int n,bool (*prior)(T const&,T const&))
{
	for(int i = 0;i < n;++i)
	{
		bool finish = true;
		for(int j = i + 1;j < n;++i)
			if(prior(ar[j],ar[i]))
			{
				std::swap(ar[j],ar[i]);
				finish = false;
			}
		if(finish)
			break;
	}
}*/

void BubbleSort(T ar[],int n,bool (*prior)(T const&,T const&))
{
	bool swapped;
	do{
		swapped = false;
		for(int i = 1;i < n;++i)
			if(prior(ar[i],ar[i-1]))
			{
				swapped = true;
				std::swap(ar[i],ar[i-1]);
			}
	}while(swapped)
}
#endif