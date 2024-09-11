/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:10:53 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/11 17:11:35 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<string>
#include<iostream>
#include<cmath>
#include<sstream>
#include<cctype>
#include<limits>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
        
        enum Type { CHAR, INT, DOUBLE, FLOAT, PSEUDOF, PSEUDOD, INVALID};

        static std::string printType(Type inputType);
        static Type getType(std::string str);
        static bool isPrintable(const std::string& str);
    
        static bool isCharLiteral(const std::string& str);
        static bool isIntLiteral(const std::string& str);
        static bool isFloatLiteral(const std::string& str);
        static bool isDoubleLiteral(const std::string& str);
        static bool isPseudoFLiteral(const std::string& str);
        static bool isPseudoDLiteral(const std::string& str);
        
        static void printChar(char c);
        static void printInt(int i);
        static void printFloat(float f);
        static void printDouble(double d);
        static void printPseudoF(float f);
        static void printPseudoD(double d);

        class WrongArgument : public std::exception {
            public:
                const char* what() const throw();
        };
        
    public:
        static void convert(std::string& str);
};

#endif