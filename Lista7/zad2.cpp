#include <iostream>

size_t f(const size_t& n)
{
    return __builtin_popcount(n);
}
int main()
{
    std::cout << f(2019) << std::endl;
}