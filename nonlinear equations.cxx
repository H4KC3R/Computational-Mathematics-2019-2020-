#include <iostream>
#include <cmath> 

using namespace std;

struct point {
	double x;
	double y;
};


point operator- (point a, point b)
{
	point c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

long double norm ( point u)
{
	long double n = sqrt((u.x) * (u.x) + (u.y) * (u.y));
	return n;
}

struct point func(point u)
{
	point f ;
	f.x  = (u.x * u.x) + (u.y * u.y) - 1;
	f.y = u.y - tan(u.x);
	return f;
}

struct point jakobian_func (point u)
{
	point F;
	long double a = 1;
	long double b = -2*u.y;
	long double c = 1/((cos (u.x))* (cos (u.x)));
	long double d = 2 * u.x;
	point f = func(u);
	long double det = 1/((2 * u.x + (2 * u.y/(cos(u.x) * cos(u.x)))));
	F.x = det *  ( a * f.x + b * f.y);
	F.y = det *  ( c * f.x + d * f.y);
	return F;	
}

int main()
{
	point u0;
	point u_root;
	point c;
	u0.x = -200;
	u0.y = 100;
	double eps = 1e-6;
	do
	{
		u_root = u0 - jakobian_func(u0);
		c = u_root -u0;
		u0 = u_root ;
	}
	while ( norm(c)  >= eps);
	cout <<"Корень уравнения:" << u_root.x << " " << u_root.y << endl;
	return 0;
}

