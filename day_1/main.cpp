#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>

int main() {
    std::ifstream inputFile("input/input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<int> left;
    std::vector<int> right;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int a, b;
        if (iss >> a >> b) {
            left.push_back(a);
            right.push_back(b);
        }
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    uint64_t total_difference = 0;
    for (size_t i = 0; i < left.size(); ++i) {
        total_difference += std::abs(left[i] - right[i]);
    }

    std::cout << "Total difference: " << total_difference << std::endl;

    return 0;
}