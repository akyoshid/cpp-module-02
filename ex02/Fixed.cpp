/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:11:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/16 19:32:42 by akyoshid         ###   ########.fr       */
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
}

Fixed::Fixed(const int i) : raw(0) {
    if (i > max_int) {
        std::cerr
            << "Warning: Integer overflow in Fixed constructor" << std::endl;
        raw = max_int << fractional_bits;
    } else if (i < min_int) {
        std::cerr
            << "Warning: Integer overflow in Fixed constructor" << std::endl;
        raw = min_int << fractional_bits;
    } else {
        raw = i << fractional_bits;
    }
}

Fixed::Fixed(const float f) : raw(0) {
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
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
    if (this != &src)
        this->raw = src.raw;
    return *this;
}

Fixed::~Fixed() {
}

bool Fixed::operator>(Fixed& rhs) const {
    return raw > rhs.raw;
}

bool Fixed::operator<(Fixed& rhs) const {
    return raw < rhs.raw;
}

bool Fixed::operator>=(Fixed& rhs) const {
    return raw >= rhs.raw;
}

bool Fixed::operator<=(Fixed& rhs) const {
    return raw <= rhs.raw;
}

bool Fixed::operator==(Fixed& rhs) const {
    return raw == rhs.raw;
}

bool Fixed::operator!=(Fixed& rhs) const {
    return raw != rhs.raw;
}

Fixed Fixed::operator+(Fixed& rhs) const {
    Fixed result;
    result.raw = raw + rhs.raw;
    return result;
}

Fixed Fixed::operator-(Fixed& rhs) const {
    Fixed result;
    result.raw = raw - rhs.raw;
    return result;
}

Fixed Fixed::operator*(Fixed& rhs) const {
    Fixed result;
    long long ll_raw
        = (static_cast<long long>(raw) * static_cast<long long>(rhs.raw))
            >> fractional_bits;
    result.raw = static_cast<int>(ll_raw);
    return result;
}

Fixed Fixed::operator/(Fixed& rhs) const {
    Fixed result;
    long long ll_raw
        = (static_cast<long long>(raw) << fractional_bits)
            / static_cast<long long>(rhs.raw);
    result.raw = static_cast<int>(ll_raw);
    return result;
}

int Fixed::getRawBits() const {
    return raw;
}

void Fixed::setRawBits(const int raw) {
    this->raw = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(raw) / scaling_factor;
}

int Fixed::toInt() const {
    return raw >> fractional_bits;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
    stream << fixed.toFloat();
    return stream;
}
