//
// Created by mas on 3/2/22.
//

#include "Config.h"
#include <fstream>

Config *Config::getInstance()
{
    if (m_instance == nullptr) m_instance = new Config();
    return m_instance;
}

Config::Config()
{
    std::string home = getenv("HOME");
    std::string m_configFile = home + "/.config/flightcheck/config";
    m_configMap = {
            {"directory", home + "flightcheck"}};
    // open file
    std::ifstream file(m_configFile);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::string key = line.substr(0, line.find('='));
            std::string value = line.substr(line.find('=') + 1);
            if (m_configMap.find(key) != m_configMap.end()) m_configMap[key] = value;
            else
                std::throw_with_nested(std::runtime_error("Config file contains unknown key: " + key));
        }
        file.close();
    }
}

std::string Config::get(const std::string& key)
{
    if (m_configMap.find(key) != m_configMap.end()) return m_configMap[key];
    else
        throw std::runtime_error("Invalid config key: " + key);
}
