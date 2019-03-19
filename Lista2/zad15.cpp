#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node* left;
    Node* right;
    Node* parent;

    Node(int _x,Node* _l=NULL,Node* _r=NULL,Node* _p=NULL)
        :x(_x),left(_l),right(_r),parent(_p)
    {}
};

void insert(Node *& t, int x)
{
	Node **t1=&t;

	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new Node(x);
}

int height(Node* t)
{

	int l = t->left ? height(t->left) : 0;
	int r = t->right ? height(t->right) : 0;
	
    return (l > r)?l+1:r+1; 
}

int main()
{
    Node *root = new Node(0);
    insert(root,4);
    insert(root,6);
    insert(root,3);
    insert(root,5);
    insert(root,1);
    insert(root,8);
    insert(root,7);
    insert(root,9);

    cout << "Glebokosc: " << height(root) << endl;    

    return 0;
}