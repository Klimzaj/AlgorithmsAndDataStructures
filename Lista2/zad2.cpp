#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


//iteracyjnie
void maks(double _tab[], int n) {
	int x = _tab[--n];
	while (n--) {
		if (x < _tab[n])
			x = _tab[n];
	}
	
	cout<<"znalazlem: "<< x <<endl;
}

void zOstatnim(double _tab[],double _n, int _s,int _i)
{
    if(_s == 1)
    {
        if(_n>_tab[_i]) cout<<"znalazlem: "<<_n<<endl;
        else cout<<"Ostatnia liczba jest najwieksza: "<<_tab[_i]<<endl;
    }
    else if(_tab[_i] > _n)
    {
        zOstatnim(_tab,_tab[_i],--_s,_i+1);
    }
    else
    {
        zOstatnim(_tab,_n,--_s,_i+1);
    }
}

void naPol(double _tab[], double _n1, double _n2, int _m, int _i)
{
    
    if(_m%2 == 0)
    {
        if(_m/2 == _i)
        {
            cout<<"znalazlem n1: "<<_n1<<" i n2: "<<_n2<<endl;
        }
        else
        {
            naPol(_tab,(_n1>_tab[_i])?_n1:_tab[_i],(_n2>_tab[_i+_m/2])?_n2:_tab[_i+_m/2],_m,_i+1);
        }     
    }
}

int main()
{
    srand( time( NULL ) );

    int m = 10000;
    double tab[m];
    double n1 = 0;
    double n2 = 0;
    double n3 = 0;
    
    for(int i=0; i< m ;i++)
    {
        tab[i] = double (rand() % 1000000);
    }

    cout << "Pierwszy sposób!"<< endl;
    maks(tab,m);
    
    cout << "Drugi sposób!"<< endl;
    zOstatnim(tab,n1,m,0);
    
    cout << "Trzeci sposób!"<< endl;
    naPol(tab,n2,n3,m,0);

    return 0;
}