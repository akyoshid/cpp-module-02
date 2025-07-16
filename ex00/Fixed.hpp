/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:11:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/16 12:38:05 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_FIXED_HPP_
# define EX00_FIXED_HPP_

class Fixed {
 public:
    Fixed();
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& src);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int raw);
 private:
    int raw;
    static const int fractional_bits = 8;
};

#endif
