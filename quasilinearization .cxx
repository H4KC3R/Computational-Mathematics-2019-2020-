#include <iostream>
#include <cmath>

using namespace std;
typedef long double ld;

const ld e = M_E;
ld f1( ld x);
ld f2(ld x);
ld f3(ld x);

void sweepMethod (int n, ld *a, ld *c, ld *b, ld *d , ld *x)
{
	double p[n];
	double q[n];
	p[1] = (-c[0])/(b[0]);
	q[1] = (d[0])/(b[0]);
	for (int i = 1; i <= n; i++)
	{
		p[i] = (-c[i-1])/(a[i-1]*p[i-1] + b[i-1]);
		q[i] = (d[i-1] - a[i-1]*q[i-1])/(a[i-1]*p[i-1] + b[i-1]);
	}
	x[n] = (d[n] - a[n]*q[n])/(p[n]*a[n] + b[n]);
	for (int i = n-1; i >= 0; i--)
    {
		x[i]= (x[i+1] * p[i+1]) + q[i+1];
    }
}

int main()
{
	ld a = 1 , b = e;
	const int size = 1001;
	ld h = (b-a) / 1000;
	
	ld x[size]; ld y[size]; ld v[size] = {};
	ld beta[size]; ld teta[size]; ld gamma[size] = {};
	ld A[size] = {}; ld B[size] = {}; ld C[size] = {}; ld D[size] = {};

	for(int i = 0 ; i < size ; i++)
	{
		x[i] = a + i * h;
		beta[i] = f1(x[i]);
		teta[i] = f2(x[i]);
		gamma[i] = f3(x[i]);
	}
	B[0] = 1;
	for(int i= 1; i < size-1 ; i++)
	{
			C[i] = ( (1/(h*h)) - (0.5 * (sqrt(beta[i])/beta[i]) * (gamma[i]/h)) );
			B[i] = ( (0.5 * (sqrt(beta[i])/beta[i]) * (gamma[i]/h)) - (2/(h*h)) - (0.5 * (sqrt(beta[i])/beta[i]) * (teta[i])) );
			A[i] = ( (1/(h*h)) );
			D[i] = ( sqrt(beta[i]) );
	}
	B[size-1] = 1;
	sweepMethod(size-1,A,C,B,D,v);
	for(int i = 0 ; i < size ; i++)
	{
		y[i] = (((e)/(e - 1)) * (x[i]-1)) - v[i];
	}
	cout << " y(1) = " << y[0] << endl << " y(1.5) = " << y[291] << endl 
	<< " y(2) = " << y[582] << endl << " y(2.5) = " << y[873] << endl 
	<< " y(e) = " << y[size-1] << endl;
	return 0;
}

ld f1(ld x) {
	ld y = ((e)/(e - 1)) * (x-1);
    return ( (1/(x*x)) + ((e/log(x))*y*y) - (exp((e/(e-1)))*y) ) ;
}
ld f2(ld x) {
   	ld y = ((e)/(e - 1)) * (x-1);
   	 return ( ((e*y*2)/log(x)) - exp((e/(e-1))) ) ;
}
ld f3(ld x) {
	ld y = (-1) * ((e)/(e - 1)) * (x-1);
    return (exp((e/(e-1)))*y);
}
