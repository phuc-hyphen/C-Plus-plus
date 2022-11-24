#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <istream>
#include <typeinfo> // operator typeid
#include <vector>

template <>
void foo<double>(double d)
{
    std::cout << d << " " << std::endl;
}
template <class T>
void foo(T t)
{
    if constexpr (std::is_same_v<T, double>)
        std::cout << t << " " << std::endl;
    else
        std::cout << t << " " << std::endl;
}

void foo(auto t)
{
    if constexpr (std::is_same_v<decltype(t), double>)
        std::cout << t << " " << std::endl;
    else
        std::cout << t << " " << std::endl;
}
//----------------------------------------------------------------
template <class T>
void foo(T a)
{
    if constexpr (std::is_same_v<decltype(a), animal *>)
        std::cout << "animal ";
    else
        std::cout << "lion ";
}

int main()
{
    auto lptr = new lion();
    animal *aptr = lptr;
    foo(lptr);
    foo(aptr);
    delete lptr;
    return 0;
}