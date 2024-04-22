#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <utility>
#include <cmath>


class PmergeMe{

    private:
        
        int margi;

        std::vector<int> jacobsthal;
        std::deque<int> d_jacobsthal;

        std::vector<std::pair<int,int> > v_pairs;
        std::vector<int> v_main;
        std::vector<int> v_pend;
        
        std::deque<std::pair<int,int> > d_pairs;
        std::deque<int> d_main;
        std::deque<int> d_pend;
        double tiempo_de_ejecucion;

        int get_jacobstal(int n);
        int fillVector(int argc, char **argv);
        int fillDeque(int argc, char **argv);

        void print(std::vector<int> v, std::string msg);
        void printPairs(std::vector<std::pair<int, int> > v, std::string msg);
        void printDeq(std::deque<int> d, std::string msg);
        void printPairsDeq(std::deque<std::pair<int, int> > v, std::string msg);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        const PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();

        void sortWithVector(int argc, char **argv);
        void sortWithDeque(int argc, char **argv);

    
        void printFinal(int type);
        void printTime(int type);


};

#endif