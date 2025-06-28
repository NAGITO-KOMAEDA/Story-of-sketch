#include "text_loader.h"
#include <fstream>
#include <iostream>

std::map<std::string, std::vector<std::string>> load_texts(const std::string& filename) {
    std::map<std::string, std::vector<std::string>> text_map;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return text_map;
    }

    std::string line;
    std::string current_section;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line.front() == '[' && line.back() == ']') {
            current_section = line.substr(1, line.size() - 2);
            continue;
        }

        if (!current_section.empty()) {
            text_map[current_section].push_back(line);
        }
    }

    return text_map;
}