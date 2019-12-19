#include <iostream>
#include <cmath>

using namespace std;
long double eps = 0.000001;//точность

struct interval
{
   long double a, b;
};

long double f_1 (long double x)
{
	long double f;
	f = 0.5 * acos(-0.4 *x);
	return f;
}

int main()
{	
	//локализация точек(определены графический)
	struct interval l1;
	l1.a = 1.9187;
	l1.b = 1.9188;
	double length1 = l1.b - l1.a;
	struct interval l2;
	l2.a = 0.9886;
	l2.b = 0.9887;
	double length2 = l2.b - l2.a;
	struct interval l3;
	l3.a = -0.6533;
	l3.b = -0.6532;
	double length3 = l3.b - l3.a;
	//Количество итераций, требуемое для достижения заданной точности
	int n1 = (log (length1/eps))/(abs(log (2)));
	int n2 = (log (length2/eps))/(abs(log (2)));
	int n3 = (log (length3/eps))/(abs(log (2)));
	
	int i = 0;
	long double x1 = 0;
	long double a = l1.a;
	long double b = l1.b;
	while ( i < n1)
	{
		x1 = (b + a)/2;
		if((f_1(a) * f_1(x1)) < 0)
		{
			a = a;
			b = x1;
		}
		else if((f_1(x1) * f_1(b)) < 0)
		{
			a = x1;
			b = b;
		}
		i++;
	}
	
	i = 0;
	long double x2 = 0;
	a = l2.a;
	b = l2.b;
	while ( i < n2)
	{
		x2 = (b + a)/2;
		if((f_1(a) * f_1(x2)) < 0)
		{
			a = a;
			b = x2;
		}
		else if((f_1(x2) * f_1(b)) < 0)
		{
			a = x2;
			b = b;
		}
		i++;
	}
	
	i = 0;
	long double x3 = 0;
	a = l3.a;
	b = l3.b;
	while ( i < n3)
	{
		x3 = (b + a)/2;
		if((f_1(a) * f_1(x3)) < 0)
		{
			a = a;
			b = x3;
		}
		else if((f_1(x3) * f_1(b)) < 0)
		{
			a = x3;
			b = b;
		}
		i++;
	}
	
	cout << "Первый корень:" << x1 << endl;
	cout << "Второй корень:" << x2 << endl;
	cout << "Третий корень:" << x3 << endl;
	return 0;
}


