#include <iostream>
#include <cmath>

double f(double d)
{
	return 2 * d - 1;
}


double zero(double func(double), double _a, double _b)
{
	// dokladnosc porownania z zerem
	const double dZero = 0.00000000001;
	double x0, f0, a, b;
	a = _a;
	b = _b;


	double fa = f(a); 
	double fb = f(b);

	x0 = (a + b) / 2;
	f0 = f(x0);
	
	while (fabs(a - b) < dZero)
	{
		x0 = (a + b) / 2;
		f0 = f(x0);
		
		if (fabs(f0) < dZero) break;

		if (fa * f0 < dZero)
		{
			b = x0;
		} 
		else
		{
			a = x0; 
			fa = f0;
		}
	}
	return x0;
}


int main(void)
{
	double a, b;
	a = 25;
	b = 3;
	std::cout << "f(0) : " << f(0) << std::endl;
	std::cout << "f(1) : " << f(1) << std::endl;
	std::cout << "Miejsce zerowe: " << zero(f, a, b) << std::endl;
	return 0;
}








