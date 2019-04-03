#include <iostream>

const int N=200000;

using namespace std;

double b[N];

void merge(int n,int k,double t[], double _b[])
{ 
    int i=0,j=k,l=0;

    while (i<k && j<n)
    {
        if(t[i]<=t[j])
        {
            _b[l]=t[i];
            l++;
            i++;
        } 
            
        else
        {
            _b[l]=t[j];
            l++;
            j++;    
        }
            
    }

    while(i<k)
    {
        _b[l]=t[i];
        l++;
        i++;
    }

    for(i=0;i<j;i++)
    {
        t[i]=_b[i];         //przepisanie wynikow do tablicy t   
    }
        
}

void merge_sort(double t[],int n)
{
  if(n>1)
  { 
    int k=n/2;
    merge_sort(t,k);
    merge_sort(t+k,n-k);
    merge(n,k,t,b);
  }
} 

int main()
{
    double t[] = {9,22,6,19,14,10,17,3,5};
    merge_sort(t,9);
    for(int i=0;i<(sizeof(t)/sizeof(*t));i++)
    {
        cout<<t[i]<<", ";
    }
    return 0;
}