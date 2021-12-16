/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 04:49:44 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 13:53:02 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_TRAITS_HPP
#define FT_TYPE_TRAITS_HPP

#include <iterator>

// http://www.cplusplus.com/reference/type_traits/enable_if/
// https://www.cplusplus.com/reference/type_traits/is_integral/

namespace ft {
	template<bool B, class T = void> struct enable_if {};

	template<class T> struct enable_if<true, T> {typedef T type;};

	template <class T> struct is_integral {static const bool value = false;};
	template<> struct is_integral<bool> {static const bool value = true;};
	template<> struct is_integral<char> {static const bool value = true;};
	// template<> struct is_integral<char16_t> {static const bool value = true;};
	// template<> struct is_integral<char32_t> {static const bool value = true;};
	template<> struct is_integral<wchar_t> {static const bool value = true;};
	template<> struct is_integral<signed char> {static const bool value = true;};
	template<> struct is_integral<short int> {static const bool value = true;};
	template<> struct is_integral<int> {static const bool value = true;};
	template<> struct is_integral<long int> {static const bool value = true;};
	template<> struct is_integral<long long int> {static const bool value = true;};
	template<> struct is_integral<unsigned char> {static const bool value = true;};
	template<> struct is_integral<unsigned short int> {static const bool value = true;};
	template<> struct is_integral<unsigned int> {static const bool value = true;};
	template<> struct is_integral<unsigned long int> {static const bool value = true;};
	template<> struct is_integral<unsigned long long int> {static const bool value = true;};
	// for const
	template<> struct is_integral<const bool> {static const bool value = true;};
	template<> struct is_integral<const char> {static const bool value = true;};
	// template<> struct is_integral<const char16_t> {static const bool value = true;};
	// template<> struct is_integral<const char32_t> {static const bool value = true;};
	template<> struct is_integral<const wchar_t> {static const bool value = true;};
	template<> struct is_integral<const signed char> {static const bool value = true;};
	template<> struct is_integral<const short int> {static const bool value = true;};
	template<> struct is_integral<const int> {static const bool value = true;};
	template<> struct is_integral<const long int> {static const bool value = true;};
	template<> struct is_integral<const long long int> {static const bool value = true;};
	template<> struct is_integral<const unsigned char> {static const bool value = true;};
	template<> struct is_integral<const unsigned short int> {static const bool value = true;};
	template<> struct is_integral<const unsigned int> {static const bool value = true;};
	template<> struct is_integral<const unsigned long int> {static const bool value = true;};
	template<> struct is_integral<const unsigned long long int> {static const bool value = true;};
}

#endif
