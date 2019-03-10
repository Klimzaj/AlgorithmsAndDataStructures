#include <iostream>

using namespace std; 

void wypisz(int t[], int n)
{
    for(int i = 0; i<n;i++)
        cout<<t[i]<<" ";
}

void przesuniecie(int t[], int k, int n) {
    for (int j = 0; j < (k > n ? n % k : k ); j++) {
        int temp = t[n - 1];
        int temp1;
        for (int i = 0; i < n; i++) {
            temp1 = t[i];
            t[i] = temp;
            temp = temp1;
        }
    }
}
int main() {

    int N = 10;
    int tab[N] = {0,1,2,3,4,5,6,7,8,9};
    
    wypisz(tab,N);
    cout<<endl;
    przesuniecie(tab, 4, N);
    cout<<endl;
    wypisz(tab,N);
    

    return 0;
}