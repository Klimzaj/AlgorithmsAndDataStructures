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
        else if((*delta)->left == NULL && (*delta)->right == NULL)
        {
            if((*delta2)->left->x == _x)
            {
                (*delta2)->left = NULL;
            }
            else
            {
                (*delta2)->right = NULL;
            }
            delete *delta;
            
        }
		else if((*delta)->left == NULL)
		{
			node* temp = (*delta)->right;
			delete *delta;
			(*delta) = temp;
		}
		else
		// else if((*delta)->right == NULL)
		{
			node* temp = (*delta)->left;
			delete *delta;
			(*delta) = temp;
		}	
	}
}

int main()
{

    return 0;
}