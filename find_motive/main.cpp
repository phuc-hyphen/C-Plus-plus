#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <regex>
#include <sstream>

bool contains(std::string str, std::string substr){
        int i = 0;
        int j = 0;
        int save_j = j;
        while(i < str.size() && j < substr.size()){
            if (str[i] == substr[j])
            {
                save_j = j;
                j++;
            } else
            {
                    j = save_j;
            }
            i++;
        }

        if(j == substr.size())
            return true;
        return false;
}

void str_replace(std::string &str) {
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '\n')
            str[i] = ' ';
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

int find_motive(std::vector<std::string> v, std::string subStr){
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        bool b =  contains(v[i], subStr);
        if (b == 1)
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