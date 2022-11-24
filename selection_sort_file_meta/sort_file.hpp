// Do not change
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <type_traits>
#include <vector>
#include <tuple>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful

template <class CONT, class T>
void read_file_to_cont(std::ifstream &f, CONT &c)
{
    T str;
    if (f.is_open())
    {
        while (f >> str)
        {
            c.push_back(str);
        }
        f.close();
    }
}

template <class CONT>
void read_file_to_cont(std::ifstream &f, CONT &c)
{
    char ch;
    if (f.is_open())
    {
        while (f.good())
        {
            f.get(ch);
            if (ch != '\n')
                c.push_back(ch);
        }
        f.close();
        if (!f.eof() && f.fail())
            std::cout << "error reading ";
    }
}

template <class CONT, class T>
void read_and_sort(std::ifstream &fi, std::ofstream &fo)
{
    CONT cont = {};
    if constexpr (std::is_same_v<T, char>)
        read_file_to_cont<CONT>(fi, cont);
    else
        read_file_to_cont<CONT, T>(fi, cont);

    if (cont.size() < 2) //
        return;

    auto tmp = cont.cbegin();
    auto c = CONT(tmp, cont.cend());
    if constexpr (std::is_integral_v<T>)
        my_selection_sort(c.begin(), c.end(), [](auto l, auto r) -> bool {
            return std::make_tuple(l % 2, l) < std::make_tuple(r % 2, r);
        });
    else
        my_selection_sort(c.begin(), c.end());
    if (fo.is_open())
    {
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
    // else
    //     std::cout << "Unable to open output file";
}

template <class T>
void read_and_sort_decide_container(std::ifstream &fi, std::ofstream &fo)
{
    char type_container;
    fi >> type_container;
    fo << type_container;
    fo << "\n";
    switch (type_container)
    {
    case 'l': {
        read_and_sort<std::list<T>, T>(fi, fo);
        break;
    }
    case 'v': {
        read_and_sort<std::vector<T>, T>(fi, fo);
        break;
    }
    case 'd': {
        read_and_sort<std::deque<T>, T>(fi, fo);
        break;
    }
    }
}

void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo)
{
    char type_value;
    fi >> type_value;
    fo << type_value;
    fo << "\n";
    switch (type_value)
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
