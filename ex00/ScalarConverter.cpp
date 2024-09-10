/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:11:39 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/10 17:27:48 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
    if (inputType == CHAR)
        std::cout << "CHAR" << std::endl;
    if (inputType == INT)
        std::cout << "INT" << std::endl;
    if (inputType == FLOAT)
        std::cout << "FLOAT" << std::endl;
    if (inputType == PSEUDOF)
        std::cout << "PSEUDOF" << std::endl;
    if (inputType == DOUBLE)
        std::cout << "DOUBLE" << std::endl;
    if (inputType == PSEUDOD)
        std::cout << "PSEUDOD" << std::endl;
    if (inputType == INVALID)
        std::cout << "INVALID" << std::endl;
          
    // std::cout << "char: " << toChar(str, inputType) << std::endl;
    // std::cout << "int: " << toInt(str, inputType) << std::endl;
    // std::cout << "float: " << ScalarConverter::toFloat(str, inputType) << std::endl;
    // std::cout << "double: " << ScalarConverter::toDouble(str, inputType) << std::endl;
}

ScalarConverter::Type ScalarConverter::getType(std::string str) {
    if (!isPrintable(str) || str.empty())
        return INVALID;
    if (isCharLiteral(str))
        return CHAR;
    if (isIntLiteral(str))
        return INT;
    if (isFloatLiteral(str))
        return FLOAT;
    if (isPseudoFloatLiteral(str))
        return PSEUDOF;
    if (isPseudoDoubleLiteral(str))
        return PSEUDOD;
    if (isDoubleLiteral(str))
        return DOUBLE;
    return INVALID;
}

bool ScalarConverter::isPrintable(const std::string& str) {
    size_t i;
    for (i = 0; i < str.size(); i++) {
        if (!isprint(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isCharLiteral(const std::string& str) {
    bool size = str.size() == 3;
    bool quotes = (str[0] == '\'' && str[2] == '\'');
    return (size && quotes);
}

bool ScalarConverter::isIntLiteral(const std::string& str) {
    std::stringstream ss(str);
    int value;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        return false;
    }
    return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& str) {
    if (str[str.size() - 1] != 'f')
        return false;
    std::stringstream ss(str);
    float value;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        return false;
    }
    return true;
}

bool ScalarConverter::isPseudoFloatLiteral(const std::string& str) {
    return str == "-inff" || str == "+inff" || str == "nanf";
}

bool ScalarConverter::isDoubleLiteral(const std::string& str) {
    std::stringstream ss(str);
    double value;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        return false;
    }
    return true;
}


bool ScalarConverter::isPseudoDoubleLiteral(const std::string& str) {
    return str == "-inf" || str == "+inf" || str == "nan"; 
}