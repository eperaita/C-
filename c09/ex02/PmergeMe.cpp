#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
        
PmergeMe::PmergeMe(const PmergeMe &copy){ *this=copy; };

const PmergeMe &PmergeMe::operator=(const PmergeMe &copy){ 
    (void)copy;
    return(*this);
};

PmergeMe::~PmergeMe(){};

//______________________________SORTING STATIC FUNCTIONS ______________________________________

//SORT WITH DEQUE//

static std::deque<int> compareAndInsert(std::deque<int> part1, std::deque<int> part2){

    std::deque<int> merged;

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

static std::deque<int> sortpair(std::deque<int> deq){

    if (deq.size() == 1 || deq[0] <= deq[1])
        return deq;
    else{

        int aux = deq[0];
        deq[0] = deq[1];
        deq[1] = aux;
        return deq;
    }

};

static std::deque<int> mergeInsert(std::deque<int> deq){
    if (deq.size() <=2)
    {
        deq = sortpair(deq);
        return (deq);
    }

    //CUT

    int mid = deq.size() / 2;

    std::deque<int> part1(deq.begin(), deq.begin() + mid);
    std::deque<int> part2(deq.begin() + mid, deq.end());

    //RECURSIVELY CUT

    part1= mergeInsert(part1);
    part2= mergeInsert(part2);


    std::deque<int> supermerged = compareAndInsert(part1, part2);


    return(supermerged);
    

};

//SORT WITH VECTOR//

static std::vector<int> compareAndInsert(std::vector<int> part1, std::vector<int>part2){

    std::vector<int> merged;

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

static  std::vector<int> sortpair(std::vector<int> vec){

    if (vec.size() == 1 || vec[0] <= vec[1])
        return vec;
    else{

        int aux = vec[0];
        vec[0] = vec[1];
        vec[1] = aux;
        return vec;
    }

};

static std::vector<int> mergeInsert(std::vector<int> vec){
    if (vec.size() <=2)
    {
        vec = sortpair(vec);
        return (vec);
    }

    //CUT

    int mid = vec.size() / 2;

    std::vector<int> part1(vec.begin(), vec.begin() + mid);
    std::vector<int> part2(vec.begin() + mid, vec.end());

    //RECURSIVELY CUT

    part1= mergeInsert(part1);
    part2= mergeInsert(part2);


    std::vector<int> supermerged = compareAndInsert(part1, part2);

    return(supermerged);
    

};


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
    //std::cout << "----> FINAL : ";
    //for (unsigned long i = 0; i < sorted.size(); i++)
    //        std::cout << sorted[i] << " ";
    //std::cout << std::endl;

    //Print time
   std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << std::fixed << tiempo_de_ejecucion << " seconds" << std::endl;
    
   
};
