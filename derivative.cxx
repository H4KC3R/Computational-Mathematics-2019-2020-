#include <iostream>
#include <cmath>

using namespace std;

typedef long double ld;

ld f (ld x)
{
	ld y = tan (x) ;
	return y; 
} 
//~ отрезок [-1;1]
int main()
{
	cout.precision(16);
	ld eps = 1e-16 ;
	ld M = 1.557 ;
	ld x = 1; 
	ld E = eps * M ;
	ld m = 40;
	ld h = pow( (( 45  * E ) / ( 4 * m )) , 0.2 ) ; 
	ld g;
	
	g = (f( x - 2 * h ) - 8 * f( x - h ) + 8 *f( x + h ) - f( x + 2 * h))/(12 * h);
	cout << "Производная вычисленная 4 порядком :" << g << endl;    
	cout << "Производная в точке :"<<(1/(cos(x) * cos(x)));
	
	return 0;
}
