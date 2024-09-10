#include "ScalarConverter.hpp"

int main () {
    std::string str = "')'";
    std::cout << str << " is a ";
    ScalarConverter::convert(str);
    str = "-556";
    std::cout << str << " is a ";
    ScalarConverter::convert(str);
    str = "4.2f";
    std::cout << str << " is a ";
    ScalarConverter::convert(str);
    str = "-inff";
    std::cout << str << " is a ";
    ScalarConverter::convert(str);
    str = "45454.8798";
    std::cout << str << " is a ";
    ScalarConverter::convert(str);
    str = "nan";
    std::cout << str << " is a ";
    ScalarConverter::convert(str);
}