/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:42:04 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/16 18:32:34 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed x(-1);
    Fixed y(0.1f);
    std::cout << std::boolalpha;
    if (x != y)
        std::cout << true << std::endl;
    else
        std::cout << false << std::endl;
    std::cout << std::noboolalpha;
    //// code provided in Subject
    // Fixed a;
    // Fixed const b(Fixed(5.05f) * Fixed(2) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}
