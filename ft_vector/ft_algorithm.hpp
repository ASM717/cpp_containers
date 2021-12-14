/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 04:49:34 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/07 12:32:26 by amuriel          ###   ########.fr       */
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
	bool equal(InputIt1 first1, InputIt1 last1,
			   InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	// static class nullptr_t {
	// 	public:
	// 	template < class V >
	// 	operator V*() const {
	// 		return (0);
	// 	}

	// 	template < class C, class V >
	// 	operator V C::*() const {
	// 		return (0);
	// 	}

	// 	private:
	// 	void operator&() const;

	// 	} u_nullptr = {};

	// template <typename InputIterator>
	// typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last) {
	// 	typename ft::iterator_traits<InputIterator>::difference_type dist = 0;
	// 	while (first != last) {
	// 		first++;
	// 		dist++;
	// 	}
	// 	return (dist);
	// }

	// template <typename InputIterator>
	// typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last) {
	// 	typename ft::iterator_traits<InputIterator>::difference_type diff = 0;
	// 	return (last - first);
	// }

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
