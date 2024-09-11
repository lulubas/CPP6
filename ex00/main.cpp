#include "ScalarConverter.hpp"

int main (int argc, char **argv) {

    int i;
    try {
       for (i = 1; i < argc; i++) {
            std::string input;
            input = argv[i];
            ScalarConverter::convert(input);
        }
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}