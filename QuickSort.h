#include <algorithm>
#ifndef QUICKSORT_H_
#define QUICKSORT_H_

template<typename T>
int partition(T ar[],int left,int right,bool(*prior)(T const&,T const&))//划分两个部分，并返回轴值所在的下标，(left,right)
{
	int pivotIndex = (left + right) / 2;//use mid as the pivot index, a random value will be better, but it may cause more time to produce it
	T pivot = ar[pivotIndex];
	std::swap(ar[right],ar[pivotIndex]);//put the pivot at the end
	//the follow steps is partitioning the array and finding the final pivot index (vaiable l is it).
	int l = left - 1,r = right;//(l,r)
	do{
		while(prior(ar[++l],pivot));
		while(l < r && prior(pivot,ar[--r]));
		std::swap(ar[l],ar[r]);
	}while(l < r);
	std::swap(ar[l],ar[right]);//put the pivot at the pivot index
	return l;
}

template <typename T>
void QuickSort(T ar[],int left,int right,bool(*prior)(T const&,T const&))//[left,right]
{
	if(left >= right)//don't sort 0 or 1 elements
		return;
	int pivotIndex = partition(ar,left,right,prior);//partition the arary and get the index of pivot
	QuickSort(ar,left,pivotIndex-1,prior);//sort the left subarray
	QuickSort(ar,pivotIndex+1,right,prior);//sort the right subarray
}


#endif