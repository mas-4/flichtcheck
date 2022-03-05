//
// Created by mas on 3/5/22.
//
#include "utilities.h"

namespace utils {
    std::string strip(std::string str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1));
    }
}