#include <iostream>
#include <cmath> 

using namespace std;

double f(double x)
{
    return sin(100.0 * x) * exp(- x * x) * cos(2 * x);
}

int main()
{
	double a = 0, b = 3 , I = 0 , h = 0.00001;
	double n = (b - a)/h;
	int i = 0;
	double x1 = a;
	double x2;
	while ( i <= n )
	{
		x2 = x1 + h;
		I += ((f(x1) + 3 * f((2 * x1 + x2)/3)  + 3 * f((x1 + 2 * x2)/3) + f(x2)) * (x2 - x1))/8;
 		x1 = x2;
 		i++;
	}
	cout.precision(8);
	cout <<" Интеграл вычисленный методом 3/8 :" << I << endl;
	cout << " Интеграл вычисленный в Wolfram alpha : " << 0.0100061 ;
	return 0; 
}

