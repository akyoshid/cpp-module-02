/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:42 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/17 17:31:08 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main() {
    std::cout << "=== Fixed Class Operator Tests ===" << std::endl;

    Fixed a(5.5f);
    Fixed b(3.25f);
    Fixed c(5.5f);
    Fixed d(0);
    std::cout << "Test values: a=" << a << ", b=" << b
        << ", c=" << c << ", d=" << d << std::endl;

    // Comparison operators
    std::cout << "\n--- Comparison Operators ---" << std::endl;
    std::cout << "a > b: " << (a > b) << " (expected: 1)" << std::endl;
    std::cout << "a < b: " << (a < b) << " (expected: 0)" << std::endl;
    std::cout << "a >= c: " << (a >= c) << " (expected: 1)" << std::endl;
    std::cout << "a <= c: " << (a <= c) << " (expected: 1)" << std::endl;
    std::cout << "a == c: " << (a == c) << " (expected: 1)" << std::endl;
    std::cout << "a != b: " << (a != b) << " (expected: 1)" << std::endl;

    // Arithmetic operators
    std::cout << "\n--- Arithmetic Operators ---" << std::endl;
    std::cout << "a + b: " << (a + b) << " (expected: 8.75)" << std::endl;
    std::cout << "a - b: " << (a - b) << " (expected: 2.25)" << std::endl;
    std::cout << "a * b: " << (a * b) << " (expected: 17.875)" << std::endl;
    std::cout << "a / b: " << (a / b) << " (expected: 1.69141)" << std::endl;

    // Increment/Decrement operators (increment by 1/256 = 0.00390625)
    std::cout << "\n--- Increment/Decrement Operators ---" << std::endl;
    Fixed e(10.5f);
    std::cout << "e initial: " << e << std::endl;
    std::cout << "++e: " << ++e << " (expected: 10.5039)" << std::endl;
    std::cout << "e after pre-increment: " << e << std::endl;
    std::cout << "e++: " << e++ << " (expected: 10.5039)" << std::endl;
    std::cout << "e after post-increment: " << e << " (expected: 10.5078)"
        << std::endl;
    std::cout << "--e: " << --e << " (expected: 10.5039)" << std::endl;
    std::cout << "e after pre-decrement: " << e << std::endl;
    std::cout << "e--: " << e-- << " (expected: 10.5039)" << std::endl;
    std::cout << "e after post-decrement: " << e << " (expected: 10.5)"
        << std::endl;

    // Static min/max functions
    std::cout << "\n--- Static Min/Max Functions ---" << std::endl;
    Fixed f(7.25f);
    Fixed g(4.75f);
    std::cout << "f=" << f << ", g=" << g << std::endl;
    std::cout << "min(f, g): " << Fixed::min(f, g) << " (expected: 4.75)"
        << std::endl;
    std::cout << "max(f, g): " << Fixed::max(f, g) << " (expected: 7.25)"
        << std::endl;

    // Test const versions
    const Fixed cf(2.5f);
    const Fixed cg(8.75f);
    std::cout << "cf=" << cf << ", cg=" << cg << std::endl;
    std::cout << "const min(cf, cg): " << Fixed::min(cf, cg)
        << " (expected: 2.5)" << std::endl;
    std::cout << "const max(cf, cg): " << Fixed::max(cf, cg)
        << " (expected: 8.75)" << std::endl;

    std::cout << "\n=== All tests completed ===" << std::endl;

    // // Test code provided in Subject
    // Fixed x;
    // Fixed const y(Fixed(5.05f) * Fixed(2) );
    // std::cout << x << std::endl;
    // std::cout << ++x << std::endl;
    // std::cout << x << std::endl;
    // std::cout << x++ << std::endl;
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;
    // std::cout << Fixed::max(x, y) << std::endl;
    return 0;
}
