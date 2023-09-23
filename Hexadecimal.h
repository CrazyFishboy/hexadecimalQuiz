/**
 * @file Hexadecimal.h
 * @author Josh Gillum
 * @brief Hexadecimal class definition. This class stores the value of a hexadecimal number, and
 * provides operations for working with and manipulating numbers of this base
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include <string>

#include <iostream>

class Hexadecimal{
public:
// Fundamental information for the number system. Defines the base of the number system, the list of valid characters,
// and provides a way to see if a character is valid
static const int base;
static const char validCharacters[];
static bool isValidCharacter(char character);
static bool decimalValueOfCharacter(char character, int &index);

Hexadecimal() : Hexadecimal("0"){}
Hexadecimal(std::string val);
Hexadecimal* operator++();
Hexadecimal* operator--();
Hexadecimal* operator++(int); // Need to define assignment operator first
Hexadecimal* operator=(Hexadecimal *right);
/* Need to add:
*copy constructor
*assignment operator
*comparison operators
*arithmetic operators
*arithmetic functions
*subscript operator
*/
std::string getValue() const{
    return value;
}

int getSize() const {
    return value.size();
}

bool setValue(std::string val);
Hexadecimal* addHex(const Hexadecimal &hex);
Hexadecimal* addDecimal(int val);

protected:
std::string value;

};
#endif