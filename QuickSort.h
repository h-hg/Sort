#include <algorithm>
#ifndef QUICKSORT_H_
#define QUICKSORT_H_

void QuickSort(int array[],int begin,int end)
{
	if(begin >= end)
		return;
	int i = begin,j = end,key = array[i];//key 充当分界点
	while(i < j)
	{
		while(i < j && array[j] >= key)
			--j;
		array[i] = array[j];//小的复制到前面，第一次将key覆盖掉，内容中有多出的array[j]的值
		while(i < j && array[i] <= key)
			++i;
		array[j] = array[i];//大的复制到后面，覆盖掉前面多出的array[j]的值
	}
	array[i] = key;//此时i = j，填补 第一次将key的值覆盖掉
	QuickSort(array,begin,i - 1);
	QuickSort(array,i + 1,end);
}

template <typename T>
void QuickSort(T ar[],int left,int right,bool(*prior)(T const&,T const&))
{

}
#endif