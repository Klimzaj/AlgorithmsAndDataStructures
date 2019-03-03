#include <iostream>

using namespace std;

struct lnode
{
    int key;
    lnode *next;
};

int nty(int n, lnode *l)
{
    if(!l->next && n>0)
    {
        
        return 0;
    }
    else
    {
        if(n == 0)
        {
            return l->key; 
        }
        nty(n-1,l->next);
    }   
}

int main()
{
    lnode a;
    a.key = 1;
    a.next = NULL;

    lnode b;
    b.key = 2;
    b.next = &a;
    
    lnode c;
    c.key = 3;
    c.next = &b;

    lnode d;
    d.key = 4;
    d.next = &c;

    lnode e;
    e.key = 5;
    e.next = &d;

    lnode f;
    f.key = 6;
    f.next = &e;

    lnode g;
    g.key = 7;
    g.next = &f;
    // cout<<a.key<<endl;
    int test = nty(12,&g);
    cout<<test<<endl;
    return 0;
}