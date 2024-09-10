/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:11:39 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/10 15:52:30 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define INT_MAX 2147483647
#define INT_MIN -2147483648


ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    std::cout << "ScalarConverter copy assignement operator called" << std::endl;
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(std::string str) {    
    Type inputType = getType(str);
     
    std::cout << "char: " << toChar(str, inputType) << std::endl;
    std::cout << "int: " << toInt(str, inputType) << std::endl;
    std::cout << "float: " << ScalarConverter::toFloat(str, inputType) << std::endl;
    std::cout << "double: " << ScalarConverter::toDouble(str, inputType) << std::endl;
}

ScalarConverter::Type ScalarConverter::getType(std::string str) {
    if (!isPrintable(str) || str.empty())
        return INVALID;
    if (isPseudoFloatLiteral(str))
        return PSEUDOF;    
    if (isPseudoDoubleLiteral(str))
        return PSEUDOD; 
    if (isCharLiteral(str))
        return CHAR;
    if (isIntLiteral(str))
        return INT;
}

bool ScalarConverter::isPrintable(std::string& str) {
    size_t i;
    for (i = 0; i < str.size(); i++) {
        if (!isprint(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isPseudoFloatLiteral(const std::string& str) {
    if (str == "-inff" || str == "+inff") 
        return true;
    return false;
}

bool ScalarConverter::isPseudoDoubleLiteral(const std::string& str) {
    if (str == "-inf" || str == "+inf") 
        return true;
    return false;
}

bool isCharLiteral(const std::string& str) {
    bool size = str.size() == 3;
    bool quotes = (str[0] == '\'' && str[2] == '\'');
    bool alnumChar = isalnum(str[1]);
    return (size && quotes && alnumChar);
}

bool isIntLiteral(const std::string& str) {
    int i;
    bool sign = str[0] == '-' || str[0] == '+';    
    for (i = 0 + sign; i < str.size(); i++)
        if (!isdigit(str[i])) 
            return false;
    if (str.size() <= sign || str.size() >= 10 + sign) 
        return false;
    long lvalue = std::stol(str);
    if (lvalue < INT_MIN || lvalue > INT_MAX)
        return false;
    return true;
}

bool isFloatLiteral(const std::string& str) {
    int i;
    bool sign = str[0] == '-' || str[0] == '+';    
    for (i = 0 + sign; i < str.size(); i++)
        if (!isdigit(str[i])) 
            return false;
    if (str.size() <= sign || str.size() >= 10 + sign) 
        return false;
    long lvalue = std::stol(str);
    if (lvalue < INT_MIN || lvalue > INT_MAX)
        return false;
    return true;
}
