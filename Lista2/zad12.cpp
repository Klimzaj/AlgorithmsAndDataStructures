#include <iostream>

using namespace std;

struct node
{
    int x;
    node* left;
    node* right;
    node* parent;
    node(int _val, node* _l=NULL, node* _r=NULL, node* _p=NULL)
        :x(_val),left(_l),right(_r),parent(_p)
    {}
};

void insert(node *& _t, int _x)
{
    node **temp = &_t;
    while(*temp)
    {
		if((*temp)->x>_x)
		{
			temp = &((*temp)->left);
		}
		else temp = &((*temp)->right);
    }
    node *d = *temp;
    *temp = new node(_x);
    (*temp)->parent = d;
}

void remove(node *& _t, int _x)
{
    node **temp = &_t;
    node **parent = &((*temp)->parent);

    while(*temp)
    {
        parent = temp; 
		if((*temp)->x>_x)
		{
			temp = &((*temp)->left);
		}
		else temp = &((*temp)->right);
    }
    // cout<< (*temp)->x<<endl;

    if(*temp)
    {
        if((*temp)->left && (*temp)->right)
		{
			node **delta=&((*temp)->left);
			delta=&((*delta)->left);

			while ((*delta)->right)
				delta=&((*delta)->right);

			(*temp)->x=(*delta)->x;
			(*temp)->left=(*delta)->left;
			(*temp)->right=(*delta)->right;

			// delta=temp;
			delete *delta;
		}
        // if((*temp)->left && (*temp)->right)
        // {
        //     node **delta=&((*temp)->right);
		// 	while ((*delta)->left)
		// 		delta=&((*delta)->left);
		// 	(*temp)->x=(*delta)->x;
		// 	temp=delta;
        // }
        else if((*temp)->left == NULL && (*temp)->right == NULL)
        {
            if((*parent)->left->x == _x)
            {
                (*parent)->left = NULL;
            }
            else
            {
                 (*parent)->right = NULL;
            }
            delete *temp;
        }
        else if((*temp)->left == NULL)
        {
            node* delta = (*temp)->right;
			delete *temp;
			(*temp) = delta;
        }
        else
        {
            node* delta = (*temp)->left;
			delete *temp;
			(*temp) = delta;
        }
        
        
    }

}

void remove2(node *& _t, int _x)
{
	node** delta = &_t;
    node** parent = &((*delta)->parent);

	while(*delta && (*delta)->x!=_x)
	{
        parent = delta;
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

			if((*parent)->left != NULL && (*parent)->left->x == _x)
			{
				(*parent)->left = NULL;
			}
			else if((*parent)->right != NULL && (*parent)->right->x == _x)
			{
				(*parent)->right = NULL;
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
    remove2(root,2);
    cout<<root->x << " "<< root->right->x << " " << root->right->right->x << endl;
    // insert

    return 0;
}
