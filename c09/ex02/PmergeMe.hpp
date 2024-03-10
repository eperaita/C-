#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>

class PmergeMe{

    private:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        const PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();


    public:
        
        static void sortWithVector(std::vector<int> vec);
        static void sortWithDeque(std::deque<int> deq);


};

#endif