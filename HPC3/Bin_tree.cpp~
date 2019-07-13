#include<iostream>
#include<omp.h>
#include<vector>
using namespace std ; 

//image(wall)-->x time later --> ti padli
/*
normal programming:
	input -> data , rules
	o/p -> ans.
	
M/L programming:
	input -> data , ans
	o/p -> rules

*/
class node
{	public:
	int n ;
	node *left  , *right ;
	/*node()
	{
		left = right = NULL ;
	}*/

};
class tree
{	public:
	node *head ; 
	
	tree()
	{
		head = NULL ; 
	}
	void insert(int);
	node* create(int);
	void inorder(node* );
	vector<node*> queue ;
	void BFS(node* root);
};
void tree :: BFS(node* root)
{
	queue.push_back(root);
	node *temp ; 
	//vector<node*>::iterator it;
	//it = queue.begin();
	/*while(1)
	{
		while(!queue.empty())
		{
			temp = queue.front();
			queue.erase(it);
			cout<<temp->n<< " ";
			it++;
		}
	//	it++;
		if(temp->left!=NULL)
		{
			queue.push_back(temp->left);
		}
		if(temp->right!=NULL)
		{
			queue.push_back(temp->right);
		}
		if(queue.empty())
		{
			break;
		}
		
	}	*/
	
	while(!queue.empty())
	{	//cout<<"in function"<<endl;
		temp = queue.front();
		//cout<<"reading first element"<<endl;
		queue.erase(queue.begin());
		//cout<<"erasing first element"<<endl ; 
		
		
			cout<<temp->n<< " ";
		//it++;
		
		#pragma omp parallel sections
		{
			if(temp->left!=NULL)
			{	//cout<<"added left node"<<endl;
				queue.push_back(temp->left);
			}
			if(temp->right!=NULL)
			{	//cout<<"added right node"<<endl;
				queue.push_back(temp->right);
			}
		}
	}
	
	
}
void tree :: inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<ptr->n<<" ";
		inorder(ptr->right);
	}
}
node* tree:: create(int num)
{
	node *temp = new(node) ;
	temp->right = NULL;
	temp->left = NULL;
	temp ->n = num ;
	return temp;
}
void tree::insert(int num)
{
	node *ptr , *temp , *next;
	if(head == NULL)
	{
		ptr = this->create(num);
		head = ptr;
	}
	else
	{
		ptr = head ; 
		temp = this->create(num);
		while(ptr!=NULL)
		{
			if(ptr->n >= num)
			{
				if(ptr->left!=NULL)
				{
				    ptr = ptr->left ;
					//cout<<"moving left"<<endl;
				}
				else
				{
					ptr->left = temp ; 
					break;
				}
			}
			else if(ptr->n < num)
			{
				//cout<<ptr->n<<" "<<endl;
				if(ptr->right!=NULL)
				{
				    ptr = ptr->right ; 
					//cout<<"moving right"<<endl;
				}
				else
				{
					ptr->right = temp ;
					break ; 
				}
				
			}
			
		}
			
	}
}
int main()
{
	tree t1 ; 
	int n ; 
	cout<<"enter the number of elements to insert:";
	cin>>n;
	int x = 0;
	cout<<"insert nos"<<endl;
	for(int i = 0; i < n ; i++)
	{
		cin>>x;
		t1.insert(x);
	}
	
	//t1.insert(1);
	t1.inorder(t1.head);
	cout<<"\nbfs"<<endl;
	t1.BFS(t1.head);
	return 0 ; 
}
