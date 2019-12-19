#include <iostream>
#include <cmath> 

using namespace std;

long double fact(int N)
{
    if(N < 0) {
        return 0; 
	}
    else if (N == 0) {
        return 1;
	}
    else{ 
        return N * fact(N - 1); 
	}
}

int main()
{		
	cout.precision(11);
	long double dt = 0.0001;//неустранимая погрешность аргумента
	long double t; 
	long double k = 0;
	cin >> t;
	long double u = sin (t);
	long double u_app = sin (0);
	while (abs(u - u_app) >= dt)
	{
		u_app += (pow(-1,k)) * (pow(t,2*k+1))/(fact(2*k+1));
		k++;
	}
	cout << "Порядок аппроксимаций для sin t: "<< k  << endl;
	
	long double n = 1;
	long double f = exp (t);
	long double f_app = exp(0);
	while (abs(f - f_app) >= dt)
	{
		f_app += (pow(t,n))/(fact(n));
		n++;
	}
	cout << "Порядок аппроксимаций для exp(t): " << n - 1 <<endl ;
	
	
	
	
	// совершенный алгоритм для отрезка t = [10;11]
	if((t >=10) && (t<=11)){
	long double x = t - 10;
	long double g = sin (x);
	long double g_app = sin (0);
	long double i = 0;
	while (abs(g - g_app) >= dt)
	{
		g_app += (pow(-1,i)) * (pow(x,2*i+1))/(fact(2*i+1));
		i++;
	}
	cout << "Порядок аппроксимаций для sin t(мой предложенный алгоритм): "<< i  << endl;
	
	long double j = 1;
	long double q = exp (x);
	long double q_app = exp(0);
	while (abs(q - q_app) >= dt)
	{
		q_app += (pow(x,j))/(fact(j));
		j++;
	}
	cout << "Порядок аппроксимаций для exp(t)(мой предложенный алгоритм): " << j - 1 <<endl ;
	}
	return 0;
}

