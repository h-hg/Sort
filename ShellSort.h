#include <algorithm>
#ifndef SHELLSORT_H_
#define SHELLSORT_H_

//swap Shell sort
template <typename T>
void ShellSort(T ar[],int n,bool (*prior)(T const&,T const&))
{
	for(int gap = n/2;gap > 0;gap/=2)//gap 间距
		for(int j = 0;j < gap;++j)//对每个子序列进行插入排序
			//insert sort
			for(int k = j + gap;k < n;k+=gap)
				for(int l = k;l >= gap && prior(ar[l],ar[l-gap]);l -= gap)
					std::swap(ar[l],ar[l-gap]);
}

//move shell sort
template<typename T>
void ShellSort_move(T ar[],int n,bool (*prior)(T const&,T const&))
{
	for(int gap = n/2;gap > 0;gap/=2)//gap 间距
		for(int j = 0;j < gap;++j)//对每个子序列进行插入排序
			//insert sort
			for(int k = j + gap;k < n;k+=gap)
			{
				int l = k;
				auto foo = ar[l];
				for(;l >= gap && prior(foo,ar[l-gap]);l -= gap)
					ar[l] = ar[l-gap];
				ar[l] = foo;
			}
}
#endif