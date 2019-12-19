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

// m - порядок
ld d_dif(int m, ld  *population, ld *year , int k )
{
	ld res;
	if( m == 1)
	res = (population[k] - population[k-1])/(year[k] - year[k-1]);
	else
	res = d_dif( m - 1 , population , year , k ) - d_dif( m - 1 , population , year , k - 1) / (year[k] - year[k-m]);
	return res;

}

int main()
{
	ld x = 2010;
	ld *population = new ld[10] {92228496,
                        106021537,
                        123202624,
                        132164569,
                        151325798,
                        179323175,
                        203211926,
                        226545805,
                        248709873,
                        281421906};
    ld *year = new ld[10] {1910,
                    1920,
                    1930,
                    1940,
                    1950,
                    1960,
                    1970,
                    1980,
                    1990,
                    2000}; 
    int i = 1;
	ld interpolation = population[0];
	while(i <= 9)
	{
		interpolation += ((d_dif( i, population , year,i)) * ( x - year[i]));
		i++;
	}    
	ld A[8];
	for(i = 0; i < 8 ; i++)
		{
			A[i] = 0.5;
		}
		A[0] =0;
	ld B[8];
		for(i = 0; i < 8 ; i++)
		{
			B[i] = 2;
		}
	ld C[8];
		for(i = 0; i < 8 ; i++)
		{
			C[i] = 0.5;
		}
		C[7] = 0;
	ld D[8];
		for(i = 0; i < 8 ; i++)
		{
			D[i] =  6 * ( (((population[i+2]-population[i+1])/10)  -((population[i+1]-population[i])/10)) / 20 );
		}
	
	ld a[10];
	ld b[10];
	ld g[10] = {};
	ld d[10];
		for(i = 0; i <= 9 ; i++)
		{
			a[i] = population[i];
		}
	sweepMethod(8 , A , C , B , D , g);
	ld c[10];
	c[0] = 0;
	
	
	.
		for( i = 1 ; i < 9 ; i ++)
		{
			 c[i] = g[i-1];
		}
	d[0] = ( c[0] /10);
		for( i = 1 ; i < 10 ; i ++)
		{
			d[i] = ((c[i] - c[i-1]) / 10);
		}
	b[0] = ( ( c[0] * 10 ) / 3 ) +  d_dif(1,population,year, 1);
		for( i = 1 ; i < 10 ; i ++)
		{
			b[i] = ((c[i] * 10)/3) + ((c[i-1] * 10)/6) + d_dif(1,population,year,i);
		}

		ld interpolation_2 = a[9] + b[9] * 10 + c[9] * 100 + d[9] *1000 ;
	cout  << "Экстраполированое значение интерполянтом в форме Ньютона:" << interpolation << endl;
	cout  << "Экстраполированое значение кусочно-кубической интерполяцией:" << interpolation_2 << endl;
	return 0;
}

