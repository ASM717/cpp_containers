/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_utils.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 04:49:40 by amuriel           #+#    #+#             */
/*   Updated: 2021/11/27 04:49:41 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_UTILS_HPP
#define FT_ITERATOR_UTILS_HPP

#include <iterator>
#include <cstddef>

// https://en.cppreference.com/w/cpp/iterator/iterator_traits

namespace ft {
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef ptrdiff_t                  difference_type;
		typedef T                          value_type;
		typedef T*                         pointer;
		typedef T&                         reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*> {
		typedef ptrdiff_t                  difference_type;
		typedef T                          value_type;
		typedef const T*                   pointer;
		typedef const T&                   reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template<class T>
	void swap(T &a, T &b) {
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <class T>
	const T& max(const T &a, const T &b) {
		return (a < b) ? b : a;
	}


}

#endif
