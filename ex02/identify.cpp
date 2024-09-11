/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:16:54 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/11 19:02:41 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

#include<exception>

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    switch (std::rand() % 3) {
    case 0:
        return (new A);
        break;
    case 1:
        return (new B);
        break;
    case 2:
        return (new C);
        break;
    default:
        return NULL;
        break;
    }
}

void identify(Base* basePtr) {
    if (dynamic_cast<A*>(basePtr))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(basePtr))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(basePtr))
        std::cout << "C" << std::endl;
    else
    std::cout << "No type detected" << std::endl;    
}

void identify(Base& baseRef) {
    try {
        (void)dynamic_cast<A&>(baseRef);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception &e) {}
    try {
        (void)dynamic_cast<B&>(baseRef);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception &e) {}
    try {
        (void)dynamic_cast<C&>(baseRef);
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::exception &e) {}
}
