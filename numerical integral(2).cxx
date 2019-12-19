#include <iostream>
#include <cmath>

using namespace std;
typedef long double ld;

ld f ( ld x ){
	return ((cos(1000 * x)) / ( 1 + x * x));
}

int main()
{
	ld eps = 1e-6, a = 0, b = 1, I = 0 ;
	ld h = pow ( ((eps * 2) / 100) , 0.5);
	int n = (b - a)/h;
	cout << "Количество узлов : " << n << endl ;
	int i = 0;
	double x1 = a;
	double x2;
	while ( i <= n )
	{
		x2 = x1 + h;
		I += f((x1 + x2)/2) * h;
 		x1 = x2;
 		i++;
	}
	ld J = 0;
	int k = 50 ; 
	ld q = (M_PI * M_PI) - (3 / ( 2 * k * k));
	ld t2 = M_PI * sqrt ( q ); 
	ld t1 = -1*t2;
	ld c1 = ((M_PI)  /(2*k * sqrt(q))) ;
	ld c2 = (-1) * c1;
	cout << c1 << " " << c2 << " " << t1 << " " << t2 << " " << endl ;
	J = c1 * f(t1) + c2 * f(t2);
	cout.precision(12);
	cout <<" Интеграл вычисленный методом прямоугольников :" << I << endl;
	cout <<" Интеграл вычисленный методом Гаусса :" << J << endl;
	return 0;
}

