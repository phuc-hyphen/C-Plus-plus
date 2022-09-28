#include <iostream>

#include "sources.h"
//#include "sources_2.h"
int main()
{
    // std::vector<int> numbers;
    while (std::cin >> i)
    {
        std::cout << i << " is a prime: ";

        if (Is_Prime_faster(i))
            std::cout << "True" << std::endl;
        else
            std::cout << "False" << std::endl;
    }
    return 0;
}