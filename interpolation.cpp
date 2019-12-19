#include <iostream>
#include <cmath>

using namespace std;
typedef long double ld;

ld f ( ld x )
{	
	ld f = (64 * pow(x,5)) - (20 *pow (x,3)) + x;
	return f;
}

// m - порядок
ld d_dif(int m, ld  *func, ld *x , int k )
{
	ld res;
	if( m == 1)
	res = (func[k] - func[k-1])/(x[k] - x[k-1]);
	else
	res = d_dif( m - 1 , func , x , k ) - d_dif( m - 1 , func , x , k - 1) / (x[k] - x[k-m]);
	return res;

}
ld T_n(int N , ld x)
{
	if ( N == 0)
	{
		return 1;
	}
	else if (N == 1)
	{
		return x;
	}
	else 
	{
		return (( 2 * x * T_n(N-1,x)) - T_n(N-2,x));
	}
}

ld P_n(int N ,ld a, ld  *func, ld *x )
{
	int i = 1;
	ld p_n = func[0];
	while(i < N)
	{
		p_n += ((d_dif( i, func , x,i)) * ( a - x[i]));
		i++;
	}    
	return p_n;
}



int main()
{
	int i = 0 , N, j = 0 , k = 0;
	ld n;
	cout << "Разбиение :" ;
	cin >> n ;
	cout << endl << "Порядок :" ;
	cin >> N; 
	ld x[N] , func[N] , y[N];
	ld a = -1 , b = 1 , tmp = 0 ,tmpt = 0 ,  x1; 
	ld h = ( b - a )/n ;
	ld H = ( b - a )/N ;
		for(; j < N ; j++)
			{
				y[i] = cos ((( 2*i - 1) * M_PI)/(2 * N));
				x[j] = a + j* H;
				func[j] = f(x[j]);
			}
		for (; i < n ; i++)
		{
			x1 = a + i * h ;
			if(abs(f(x1) - P_n(N,x1,func,x)) > tmp)
			 {
				 tmp = abs(f(x1) - P_n(N,x1,func,x)) ;
			 }
		}
		for (; k < N ; k++)
		{
			if(abs(f(y[k]) - T_n(N,y[k])) > tmpt)
			 {
				 tmpt = abs(f(y[k]) - T_n(N,y[k])) ;
			 }
		}
	cout << "Равномерная сетка :" << tmp << endl ;
	cout << "Чебышевская сетка :" << tmpt << endl ;
	return 0;
}

