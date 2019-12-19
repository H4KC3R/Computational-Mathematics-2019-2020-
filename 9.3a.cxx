#include <iostream>
#include <cmath>

using namespace std;
typedef long double ld;
int a = 0 ; int b = 1 ; int n = 10000;
ld Y1 = 2;
ld h = (double)(b-a)/n;

ld f(ld x, ld y){
        return (x * sqrt(y));
}

ld F( ld alpha)
{
	double X[n]; double Y[n] ; double Z[n];
	X[0]=a; Y[0]=0 , Z[0] = alpha;
    for(int i=1; i<=n; i++)
    {
      X[i]=a+i*h;
      Z[i] = Z[i-1] + (h*f(X[i-1],Z[i-1]));
      Y[i]=Y[i-1]+ h * Z[i];
    } 
   return (Y[n] - Y1);
	
}

int main()
{
	ld alpha1 = 0;
	ld alpha2 = 100;
	ld alpha = ((alpha1 + alpha2 )/2);
	while ( F(alpha) != 0)
	{
		if (F(alpha1) * F(alpha) >= 0)  
			alpha1 = alpha;
		else
			alpha2 = alpha;			
	 alpha = ((alpha1 + alpha2 )/2);
	}
	
	cout << alpha << endl;
	double X[n]; double Y[n] ; double Z[n];
	X[0]=a; Y[0]=0 , Z[0] = alpha;
    for(int i=1; i<=n; i++)
    {
      X[i]=a+i*h;
      Z[i] = Z[i-1] + (h*f(X[i-1],Z[i-1]));
      Y[i]=Y[i-1]+ h * Z[i];
      cout << X[i] << " " << Y[i] <<endl;
    }  
    cout << Y[n];
 return 0 ;
}
