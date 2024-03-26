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
    
    std::vector<std::pair<int, int> > sort1;

       std::cout << "Before: ";
       for (int i = 1; i + 1 < argc ; i+=2 ){
            try{
                for (int j = 0; argv[i][j]; j++ ){ 
                    if(!isdigit(argv[i][j]))
                        throw std::exception();
                }
                int n = std::stoi(argv[i]);
                if (n < 0 )
                    throw std::exception();
                std::cout << n << " " << n + 1 << " ";
                sort1.push_back(std::make_pair(std::stoi(argv[i]), std::stoi(argv[i + 1]))); 

            }
            catch(std::exception &e){
                std::cout << "ERROR: Invalid input. Only allowed with positive integers" << std::endl;
                return 1;
            }
       };
    std::cout << std::endl;

    //Rellenar deque con input
   //std::deque<std::pair<int, int> > sort2;
   //   
   //   for (int i = 1; i < argc ; i++ ){
   //        try{
   //            for (int j = 0; argv[i][j]; j++ ){ 
   //                if(!isdigit(argv[i][j]))
   //                    throw std::exception();
   //            }
   //            int n = std::stoi(argv[i]);
   //            if (n < 0 )
   //                throw std::exception();
   //            sort2.push_back(n);
   //        }
   //        catch(std::exception &e){
   //            std::cout << "ERROR: Invalid input. Only allowed with positive integers" << std::endl;
   //            return 1;
   //        }
   //   };
    PmergeMe::sortWithVector(sort1);
    //PmergeMe::sortWithDeque(sort1);


    return 0;

}