#include<iostream>
#include<stdlib.h>
#include<omp.h>
#define max 10
using namespace std;

void merge_sort(int *a, int low, int high);
void merge(int *a, int low, int high);
void display(int a);

void display(int a[max])
{
	for(int i=0;i<max;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}


void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		#pragma omp parallel sections num_threads(2)
		{
			// Split the data into two half.
			#pragma omp section
			{	
				MergeSort(a, low, mid);
			}	
			#pragma omp section
			{
				MergeSort(a, mid+1, high);
			}
		}	
			Merge(a, low, high, mid);
		
	}
}

int main()
{	
	int a[max];
	for(int i=0;i<max;i++)
	{
		a[i]=rand()%100;
	}
	cout<<"\nArray before sorting :\n";
	display(a);
	MergeSort(a,0,max);
	cout<<"\nArray after sorting :\n";
	display(a);
	
	return 0;
}
