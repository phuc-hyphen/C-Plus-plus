#include<vector>
#include<iostream>
#include <typeinfo>
template<class T>
int main()
{
    std::vector<int> args; 
    print_me<std::vector<int>>();
    return 0;
}
