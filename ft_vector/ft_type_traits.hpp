#ifndef FT_TYPE_TRAITS_HPP
#define FT_TYPE_TRAITS_HPP

#include <iterator>

// http://www.cplusplus.com/reference/type_traits/enable_if/
// https://www.cplusplus.com/reference/type_traits/is_integral/

namespace ft {
	template <bool B, class T = void> struct enable_if {};

	template <> struct enable_if<true> {typedef int type;};

	template <class T> struct is_integral {static const bool value = false;};

	template <> struct is_integral<bool> {static const bool value = true;};

	template <> struct is_integral<char> {static const bool value = true;};

	template <> struct is_integral<short> {static const bool value = true;};

	template <> struct is_integral<int> {static const bool value = true;};

	template <> struct is_integral<long> {static const bool value = true;};

	template <> struct is_integral<long long> {static const bool value = true;};

	template <> struct is_integral<unsigned char> {static const bool value = true;};

	template <> struct is_integral<unsigned short> {static const bool value = true;};

	template <> struct is_integral<unsigned int> {static const bool value = true;};

	template <> struct is_integral<unsigned long> {static const bool value = true;};

	template <> struct is_integral<unsigned long long> {static const bool value = true;};
}

#endif