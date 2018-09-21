#include <algorithm>
#ifndef HEAPSORT_H_
#define HEAPSORT_H_

template <typename T>
void siftDown(T ar[],int n,int root,bool(*prior)(T const&,T const&))
{
	while(!(root >= n/2 && root < n))
	{
		int lc = root * 2 + 1,rc = lc + 1;
		if(rc < n && prior(ar[rc],ar[lc]))
			lc = rc;
		if(prior(ar[root],ar[lc]))
			break;
		std::swap(ar[root],ar[lc]);
		root = lc;
	}
}
template <typename T>
void HeapSort(T ar[],int n,bool(*prior)(T const&,T const&))
{
	//build heap
	for(int root = n/2-1;root >= 0;--root)
		siftDown(ar,n,root,prior);
	for(int i = n;i > 1;)
	{
		std::swap(ar[0],ar[--i]);//move the highest priority to the end
		siftDown(ar,i,0,prior);//rebuild heap
	}
	//reverse the array
	for(int i = 0;i < n/2;++i)
		std::swap(ar[i],ar[n-i-1]);
}

#endif