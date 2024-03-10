#ifndef RPN_HPP
#define RPN_HPP

#include <stdlib.h>
#include <iostream>


int sum(int b, int a);
int sub(int b, int a);
int multi(int b, int a);
int divide(int b, int a);
void error();

void Calculator(const std::string &input);


#endif