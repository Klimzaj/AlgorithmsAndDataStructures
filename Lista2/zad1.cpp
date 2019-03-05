#include <iostream>
#include <cmath>

using namespace std;

// wyszukując algorytmem bisekcji ilość porównań w najgorszym wypadku to log2N.

int polowa(double min, double max)
{
    double rozmiar = 0;
    
    for(int i = min;i<=max;i++)
    {
        rozmiar++;
    }
    if(rozmiar == 1)
    {
        return 0;
    }
    if((int)rozmiar%2!=0)
    {
        return (int)(min + (rozmiar-1)/2.0);
    }
    else
    {
        return (int)(min + rozmiar/2.0-1);
    }
}

void CheckMax(int _t[] ,int _x,double _min,double _max)
{    
    int pol = polowa(_min,_max);
    
    if(_t[pol] == _x)
    {
        cout<<"Liczba: "<<_x<<" lezy na miejsu "<<pol<<endl;
    }
    else if(_t[pol] > _x)
    {
        CheckMax(_t,_x,_min,pol);
    }
    else
    {
        CheckMax(_t,_x,pol,_max);
    }
}
int main()
{
    int m = 10000;
    int tab[m];
    
    for(int i=0; i< m ;i++)
    {
        tab[i] = i;
    }

    int szukaj = 500;

    CheckMax(tab,szukaj,0,m);
    
    return 0;
}