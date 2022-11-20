// Do not change
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful

template <class CONT>
void read_file_to_cont(std::ifstream &f, CONT &c)
{
    CONT tmp = c;
    std::string str;

    if (f.is_open())
    {
        while (getline(f, str))
        {
            if (str.size() > 0)
                c.push_back(str);
        }
        f.close();
    }
    else
        std::cout << "Unable to open input file";
}

template <class CONT, class T>
void read_and_sort(std::ifstream &fi, std::ofstream &fo)
{
    std::vector<std::string> cont;
    read_file_to_cont<std::vector<std::string>>(fi, cont);
    if (cont.size() < 2) //
        return;

    auto tmp = cont.cbegin();
    // tmp++;
    auto c = CONT(tmp += 2, cont.cend());
    my_selection_sort(c.begin(), c.end());
    if (fo.is_open())
    {
        fo << cont[0] << "\n";
        fo << cont[1] << "\n";
        auto tmp = c.begin();
        while (tmp != c.end())
        {
            fo << *tmp;
            if (tmp != c.end())
                fo << "\n";
            tmp++;
        }
        fo.close();
    }
    else
        std::cout << "Unable to open output file";
}

// template <class T>
// void read_and_sort_decide_container(std::ifstream &fi, std::ofstream &fo)
// {
//     std::vector<std::string> cont;
//     read_file_to_cont(fi, cont);
//     if (cont.size() < 2) //
//         return;
//     const char *a = cont[0].c_str(); // sring to char array

//     switch (a[0])
//     {
//     case 'l': {
//         read_and_sort<std::list<T>>(fi, fo);
//         break;
//     }
//     case 'v': {
//         read_and_sort<std::vector<T>>(fi, fo);
//         break;
//     }
//     case 'd': {
//         read_and_sort<std::deque<T>>(fi, fo);
//         break;
//     }
//     }
// }

// void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo)
// {
//     std::vector<std::string> cont;
//     read_file_to_cont(fi, cont);
//     if (cont.size() < 2) //
//         return;
//     const char *a = cont[0].c_str(); // sring to char array
//     switch (a[1])
//     {
//     case 'i': {
//         read_and_sort_decide_container<int>(fi, fo);
//         break;
//     }
//     case 'u': {
//         read_and_sort_decide_container<unsigned>(fi, fo);
//         break;
//     }
//     case 'f': {
//         read_and_sort_decide_container<float>(fi, fo);
//         break;
//     }
//     case 'd': {
//         read_and_sort_decide_container<double>(fi, fo);
//         break;
//     }
//     case 'c': {
//         read_and_sort_decide_container<char>(fi, fo);
//         break;
//     }
//     case 's': {
//         read_and_sort_decide_container<std::string>(fi, fo);
//         break;
//     }
//     }
// }
