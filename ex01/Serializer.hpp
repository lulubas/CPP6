/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:36:31 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/11 16:31:00 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Serializer.hpp
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include<string>
#include<iostream>

typedef long unsigned int uintptr_t;

struct Data {
    int i;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
        ~Serializer();
        
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif