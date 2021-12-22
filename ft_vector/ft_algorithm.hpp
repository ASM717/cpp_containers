/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 04:49:34 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/22 18:15:03 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_HPP
#define FT_ALGORITHM_HPP

namespace ft {
	// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (*first2 < *first1)
				return false;
			if (*first1 < *first2)
				return true;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (comp(*first2, *first1))
				return false;
			if (comp(*first1, *first2))
				return true;
		}
		return (first1 == last1) && (first2 != last2);
	}

	// https://en.cppreference.com/w/cpp/algorithm/equal
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
//		for (; first1 != last1; ++first1, ++first2) {
//			if (!(*first1 == *first2)) {
//				return false;
//			}
//		}
//		return true;
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1; ++first2;
		}
		return (true);
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return (false);
			}
		}
		return (true);
		// while (first1 != last1)
		// {
		// 	if (!pred(*first1, *first2))
		// 		return (false);
		// 	++first1; ++first2;
		// }
		// return (true);
	}

	template <class InputIterator>
	size_t	distance(InputIterator first, InputIterator second)
	{
		size_t i = 0;
		for (InputIterator it = first; it != second; ++it)
			i++;
		return (i);
	}
}

#endif
