#include <iostream>

using namespace std;

struct node
{
    int x;
    node* left;
    node* right;

    node(int val, node* l=NULL, node* r=NULL)
		:x(val), left(l), right(r)
	{}
};

void insert(node *& t, int x)
{
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new node(x);
}  

void remove(node *& _t, int _x)
{
	node** delta = &_t;
    node** delta2 = &_t;
	while(*delta && (*delta)->x!=_x)
	{
        delta2 = delta;
		if((*delta)->x>_x)
		{
			delta = &((*delta)->left);
		}
		else delta = &((*delta)->right);
	}
	if(*delta)
	{
		cout << "test" << endl;
		if((*delta)->left && (*delta)->right)
		{
			cout<<"Dwie galezie zajete"<<endl;

			node **temp=&((*delta)->left);
			// cout <<(*temp)<<endl;
			temp=&((*temp)->left);

			while ((*temp)->right != NULL)
				temp=&((*temp)->right);

			// cout<<"po while, temp: "<<(*temp)->x<<" delta: "<<(*delta)->x<<endl;

			(*delta)->x=(*temp)->x;

			// cout << (*delta)->x <<endl;

			if((*delta)->left != NULL)
			{
				(*delta)->left=(*temp)->left;
			}
            else if((*delta)->right != NULL)
            {
				(*delta)->right=(*temp)->right;
            }


			// delta=temp;
			delete *temp;
		}
		//dziala
        else if((*delta)->left == NULL && (*delta)->right == NULL)
        {
			cout<< "right&left = NULL"<< endl;
			// if((*delta2)->left!=NULL ? (*delta)->x == _x)

			if((*delta2)->left != NULL && (*delta2)->left->x == _x)
			{
				(*delta2)->left = NULL;
			}
			else if((*delta2)->right != NULL && (*delta2)->right->x == _x)
			{
				(*delta2)->right = NULL;
			}

            delete *delta;
        }
		// dziala
		else if((*delta)->left == NULL)
		{
			cout<< "left = NULL"<< endl;
			node* temp = (*delta)->right;
			delete *delta;
			(*delta) = temp;
		}
		// dziala
		else
		{
			cout<< "right = NULL"<< endl;
			node* temp = (*delta)->left;
			delete *delta;
			(*delta) = temp;
		}	
	}
}

int main()
{
	node* root = NULL;
	insert(root,2);
	insert(root,5);
	insert(root,6);
	insert(root,4);
	insert(root,3);
	insert(root,7);
	cout<<root->x << " "<< root->right->x << " " << root->right->right->x << endl;
	remove(root,5);
	cout<<root->x << " "<< root->right->x << " " << root->right->right->x << endl;

    return 0;
}