#include "ScalarConverter.hpp"

int main () {
    std::string str = "0";
    std::cout << "==" << str << "==" << std::endl;
    ScalarConverter::convert(str);
    str = "nan";
    std::cout << "==" << str << "==" << std::endl;
    ScalarConverter::convert(str);
    str = "42.0f";
    std::cout << "==" << str << "==" << std::endl;
    ScalarConverter::convert(str);
    // str = "96.0654f";
    // std::cout << str << " = ";
    // ScalarConverter::convert(str);
    // str = "4.2f";
    // std::cout << str << " is a ";
    // ScalarConverter::convert(str);
    // str = "-inff";
    // std::cout << str << " is a ";
    // ScalarConverter::convert(str);
    // str = "45454.8798";
    // std::cout << str << " is a ";
    // ScalarConverter::convert(str);
    // str = "nan";
    // std::cout << str << " is a ";
    // ScalarConverter::convert(str);
    return 0;
}