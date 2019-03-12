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
    node **parent = &(*temp)->parent;

    while(*temp)
    {
        parent = temp; 
		if((*temp)->x>_x)
		{
			temp = &((*temp)->left);
		}
		else temp = &((*temp)->right);
    }

    if(*temp)
    {
        if((*delta)->left && (*delta)->right)
		{
			node **temp=&((*delta)->left);
			temp=&((*temp)->left);

			while ((*temp)->right)
				temp=&((*temp)->right);

			(*delta)->x=(*temp)->x;
			(*delta)->left=(*temp)->left;
			(*delta)->right=(*temp)->right;

			// delta=temp;
			delete temp;
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
int main()
{
    node* root = NULL;
    // insert

    return 0;
}
