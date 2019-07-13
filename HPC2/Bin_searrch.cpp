#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include<bits/stdc++.h>
#define max 10
using namespace std;
int found=0;

int binary(int *, int, int, int);

int binarySearch(int *a, int low, int high, int key)
{
	int mid;	
	mid=(low+high)/2;
	int low1,low2,high1,high2,mid1,mid2,loc=-1;

	#pragma omp parallel sections
	{
	    #pragma omp section
    	{ 
			low1=low;
			high1=mid;
			
			while(low1<=high1)
			{
				if(!(key>=a[low1] && key<=a[high1]))
				{
					low1=low1+high1;
					continue;
				}
				
				mid1=(low1+high1)/2;
				
				if(key==a[mid1])
				{
					found=1;
					loc=mid1;
					low1=high1+1;
				}
				else if(key>a[mid1])
				{

					low1=mid1+1;
				}
				
				else if(key<a[mid1])
					high1=mid1-1;
			
			}
		}
				   			
			#pragma omp section
    		{ 
      		low2=mid+1;
			high2=high;
			while(low2<=high2)
			{
				if(!(key>=a[low2] && key<=a[high2]))
				{
					low2=low2+high2;
					continue;
				}
				
				
				mid2=(low2+high2)/2;
				
				if(key==a[mid2])
				{

					found=1;
					loc=mid2;
					low2=high2+1;	
				}									
				else if(key>a[mid2])
				{

				low2=mid2+1;
				}
				else if(key<a[mid2])
				high2=mid2-1;

			}	
    		}
	}
	return loc+1;
}


int main()
{	
	int n,key,pos;
	cout<<"\nEnter size of array : ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	int m = sizeof(a)/sizeof(a[0]); 
	sort(a,a+m);
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\nEnter the key to be searched : ";
	cin>>key;
	pos=binarySearch(a,0,n,key);
	if(found)
	{
		cout<<"\nKey fouund at location : "<<pos;
	}
	else
		cout<<"\nKey not found";
		
	cout<<endl;	
	
	return 0;
}

