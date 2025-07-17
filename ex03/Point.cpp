/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:47:21 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/17 11:30:20 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float x, const float y) : x(x), y(y) {
}

Point::Point(const Point& src) : x(src.x), y(src.y) {
}

Point& Point::operator=(const Point& src) {
    static_cast<void>(src);
    std::cerr
        << "Warning: x and y are const variables, "
        << "so their values cannot be changed." << std::endl;
    return (*this);
}

Point::~Point() {
}
