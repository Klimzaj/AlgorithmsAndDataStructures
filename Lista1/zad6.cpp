#include <iostream>
#include <vector>

using namespace std;


void podaj(vector<int> & _v)
{   
    int min = 0 ;
    int max = 0;
    bool first = false;

    for(int i = 0; i<_v.size();i++)
    {
        if(!first)
        {
            min = _v[0];
            max = _v[0];
            first = !first;
        }
        min = (min < _v[i])?min:_v[i];
        max = (max > _v[i])?max:_v[i];
    }
    
    cout<<"min: "<<min<<endl;
    cout<<"max: "<<max<<endl;
}


int main()
{

    int myVec1[] = {10,2,3,4,2,4,-1,-5,34};

    vector<int> v1 (myVec1, myVec1 + sizeof(myVec1) / sizeof(int)); 
    
    podaj(v1); 

    return 0;
}
