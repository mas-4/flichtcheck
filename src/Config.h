#ifndef FLIGHTCHECK_CONFIG_H
#define FLIGHTCHECK_CONFIG_H

#include <map>
#include <string>

class Config
{
private:
    static Config *instance;
    std::map<std::string, std::string> m_configMap;
    Config();

public:
    static Config *getInstance();
    std::string get(std::string key);
};


#endif//FLIGHTCHECK_CONFIG_H
