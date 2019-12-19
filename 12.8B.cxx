#include <iostream>
#include <cmath> 

using namespace std;

long double x_max = sqrt(0.5);//найден аналитический
long double A = 0.5 * sqrt(0.5) * exp(-0.5);
long double y_max =  x_max * exp(x_max);
long double eps = 0.001;//точность

long double f_1 (long double x)
{
	long double f;
	f = 0.5 *x_max * exp((x * x) - 0.5);
	return f;
}

long double f_2 (long double x)
{
	long double f;
	long double a = (-1) * log (A/x);
	f = pow (a,0.5);
	return f;
}

int main()
{	
	long double x_0 = x_max;
	long double x1 = 0;//правый корень
	int i = 0;
	long double q_1 = 0.9;
	long double eps_0_1 = ((f_1(x_max))/(2*x_max*x_max * exp((x_max  * x_max ) + x_max)));
	int n_1 = abs((log((eps/2)/eps_0_1))/(log(q_1)));//количесвто итераций
	while(i <= n_1)
	{
		x1 = f_1(x_0);
		x_0 = x1;
		i++;
	}
	long double x2 = 0;//левый корень
	x_0 = 0;
	int j = 0;
	long double q_2 = 0.53;
	long double eps_0_2 = ((f_2(x_max))/((1/(pow(-log(A/x_max),0.5) * 2 *x_max))));
	int n_2 = abs((log((eps/2)/eps_0_2))/(log(q_2)));//количесвто итераций
	while(j <= n_2)
	{
		x2 = f_2(x_0);
		x_0 = x2;
		j++;
	}	
	cout << x1<< " " << x2 << endl;
	cout<< "Ответ:"<< x2 - x1;
	return 0;
}

