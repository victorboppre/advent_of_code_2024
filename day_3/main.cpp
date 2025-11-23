#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <regex>

// For this problem i'll use regex

int main()
{
    // Opening the input file
    std::ifstream inputFile("input/input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string fileContent;
    std::getline(inputFile, fileContent, '\0'); // Read entire file content
    inputFile.close();

    std::regex pattern("\\bdo(?:n't)?\\(\\)|mul\\(\\d+,\\s*\\d+\\)");

    std::smatch matches;

    std::sregex_iterator currentMatch(fileContent.begin(), fileContent.end(), pattern);
    std::sregex_iterator lastMatch; // Iterador final

    uint64_t totalSum = 0;
    bool do_multiplication = true;
    while (currentMatch != lastMatch)
    {
        std::smatch match = *currentMatch;
        if(match.str().find("do()") != std::string::npos)
        {
            do_multiplication = true;
        }
        else if(match.str().find("don't()") != std::string::npos)
        {
            do_multiplication = false;
        }
        else if(match.str().find("mul(") != std::string::npos)
        {
            std::regex numPattern("\\d+");
            std::sregex_iterator numIt(match.str().begin(), match.str().end(), numPattern);
            std::sregex_iterator numEnd;

            if (numIt != numEnd)
            {
                int num1 = std::stoi(numIt->str());
                ++numIt;
                if (numIt != numEnd)
                {
                    int num2 = std::stoi(numIt->str());
                    if (do_multiplication)
                    {
                        totalSum += static_cast<uint64_t>(num1) * static_cast<uint64_t>(num2);
                    }
                }
            }
        }
        
        currentMatch++;
    }

    std::cout << "Total Sum: " << totalSum << std::endl;
    return 0;
}