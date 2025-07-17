/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:47:33 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/17 14:16:02 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

namespace {
    Fixed get_cross_z(const Point& a, const Point& b, const Point& p) {
        Fixed ab_x = b.get_x() - a.get_x();
        Fixed ab_y = b.get_y() - a.get_y();
        Fixed ap_x = p.get_x() - a.get_x();
        Fixed ap_y = p.get_y() - a.get_y();
        return ab_x * ap_y - ap_x * ab_y;
    }

    bool are_signs_same(const Fixed& a, const Fixed& b, const Fixed& c) {
        Fixed zero;
        if (a > zero && b > zero && c > zero)
            return true;
        else if (a < zero && b < zero && c < zero)
            return true;
        else
            return false;
    }
}  // namespace

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed ab_ap_cross_z = get_cross_z(a, b, point);
    Fixed bc_bp_cross_z = get_cross_z(b, c, point);
    Fixed ca_cp_cross_z = get_cross_z(c, a, point);
    return are_signs_same(ab_ap_cross_z, bc_bp_cross_z, ca_cp_cross_z);
}
