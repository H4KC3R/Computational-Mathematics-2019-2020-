#include <iostream>
#include <cmath> 
#include <vector>

//~ x^{5}-999998x^{4}-1999998.000001x^{3}-1999997x^{2}-1999999.000001x-999999=y
using namespace std;

long double a0 = 1;
long double a1 = -999998;
long double a2 = -1999998.000001;
long double a3 = -1999997;
long double a4 = -1999999.000001;
long double a5 = -999999;
	
struct interval
{
   long double a, b;
};

long double f(long double x)
{
	long double q = (a0 * pow(x,5)) + (a1 * pow(x,4)) + (a2 * pow(x,3)) + (a3 * pow(x,2)) + (a4 * pow(x,1)) + a5;
	return q;
}

void localization (interval x, long double R)
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
	
}
int main() 
{ 
	struct interval x;
	struct interval x1;
	x1.a = -1.01;
	x1.b = -0.99; 
	x.a = (abs(a5))/(abs(a5) + abs(a4));
	x.b = 1 + ((abs(a4))/a0);
	double R;
	cin >> R;
	localization(x,R);
	localization(x1,R * 10);
    return 0;
}

