#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<omp.h>
using namespace std;

class Person
{
	public:
	int height,weight;
	float ED;
	int group;
	
};

bool comparison(Person a, Person b)
{
	return (a.ED < b.ED); 
}

int classifyPerson(Person arr[], int n, int k, Person p) 
{ 
	// Fill EDs of all points from p 
	#pragma omp parallel for 
	for (int i = 0; i < n; i++) 
		arr[i].ED = 
			sqrt((arr[i].height - p.height) * (arr[i].height - p.height) + 
				(arr[i].weight - p.weight) * (arr[i].weight - p.weight));
				
	sort(arr, arr+n, comparison); 
	
	int freq1 = 0;	 // Frequency of group 0 
	int freq2 = 0;	 // Frequency of group 1 
	for (int i = 0; i < k; i++) 
	{ 
		if (arr[i].group == 0) 
			freq1++; 
		else if (arr[i].group == 1) 
			freq2++; 
	} 

	return (freq1 > freq2 ? 0 : 1); 	
}

int main() 
{ 
	int n = 11; // Number of persons 
	Person arr[n]; 

	arr[0].height = 178; 
	arr[0].weight = 59; 
	arr[0].group = 0; 

	arr[1].height = 179; 
	arr[1].weight = 62; 
	arr[1].group = 0; 

	arr[2].height = 179; 
	arr[2].weight = 90; 
	arr[2].group = 1; 

	arr[3].height = 160; 
	arr[3].weight = 65; 
	arr[3].group = 1; 

	arr[4].height = 165; 
	arr[4].weight = 50; 
	arr[4].group = 0; 

	arr[5].height = 170; 
	arr[5].weight = 80; 
	arr[5].group = 1; 

	arr[6].height = 172; 
	arr[6].weight = 75; 
	arr[6].group = 1; 

	arr[7].height = 185; 
	arr[7].weight = 85; 
	arr[7].group = 1; 

	arr[8].height = 176; 
	arr[8].weight = 70; 
	arr[8].group = 1; 


	arr[9].height = 170; 
	arr[9].weight = 65; 
	arr[9].group = 0; 

	arr[10].height = 177; 
	arr[10].weight = 68; 
	arr[10].group = 0; 

	/*Testing Point*/
	Person p;
	
	cout<<"\n Enter Height of Person : ";
	cin>>p.height;
	cout<<"\n Enter Weight of Person : ";
	cin>>p.weight;
	 
	 

	// Parameter to decide group of the testing person 
	int k = 3; 
	cout<<"\nThe group classified to unknown person"
			" is : "<< classifyPerson(arr, n, k, p); 
	cout<<endl;		
	return 0; 
} 	
			
