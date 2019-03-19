#include <iostream>

using namespace std;

struct node
{
    int x;
    node* left;
    node* right;

    node(int _val, node* _l=NULL, node* _r=NULL)
        :x(_val), left(_l),right(_r)
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

void inorder(node * _t, void _f(node *))
{
    node *temp = _t;

    if(temp)
    {
        inorder(temp->left,_f);
        _f( temp);
        inorder(temp->right,_f);
    }
}

void myPrint(node * _t)
{
    node *temp = _t;
    if(temp)
    {
        cout << temp->x << endl;   
    }
}

int main()
{
    node *root = new node(0);
    insert(root,4);
    insert(root,6);
    insert(root,3);
    insert(root,5);
    insert(root,1);
    insert(root,8);
    insert(root,7);
    insert(root,9);
    inorder(root,[](node* x) {myPrint(x);} );
    return 0;
}