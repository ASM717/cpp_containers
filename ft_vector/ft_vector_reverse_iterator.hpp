#ifndef FT_VECTOR_REVERSE_ITERATOR
#define FT_VECTOR_REVERSE_ITERATOR

#include "ft_iterator_utils.hpp"

//https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/

namespace ft {
	template <class Iterator>
	class VectorReverseIterator {
	public:
		typedef Iterator                                                  iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type        value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type   difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer           pointer;
		typedef typename ft::iterator_traits<Iterator>::reference         reference;
	private:
		Iterator m_it;
	public:
		VectorReverseIterator() : m_it(){}
		explicit VectorReverseIterator(iterator_type it) : m_it(it) {}
		VectorReverseIterator(const VectorReverseIterator<Iterator> &rev_it) : m_it(rev_it.base()) {}
		~VectorReverseIterator() {}
	};
}

#endif