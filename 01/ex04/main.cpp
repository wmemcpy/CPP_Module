#include <iostream>
#include <fstream>
#include <sstream>

std::string replace(const std::string &str, const std::string &from, const std::string &to)
{
    std::string result = str;
    size_t start_pos = 0;

    while ((start_pos = result.find(from, start_pos)) != std::string::npos)
    {
        result.erase(start_pos, from.length());
        result.insert(start_pos, to);
        start_pos += to.length();
    }
    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./" << argv[0] << "<filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (filename.empty() || s1.empty())
    {
        std::cerr << "Error: Empty string" << std::endl;
        return 1;
    }
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();
    inFile.close();

    std::string newContent = replace(content, s1, s2);

    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not create output file " << filename + ".replace" << std::endl;
        return 1;
    }

    outFile << newContent;
    outFile.close();

    return 0;
}
