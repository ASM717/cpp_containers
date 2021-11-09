#ifndef FT_ITERATOR_UTILS_HPP
#define FT_ITERATOR_UTILS_HPP

#include <iterator>

// https://en.cppreference.com/w/cpp/iterator/iterator_traits

namespace ft {
	template<class Iterator>
	struct iterator_traits
	{
		typedef ptrdiff_t         difference_type;
		typedef Iterator          value_type;
		typedef Iterator*         pointer;
		typedef Iterator&         reference;
		typedef size_t            size_type;
		typedef const Iterator&   const_reference;
		typedef const Iterator*   const_pointer;
		//typedef std::random_access_iterator_tag iterator_category;
	};

	template<class Iterator>
	struct iterator_traits<Iterator*>
	{
		typedef ptrdiff_t                       difference_type;
		typedef Iterator                        value_type;
		typedef Iterator*                       pointer;
		typedef Iterator&                       reference;
		//typedef std::random_access_iterator_tag iterator_category;
	};

	template<class Iterator>
	struct iterator_traits<const Iterator*> {
		typedef ptrdiff_t                       difference_type;
		typedef Iterator                        value_type;
		typedef const Iterator*                 pointer;
		typedef const Iterator&                 reference;
		//typedef std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	void swap(T&a, T&b) {
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <class T>
	const T& max(const T &a, const T &b) {
		return (a < b) ? b : a;
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
