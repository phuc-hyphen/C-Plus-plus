#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

void str_replace(std::string &str) {
    for (char & i : str) {
        if (i == '\n')
            i = ' ';
    }
}

std::string read_file(std::ifstream &ifs)
{
    std::string content;
    std::ostringstream ss;
    ss << ifs.rdbuf();
    content = ss.str();

    return content;
}

std::vector<std::string> tokenize(std::ifstream &ifs) {
    std::vector<std::string> v;
    std::string content = read_file(ifs);
    str_replace(content);
    std::stringstream ss(content);
    std::string str;
    while (getline(ss, str, ' ')){
            v.push_back(str);
        }
    return v;
}

int find_motive(const std::vector<std::string>& v, const std::string& subStr){
    int count = 0;
    for (auto & i : v) {
        if (i.find(subStr) != std::string::npos)
        {
            count++;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    std::ifstream file;
    if (argc != 3) {
        std::cout << "Usage : You have to enter only 2 arguments.";
        return 1;
    }
    if (strlen(argv[1]) < strlen(argv[2])) {
        return 1;
    }
    file.open(argv[1]);
    if (!file.fail()) {
        std::vector<std::string> tokens = tokenize(file);
        int res = find_motive(tokens, argv[2]);
        std::cout << "The file " << argv[1] << " contains " << res << " words containing the motive " << argv[2];
        file.close();
        return 0;
    }
    std::cout << "The file " << argv[1] << " could not be opened";
    return 1;
}