/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:33:26 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/11 17:58:19 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>

Base *generate(void);
void identify(Base* basePtr);
void identify(Base& basePtr);

#endif