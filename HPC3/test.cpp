#include<iostream>
using namespace std ; 
#define MAX 5
int* add_1(int *a)
{	
	for(int i = 0 ; i< MAX ; i++)
	{
		a[i]+=1;
	}
	cout<<"\n";
	return a ; 
}
int main()
{
	int a[5] = {1,2,3,4,5};
	int *temp;
	temp = add_1(a);
	for(int i = 0 ; i< 5; i++)
	{
		cout<<temp[i];
	}
	return 0;
}
