#include "Serializer.hpp"
int main(void) {

    Data *ptr = new Data;
    ptr->i = 42;
    std::cout << "Initial Data pointer address: " << ptr;
    std::cout << "(content=" << ptr->i << ")" << std::endl;

    uintptr_t intPtr = Serializer::serialize(ptr);
    std::cout << "Serialized (int) address: " << intPtr << std::endl;

    ptr = Serializer::deserialize(intPtr);
    std::cout << "Deserialized data pointer address: " << ptr;
    std::cout << "(content=" << ptr->i << ")" << std::endl;
    
    delete ptr;
}