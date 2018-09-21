#include <algorithm>
#ifndef MERGESORT_H_
#define MERGESORT_H_

//[left,right]
template <typename T>
void MergeSort(T ar[],T temp[],int left,int right,bool (*prior)(T const&,T const&))
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(ar,temp,left,mid,prior);//[left,mid]
		MergeSort(ar,temp,mid+1,right,prior);//[mid+1,right]
		//the follow steps is Merge
		for(int i = left;i <= mid;++i)
			temp[i] = ar[i];
		for(int i = mid+1;i <= right;++i)//倒置存入
			temp[mid + right-i + 1] = ar[i];
		for(int l = left,r = right,k = left;k <= right;++k)
			if(prior(temp[l],temp[r]))
				ar[k] = temp[l++];
			else
				ar[k] = temp[r--];
	}
}

/*
下面这种实现，是把拍好的结果放在temp，然后复制回array
上面是把array复制到temp，把结果放在array
*/
//合并
void Merge2(int array[],int TempArray[],int begin,int middle,int end)
{
	int i = begin,j = middle + 1,k = begin;
	while(i != middle + 1 && j != end + 1)
	{
		if(array[i] < array[j])
			TempArray[k++] = array[i++];
		else
			TempArray[k++] = array[j++];
	}
	while(i != middle + 1)
		TempArray[k++] = array[i++];
	while(j != end + 1)
		TempArray[k++] = array[j++];
	memcpy(array + begin,TempArray + begin,(end - begin + 1)*sizeof(int));
}
//排序
void MergeSort2(int array[],int TempArray[],int begin,int end)
{
	if(begin < end)
	{
		int middle = (begin + end) / 2;
		MergeSort(array,TempArray,begin,middle);
		MergeSort(array,TempArray,middle+1,end);
		Merge(array,TempArray,begin,middle,end);
	}
}

#endif