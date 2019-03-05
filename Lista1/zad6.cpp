#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

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

// int podajMin(vector<int> & _v)
// {
//     int min = _v[0];

//     for(int i = 1; i < _v.size(); i++)
//     {
//         min = (min < _v[i]) ? min : _v[i];
//     }
//     return min;
// }   
// int podajMax(vector<int> & _v)
// {
//     int max = _v[0];
//     for(int i = 1; i < _v.size(); i++)
//     {
//         max = (max > _v[i]) ? max : _v[i];
//     }
// }
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
void iterPodajMin(vector<int> _min)
{
    vector<int> newMin;
    vector<int> deltaV = _min;
    do
    {      
        if(deltaV.size()%2==1)
        {
            newMin.push_back(deltaV.back());
        }
        for(int i = 0; i < deltaV.size()-1 ; i+=2)
        {
            if(deltaV[i] < deltaV[i+1])
            {
                newMin.push_back(deltaV[i]);
            }
            else newMin.push_back(deltaV[i+1]);
        }
        deltaV = newMin;
        newMin.clear();

    }while(deltaV.size() != 1);
    cout << "Min2: " << deltaV.back() << endl;
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

void iterPodajMax(vector<int> _max)
{
    vector<int> newMax;
    vector<int> deltaV = _max;
    do
    {      
        if(deltaV.size()%2==1)
        {
            newMax.push_back(deltaV.back());
        }
        for(int i = 0; i < deltaV.size()-1 ; i+=2)
        {
            if(deltaV[i] > deltaV[i+1])
            {
                newMax.push_back(deltaV[i]);
            }
            else newMax.push_back(deltaV[i+1]);
        }
        deltaV = newMax;
        newMax.clear();

    }while(deltaV.size() != 1);
    cout << "Max2: " << deltaV.back() << endl;
}

void podaj2(vector<int> & _v)
{
    vector<int> min;
    vector<int> max;

    int sizeV = _v.size();

    if(sizeV % 2 == 1)
    {
        max.push_back(_v.back());
        min.push_back(_v.back());
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
        // cout << "Min to: " << podajMin(min) << endl;
        rekPodajMin(min);
        iterPodajMin(min);
        cout << endl;

        // cout << "Max to: " << podajMax(max) << endl;
        rekPodajMax(max);
        iterPodajMax(max);



    
}



int main()
{

    int myVec1[] = {10,49,-30,56,-3,22,-44,29,4,2,3,4,2,4,-1,-5,34,5,-50};
    vector<int> v1 (myVec1, myVec1 + sizeof(myVec1) / sizeof(int)); 
    
    // podaj(v1); 
    // podaj2(v1);
    



    // your test    

    // clock_t start;
    // clock_t start2;

    vector<int> v2;
    int count = 1000000;

    for(int i = 0; i < count; i++)
    {
        v2.push_back(i);
    }
    std::random_shuffle(v2.begin(),v2.end());

    // start = clock();
    podaj2(v2);
    // cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    // start2 = clock();
    // podaj(v2);
    // cout << "Time: " << (clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    

    return 0;
}
