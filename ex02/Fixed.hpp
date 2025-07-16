/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:11:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/16 18:20:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FIXED_HPP_
# define EX01_FIXED_HPP_

# include <iostream>

class Fixed {
 public:
    Fixed();
    explicit Fixed(const int i);
    explicit Fixed(const float f);
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& src);
    ~Fixed();
    bool operator>(Fixed& rhs) const;
    bool operator<(Fixed& rhs) const;
    bool operator>=(Fixed& rhs) const;
    bool operator<=(Fixed& rhs) const;
    bool operator==(Fixed& rhs) const;
    bool operator!=(Fixed& rhs) const;
    int getRawBits() const;
    void setRawBits(const int raw);
    float toFloat() const;
    int toInt() const;
 private:
    int raw;
    static const int fractional_bits = 8;
    static const int scaling_factor = 1 << fractional_bits;
    static const int max_int = (1 << (31 - fractional_bits)) - 1;
    static const int min_int = -(1 << (31 - fractional_bits));
    static const double max_flp;
    static const double min_flp;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
