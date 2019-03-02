#include <iostream>
#include <cmath>

double f(double d)
{
	return 2 * d - 1;
}


double zero(double func(double), double _a, double _b)
{
	// dokladnosc porownania z zerem
	const double dZero = 0.0000000001;
	

	double fa = f(_a); 
	double fb = f(_b);

	double x0, f0;
	x0 = (_a + _b) / 2;
	
	while (fabs(_a - _b) > dZero)
	{
		x0 = (_a + _b) / 2;
		f0 = f(x0);
		
		if (fabs(f0) < dZero) break;
		if (fa * f0 < 0) _b = x0;
		else
		{
			_a = x0; 
			fa = f0;
		}
	}
	return x0;
}


int main(void)
{
	double a, b;
	a = 2;
	b = 100;
	std::cout << "f(0) : " << f(0) << std::endl;
	std::cout << "f(1) : " << f(1) << std::endl;
	std::cout << "Miejsce zerowe: " << zero(f, a, b) << std::endl;
	return 0;
}








