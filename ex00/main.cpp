#include "ScalarConverter.hpp"

int main () {
    std::string str = "'a'";
    std::cout << ScalarConverter::convert(str) << std::endl;
}