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
        min = (min < _v[i]) ? min : _v[i];
        max = (max > _v[i]) ? max : _v[i];
    }
    
    cout<<"min: "<<min<<endl;
    cout<<"max: "<<max<<endl;
}

void rekPodajMin(vector<int> _min)
{
    if(_min.size() != 1)
    {
        vector<int> newMin;

        if(_min.size() % 2 == 1 )
        {
            newMin.push_back(_min.back());

        }
        
        for(int i = 0; i <= _min.size()-2; i += 2)
        {
            if(_min[i] <= _min[i+1])
            {
                newMin.push_back(_min[i]);
            }
            else
            {
                newMin.push_back(_min[i+1]);
            }
        }
        rekPodajMin(newMin);
    }
    else 
    {
        cout << "Min: " << _min[0] << endl;
    }
}

void rekPodajMax(vector<int> _max)
{
    if(_max.size() != 1)
    {
        vector<int> newMax;

        if(_max.size() % 2 == 1 )
        {
            newMax.push_back(_max.back());
        }
        for(int i = 0; i <= _max.size()-2; i += 2)
        {
            if(_max[i] >= _max[i+1])
            {
                newMax.push_back(_max[i]);
            }
            else
            {
                newMax.push_back(_max[i+1]);
            }
        }
        rekPodajMax(newMax);
    }
    else 
    {
        cout << "Max: " << _max[0] << endl;
    }
}

void podaj2(vector<int> & _v)
{
    vector<int> min;
    vector<int> max;

    int sizeV = _v.size();

    if(sizeV % 2 == 1)
    {
        max.push_back(_v.back());
    }
        for(int i = 0; i < sizeV-1; i+= 2)
        {
            if(_v[i] > _v[i+1])
            {
                max.push_back(_v[i]);
                min.push_back(_v[i+1]);
            }
            else
            {
                max.push_back(_v[i+1]);
                min.push_back(_v[i]);
            }
        }

        rekPodajMin(min);
        cout << endl;
        rekPodajMax(max);
}



int main()
{

    int myVec1[] = {10,2,3,4,2,4,-1,-5,34,5};
    vector<int> v1 (myVec1, myVec1 + sizeof(myVec1) / sizeof(int)); 
    

    // podaj(v1); 
    podaj2(v1);

    return 0;
}
