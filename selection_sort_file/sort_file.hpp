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
void read_file_to_cont(std::ifstream &f, CONT c)
{
    CONT tmp = c;
    if (f.is_open())
    {
        while (getline(f, *tmp))
        {
            // *tmp = *line;
            tmp++;
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
    read_file_to_cont(fi, cont);

    auto c = CONT(cont.cbegin(), cont.cend());

    my_selection_sort(c.begin(), c.end());
    if (fo.is_open())
    {
        auto tmp = cont.begin();
        while (tmp != cont.end())
        {
            fo << *tmp;
            tmp++;
        }
        fo.close();
    }
    else
        std::cout << "Unable to open output file";
}

template <class T>
void read_and_sort_decide_container(std::ifstream &fi, std::ofstream &fo)
{
    std::vector<std::string> cont;
    read_file_to_cont(fi, cont);
    switch (*cont.begin())
    {
    case 'l': {
        read_and_sort<std::list<T>>(fi, fo);
        break;
    }
    case 'v': {
        read_and_sort<std::vector<T>>(fi, fo);
        break;
    }
    case 'd': {
        read_and_sort<std::deque<T>>(fi, fo);
        break;
    }
    }
}

void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo)
{
    std::vector<std::string> cont;
    read_file_to_cont(fi, cont);

    switch (*cont.at(1))
    {
    case 'i': {
        read_and_sort_decide_container<int>(fi, fo);
        break;
    }
    case 'u': {
        read_and_sort_decide_container<unsigned>(fi, fo);
        break;
    }
    case 'f': {
        read_and_sort_decide_container<float>(fi, fo);
        break;
    }

    case 'd': {
        read_and_sort_decide_container<double>(fi, fo);
        break;
    }
    case 'c': {
        read_and_sort_decide_container<char>(fi, fo);
        break;
    }
    case 's': {
        read_and_sort_decide_container<std::string>(fi, fo);
        break;
    }
    }
}
