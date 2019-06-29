#include<iostream>
#include<omp.h>
#include<stdlib.h>
#define MAX 50
using namespace std ;
void disp( int* a )
{
	for(int i = 0 ; i < MAX ; i++)
	{
		cout<<a[i]<<" " ; 
	}
	cout<<"\n";
}
void bubblesort( int* a)
{	int temp = 0;
	for(int i = 0 ; i < MAX ; i++)
	{
		for(int j = 0 ; j < MAX -1; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j+1] ; 
				a[j+1] = a[j];
				a[j] = temp ; 
			}
		}
	}
}
void oddeven_bubblesort(int* a)
{
	
	for(int i = 0 ; i < MAX ; i++)
	{
		//odd phase
		//#pragma omp parallel for
		for(int j = 1 ; j < MAX-1 ; j+=2)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j] , a[j+1]);
			}
		}
		//even phase
		//#pragma omp parallel for
		for(int k = 0 ; k < MAX -1 ; k+=2)
		{
			if(a[k] > a[k+1])
			{
				swap(a[k] , a[k+1]);
			}
		}
	}
}
int main()
{
	int a[50];
	for(int i = 0 ; i < MAX ; i++)
	{
		a[i] = rand()%1000;
	}
	cout<<" before sorting "<<endl;
	disp(a);
	oddeven_bubblesort(a);
	cout<<"after sorting " <<endl;
	disp(a);
	
		
}
