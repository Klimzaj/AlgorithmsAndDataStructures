#include <iostream>
#include <stack>

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

void inOrder(Node* _t, void _f(Node* x))
{
	if(!_t)
	    return;
	bool done = false;

	Node* temp = _t;

	std::stack<Node*> s;
	
	while (!done)
	{
		if (temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}

		else
		{
			if (!s.empty())
			{
				temp = s.top();
				s.pop();
				
				_f(temp);
				temp = temp->right;
			}
			else
				done = true;
		}
	} 
}

void myPrint(Node * _t)
{
    Node *temp = _t;
    if(temp)
    {
        cout << temp->x << endl;   
    }
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

    inOrder(root,[](Node* x) {myPrint(x);} );
    return 0;
}