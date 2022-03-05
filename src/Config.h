#ifndef FLIGHTCHECK_CONFIG_H
#define FLIGHTCHECK_CONFIG_H

#include <map>
#include <string>

class Config
{
private:
    std::map<std::string, std::string> m_configMap;
    static void validate(const std::string &key, std::string &value);

public:
    Config();
    std::string get(const std::string& key);
};

#endif//FLIGHTCHECK_CONFIG_H
