#include "RPN.hpp"
#include <stack>

void Calculator(const std::string &input){

        const std::string operators = "+-/*";

        std::stack<int> pile;

        for(std::string::const_iterator ptr=input.cbegin(); ptr != input.end(); ptr++){
            if(*ptr == ' ') //es espacio
                continue;
            else if(std::isdigit(*ptr))//es un numero
            {
                pile.push(std::atoi(&(*ptr)));
            }
            else if(operators.find(*ptr) != std::string::npos) //es + - / *
            {
                if (pile.size() < 2)
                    error();
                int a = pile.top();
                pile.pop();
                int b = pile.top();
                pile.pop();
                switch((*ptr)){
                    case '+':
                        pile.push(sum(b, a));
                        break;
                    case '-':
                         pile.push(sub(b, a));
                         break;
                    case '/':
                         pile.push(divide(b, a));
                         break;
                    case '*':
                         pile.push(multi(b, a));
                         break;
                }
            }
            else 
                error();
        }
        if (pile.size() != 1)
            error();
        else
            std::cout << pile.top() << std::endl;
}

//----MATEMATHICS-----

int  sum(int b, int a){
    return(b+a);
}

int  sub(int b, int a){
    return(b-a);
}

int  multi(int b, int a){
    return(b*a);
}

int  divide(int b, int a){
    if (a == 0)
        error();
    return(b/a);
}

//----ERROR-----

void error(){

    std::cout << "Error" << std::endl;
    exit(1);

};