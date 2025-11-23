#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstdint>

#define MAX_DIFFERENCE 3

int main()
{
    std::ifstream inputFile("input/input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Create the counter for true conditions
    int true_condition_count = 0;

    std::string line;
    int line_num = 0;

    // Read each line from the input file
    while (std::getline(inputFile, line))
    {
        bool condition = false;
        std::istringstream iss(line);
        std::vector<int> numbers;
        int num;

        while (iss >> num)
        {
            numbers.push_back(num);
        }
        // Checking the conditions
        for (int vector_counter = 0; vector_counter < numbers.size() - 1; vector_counter++)
        {
            // crescent condition
            if ((numbers[vector_counter + 1] - numbers[vector_counter] <= MAX_DIFFERENCE) && (numbers[vector_counter + 1] - numbers[vector_counter] > 0))
            {
                std::cout << numbers[vector_counter + 1] << " " << numbers[vector_counter] << " ";; 
                condition = true;
            }
            else
            {
                std::cout << numbers[vector_counter + 1] << " " << numbers[vector_counter]<< " " <<line_num <<std::endl;
                condition = false;
                break;
            }
        }

        if (condition)
        {
            std::cout << std::endl;
            true_condition_count++;
            std::cout << "Current true condition count for cresent: " << line_num <<std::endl;
        }

        for (int vector_counter = 0; vector_counter < numbers.size() - 1; vector_counter++)
        {
            // decrescent condition
            if ((numbers[vector_counter] - numbers[vector_counter + 1] <= MAX_DIFFERENCE) && (numbers[vector_counter] - numbers[vector_counter + 1] > 0))
            {
                condition = true;
            }
            else
            {
                condition = false;
                break;
            }
        }
        if (condition)
        {
            true_condition_count++;
            std::cout << "Current true condition count for decresent: " << line_num <<std::endl;
        }
        line_num++;

    }

    std::cout << "Total true condition count: " << true_condition_count << std::endl;
    return 0;
}