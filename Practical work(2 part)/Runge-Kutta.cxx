#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y){
        return (cos(y)*x - (cos(x)*x) +1);
}

int main() {
        double a=0; double b=1;int n = 100000;
        double h=(b-a)/n;
        
        double X[n];
        double k1[n];
        double k2[n];
        double k3[n];
        double k4[n];
        double Y[n];
        
        X[0]=a; Y[0]=0;
        for(int i=1; i<=n; i++){
                X[i]=a+i*h;
                k1[i]=h*F(X[i-1],Y[i-1]);
                k2[i]=h*F(X[i-1]+h/2.0,Y[i-1]+k1[i]/2.0);
                k3[i]=h*F(X[i-1]+h/2,Y[i-1]+k2[i]/2);
                k4[i]=h*F(X[i-1]+h,Y[i-1]+k3[i]);
                Y[i]=Y[i-1]+(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6;
        }
       for(int i=0; i<=n; i++){
						cout << X[i] << " ";
                        cout << Y[i] << endl;
        }
        return 0;
}
