#include "PmergeMe.hpp"

PmergeMe::PmergeMe():margi(-1){};
        
PmergeMe::PmergeMe(const PmergeMe &copy){ *this=copy; };

const PmergeMe &PmergeMe::operator=(const PmergeMe &copy){ 
    (void)copy;
    return(*this);
};

PmergeMe::~PmergeMe(){};

//_____________________________________________________________________________________________
//______________________________ SIDE FUNCTIONS ____________________________________

//se pega una fumada el Jacobsthal que genera una secuencia donde multiplica por dos y le suma el anterior 
//sucesivamente, de modo que incrementa el numero exponencialmente. Me recuerda a Mandelbrot. 
// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683 ...
int PmergeMe::get_jacobstal(int n){

    if (n == 0 || n == 1 )
        return n;
    
    int a = 0;
    int b = 1; 
    int c; 
    for (int i = 2; i <= n; ++i)
    {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b; 
};

static bool compare_pair(const std::pair<int, int> a , const std::pair<int, int> b){
    return (a.second < b.second);
};


int PmergeMe::fillVector(int argc, char **argv){

    int in_size = argc -1 ;
    try
    {
        //Si todos son digitos 
        for (int i = 1; i < in_size - 1 ; i++)
        {
            for (size_t j = 0; j < static_cast<std::string>(argv[i]).size() ; j++)
                if (!std::isdigit(argv[i][j]))
                    throw std::exception();
        }
        //Si es impar el ultimo margi 
        if (argc % 2 == 0)
        {
            int n = std::stoi(argv[argc - 1]);
            if( n < 0 )
                throw std::exception();
            margi = n;
            //std::cout << "Odd number : "<< margi << std::endl;
            in_size --;
        }

        

        //Vector in pairs
        for (int i = 1; i < argc - 1; i++)
        {
            int n = std::stoi(argv[i]);
            int n2 = std::stoi(argv[i + 1]);
            if (n < 0 || n2 < 0 )
                throw std::exception();
            v_pairs.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
            if (i + 1 < argc - 1)
            {
                i++;
            }
        }
    }catch(const std::exception& e)
    {
        std::cout << "ERROR: Invalid input. Only allowed with positive integers" << std::endl;
        return 1;
    }
        
    //Print 
    std::cout << "Before: ";
    for (unsigned long i = 0; i < v_pairs.size(); i++)
        std::cout << v_pairs[i].first << " " << v_pairs[i].second << " ";
    if (margi != -1)
        std::cout << margi << " ";
    std::cout << std::endl;
    return 0;
};

int PmergeMe::fillDeque(int argc, char **argv){

    int in_size = argc -1 ;
    try
    {
        //Si todos son digitos 
        for (int i = 1; i < in_size - 1 ; i++)
        {
            for (size_t j = 0; j < static_cast<std::string>(argv[i]).size() ; j++)
                if (!std::isdigit(argv[i][j]))
                    throw std::exception();
        }
        //Si es impar el ultimo margi 
        if (argc % 2 == 0)
        {
            int n = std::stoi(argv[argc - 1]);
            if( n < 0 )
                throw std::exception();
            margi = n;
            //std::cout << "Odd number : "<< margi << std::endl;
            in_size --;
        }

        

        //Deque in pairs
        for (int i = 1; i < argc - 1; i++)
        {
            int n = std::stoi(argv[i]);
            int n2 = std::stoi(argv[i + 1]);
            if (n < 0 || n2 < 0 )
                throw std::exception();
            d_pairs.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
            if (i + 1 < argc - 1)
            {
                i++;
            }
        }
    }catch(const std::exception& e)
    {
        std::cout << "ERROR: Invalid input. Only allowed with positive integers" << std::endl;
        return 1;
    }
        
    //Print 
    //std::cout << "Before: ";
    //for (unsigned long i = 0; i < d_pairs.size(); i++)
    //    std::cout << d_pairs[i].first << " " << d_pairs[i].second << " ";
    //if (margi != -1)
    //    std::cout << margi << " ";
    //std::cout << std::endl;
    return 0;
};


//_____________________________________________________________________________________________
//______________________________ PRINTERS ____________________________________

void PmergeMe::printTime(int type){
    if (type == 1)
        std::cout << "Time to process a range of " << v_main.size() << " elements with std::vector: " << std::fixed << tiempo_de_ejecucion << " seconds" << std::endl;  
    if (type == 2)
        std::cout << "Time to process a range of " << d_main.size() << " elements with std::deque: " << std::fixed << tiempo_de_ejecucion << " seconds" << std::endl;       
};

void PmergeMe::printFinal(int type){
    if (type == 1)
        print(v_main, "After: " );
    if (type == 2)
        printDeq(d_main, "After: ");
};


void PmergeMe::printPairs(std::vector<std::pair<int, int> > v, std::string msg){
    std::cout << msg;
    for (size_t i = 0 ; i < v.size(); i++)  
        std::cout << "[" << v[i].first << " "  << v[i].second << "] ";
    std::cout << std::endl;

};

void PmergeMe::print(std::vector<int> v, std::string msg){
    std::cout << msg;
    for (unsigned long i = 0; i < v.size(); i++)
            std::cout << v[i] << " ";
    std::cout << std::endl;
};

void PmergeMe::printPairsDeq(std::deque<std::pair<int, int> > d, std::string msg){
    std::cout << msg;
    for (size_t i = 0 ; i < d.size(); i++)  
        std::cout << "[" << d[i].first << " "  << d[i].second << "] ";
    std::cout << std::endl;

};

void PmergeMe::printDeq(std::deque<int> d, std::string msg){
    std::cout << msg;
    for (unsigned long i = 0; i < d.size(); i++)
            std::cout << d[i] << " ";
    std::cout << std::endl;
};

//_____________________________________________________________________________________________
//____________________________________ PMERGEME VECTOR ________________________________________

void PmergeMe::sortWithVector(int argc, char **argv){


    // Start timer
    clock_t start = clock();

    //---------------ORDER DATA---------------//

     //Vector in pairs con input y si es impar el ultimo a margi
    if (fillVector(argc, argv))
        return ;

//std::cout << "Odd number : "<< margi << std::endl;
//printPairs(v_pairs, "Paired: ");

    //Sort each pair 

    for(unsigned long i = 0; i < v_pairs.size(); i++)
    {
        if (v_pairs[i].first > v_pairs[i].second)
            std::swap(v_pairs[i].first, v_pairs[i].second);
    }
//printPairs(v_pairs, "Pairs sorted: ");

    //Sort paired by second element: compare and sort(<algorithm>)

    sort(v_pairs.begin(), v_pairs.end(), compare_pair);
//printPairs(v_pairs, "Ordered by second: ");

    //Second element (sorted) to main and first (unsorted) to pend

    for (std::vector<std::pair<int,int> >::iterator i = v_pairs.begin(); i != v_pairs.end(); i++)  
    {
        v_main.push_back((*i).second);
        v_pend.push_back((*i).first);
    }
//std::cout << "First to main and second to pend: " << std::endl;
//print(v_main, "\tMain: ");
//print(v_pend, "\tPend: ");

    //Main is ordered 

   //---------------MERGE INSERT---------------//

    //Jacobstal number sequence. Hasta que el numero que salga sea == size del pend, sino no nos sirve como index
    //Los numeros intermedios se rellenan marcha atras 
    int size = v_pend.size();
    int index = 2;
    int jacob = 0;
    while (jacob < size)
    {
        jacob = get_jacobstal(index++);
        if (jacob < size)
            {
                jacobsthal.push_back(jacob);
            }
    }
    jacobsthal.push_back(size);
//print(jacobsthal, "Jacobstal: " );

    //Vector of pairs "temp": Los numeros de pend asignados a su potencia jacobsthal.
    //Orden de numeros : En orden de los jacobsthal pero los que nos faltan marcha atras: 1, 3, 2, 5, 4, ..
    //Cada bloque que saltamos de numero jacobsthal es un chunk, y se le asigna en .second su pow :  pow(2, i + 1) - 1 )

    std::vector<std::pair<int, int> > temp;
    int k = 1;
    for (std::vector<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); it++)
    {
        int i = *it;
        int j = 0;
        if (it != jacobsthal.begin())// Obtenemos el valor anterior si no estamos en el primer elemento
            j = *(it - 1); 
        while (i-- > j)
        {
            std::vector<int>::iterator pend_it = v_pend.begin() + i; // Avanzamos pend_it i veces
            temp.push_back(std::make_pair(*pend_it, (pow(2, k) - 1)));
        }
        k++;
    }
//printPairs(temp, "Pend ordered by Jacobsthal with pow: ");

    ////Esto luego sirve para que cada uno se inserte luego con binarysearch limitando la busqueda (end) 
    //a esa potencia, porque se supone que ya es su pareja y siempre sera menor
   
    //---------------LAST INSERTIONS---------------//

    //First number of pend always going to be the first of main, cause is smaller than its pair and main is ordered 
    v_main.insert(v_main.begin(), temp[0].first);
    temp.erase(temp.begin());

    //Insertar en orden de temp con binaryseach (upper_bound devuelve la posicion donde deberia ir usando binarysearch )
    //utilizamos los pow asignados para determinar el end de la busqueda binaria
    for (std::vector<std::pair<int, int> >::iterator it = temp.begin(); it != temp.end(); it++)
    {
        std::vector<int>::iterator pos = std::upper_bound(v_main.begin(), v_main.begin() + ((*it).second < static_cast<int>(v_main.size()) - 1 ? (*it).second : static_cast<int>(v_main.size()) - 1), (*it).first);
        v_main.insert(pos, (*it).first);
    }
    //Insert margi if exists (con upper_bound que usa binarysearch)

    if (margi != -1)
    {
        std::vector<int>::iterator pos = std::upper_bound(v_main.begin(), v_main.end(), margi);
        v_main.insert(v_main.begin() + std::distance(v_main.begin(), pos), margi);
    }

    ////Sorted!

    //Stop timer
    clock_t end = clock();
    tiempo_de_ejecucion = (double)(end - start) / CLOCKS_PER_SEC;

};

