/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:11:39 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/11 11:08:43 by lbastien         ###   ########.fr       */
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

std::string ScalarConverter::printType(Type inputType) {
    if (inputType == INVALID)
        return("INVALID");
    if (inputType == CHAR)
        return("CHAR");
    if (inputType == INT)
        return("INT");
    if (inputType == DOUBLE)
        return("DOUBLE");
    if (inputType == FLOAT)
        return("FLOAT");
    if (inputType == PSEUDO)
        return("PSEUDO");
    return("UNKNOWN");
    
}

void ScalarConverter::convert(std::string& str) {
    Type inputType = getType(str);
    std::cout << "->" << printType(inputType) << std::endl;
    
    if (inputType == INVALID)
        throw WrongArgument();
    
    printChar(inputType, str);
    printInt(inputType, str);
    printFloat(inputType, str);
    // printDouble(inputType, str);
    
    // try{
    //     int c = toInt(inputType, str);
    //     std::cout <<  "int: '" << c << "'" << std::endl;
    // }
    // catch (std::exception& e) {
    //     std::cout <<  "int: impossible" << std::endl;
    // }
    
    // try{
    //     float c = toFloat(inputType, str);
    //     std::cout <<  "float: '" << c << "'" << std::endl;
    // }
    // catch (std::exception& e) {
    //     std::cout <<  "float: impossible" << std::endl;
    // }

    // try{
    //     double c = toDouble(inputType, str);
    //     std::cout <<  "double: '" << c << "'" << std::endl;
    // }
    // catch (std::exception& e) {
    //     std::cout <<  "double: impossible" << std::endl;
    // }
}

void ScalarConverter::printChar(Type inputType, const std::string& str) {
    try {
        char value = toChar(inputType, str);
        std::cout << "char: '" << value << "'" << std::endl;
    }
    catch (nonPrintableChar& e) {
        std::cout <<  "char: non-printable" << std::endl;
    }
    catch (std::exception& e) {
        std::cout <<  "char: impossible" << std::endl;
    }
}

void ScalarConverter::printInt(Type inputType, const std::string& str) {
    try {
        int value = toInt(inputType, str);
        std::cout << "int: " << value << std::endl;
    }
    catch (std::exception& e) {
        std::cout <<  "int: impossible" << std::endl;
    }
}

void ScalarConverter::printFloat(Type inputType, const std::string& str) {
    try {
        float value = toFloat(inputType, str);
        std::cout << "float: " << value << "f" << std::endl;
    }
    catch (std::exception& e) {
        std::cout <<  "float: impossible" << std::endl;
    }
}

char ScalarConverter::toChar(Type inputType, const std::string& str) {
    if (inputType == CHAR)
        return(str[1]);
    
    if (inputType == INT || inputType == DOUBLE || inputType == FLOAT) {
        std::stringstream ss(str);
        int value;
        ss >> value;
        if (isprint(value))
            return (static_cast<char>(value));
        if (value >= 0 && value < 32)
            throw nonPrintableChar();
    }
    
    throw ImpossibleConversion();
}

int ScalarConverter::toInt(Type inputType, const std::string& str) {
    if (inputType == CHAR)
        return(static_cast<int>(str[1]));  
        
    if (inputType == INT) {
        std::stringstream ss(str);
        int value;
        ss >> value;
        return value;
    }
    
    if (inputType == FLOAT || inputType == DOUBLE) {
        std::string numberPart = str;
        if (inputType == FLOAT)
            numberPart = str.substr(0, str.size() - 1);
        std::stringstream ss(numberPart);
        double value;
        ss >> value;
        if (ss.fail() || !ss.eof())
            throw ImpossibleConversion();
        return static_cast<int>(value);
    }
    throw ImpossibleConversion();
}

float ScalarConverter::toFloat(Type inputType, const std::string& str) {
    if (inputType == CHAR)
        return(static_cast<float>(str[1]));  
        
    if (inputType == INT) {
        std::stringstream ss(str);
        int value;
        ss >> value;
        return static_cast<float>(value);
    }
    
    if (inputType == FLOAT || inputType == DOUBLE) {
        std::string numberPart = str;
        if (inputType == FLOAT)
            std::string numberPart = str.substr(0, str.size() - 1);
        std::stringstream ss(numberPart);
        double value;
        ss >> value;
        if (ss.fail() || !ss.eof())
            throw ImpossibleConversion();
        return static_cast<float>(value);
    }
    
    if (inputType == PSEUDO) {
        if (str == "nan" || str == "nanf")
            return std::numeric_limits<float>::quiet_NaN();
        if (str == "+inf" || str == "+inff")
            return std::numeric_limits<float>::infinity();
        if (str == "-inf" || str == "-inff")
            return -std::numeric_limits<float>::infinity();
    }
        throw ImpossibleConversion();
}

double ScalarConverter::toDouble(Type inputType, const std::string& str) {
    if (inputType == CHAR)
        return(static_cast<double>(str[1]));
        
    if (inputType == INT) {
        std::stringstream ss(str);
        int value;
        ss >> value;
        return static_cast<double>(value);
    }
    
    if (inputType == FLOAT || inputType == DOUBLE) {
        std::string numberPart = str;
        if (inputType == FLOAT)
            std::string numberPart = str.substr(0, str.size() - 1);
        std::stringstream ss(numberPart);
        double value;
        ss >> value;
        if (ss.fail() || !ss.eof())
            throw ImpossibleConversion();
        return value;
    }
    
    if (inputType == PSEUDO) {
        if (str == "nan" || str == "nanf")
            return std::numeric_limits<double>::quiet_NaN();
        if (str == "+inf" || str == "+inff")
            return std::numeric_limits<double>::infinity();
        if (str == "-inf" || str == "-inff")
            return -std::numeric_limits<double>::infinity();
    }

    throw ImpossibleConversion();
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
    if (isDoubleLiteral(str))
        return DOUBLE;
    if (isPseudoLiteral(str))
        return PSEUDO;
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
    if (str[str.size() - 1] != 'f') {
        return false;
    }
    std::string numberPart = str.substr(0, str.size() - 1);
    std::stringstream ss(numberPart);
    float value;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        return false;
    }
    return true;
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

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
    return str == "-inf" || str == "+inf" || str == "nan" || str == "-inff" || str == "+inff" || str == "nanf"; 
} 

const char* ScalarConverter::WrongArgument::what() const throw() {
    return "Wrong argument. Please use only CPP literals.";
}

const char* ScalarConverter::nonPrintableChar::what() const throw() {
    return "Character is non-printable";
}

const char* ScalarConverter::ImpossibleConversion::what() const throw() {
    return "Cannot convert to this type.";
}
