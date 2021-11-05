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
		//template <typename Iter> если надо, то вниз уйдет <Iter>
		VectorReverseIterator(const VectorReverseIterator<Iterator> &rev_it) : m_it(rev_it.base()) {}
		~VectorReverseIterator() {}

		iterator_type base() const {return (this->m_it);}
		// *
		reference operator*() const {return (*this->m_it);}
		// +
		VectorReverseIterator operator+(difference_type n) const {
			return (ReverseIterator(this->m_it - n));
		}
		// ++iterator
		VectorReverseIterator operator++() {
			--this->m_it;
			return (*this);
		}
		// iterator++
		VectorReverseIterator operator++(int) {
			VectorReverseIterator tmp(*this);
			--this->m_it;
			return (tmp);
		}
		// +=
		VectorReverseIterator &operator+=(difference_type n) {
			this->m_it = this->m_it - n;
			return (*this);
		}
		// -
		VectorReverseIterator operator-(difference_type n) const {
			return (VectorReverseIterator(this->m_it + n));
		}
		// --iterator
		VectorReverseIterator operator--() {
			++this->m_it;
			return (*this);
		}
		// iterator--
		VectorReverseIterator operator--(int) {
			VectorReverseIterator tmp(*this);
			++this->m_it;
			return (tmp);
		}
		// -=
		VectorReverseIterator &operator-=(difference_type n) {
			this->m_it = this->m_it + n;
			return (*this);
		}
//		bool operator==(reverse_iterator const &ref) const {
//			return (this->m_it == ref.m_it);
//		}
//		bool operator!=(reverse_iterator const &ref) const {
//			return (this->m_it != ref.m_it);
//		}
		// ->
		pointer operator->() const {return (&(this->operator*()));}
		/*	Accesses the element located n positions away from the element
		 * currently pointed to by the iterator.
		 * If such an element does not exist, it causes undefined behavior.
		 * Internally, the function accesses the proper element of its base iterator,
		 * returning the same as: base()[-n-1].
		*/
		reference operator[](difference_type n) const {return (base()[-n-1]);} //???

	};
	/*
	 * relational operators (reverse_iterator)
	 * https://www.cplusplus.com/reference/iterator/reverse_iterator/operators/
	*/
	template <class Iterator>
	bool operator==(const VectorReverseIterator<Iterator>& lhs, const VectorReverseIterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!=(const VectorReverseIterator<Iterator>& lhs, const VectorReverseIterator<Iterator>& rhs) {
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator<(const VectorReverseIterator<Iterator>& lhs, const VectorReverseIterator<Iterator>& rhs) {
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator<=(const VectorReverseIterator<Iterator>& lhs, const VectorReverseIterator<Iterator>& rhs) {
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	bool operator>(const VectorReverseIterator<Iterator>& lhs, const VectorReverseIterator<Iterator>& rhs) {
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator>=(const VectorReverseIterator<Iterator>& lhs, const VectorReverseIterator<Iterator>& rhs) {
		return (lhs.base() >= rhs.base());
	}
	///////////////////////////////////////////////////////////////
	template <class Iterator_Lhs, class Iterator_Rhs>
	bool operator==(const VectorReverseIterator<Iterator_Lhs>& lhs, const VectorReverseIterator<Iterator_Rhs>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <class Iterator_Lhs, class Iterator_Rhs>
	bool operator!=(const VectorReverseIterator<Iterator_Lhs>& lhs, const VectorReverseIterator<Iterator_Rhs>& rhs) {
		return (lhs.base() != rhs.base());
	}
	template <class Iterator_Lhs, class Iterator_Rhs>
	bool operator<(const VectorReverseIterator<Iterator_Lhs>& lhs, const VectorReverseIterator<Iterator_Rhs>& rhs) {
		return (lhs.base() < rhs.base());
	}
	template <class Iterator_Lhs, class Iterator_Rhs>
	bool operator<=(const VectorReverseIterator<Iterator_Lhs>& lhs, const VectorReverseIterator<Iterator_Rhs>& rhs) {
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator_Lhs, class Iterator_Rhs>
	bool operator>(const VectorReverseIterator<Iterator_Lhs>& lhs, const VectorReverseIterator<Iterator_Rhs>& rhs) {
		return (lhs.base() > rhs.base());
	}
	template <class Iterator_Lhs, class Iterator_Rhs>
	bool operator>=(const VectorReverseIterator<Iterator_Lhs>& lhs, const VectorReverseIterator<Iterator_Rhs>& rhs) {
		return (lhs.base() >= rhs.base());
	}
}

#endif