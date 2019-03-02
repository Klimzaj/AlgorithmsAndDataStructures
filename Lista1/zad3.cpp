#include <iostream>

double oblicz(double a[], int n,double x)
{
    int wynik = a[0];

	for(int i=1;i<=n;i++)
		wynik = wynik*x + a[i];
	
	return wynik;
}

int main()
{
    double _a[10] = {4,5,3,2,2,3,4,8,0,9};
    int _n = 7;
    double _x = 2.4;
    std::cout<<oblicz(_a,_n,_x)<<std::endl;
    return 0;

}