/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:11:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/17 17:29:05 by akyoshid         ###   ########.fr       */
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

bool Fixed::operator>(const Fixed& rhs) const {
    return raw > rhs.raw;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return raw < rhs.raw;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return raw >= rhs.raw;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return raw <= rhs.raw;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return raw == rhs.raw;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return raw != rhs.raw;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.raw = raw + rhs.raw;
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.raw = raw - rhs.raw;
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    int64_t temp
        = (static_cast<int64_t>(raw) * static_cast<int64_t>(rhs.raw))
            / scaling_factor;
    result.raw = static_cast<int>(temp);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    if (rhs.raw == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    int64_t temp
        = (static_cast<int64_t>(raw) * scaling_factor)
            / static_cast<int64_t>(rhs.raw);
    result.raw = static_cast<int>(temp);
    return result;
}

Fixed Fixed::operator++() {
    ++raw;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed ret = *this;
    ++(*this);
    return ret;
}

Fixed Fixed::operator--() {
    --raw;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed ret = *this;
    --(*this);
    return ret;
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
    return raw / scaling_factor;
}

Fixed& Fixed::min(Fixed& x, Fixed& y) {
    if (x.raw <= y.raw)
        return x;
    else
        return y;
}

const Fixed& Fixed::min(const Fixed& x, const Fixed& y) {
    if (x.raw <= y.raw)
        return x;
    else
        return y;
}

Fixed& Fixed::max(Fixed& x, Fixed& y) {
    if (x.raw >= y.raw)
        return x;
    else
        return y;
}

const Fixed& Fixed::max(const Fixed& x, const Fixed& y) {
    if (x.raw >= y.raw)
        return x;
    else
        return y;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
    stream << fixed.toFloat();
    return stream;
}
