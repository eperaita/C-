#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
        
PmergeMe::PmergeMe(const PmergeMe &copy){ *this=copy; };

const PmergeMe &PmergeMe::operator=(const PmergeMe &copy){ 
    (void)copy;
    return(*this);
};

PmergeMe::~PmergeMe(){};

//_____________________________________________________________________________________________
//______________________________ALGORITHM STATIC FUNCTIONS ____________________________________

template <typename Container_type>
Container_type compareAndInsert(Container_type part1, Container_type part2){

    Container_type merged;

    unsigned long i= 0; 
    unsigned long j= 0;

    while (i <= part1.size()){
        
        //Check finish
        if (i == part1.size())
        {    
            for (part2[j] ; j < part2.size(); j++ )
                merged.push_back(part2[j]);
            return merged;
        }     
        else if (j == part2.size())
        {
            for (part1[i] ; i < part1.size(); i++ )
               merged.push_back(part1[i]);
            return merged;
        }
        //Compare
        else if (part1[i] <= part2[j])
        {
            merged.push_back(part1[i]);
            i++;
        }
        else 
        {
            merged.push_back(part2[j]);
            j++;
        }
    }

    return merged;


};

template <typename Container_type>
static Container_type sortpair(Container_type deq){

    if (deq.size() == 1 || deq[0] <= deq[1])
        return deq;
    else{

        int aux = deq[0];
        deq[0] = deq[1];
        deq[1] = aux;
        return deq;
    }

};

template <typename Container_type>
Container_type mergeInsert(Container_type deq){
    if (deq.size() <=2)
    {
        deq = sortpair(deq);
        return (deq);
    }

    //CUT

    int mid = deq.size() / 2;

    Container_type part1(deq.begin(), deq.begin() + mid);
    Container_type part2(deq.begin() + mid, deq.end());

    //RECURSIVELY CUT

    part1= mergeInsert(part1);
    part2= mergeInsert(part2);


    Container_type supermerged = compareAndInsert(part1, part2);


    return(supermerged);
    
};


//_____________________________________________________________________________________________
//______________________________ PMERGEME MEMBER FUNCTIONS ______________________________________

void PmergeMe::sortWithVector(std::vector<int> vec){

    // Start timer
    clock_t start = clock();

 
    std::vector<int> sorted = mergeInsert(vec);

    //Stop timer
    clock_t end = clock();
    double tiempo_de_ejecucion = (double)(end - start) / CLOCKS_PER_SEC;

    //Print sorted 
    std::cout << "After: ";
    for (unsigned long i = 0; i < sorted.size(); i++)
            std::cout << sorted[i] << " ";
    std::cout << std::endl;

    //Print time
   std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << tiempo_de_ejecucion << " seconds" << std::endl;  

};

void PmergeMe::sortWithDeque(std::deque<int> deq){

    // Start timer
    clock_t start = clock();

 
    std::deque<int>sorted = mergeInsert(deq);

    //Stop timer
    clock_t end = clock();
    double tiempo_de_ejecucion = (double)(end - start) / CLOCKS_PER_SEC;

    //Print sorted 
    //std::cout << "After: ";
    //for (unsigned long i = 0; i < sorted.size(); i++)
    //        std::cout << sorted[i] << " ";
    //std::cout << std::endl;

    //Print time
   std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << std::fixed << tiempo_de_ejecucion << " seconds" << std::endl; 
   
};
