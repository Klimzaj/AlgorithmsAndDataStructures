#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//-std=c++11 !important

vector<double> odczytaj(string _name)
{
    vector<double> V;
    ifstream plik (_name);
    if(plik.is_open())
    {
        string number;
        string::size_type s;
        while(getline(plik,number))
        {
            s = number.length();
            if(s!=0)
            {
                double _n = stod(number);
                V.push_back(_n);
            }
        }
        plik.close();
    }

    return V;
}
void zapisz(string _name, vector<double> & _v)
{
    ofstream out(_name);
    for(int i =0;i<_v.size();i++)
    {
        out<<_v[i]<<endl;
    }
    out.close();
    
}
vector<double> oblicz(vector<double> & _v1, vector<double> & _v2)
{
    int length;
    if(_v1.size()>_v2.size())
    {
        length = _v2.size();
    }
    else length = _v1.size();

    vector<double> V;

    for(int i = 0;i<length;i++)
    {
        V.push_back(_v1[i] * _v2[i]);
    }
    cout << "Done!" << endl;
    return V;
}
int main()
{
    vector<double> x = odczytaj("a.txt");
    vector<double> y = odczytaj("b.txt");
    vector<double> c = oblicz(x,y);
    zapisz("c.txt",c);
    return 0;
}