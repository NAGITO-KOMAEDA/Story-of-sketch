#pragma once
#include <string>
#include <map>
#include <vector>

extern std::map<std::string, std::vector<std::string>> game_texts;

void print_section(const std::string& section, int delay_ms = 1500);