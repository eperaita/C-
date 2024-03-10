#include "PmergeMe.hpp"

//Containers used: STD::VECTOR and STD::DEQUE

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
            std::cout << "Invalid input" << std::endl;
            return 1;
    }

    //Rellenar vector con input
    std::vector<int> sort1;

       std::cout << "Before: ";
       for (int i = 1; i < argc ; i++ ){
            try{
                for (int j = 0; argv[i][j]; j++ ){ 
                    if(!isdigit(argv[i][j]))
                        throw std::exception();
                }
                int n = std::stoi(argv[i]);
                if (n < 0 )
                    throw std::exception();
                std::cout << n << " ";
                sort1.push_back(n);
            }
            catch(std::exception &e){
                std::cout << "ERROR: Invalid input. Only allowed with positive integers" << std::endl;
                return 1;
            }
       };
    std::cout << std::endl;

    //Rellenar deque con input
    std::deque<int> sort2;
       
       for (int i = 1; i < argc ; i++ ){
            try{
                for (int j = 0; argv[i][j]; j++ ){ 
                    if(!isdigit(argv[i][j]))
                        throw std::exception();
                }
                int n = std::stoi(argv[i]);
                if (n < 0 )
                    throw std::exception();
                sort2.push_back(n);
            }
            catch(std::exception &e){
                std::cout << "ERROR: Invalid input. Only allowed with positive integers" << std::endl;
                return 1;
            }
       };


    PmergeMe::sortWithVector(sort1);
    PmergeMe::sortWithDeque(sort2);


    return 0;

}