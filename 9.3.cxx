#include <iostream>
#include <cmath>

using namespace std;
typedef long double ld;
double m = 1000;

ld F(ld z ,ld x)
{
	return (m*(z - pow(z,3))) - x ;
}


int main()
{
	double T = 0 ; double X = 0 ; double Z = 0.001;
	double X1 ; double Z1 ;
	double h = 0.0001;
    for(int i=1; i<=10000000; i++)
    {
      T = 0 + i*h;
      Z1 = Z + h*F(Z,X);
      X1=X+ h * Z;
      cout << T << " " << X1 <<endl;
      Z = Z1;
      X = X1;
    }  
 return 0 ;
}
