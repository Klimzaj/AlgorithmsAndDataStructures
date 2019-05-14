#include <iostream>
#include <array>

using namespace std;

int kta(int n, int number) {
    int exp = 1;
    while(n--)exp *= 10;
    return (number/exp)%10;
}


int main() {

    array<int, 5> values;
    int a = 35421;

    int count = 0;

    for(int i = values.size()-1; i >= 0; i--)
    {
        cout<<"indeks: "<<i<<" wartość: "<<kta(i, a)<<endl;
        count++;
    }

    cout<<"Ilość: " << count <<endl;

    return 0;
}