#include "identify.hpp"

int main(void) {
    Base* basePtr = generate();
    
    Base& baseRef = *basePtr;
    identify(basePtr);
    identify(baseRef);
    delete basePtr;
}