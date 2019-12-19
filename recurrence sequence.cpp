#include <iostream>
#include <cmath> 

using namespace std;

long double e = exp(1);

struct solution
{
   long double q1, q2;
};

struct solution sol_quad (int a , int b , int c )
{
       long double q1 = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
       long double q2 = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
       struct solution q = { q1 , q2 };
       return q;
}
long double sol_heterogeneity(int a , int b , int c , long double f)
{
	long double q = f / (a + b + c );
	return q;
}

struct solution find_const(struct solution q , long double q_private, long double y0 , long double y1 , long double f)
{
	long double c2 = ((y1 - q_private ) - (q.q1*(y0 - q_private)))/(q.q2 - q.q1);
	long double c1 =  y0 - q_private - c2;
	struct solution c = {c1 , c2};
	return c;
}

void sequence (int N , struct solution q ,struct solution constant, long double q_private )
{
	int i = 0;
	for ( ; i<=N ; i++)
	{
		cout << "N:" <<  i << " " <<  (constant.q1 * pow(q.q1,i)) + (constant.q2 *pow(q.q2,i)) + q_private << endl;

	}
}

int main() 
{ 
	int N;
	struct solution constant;
	struct solution q;
	long double q_private;
    int a, b ,c ;
    long double y0 = e/10, y1 = e/10 ;
    cout << " a * y(n+1) + b * y(n) + c * y(n-1) = e ";
    cout << endl; 
    cout << "Коэфицент a: ";
    cin >> a;
    cout << endl;  
    cout << "Коэфицент b: ";
    cin >> b;
    cout << endl;  
    cout << "Коэфицент c: ";
    cin >> c;
    cout << endl; 
    
    if((b*b - 4*a*c) >= 0)
    {
		q = sol_quad(a,b,c);
	}
	else
	{
		system("дискримант меньше нуля");
		return 0; 
	}
	q_private = sol_heterogeneity(a,b,c,e);
	constant = find_const(q,q_private,y0,y1,e);
	
	cout << "Общее решение : " << "(" << constant.q1 << ")" << "*" << "("<< q.q1 << ")" <<  "^(n)" << "+" << "("<< constant.q2 << ")" << "*" << "("<< q.q2 << ")" << "^(n)" << "+" << q_private << endl;
	cout << "Введите сколько элементов последовательности вы хотите вывести:";
	cin >> N;
    cout << endl;
	sequence(N,q,constant,q_private);
    return 0;
}
