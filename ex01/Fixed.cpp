/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:11:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/17 17:27:43 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cmath>
#include "Fixed.hpp"

const double Fixed::max_flp
    = static_cast<double>(INT_MAX) / Fixed::scaling_factor;
const double Fixed::min_flp
    = static_cast<double>(INT_MIN) / Fixed::scaling_factor;

Fixed::Fixed() : raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : raw(0) {
    std::cout << "Int constructor called" << std::endl;
    if (i > max_int) {
        std::cerr
            << "Warning: Integer overflow in Fixed constructor" << std::endl;
        raw = max_int * scaling_factor;
    } else if (i < min_int) {
        std::cerr
            << "Warning: Integer overflow in Fixed constructor" << std::endl;
        raw = min_int * scaling_factor;
    } else {
        raw = i * scaling_factor;
    }
}

Fixed::Fixed(const float f) : raw(0) {
    std::cout << "Float constructor called" << std::endl;
    if (static_cast<double>(f) > max_flp) {
        std::cerr
            << "Warning: Float overflow in Fixed constructor" << std::endl;
        raw = INT_MAX;
    } else if (static_cast<double>(f) < min_flp) {
        std::cerr
            << "Warning: Float underflow in Fixed constructor" << std::endl;
        raw = INT_MIN;
    } else {
        raw = static_cast<int>(roundf(f * scaling_factor));
    }
}

Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->raw = src.raw;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return raw;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->raw = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(raw) / scaling_factor;
}

int Fixed::toInt() const {
    return raw / scaling_factor;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
    stream << fixed.toFloat();
    return stream;
}
