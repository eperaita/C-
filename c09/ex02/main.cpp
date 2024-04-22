#include "PmergeMe.hpp"

//Containers used: STD::VECTOR and STD::DEQUE

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
            std::cout << "Invalid input" << std::endl;
            return 1;
    }

    PmergeMe vector;
    vector.sortWithVector(argc, argv);
    vector.printFinal(1);

    PmergeMe deque;
    deque.sortWithDeque(argc, argv);

    vector.printTime(1);
    deque.printTime(2);

    return 0;

}