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

// find
node* find(node* t,int x)  // wyszukiwanie klucza (bez rekurencji)
{
	while(t && t->x!=x)
	{
		if(x<t->x)
			t=t->left; 
		else
			t=t->right; 
	}
	return t;
}


// insert
void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	// cout << "to przyszlo jako argument x: " << t << endl;
	node **t1=&t;
	// cout << "Wskaznik na argument: " << (*t1)->x << endl; 
	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	// cout << "cos: " << &((*t1)->x) << endl;
	*t1=new node(x);
}  

// remove
void remove(node *& _t, int _x)
{
	node** delta = &_t;
	while(*delta && (*delta)->x!=_x)
	{
		// if(x<(*t1)->x)
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
			node **temp=&((*delta)->right);
			while ((*temp)->left)
				temp=&((*temp)->left);
			(*delta)->x=(*temp)->x;
			delta=temp;
		}
		if((*delta)->left == NULL)
		{
			node* temp = (*delta)->right;
			delete *delta;
			(*delta) = temp;
		}
		else
		{
			node* temp = (*delta)->left;
			delete *delta;
			(*delta) = temp;
		}	
	}
}

// void remove(node *& t, int x)
// {
//     node* deltaLast;
// 	while(t && t->x!=x)
// 	{
//         deltaLast = t;
// 		if(x<t->x)
// 			t=t->left; 
// 		else
// 			t=t->right; 
// 	}
//     cout << t->x << endl;
//     cout << deltaLast->x << endl;
// }

 

// void insert_recursive(node *& t, int x) // wstawianie (rekurenycjnie)
// {
// 	if(!t)
// 		t=new node(x);
// 	else
// 		if(x<t->x)
// 			insert_recursive(t->left,x); // tail recursion 
// 		else
// 			insert_recursive(t->right,x); // tail recursion 
// }  

// node* find_recursive(node* t,int x) // wyszukiwanie klucza (rekurencja)
// {
// 	if(t==NULL || t->x==x) 
// 		return t;
// 	if(x<t->x) 
// 		return find_recursive(t->left,x); // tail recursion 
// 	else
// 		return find_recursive(t->right,x); // tail recursion
// }



int main()
{
    node* root = NULL;
    insert(root,7);
    insert(root,8);
    insert(root,9);
	cout << root->x << " " << root->right->x << " "<< root->right->right->x << endl; 
	remove(root,8);
	cout << root->x << " " << root->right->x << endl; 

	cout << endl;

	node* root2 = NULL;
    insert(root2,7);
    insert(root2,9);
    insert(root2,8);
    insert(root2,10);
	cout << root2->x << " " << root2->right->x << " "<< root2->right->right->x << endl; 
	remove(root2,9);
	cout << root2->x << " " << root2->right->x << endl; 

	cout << endl;

	node* root3 = NULL;
    insert(root3,7);
    insert(root3,9);
    insert(root3,11);
	cout << root3->x << " " << root3->right->x << " "<< root3->right->right->x << endl; 
	remove(root3,11);
	cout << root3->x << " " << root3->right->x << endl; 

    return 0;
}