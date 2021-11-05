#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP

//https://www.cplusplus.com/reference/iterator/iterator_traits/
//https://www.cplusplus.com/reference/iterator/

#include <cstddef>
#include <cstdlib>
#include "ft_iterator_utils.hpp"

namespace ft {
	template <class T, class Pointer = T*, class Reference = T&,
	        class Category = std::random_access_iterator_tag, class allocator_type = std::allocator<T> >
	class VectorRandomAccessIterator {
	public:
		typedef typename ft::iterator_traits<T>::value_type         value_type;
		typedef typename ft::iterator_traits<T>::reference          reference;
		typedef typename ft::iterator_traits<T>::pointer            pointer;
		typedef typename ft::iterator_traits<T>::size_type          size_type;
		typedef typename ft::iterator_traits<T>::difference_type    difference_type;
		typedef Category                                            iterator_category;
	private:
		pointer m_arr_point;
	public:
		pointer getArrPointer() const {return  m_arr_point;}
		VectorRandomAccessIterator() {
			m_arr_point = NULL;
		}
		VectorRandomAccessIterator(VectorRandomAccessIterator const &ref)
			: m_arr_point(ref.m_arr_point) {}
		VectorRandomAccessIterator operator=(VectorRandomAccessIterator const &ref) {
			m_arr_point = ref.m_arr_point;
			return (*this);
		}
		virtual ~VectorRandomAccessIterator() {}

		// ==
		bool operator==(const VectorRandomAccessIterator &ref) const {
			return (this->m_arr_point == ref->m_arr_point);
		}
		// !=
		bool operator!=(const VectorRandomAccessIterator &ref) const {
			return (this->m_arr_point != ref->m_arr_point);
		}
		// ++iterator
		VectorRandomAccessIterator &operator++() {
			this->m_arr_point++;
			return (*this);
		}
		// iterator++
		VectorRandomAccessIterator operator++(int) {
			VectorRandomAccessIterator tmp = (*this);
			++this->m_arr_point;
			return (tmp);
		}
		// --iterator
		VectorRandomAccessIterator &operator--() {
			this->m_arr_point--;
			return (*this);
		}
		// iterator--
		VectorRandomAccessIterator operator--(int) {
			VectorRandomAccessIterator tmp = (*this);
			--this->m_arr_point;
			return (tmp);
		}
		// +=
		VectorRandomAccessIterator &operator+=(difference_type n) {
			this->m_arr_point = this->m_arr_point + n;
			return (*this);
		}
		// -=
		VectorRandomAccessIterator &operator-=(difference_type n) {
			this->m_arr_point = this->m_arr_point - n;
			return (*this);
		}
		// +
		VectorRandomAccessIterator operator+(difference_type n) const {
			return (m_arr_point + n);
		}
		// -
		VectorRandomAccessIterator operator-(difference_type n) const {
			return (m_arr_point - n);
		}
		bool operator>=(VectorRandomAccessIterator const &ref) const {
			return (m_arr_point >= ref.m_arr_point);
		}
		bool operator<=(VectorRandomAccessIterator const &ref) const {
			return (m_arr_point <= ref.m_arr_point);
		}
		bool operator>(VectorRandomAccessIterator const &ref) const {
			return (m_arr_point > ref.m_arr_point);
		}
		bool operator<(VectorRandomAccessIterator const &ref) const {
			return (m_arr_point < ref.m_arr_point);
		}
		//*
		reference operator*() {return (*this->m_arr_point);}
		//->
		pointer operator->() {return (this->m_arr_point);}

		reference operator[](difference_type n) {return (*(this->m_arr_point + n));}
	};

	//relational operators (vector)

	template <typename T>
	bool operator==(const ft::VectorRandomAccessIterator<T> lhs, const ft::VectorRandomAccessIterator<T> rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T>
	bool operator!=(const ft::VectorRandomAccessIterator<T> lhs, const ft::VectorRandomAccessIterator<T> rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	bool operator<(const ft::VectorRandomAccessIterator<T> lhs, const ft::VectorRandomAccessIterator<T> rhs) {
		return (lhs.base() < rhs.base());
	}

	template <typename T>
	bool operator>(const ft::VectorRandomAccessIterator<T> lhs, const ft::VectorRandomAccessIterator<T> rhs) {
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	bool operator<=(const ft::VectorRandomAccessIterator<T> lhs, const ft::VectorRandomAccessIterator<T> rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <typename T>
	bool operator>=(const ft::VectorRandomAccessIterator<T> lhs, const ft::VectorRandomAccessIterator<T> rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <typename T>
	typename ft::VectorRandomAccessIterator<T>::difference_type operator-(const ft::VectorRandomAccessIterator<T> lhs,
			const ft::VectorRandomAccessIterator<T> rhs) {return (lhs.base() - rhs.base());}

	template<typename T>
	ft::VectorRandomAccessIterator<T> operator+(typename ft::VectorRandomAccessIterator<T>::difference_type n,
			typename ft::VectorRandomAccessIterator<T>& ref) {return (&(*ref) + n);}

	template<typename T_Left, typename T_Right>
	bool operator==(const ft::VectorRandomAccessIterator<T_Left> lhs, const ft::VectorRandomAccessIterator<T_Right> rhs) {
		return (lhs.base() == rhs.base());
	}

	template<typename T_Left, typename T_Right>
	bool operator!=(const ft::VectorRandomAccessIterator<T_Left> lhs, const ft::VectorRandomAccessIterator<T_Right> rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T_Left, typename T_Right>
	bool operator<(const ft::VectorRandomAccessIterator<T_Left> lhs, const ft::VectorRandomAccessIterator<T_Right> rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T_Left, typename T_Right>
	bool operator>(const ft::VectorRandomAccessIterator<T_Left> lhs, const ft::VectorRandomAccessIterator<T_Right> rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T_Left, typename T_Right>
	bool operator<=(const ft::VectorRandomAccessIterator<T_Left> lhs, const ft::VectorRandomAccessIterator<T_Right> rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T_Left, typename T_Right>
	bool operator>=(const ft::VectorRandomAccessIterator<T_Left> lhs, const ft::VectorRandomAccessIterator<T_Right> rhs) {
		return (lhs.base() >= rhs.base());
	}

	template<typename T_Left, typename T_Right>
	typename ft::VectorRandomAccessIterator<T_Left>::difference_type operator-(const ft::VectorRandomAccessIterator<T_Left> lhs,
			const ft::VectorRandomAccessIterator<T_Right> rhs) {return (lhs.base() - rhs.base());}
}

#endif
