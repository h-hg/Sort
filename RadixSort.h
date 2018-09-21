#ifndef RADIXSORT_H_
#define RADIXSORT_H_
template <typename T>
void RadixSort(T ar[],T bin[],int n,int k,int r,int cnt[],int (*getKey)(T const&))
//k = the count of loop, r = radix, cnt[i] stores number of records in bin[i]
{
	for(int i = 0,rtoi = 1;i < k;++i,rtoi *= r)//rtoi = r^i
	{
		//initialize cnt
		for(int j = 0;j < r;++j)
			cnt[j] = 0;
		//cout the number of records for each bin on this pass
		for(int j = 0;j < n;++j)
			cnt[(getKey(ar[j])/rtoi)%r]++;
		//index bin:cnt[j] will be index for last slot of bin j
		for(int j = 1;j < r;++j)
			cnt[j] += cnt[j-1];
		//put records into bins, work from bottom of each bin, since bins fill from bottom, j counts donwwars
		for(int j = n-1;j>=0;--j)
			bin[--cnt[ (getKey(ar[j])/rtoi) %r]] = ar[j];
		//copy bin to ar
		for(int j = 0;j < n;++j)
			ar[j] = bin[j];
	}
}
#endif