//_____________________________________________________________________________________________
//_____________________________________ PMERGEME DEQUE ________________________________________

void PmergeMe::sortWithDeque(int argc, char **argv){


    // Start timer
    clock_t start = clock();

    //---------------ORDER DATA---------------//

     //Vector in pairs con input y si es impar el ultimo a margi
    if (fillDeque(argc, argv))
        return ;

//std::cout << "Odd number : "<< margi << std::endl;
//printPairs(v_pairs, "Paired: ");

    //Sort each pair 

    for(unsigned long i = 0; i < d_pairs.size(); i++)
    {
        if (d_pairs[i].first > d_pairs[i].second)
            std::swap(d_pairs[i].first, d_pairs[i].second);
    }
//printPairs(v_pairs, "Pairs sorted: ");

    //Sort paired by second element: compare and sort(<algorithm>)

    sort(d_pairs.begin(), d_pairs.end(), compare_pair);
//printPairs(v_pairs, "Ordered by second: ");

    //Second element (sorted) to main and first (unsorted) to pend

    for (std::deque<std::pair<int,int> >::iterator i = d_pairs.begin(); i != d_pairs.end(); i++)  
    {
        d_main.push_back((*i).second);
        d_pend.push_back((*i).first);
    }
//std::cout << "First to main and second to pend: " << std::endl;
//print(v_main, "\tMain: ");
//print(v_pend, "\tPend: ");

    //Main is ordered 

   //---------------MERGE INSERT---------------//

    //Jacobstal number sequence. Hasta que el numero que salga sea == size del pend, sino no nos sirve como index
    //Los numeros intermedios se rellenan marcha atras 
    int size = d_pend.size();
    int index = 2;
    int jacob = 0;
    while (jacob < size)
    {
        jacob = get_jacobstal(index++);
        if (jacob < size)
            {
                d_jacobsthal.push_back(jacob);
            }
    }
    d_jacobsthal.push_back(size);
//print(jacobsthal, "Jacobstal: " );

    //Vector of pairs "temp": Los numeros de pend asignados a su potencia jacobsthal.
    //Orden de numeros : En orden de los jacobsthal pero los que nos faltan marcha atras: 1, 3, 2, 5, 4, ..
    //Cada bloque que saltamos de numero jacobsthal es un chunk, y se le asigna en .second su pow :  pow(2, i + 1) - 1 )

    std::deque<std::pair<int, int> > temp;
    int k = 1;
    for (std::deque<int>::iterator it = d_jacobsthal.begin(); it != d_jacobsthal.end(); it++)
    {
        int i = *it;
        int j = 0;
        if (it != d_jacobsthal.begin())// Obtenemos el valor anterior si no estamos en el primer elemento
            j = *(it - 1); 
        while (i-- > j)
        {
            std::deque<int>::iterator pend_it = d_pend.begin() + i; // Avanzamos pend_it i veces
            temp.push_back(std::make_pair(*pend_it, (pow(2, k) - 1)));
        }
        k++;
    }
//printPairs(temp, "Pend ordered by Jacobsthal with pow: ");

    ////Esto luego sirve para que cada uno se inserte luego con binarysearch limitando la busqueda (end) 
    //a esa potencia, porque se supone que ya es su pareja y siempre sera menor
   
    //---------------LAST INSERTIONS---------------//

    //First number of pend always going to be the first of main, cause is smaller than its pair and main is ordered 
    d_main.insert(d_main.begin(), temp[0].first);
    temp.erase(temp.begin());

    //Insertar en orden de temp con binaryseach (upper_bound devuelve la posicion donde deberia ir usando binarysearch )
    //utilizamos los pow asignados para determinar el end de la busqueda binaria
    for (std::deque<std::pair<int, int> >::iterator it = temp.begin(); it != temp.end(); it++)
    {
        std::deque<int>::iterator pos = std::upper_bound(d_main.begin(), d_main.begin() + ((*it).second < static_cast<int>(d_main.size()) - 1 ? (*it).second : static_cast<int>(d_main.size()) - 1), (*it).first);
        d_main.insert(pos, (*it).first);
    }
    //Insert margi if exists (con upper_bound que usa binarysearch)

    if (margi != -1)
    {
        std::deque<int>::iterator pos = std::upper_bound(d_main.begin(), d_main.end(), margi);
        d_main.insert(d_main.begin() + std::distance(d_main.begin(), pos), margi);
    }

    ////Sorted!

    //Stop timer
    clock_t end = clock();
    tiempo_de_ejecucion = (double)(end - start) / CLOCKS_PER_SEC;


};

