#include <iostream>
#include <cmath>

double fac(double n)
{
    if(n > 1)
        return n * fac(n - 1);
    else
        return 1;
}
double P(double k,double n,double p)
{
    double q = 1.0-p;
    double wynik = 0.0;

    wynik += pow(q,n);
    
    for(int i = 1;i<k;i++)
    {
        wynik += fac(n) / (fac(i)*fac(std::abs(n-i))) * pow(p,i) * pow(q,n-i);
    }
    return wynik;


}

int main()
{
    std::cout<<P(5,2,2)<<std::endl;
    // std::cout<<fac(3)<<std::endl;
    return 0;
    
}
