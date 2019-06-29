#include<iostream>
using namespace std ;
void disp( int* a )
{
	for(int i = 0 ; i < 6 ; i++)
	{
		cout<<a[i]<<" " ; 
	}
	cout<<"\n";
}
int main()
{
	int a[6] ={5,4,3,2,1,0}, n = 0 , temp = 0;
	cout<<" before sorting "<<endl;
	disp(a);
	for(int i = 0 ; i < 6 ; i++)
	{
		for(int j = 0 ; j < 5; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j+1] ; 
				a[j+1] = a[j];
				a[j] = temp ; 
			}
		}
	}
	cout<<"after sorting " <<endl;
	disp(a);
	
		
}
