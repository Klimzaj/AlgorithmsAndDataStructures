#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	unsigned int n, i, g, w;
	bool * S;

	cout << "n wynosi: ";
	cin >> n;

	S = new bool[n + 1];

	for (i = 2; i <= n; i++) S[i] = true;

	g = (unsigned int)sqrt(n);

	for (i = 2; i <= g; i++)
		if (S[i])
		{
			w = i * i;
			while (w <= n)
			{
				S[w] = false;
                w++;
			}
		}

	for (i = 2; i <= n; i++) if (S[i]) std::cout << i << " ";
	std::cout << std::endl;
	
	delete[] S;
	return 0;
}