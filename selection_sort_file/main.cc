// Do not change me

#include <iostream>
#include <string>

#include "sort_file.hpp"
int main(int argc, char *argv[])
{
    if (argc != 2)
        throw std::runtime_error("Expected input filename as argument");

    std::ifstream fi(argv[1]);
    if (!fi)
        throw std::runtime_error("Expected input filename as argument");

    std::ofstream fo("sorted.txt");
    if (!fo)
        throw std::runtime_error("Unable to open output");

    std::vector<std::string> cont;
    read_and_sort<std::vector<std::string>,std::string>(fi, fo);


    // read_and_sort_decide_valuetype(fi, fo);
    // read_and_sort<std::vector<std::string>>(fi, fo);
    return 0;
}