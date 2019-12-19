#include <iostream>
#include <cmath>

using namespace std;
typedef long double ld;

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

ld f( ld x)
{
	return ((exp(x) * (x*x) * cos (x)) + 2 + ( 2 * (pow(x,3))) - (pow(x,4)) + 2*(x*x)) ;
}

ld q ( ld x )
{
	return x*x - 2;
}

ld p ( ld x )
{
	return (-1 * (x*x - 2) * cos (x));
}

int main()
{
	int i;
	ld a = 0 ; ld b = M_PI;
	int n = 1000;
	ld h = (b-a)/n;
	ld Y[n] = {};
	ld X[n];
	for(i = 0; i < n ; i++)
		{
			X[i] = a + i * h  ;
		}
	ld A[n] , B[n] , C[n] , D[n];
		B[0] = 1;
		B[n] = 1;
		for(i = 1; i <= n-1 ; i++)
		{
			B[i] = (((-1)*q(X[i])) - (p(X[i])/h) - (2/( h*h)));
		}
		A[0] = 0;
		A[n] = 0;
		for(i= 1; i <= n-1 ; i++)
		{
			A[i] = (1/(h*h));
		}
		C[0] = 0;
		C[n] = 0;
		for(i= 1; i <= n-1 ; i++)
		{
			C[i] = ((1/(h*h)) + (p(X[i])/h));
		}
		D[0] = 0;
		D[n] = M_PI * M_PI;		
		for(i= 1; i <= n-1 ; i++)
		{
			D[i] = (f(X[i]));
		}
		sweepMethod(n,A,C,B,D,Y);
		cout << " y(0) = " << Y[0] << endl << " y(0.5) = " << Y[160] << endl << " y(1) = " << Y[318] << endl << " y(1.5) = " << Y[477] << endl << " y(2) = " << Y[637] << endl << " y(2.5) = " << Y[796] << endl << " y(3) = " << Y[955] << endl <<  " y(pi) = ";
		cout << Y[n];	
}
