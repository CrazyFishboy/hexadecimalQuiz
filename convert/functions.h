#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

const char validDigits[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void display(uint64_t num, int base = 0);
uint64_t convertBase(std::string str, unsigned base);
void printHelp();


#endif