#include <iostream>
#include <string>

size_t hash_str(const std::string& s)
{
    size_t h = 0; 
    for(const char& c : s)
        h = h * 13 ^ c;
    return h;
}

int main()
{
    std::cout << hash_str("zaba") << std::endl;
}
