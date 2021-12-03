#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
#define FT_BIDIRECTIONAL_ITERATOR_HPP

#include "../ft_vector/ft_iterator_utils.hpp"

namespace ft {
	template <class Iterator>
	class BidirectionalIterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag,T>::difference_type difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag,T>::iterator_category iterator_category;

//		typedef ft::node<T> node;
//		typedef T	value_type;
//		typedef typename iterator_traits<T>::size_type size_type;
//		typedef typename iterator_traits<T>::difference_type difference_type;
//		typedef typename iterator_traits<T>::pointer pointer;
//		typedef typename iterator_traits<T>::reference reference;
//		typedef std::bidirectional_iterator_tag iterator_category;

	private:
		pointer m_pointer;
	public:
		BidirectionalIterator() : m_pointer() {}

		template <class Iterator>
		BidirectionalIterator(const BidirectionalIterator<Iterator> &ref)
				: it_(it.base()) {}

		virtual ~BidirectionalIterator() {}
	};
}

#endif
