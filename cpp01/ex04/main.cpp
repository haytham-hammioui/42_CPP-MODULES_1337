#include <string>
#include <fstream>

int main(int ac, char **av){
    if(ac == 4){
        std::string filename = av[1];
        std::string s1 = av[2];
        if(s1.empty())
            return 1;
        std::string s2 = av[3];
        std::ifstream input(filename.c_str());
        if(!input)
            return 1;
        std::ofstream output((filename + ".replace").c_str());
        if(!output)
            return 1;
        std::string line;
        std::string replaced;
        while(std::getline(input, line)){
            replaced += line;
            if(!input.eof())
                replaced += "\n";
        }
        std::string result;
        size_t pos = 0;
        size_t found;
        while ((found = replaced.find(s1, pos)) != std::string::npos)
        {
            result += replaced.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }
        result += replaced.substr(pos);
        output << result;
        return 0;
    }
    return 1;
}