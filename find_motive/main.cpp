#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string path, symbol;

    std::cout << "Could give the the file path you want to analyze ?"
              << std::endl;
    std::cin >> path;
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cout << "The file " << path << " could not be opened";
        return 1;
    }

    std::cout << "Veuillez entrer un motif svp ?" << std::endl;
    std::cin >> symbol;

    int count = 0;

    for (std::string word; file >> word;)
        if (word.find("in") != std::string::npos)
            count++;

    std::cout << "The file " << path << " contains " << count
              << " words contanninng the motive '" << symbol << "'"
              << std::endl;
    return 0;
}
