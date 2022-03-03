#ifndef FLIGHTCHECK_CONFIG_H
#define FLIGHTCHECK_CONFIG_H

#include <map>
#include <string>

class Config
{
protected:
    Config();
    static Config *m_instance;
    std::map<std::string, std::string> m_configMap;

public:
    static Config& getInstance();
    std::string get(const std::string& key);
};


#endif//FLIGHTCHECK_CONFIG_H
