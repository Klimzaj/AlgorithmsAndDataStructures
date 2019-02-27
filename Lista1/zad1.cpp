#include <iostream>
#include <cmath>

int bezRek(int liczba, int wykladnik) {

	if (wykladnik == 0) {
		return 1;
	}
	int result = 1;
	int liczba_operacji = wykladnik / 2;
	if (wykladnik % 2 == 0) {
		while (liczba_operacji > 0)
		{
			result *= liczba;
			liczba_operacji--;
		}

		return result*result;
	}
	else {
		while (liczba_operacji > 0)
		{
			result *= liczba;
			liczba_operacji--;
		}
		return result*result*liczba;
	}



}

int zRek(int liczba, int wykladnik)
{
	int value = liczba;
	if (wykladnik == 0) {
		return 1;
	}
	else if (wykladnik == 1) {
		return liczba;
	}
	if (wykladnik % 2 == 0) {
		return zRek(liczba*liczba, wykladnik / 2);
	}
	else
	{
		return liczba *zRek(liczba*liczba, wykladnik / 2);
	}
	
}


int main(void)
{
	std::cout << bezRek(2, 20) << std::endl;
	std::cout << zRek(2, 20) << std::endl;
	std::cout << std::pow(2, 20) << std::endl;
	return 0;
}
