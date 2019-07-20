#include<iostream>
#include<math.h>
using namespace std ;
class point
{
	float height ; 
	float weight ;
	bool label ;
	public:
	point(float new_height ,float new_weight , bool new_label )
	{
		height  = new_height;
		weight = new_weight ;
		label = new_label ; 
	}
	void print_point();
	float euc_distance(point);

};
void point::print_point()
{
	cout<<"height ---->"<<this->height;
	cout<<"\tweight ---->"<<this->weight;
	cout<<"\tlabel -->"<<this->label<<endl;
}
class KNN
{
	point *data_points[10];
	public :
	KNN()
	{
		float points[10][10] = {{4,5},
		{6,4},
		{3,5},
		{3,2},
		{6,8},
		{1,5},
		{5,3},
		{6,3},
		{9,2},
		{6,6}
		};
		bool labels[10]  = {1,0,1,0,1,1,0,1,0,1} ; //abnormal-->1 , normal -->0
		for(int i = 0 ; i < 10 ; i++)
		{	
			//allocate some points
			data_points[i] = new point(points[i][0] , points[i][1] , labels[i]) ;
		
		}
	}
	void print_data();
		
};
void KNN::print_data()
{
	for(int i = 0 ; i<10 ; i++)
	{
		data_points[i]->print_point();
	}
}
float point:: euc_distance(point p)
{
	float distance = 0;
	distance = sqrt(pow((this->height - p.height ),2) + pow((this->weight - p.weight ),2));
	return distance;
}
int main()
{	
	//point p1(1,1);
	//point p2(0 ,0);
	//cout<<p1.euc_distance(p2);
	KNN model ;
	model.print_data();
}
