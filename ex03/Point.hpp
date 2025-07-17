/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:47:35 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/17 13:23:55 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_POINT_HPP_
# define EX03_POINT_HPP_

# include "Fixed.hpp"

class Point {
 public:
    Point();
    Point(const float x, const float y);
    Point(const Point& src);
    Point& operator=(const Point& src);
    ~Point();
    const Fixed& get_x() const;
    const Fixed& get_y() const;
 private:
    const Fixed x;
    const Fixed y;
};

#endif
