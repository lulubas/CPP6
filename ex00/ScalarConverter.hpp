/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:10:53 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/10 17:13:19 by lbastien         ###   ########.fr       */
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
        
        enum Type { CHAR, INT, DOUBLE, FLOAT, PSEUDOF, PSEUDOD, INVALID};
        
        static bool isPrintable(const std::string& str);
        static bool isCharLiteral(const std::string& str);
        static bool isPseudoFloatLiteral(const std::string& str);
        static bool isPseudoDoubleLiteral(const std::string& str);
        static bool isIntLiteral(const std::string& str);
        static bool isFloatLiteral(const std::string& str);
        static bool isDoubleLiteral(const std::string& str);
        static Type getType(std::string str);
        
        // static char toChar(const std::string str, Type inputType);
        // static int toInt(const std::string str, Type inputType);
        // static double toDouble(const std::string str, Type inputType);
        // static float toFloat(const std::string str, Type inputType);
    
        // static void printResult(const std::string& str, Type inputType);
 
    public:
        static void convert(std::string str);
};

#endif