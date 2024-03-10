
#include "BitcoinExchange.hpp"
#include <string>


int main(int argc, char **argv)
{
    BitcoinExchange btc;

    if (argc == 2)
    {
        btc.read_files(argv[1]);
    }
    else
        return(1);
    return 0;
}

