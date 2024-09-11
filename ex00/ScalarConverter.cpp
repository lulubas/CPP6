/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:11:39 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/11 15:27:03 by lbastien         ###   ########.fr       */
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


void ScalarConverter::convert(std::string& str) {
    Type inputType = getType(str);

    // std::cout << "->" << printType(inputType) << std::endl;
    
    if (inputType == INVALID)
        throw WrongArgument();
        
    if (inputType == CHAR) {
        char c = str[1];
        printChar(c);
    } 
    
    if (inputType == INT) {
        std::stringstream ss(str);
        int i;
        ss >> i;
        printInt(i);
    }
    
    if (inputType == FLOAT) {
        std::stringstream ss(str.substr(0, str.size() - 1));
        float f;
        ss >> f;
        printFloat(f);
    }

    if (inputType == DOUBLE) {
        std::stringstream ss(str);
        double d;
        ss >> d;
        printDouble(d);
    }
    
    if (inputType == PSEUDOF) {
        float f = 0;
        if (str == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (str == "+inff")
            f = std::numeric_limits<float>::infinity();
        else
            f = -std::numeric_limits<float>::infinity();
        printPseudoF(f);
    }
    
    if (inputType == PSEUDOD) {
        double d = 0;
        if (str == "nan")
            d = std::numeric_limits<float>::quiet_NaN();
        else if (str == "+inf")
            d = std::numeric_limits<float>::infinity();
        else
            d = -std::numeric_limits<float>::infinity();
        printPseudoD(d);
    }
}

void ScalarConverter::printChar(char c) {
  std::cout << "char: '" << c << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printInt(int i) {
      if (i >= 0 && i <= 255 && isprint(static_cast<int>(i)))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: " << "non-printable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::printFloat(float f)  {
    if (f >= 0 && f <= 255 && isprint(static_cast<int>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: " << "non-printable" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << (std::fmod(f, 1.0f) == 0 ? ".0f" : "f") << std::endl;
    std::cout << "double: " << static_cast<double>(f) << (std::fmod(f, 1.0f) == 0 ? ".0" : "") << std::endl;
}

void ScalarConverter::printDouble(double d)  {
    
    if (d >= 0 && d <= 255 && isprint(static_cast<int>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: " << "non-printable" << std::endl;
        
    if (d >= -std::numeric_limits<int>::max() && d <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: " << "impossible" << std::endl;
    
    if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max())
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "float: " << "impossible" << std::endl;
        
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printPseudoF(float f) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float:" << f << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printPseudoD(double d) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float:" << static_cast<float>(d) << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
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
    if (isPseudoFLiteral(str))
        return PSEUDOF;
    if (isPseudoDLiteral(str))
        return PSEUDOD;
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
    double value;
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

bool ScalarConverter::isPseudoFLiteral(const std::string& str) {
    return str == "-inff" || str == "+inff" || str == "nanf"; 
} 

bool ScalarConverter::isPseudoDLiteral(const std::string& str) {
    return str == "-inf" || str == "+inf" || str == "nan";
} 

const char* ScalarConverter::WrongArgument::what() const throw() {
    return "Wrong argument. Please use only CPP literals.";
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
    if (inputType == PSEUDOF)
        return("PSEUDOF");
    if (inputType == PSEUDOD)
        return("PSEUDOD");
    return("UNKNOWN");
    
}