#include <iostream>
#include <cmath>

using namespace std;

class Ulamek
{
private:
    int licznik;
    int mianownik;
public:
    Ulamek(int _l,int _m);
    int NWD(int _a,int _b);
    void CHECK(int _a,int _b);
    void ustawLicznik(int _l);
    void ustsawMianownik(int _m);
    int takeLicznik();
    int takeMianownik();
    void SHOW();
    Ulamek operator +(Ulamek & _u);
    Ulamek operator -(Ulamek & _u);
    Ulamek operator *(Ulamek & _u);
    Ulamek operator /(Ulamek & _u);

};
Ulamek::Ulamek(int _l,int _m = 1) 
{
    Ulamek::CHECK(_l,_m);
    // cout<<licznik<<"/"<<mianownik<<endl;
}
int Ulamek::NWD(int _a,int _b)
{
    int a = _a;
    int b = _b;
    do
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    while(a!=b);
    return a;
}
void Ulamek::CHECK(int _a,int _b)
{
    int a = abs(_a);
    int b = abs(_b);
    int dzielnik = 1;
    do{
        
        a /= dzielnik;
        b /= dzielnik;
        dzielnik = Ulamek::NWD(a,b);
    }
    while(dzielnik!=1); 
    Ulamek::ustawLicznik(a);
    Ulamek::ustsawMianownik(b);
}
void Ulamek::SHOW()
{
    if(mianownik!=1)
    {
        cout<<licznik<<"/"<<mianownik<<endl;
    }
    else cout<<licznik<<endl;
}
void Ulamek::ustawLicznik(int _l)
{
    licznik = _l;
}
void Ulamek::ustsawMianownik(int _m)
{
    mianownik = _m;
}
int Ulamek::takeLicznik()
{
    return licznik;
}
int Ulamek::takeMianownik()
{
    return mianownik;
}
Ulamek Ulamek::operator +(Ulamek & _u)
{
    if (this->takeMianownik() == _u.takeMianownik())
    {
        return Ulamek((this->takeLicznik()+_u.takeLicznik()),this->takeMianownik());
    }
    else return Ulamek((this->takeLicznik()*_u.takeMianownik()+this->takeMianownik()*_u.takeLicznik()),(this->takeMianownik()*_u.takeMianownik()));
}
Ulamek Ulamek::operator -(Ulamek & _u)
{
    if (this->takeMianownik() == _u.takeMianownik())
    {
        return Ulamek((this->takeLicznik()-_u.takeLicznik()),this->takeMianownik());
    }
    else return Ulamek((this->takeLicznik()*_u.takeMianownik()-this->takeMianownik()*_u.takeLicznik()),(this->takeMianownik()*_u.takeMianownik()));
}
Ulamek Ulamek::operator *(Ulamek & _u)
{
    return Ulamek((this->takeLicznik()*_u.takeLicznik()),(this->takeMianownik()*_u.takeMianownik()));
}
Ulamek Ulamek::operator /(Ulamek & _u)
{
    return Ulamek((this->takeLicznik()*_u.takeMianownik()),(this->takeMianownik()*_u.takeLicznik()));
}

int main()
{
    Ulamek a(1,2);
    Ulamek b(1,3);

    a = a+b;
    a.SHOW();
    a = a*a;
    a.SHOW();
    a = a/b;
    a.SHOW();
    b = b-a;
    b.SHOW();
    

    return 0;
}