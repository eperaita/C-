#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <exception>

BitcoinExchange::BitcoinExchange(){

};
BitcoinExchange::~BitcoinExchange(){

};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
    *this = other;
};
const BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
    this->map = other.map;
    return (*this);
}; 

//--------------------------------------

void BitcoinExchange::bitcoinexchange(std::string date, float ammount, std::map<std::string, float> map){

    std::string ref_date;
    float ref_value;

    //Buscar la fecha en el map hasta encontrar una superior. Si llega a la superior se queda con la anterior. 
    for (std::map<std::string, float>::iterator iter = map.begin(); iter != map.end(); iter++){
        if (iter->first <= date)
        {
            ref_date = iter->first;
            ref_value = iter->second;
        }
        else
            break;
    }
    
    std::cout << std::fixed << std::setprecision(2) << ref_value * ammount << std::endl;
    return;
};

//-----------INPUT FILTERING -------------

bool BitcoinExchange::aredigit(const std::string& str) {
    bool first = 0;
    for ( size_t i = 0;  i < str.size() ; i++) {
        if (first == 1)
        {
            if (!isdigit(str[i])) 
                return false; // Si un carácter no es un dígito
        }
        else 
        {
            if (!isdigit(str[i]) || str[i] != '-' )
                return false; // Si un carácter no es un dígito, o guion
        }
        first = 1;

    }
    return true; // Si todos los caracteres son dígitos,
}

int BitcoinExchange::check_date(std::string date, std::map<std::string, float> map){

    try{
        //YEAR
        size_t pos = std::distance(date.begin(), std::find(date.begin(), date.end(), '-'));
        if (pos == std::string::npos)
            throw std::exception();
        std::string year; 
        year = date.substr(0, pos);
        if (aredigit(year) || std::atoi(year.c_str()) < 0 || std::atoi(year.c_str()) > 2024)
            throw std::exception();
        year = date.substr(0, pos);

        //MONTH
        size_t pos2 = std::distance(std::find(std::find(date.begin(), date.end(), '-'), date.end(), '-'), date.end()) ; //emplieza desde el guion?? o despues ? 
        if (pos2 == std::string::npos)
            throw std::exception();
        std::string s_month; 
        s_month = date.substr(pos + 1, pos2);
        if (aredigit(s_month) || std::atoi(s_month.c_str()) < 0 || std::atoi(s_month.c_str()) > 12)
            throw std::exception();
        int month = std::atoi(s_month.c_str());
        //DAY
        std::string s_day; 
        s_day = date.substr(pos2 + 2, date.size());
        if (aredigit(s_day) || std::atoi(s_day.c_str()) < 0 || std::atoi(s_day.c_str()) > 31)
            throw std::exception();
        int day = std::atoi(s_day.c_str());
        if (month == 2 &&  std::atoi(year.c_str()) % 4 == 0 && day > 29 ) //febrero bisiesto
            throw std::exception();
        else if (month == 2 &&  std::atoi(year.c_str()) % 4 != 0  && day > 28) //febrero no bisiesto
            throw std::exception();
        else if ((month == 1 || month == 3  || month == 5 || month == 7 || month == 8  || month == 10 || month == 12) && day > 31) //31 d
            throw std::exception();
        else if ( day > 30)
            throw std::exception();
    }
    catch(std::exception &e){
        std::cout << "Error: bad date input => " << date << std::endl;
        return 1 ;
    }
    //DATE TOO OLD
    std::map<std::string, float>::iterator iter = map.begin();
    if (iter->first > date)
    {
        std::cout << "Error: date required too old." << std::endl;
        return 1;
    }
    return 0;
};

int BitcoinExchange::check_value(std::string s_ammount){

        if (aredigit(s_ammount))
        {    
            std::cout << "Error: bad ammount input => " << s_ammount << std::endl;
            return 1;
        }
        float ammount; 
        ammount = std::stof(s_ammount);
        if (ammount < 0)
        {    
            std::cout << "Error: not a positive number." << std::endl;
            return 1;
        }
        if (ammount > 1000)
        {    
            std::cout << "Error: too large number." << std::endl;
            return 1;
        }
        return 0;

};

int BitcoinExchange::check_line(std::string line, std::map<std::string, float> map){

    std::string date;
    std::string ammount;

    size_t pos = std::distance(line.begin(), std::find(line.begin(), line.end(), '|'));
    if ( pos != std::string::npos)
    {
        
        date = line.substr(0, pos - 1 );
        ammount = line.substr(pos + 2 , line.size());
        if (!check_date(date, map))
        {
            if(!check_value(ammount))
            {
                std::cout << date << " => " << ammount << " = " ;
                bitcoinexchange(date, std::stof(ammount), map);
                return(0);
            }
        } 
        
    }
    return (1);

};

//-----------INPUT PROCESSING -------------

void BitcoinExchange::save_line(std::map<std::string, float> *map , std::string &line)
{
    std::string key;
    float value;

    size_t pos = std::distance(line.begin(), std::find(line.begin(), line.end(), ','));
    if ( pos != std::string::npos)
    {
        
        key = line.substr(0, pos);
        value = std::stof(line.substr(pos + 1 , line.size()));
        //std::cout << "LINEA: " << key << " - " << value << std::endl;
	    (*map)[key] = value;
        
    }
    else
        std::cout << "Error: Datafile corrupted in line => " << line << std::endl;

};

void BitcoinExchange::read_files(std::string file){

    std::fstream datafile;
    std::fstream myfile;
    size_t first = 0;

    datafile.open("data.csv", std::ios::in);
    if (!datafile)
    {
        std::cout << "Error: the file data.csv does not exist." << std::endl;
        exit (1);
    }

    std::map<std::string, float> *map = new std::map<std::string, float>;
    while (true)
    {
        std::string line;
        try{
            if (!std::getline(datafile, line))
            {    
                if (datafile.eof())
                    break;
                std::cout << "Error: Datafile corrupted in line => " << line << std::endl;
            }
            else if (first !=  0 )
                save_line(map, line);
            first = 1;
        }
        catch(std::exception &e){
            std::cout << "Error: bad input => "<< line << std::endl; }
    }
    //std::cout << "           Data read!" << std::endl;

    myfile.open(file, std::ios::in);
    if (!myfile)
    {
        std::cout << "Error: the file provided does not exist." << std::endl;
        exit (1);
    }

    while (true)
    {
        std::string line;
        try{
            
            if (!std::getline(myfile, line))
            {    
                if (myfile.eof())
                    break;
                std::cout << "Error: File provided corrupted in line => " << line << std::endl;
            }
            else if (first != 1 )
                check_line(line, *map);
            first = 0;
        }
        catch(std::exception &e){
            std::cout << "Error: bad input => "<< line << std::endl; }
    }

    delete map ;
};