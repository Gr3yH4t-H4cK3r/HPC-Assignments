#include<iostream>
#include<omp.h>
#include<stdlib.h>
#define MAX 10
using namespace std ;
void merge(int *a , int low , int high);
void mergesort(int* a , int low , int high);

void mergesort(int * a , int low , int high)
{	
	//#pragma omp parallel 
	if(low < high)
	{
		mergesort(a , low , (low+high)/2);
		mergesort(a , ((low+high)/2)+1 , high);
		merge(a , low , high);
	}
}
void merge(int* a , int low , int high)
{
	int temp[100];
	int mid = ((low+high)/2); 
	int i = low , j = mid  ;
	int index = 0 ; 
	while(i < mid && j < high)
	{
		if(a[i] > a[j])
		{
			temp[index] = a[j];	
			j++;
		}
		else
		{
			temp[index] = a[i];
		     i++ ; 
	     }
		 
		index++;
	}
	while(i < mid)
	{
		//store remaining items
		temp[index] = a[i];
		i++ , index++;
		
	}
	
	while( j < high)
	{
		//store remaining items
		temp[index] = a[j];
		j++ , index++;
	}
	int f = 0;
	for(int k = low ; k < high ; k++)
	{
		a[k] = temp[f];
		f++;
		
	}
	/*for(int f = 0 ; f < index ; f++)
		cout<<temp[f]<<" ";
	cout<<endl;*/
}
int main()
{
	int a[5] = {13,12,4,3,5};
	mergesort(a , 0 , 5);
	for(int i = 0 ; i< 5; i++)
		cout<<a[i]<< " ";
	return 0 ;
}
