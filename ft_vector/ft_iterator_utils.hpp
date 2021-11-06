#ifndef FT_ITERATOR_UTILS_HPP
#define FT_ITERATOR_UTILS_HPP

#include <iterator>

// https://en.cppreference.com/w/cpp/iterator/iterator_traits

namespace ft {
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t                       difference_type;
		typedef T                               value_type;
		typedef T*                              pointer;
		typedef T&                              reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	class iterator_traits<const T*> {
		typedef ptrdiff_t                       difference_type;
		typedef T                               value_type;
		typedef const T*                        pointer;
		typedef const T&                        reference;
		typedef std::random_access_iterator_tag iterator_category;
		//std::random_access_iterator_tag
	};

	template<class T>
	void swap(T&a, T&b) {
		T tmp = a;
		a = b;
		b = tmp;
	}

//	template<typename InputIterator>
//	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last,
//		typename ft::enable_if<ft::is_random_access_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL) {
//		return (last - first);
//	}
//
//	template<typename InputIterator>
//	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last,
//		typename ft::enable_if<!ft::is_random_access_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL) {
//		typename iterator_traits<InputIterator>::difference_type diff = 0;
//		while (first != last) {
//			first++;
//			diff++;
//		}
//		return (diff);
//	}
}

#endif