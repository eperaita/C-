#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange{

    private: 
        std::map<std::string, float> map;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        const BitcoinExchange &operator=(const BitcoinExchange &other); 

        void bitcoinexchange(std::string date, float ammount, std::map<std::string, float> map);
        bool aredigit(const std::string& str);
        int check_date(std::string date);
        int check_value(std::string s_ammount);
        int check_line(std::string line, std::map<std::string, float> map);
        void save_line(std::map<std::string, float> *map , std::string &line);
        void read_files(std::string file);

};

#endif