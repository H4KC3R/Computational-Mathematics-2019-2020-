#include <iostream>
 
#include <cmath>
 
using namespace std;
 
long double computef1(long double x, long double y);
 
long double computef2(long double x, long double y, long double h);
 
int main() {
    long double step;
    cin >> step;
    const int size = 0.9 / (step);
    auto *y = new long double[size];
    auto *x = new long double[size];
    x[0] = 0;
    y[0] = sqrt(2) + 1e-15 ;
    for (int i = 1; i < size; ++i) {
        x[i] = x[i - 1] + step;
        y[i] = y[i - 1] + step * computef2(x[i - 1], y[i - 1], step);
    }
    for (int i = 0; i < size; ++i) {
        cout << "y[" << i << "] = " << y[i] - sqrt(2)<< endl;
    }
    delete[] x;
    delete[] y;
    return 0;
}
 
long double computef1(long double x, long double y) {
    return 1000 * (y - sqrt(2)) / pow((x - 1.0), 2);
}
 
long double computef2(long double x, long double y, long double h) {
    return computef1(x + h / 2.0, y + h * computef1(x, y) / 2.0);
}
