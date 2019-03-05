#include <iostream>
#include <cmath>

double oblicz(double a[], int n,double x)
{
    double wynik = 0.0;
    int iloscMnozen = 0;

    int p = n;

	for(int i=0;i < n;i++)
    {
        wynik += a[i] * std::pow(x,p--);

        iloscMnozen++;
        iloscMnozen += p-1;
    }

    std::cout << "Dla n= "<< n << " wykonamy " << iloscMnozen << " mnożeń." <<std::endl;
	return wynik += a[n];
}

// zlozonosc algortymu to: 2n + 3

int main()
{
    int _n = 10;
    // double _a[_n] = {4,5,3,2,2,3,4,8,0,9};
    double _b[4] = {2,1,3,4};
    double _x = 2;
    std::cout << oblicz(_b,4,_x) << std::endl;
    return 0;

}