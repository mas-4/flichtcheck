//
// Created by mas on 3/2/22.
//

#include "Config.h"
#include "utilities.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

Config::Config()
{
    std::string home = getenv("HOME");
    std::string m_configFile = home + "/.config/flightcheck/config";
    m_configMap = {
            {"home", home},
            {"directory", home + "/flightcheck/"},
    };
    // open file
    std::ifstream file(m_configFile);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            // strip comments
            if (line.find('#') != std::string::npos) line = line.substr(0, line.find('#'));
            // if whitespace only, skip
            if (line.find_first_not_of(' ') == std::string::npos) continue;
            line = utils::strip(line);
            // split into key and value and store
            std::string key = line.substr(0, line.find('='));
            std::string value = line.substr(line.find('=') + 1);
            if (m_configMap.find(key) != m_configMap.end())
            {
                Config::validate(key, value);
                m_configMap[key] = value;
            }
            else
                throw std::runtime_error("Config file contains unknown key: " + key);
        }
        file.close();
    }
}

std::string Config::get(const std::string &key)
{
    if (m_configMap.find(key) != m_configMap.end()) return m_configMap[key];
    else
        throw std::runtime_error("Invalid config key: " + key);
}

void Config::validate(const std::string &key, std::string &value)
{
    // validation and normalization of config values
    if (key == "directory")
    {
        if (value.at(0) == '~') value = getenv("HOME") + value.substr(1);
        value = fs::path(value).string();
    }
}
