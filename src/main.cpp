#include <iostream>
#include "Config.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Config * config = Config::getInstance();
    std::cout << config->get("directory") << std::endl;
    return 0;
}
