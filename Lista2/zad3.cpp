#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// void wyswietl(int _tab[][])
// {
//     for(int i = 0;i<=1;i++)
//     {
//         for(int j = 0;j<= 1;j++)
//         {
//             cout<<_tab[i][j]<<endl;
//         }
//     }
// }

int iloczynSkalarny(vector<int> & _a, vector<int> & _b)
{
    int wynik = 0;
    int iloscMnozen = 0;
    for(int i = 0; i < _a.size(); i++)
    {
        iloscMnozen++;
        wynik += _a.at(i) * _b.at(i);
    }
    cout<<"Iloczyn skalarny wykona " << iloscMnozen << " mnożeń, przy n = " << _a.size()<< endl;
    return wynik;    
}

int wartoscWielomianu(vector<int> & _a, int _val)
{
    int wynik = 0;
    int iloscMnozen = 0;
    for(int i = 0; i < _a.size()-1; i++)
    {
        iloscMnozen++;
        // iloscMnozen += i;
        // czy te    o te z pow też liczyc?
        wynik += _a.at(i) * pow(_val, i);
    }
    wynik += _a.back();
    cout<<"Wyliczając wartość wielomianu wykonamy " << iloscMnozen << " mnożeń, przy stopniu n = " << _a.size()<< endl;
    return wynik;
}

int iloczynWielomianow(vector<int> & _a, vector<int> & _b, int val)
{
    int wynik = 0;
    int iloscMnozen = 0;
    int test = 0;
    int wynikTest = 0;
    for(int i = 0; i < _a.size(); i++)
    {
        for(int j = 0; j < _b.size(); j++)
        {
            wynik += _a.at(i) * pow(val,i) * _b.at(j) * pow(val,j);
            test += _a.at(i) * pow(val,i) * _b.at(j) * pow(val,j);
            iloscMnozen += 3;
            // iloscMnozen += i+j;
        }
        wynikTest += test;
    }
    cout << "Wyliczając iloczyn wielominaów wykonamy "<< iloscMnozen << " mnożeń, przy tym samym stopniu n = " << _a.size()<< endl; 
}
void iloczynMacierzy(int _a[][2], int _b[][2], int _c[][2], int _size)
{
    int iloscMnozen = 0;
    for(int i = 0; i < _size; i++)
    {
        for(int j = 0; j < _size; j++)
        {
            _c[i][j] = 0;
            for(int z = 0; z < _size; z++)
            {
                _c[i][j] += _a[i][z] * _b[z][j]; 
                iloscMnozen++;
            }
        }
    }
    cout << "Wyliczając iloczyn dwóch macierzy, o rozmiarze "<< _size <<"x"<<_size << " wykonamy " << iloscMnozen << " mnożen" << endl;    
}



// int wyznacznikMacierzy(int _a[][3], int _size)
// {
//     int pos = 1;
//     int neg = 1;
//     int iloscMnozen = 0;

//     for(int i = 0; i < _size; i++)
//     {
//         for(int j = 0; j < _size; j++)
//         {
//             if(i == j)
//             {
//                 pos *= _a[i][j];
//                 iloscMnozen++;
//             }
//         }
//     }
//     for(int i = _size-1; i >= 0; i--)
//     {
//         for(int j = 0; j < _size; j++)
//         {
//             if(i == j)
//             {
//                 neg *= _a[i][j];
//                 iloscMnozen++;
//             }
//         }
//     }
//     cout << "Wyliczajac wyznacznik macierzy o rozmiarach " << _size << "x" <<_size << " wykonamy " << iloscMnozen << " mnożeń"<<endl;
//     return pos-neg;
// }

int main()
{
    int myVec1[] = {2,5,0,0,3,3,0,0,1,2};
    int myVec2[] = {4,0,2,2,0,0,6,7,3,4};

    vector<int> v1 (myVec1, myVec1 + sizeof(myVec1) / sizeof(int)); 
    vector<int> v2 (myVec2, myVec2 + sizeof(myVec2) / sizeof(int)); 

    int mySize = 2;

    int m1[2][2] = {
        {2,3},
         {7,1}
    };

    int m2[2][2] = {
        {3,6},
         {4,1}
    };
    
    int m3[2][2] = {
        {0,0},
        {0,0}
    };
    // int m4[3][3] = {
    //     {0,3,1},
    //     {1,-1,2},
    //     {2,4,1}
    // };

    cout << "Iloczyn skalarny wynosi " << iloczynSkalarny(v1,v2) << endl;
    cout << endl;
    cout << "Wartość wielomianu " << wartoscWielomianu(v1, 5) << endl;
    cout << endl;
    cout << "Iloczyn dwóch wielomianów " << iloczynWielomianow(v1,v2, 5) << endl;
    cout << endl;
    iloczynMacierzy(m1,m2,m3,mySize);
    for(int i = 0;i<mySize;i++) {
        for(int j = 0;j<mySize;j++) {
            cout<< m3[i][j]<<", ";
        }    
        cout<<endl;
    }
    cout<<endl;
    cout << "licząc wyznacznik macierzy o rozmiarze 3x3 wykonamy 12 mnożeń"<< endl; 
    // cout << "wyznacznik macierzy " <<wyznacznikMacierzy(m4,3) << endl;

    return 0;
}