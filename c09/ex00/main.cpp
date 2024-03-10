
#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>

//Container used: STD::MAP

int main(int argc, char **argv)
{
    BitcoinExchange btc;

    if (argc != 2)
    {
        std::cout << "Invalid input: ./btc <input.txt>" << std::endl;
        return(1);
    }
    btc.read_files(argv[1]);
        
    return 0;
}

