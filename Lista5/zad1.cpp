#include <iostream>
#include <cmath>

using namespace std;

int getIndex(double x, int n, int a, int b) {
    if (a > b) return -1;
    return (x-a)/(b-a)*n;
}

int main() {
    int a = 0, b = 5, n = 10;
    for (double i = a; i <= b; i+=0.20) {
        cout << "x = " << i << ", index = " << getIndex(i, n, a, b) << endl;
    }
}