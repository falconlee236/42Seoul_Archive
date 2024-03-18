#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av){
    if (ac != 4){
        std::cerr << "you must input three parameter\n";
        return 1;
    }
    std::string filename(av[1]), src(av[2]), dst(av[3]);
    std::ifstream inputStream(filename);
    std::ofstream outputStream(filename + ".replace");
    if (!inputStream.is_open()){
        std::cerr << "invalid file name\n";
        return 1;
    }
    if (!outputStream.is_open()){
        std::cerr << "invalid output file name\n";
        inputStream.close();
        return 1;
    }
    while (true){
        std::string line;
        std::getline(inputStream, line);
        std::string::size_type idx;
        while ((idx = line.find(src)) != std::string::npos){
            line.insert(idx, dst);
            line.erase(idx + dst.length(), src.length());
        }
        outputStream << line;
        if (inputStream.eof())
            break;
        outputStream << "\n";
    }
    inputStream.close();
    outputStream.close();
}