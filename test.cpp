#include <fstream>
#include <iostream>
#include <istream>
#include <typeinfo> // operator typeid
#include <vector>
int main()
{
    std::ifstream myfile;
    myfile.open(
        "/home/huu-phuc-le/cpp_phuc/Exercices/selection_sort_file/v_i.txt");

    char test;
    // myfile.get(test);
    // while(getline(myfile, test);

    myfile >> test;
    myfile >> test;

    // std::cout << test << std::endl ;
    std::cout << test << std::endl;
    double tes;
    // myfile.get(tes);

    // auto t = getline(myfile, tes);

    myfile.close();
    // auto v = std::vector<std::string>{ "z", "x", "a", "aba", "c", "c", "uzm"
    // };
    // // auto e1 = v[1];

    // // std::cout << std::type_info(e1);

    // auto temp = v.begin();
    // // temp+= 2;
    // // std::cout << *temp;

    // auto c = std::vector<std::string>(temp+=2, v.end());

    // for (auto i : c  )
    // {
    //     std::cout<< i <<" ";
    // }

    // // const char* a = v[0].c_str(); // sring to char array

    // switch (a[0])
    // {
    // case 'z':
    //     std::cout << v.at(1);
    //     break;

    // default:
    //     break;
    // }
    // print_me<std::vector<int>>();
    return 0;
}
