#include <iostream>
#include <cmath> 
#include <vector>

using namespace std;

struct interval
{
   long double a, b;
};

long double f(long double x)
{
	long double f = atan(exp(x)) - 1e-8;
	return f;
}
long double f_1(long double x)
{
	long double f = (exp (x) / (exp(x * x) + 1));
	return f;
}

long double f_2(long double x)
{
	long double f = ((exp (x)) + ((1-2*x)*exp(x*x+x)))/((exp(x*x)+1)*(exp(x*x)+1));
	return f;
}

interval localization (interval x, long double R)
{
	vector<interval> root;
    struct interval tmp;
    long double distance = x.b - x.a ;
	long double a = x.a;
	long double b;
	long double step = (distance / R );
	while (a <= x.b)
	{
		b = a + step;

		if((f(a)*f(b)) < 0 )
		{
			tmp.a = a;
			tmp.b = b;
			root.push_back(tmp);
		}
		a += step;
	}
	vector <interval>::iterator iter;
	cout.precision(8);
    for (iter = root.begin(); iter < root.end(); iter++)
     {
         cout << "["<<iter->a<< ";" << " " << iter->b << "]"  << endl;
     }
	return tmp;
}
int main()
{
	interval Z;
	Z.a = -50 ;
	Z.b = 0 ;
	long double c;
	long double x_0;
	long double x;
	long double  x_root;
	Z = localization ( Z , 10000);
	cin >> x;
	cout << f(x) << endl ;
	cout << f_1(x) << endl;
	cout << f_2(x) << endl ;
	if(((f(x) * f_2(x))>0) && (( Z.a <= x ) && ( Z.b >= x)))
	{
		x_0 = x;
	}
	else 
	{
		cout << "Невыполнены следующие условия :" << endl << "1)f(x)*f''(x)> 0 или"  << endl << "2)x не принадлежит лок.отрезку "<< endl; 
		cin >> x;
		x_0 = x;
	}
	double eps = 1e-6;
	do
	{
		x_root = x_0 - ((f(x_0))/(f_1(x_0)));
		c = x_root - x_0;
		cout << c << endl;
		x_0 = x_root ;
	}
	while ( abs(c)  >= eps);
	cout << "корень уравнения:" << (f(x_0))/(f_1(x_0)) << endl;
	return 0;
}
