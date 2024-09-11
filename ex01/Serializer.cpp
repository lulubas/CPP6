/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:30 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/11 16:21:02 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    std::cout << "Serializer copy constructor called" << std::endl;
    (void)other;
}

Serializer& Serializer::operator=(const Serializer &other) {
    std::cout << "Serializer copy assignement operator called" << std::endl;
    (void)other;
    return *this;
}

Serializer::~Serializer(){
    std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);
    return(intPtr);
}

Data* Serializer::deserialize(uintptr_t intPtr) {
    Data *ptr = reinterpret_cast<Data*>(intPtr);
    return(ptr);
}