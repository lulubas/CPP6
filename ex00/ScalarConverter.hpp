/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:10:53 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/11 11:07:48 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.hpp
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<string>
#include<iostream>
#include<sstream>
#include<cctype>
#include<limits>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
        
        enum Type { CHAR, INT, DOUBLE, FLOAT, PSEUDO, INVALID};

        static std::string printType(Type inputType);
        static Type getType(std::string str);
        static bool isPrintable(const std::string& str);
    
        static bool isCharLiteral(const std::string& str);
        static bool isPseudoLiteral(const std::string& str);
        static bool isIntLiteral(const std::string& str);
        static bool isFloatLiteral(const std::string& str);
        static bool isDoubleLiteral(const std::string& str);
        
        static char toChar(Type inputType, const std::string& str);
        static int toInt(Type inputType, const std::string& str);
        static float toFloat(Type inputType, const std::string& str);
        static double toDouble(Type inputType, const std::string& str);

        static void printChar(Type inputType, const std::string& str);
        static void printInt(Type inputType, const std::string& str);
        static void printFloat(Type inputType, const std::string& str);

        // static int toInt(const std::string str, Type inputType);
        // static double toDouble(const std::string str, Type inputType);
        // static float toFloat(const std::string str, Type inputType);

        class WrongArgument : public std::exception {
            public:
                const char* what() const throw();
        };
        
        class nonPrintableChar : public std::exception {
            public:
                const char* what() const throw();
        };
        
        class ImpossibleConversion : public std::exception {
            public:
                const char* what() const throw();
        };
        
    public:
        static void convert(std::string& str);
};

#endif