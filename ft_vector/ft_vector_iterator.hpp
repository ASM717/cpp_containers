#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP

// https://www.cplusplus.com/reference/iterator/iterator_traits/
// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

#include <cstddef>
#include <cstdlib>
#include "ft_iterator_utils.hpp"

namespace ft
{
	template <class T, class Pointer = T*, class Reference = T&,
			class Category = std::random_access_iterator_tag, class allocator_type = std::allocator<T> >
	class VectorRandomAccessIterator{
	public:
		typedef typename ft::iterator_traits<T>::value_type         value_type;
		typedef typename ft::iterator_traits<T>::reference          reference;
		typedef typename ft::iterator_traits<T>::pointer            pointer;
		typedef typename ft::iterator_traits<T>::size_type          size_type;
		typedef typename ft::iterator_traits<T>::difference_type    difference_type;
		typedef typename ft::iterator_traits<T>::const_reference    const_reference;
		typedef typename ft::iterator_traits<T>::const_pointer      const_pointer;
		typedef Category                                            iterator_category;
	private:
		pointer m_arr_ptr;
	public:
		VectorRandomAccessIterator (pointer m_arr_ptr = 0) : m_arr_ptr(m_arr_ptr) {};

		VectorRandomAccessIterator (VectorRandomAccessIterator const &other)
			: m_arr_ptr (other.m_arr_ptr) {}

		VectorRandomAccessIterator &operator=(VectorRandomAccessIterator const &other) {
			m_arr_ptr = other.m_arr_ptr;
			return *this;
		}

		virtual ~VectorRandomAccessIterator() {}

		bool operator==(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr == ref.m_arr_ptr);}
		bool operator!=(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr != ref.m_arr_ptr);}
		reference operator*() {return(*m_arr_ptr);}
		const_reference operator*() const {return(*m_arr_ptr);}
		pointer operator->() {return (m_arr_ptr);}
		const_pointer operator->() const {return (m_arr_ptr);}
		VectorRandomAccessIterator operator+(difference_type n) const {return (m_arr_ptr + n);}
		VectorRandomAccessIterator &operator++() {
			m_arr_ptr++;
			return (*this);
		}
		VectorRandomAccessIterator operator++(int) {
			VectorRandomAccessIterator result = *this;
			++(*this);
			return (result);
		}
		difference_type operator-(VectorRandomAccessIterator it) const {return (m_arr_ptr - it.m_arr_ptr);}
		VectorRandomAccessIterator operator-(difference_type n) const {return (m_arr_ptr - n);}
		VectorRandomAccessIterator &operator--() {
			m_arr_ptr--;
			return (*this);
		}
		VectorRandomAccessIterator operator--(int) {
			VectorRandomAccessIterator result = *this;
			--(*this);
			return (result);
		}
		bool operator>=(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr >= ref.m_arr_ptr);}
		bool operator<=(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr <= ref.m_arr_ptr);}
		bool operator>(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr > ref.m_arr_ptr);}
		bool operator<(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr < ref.m_arr_ptr);}
		pointer base() {return m_arr_ptr;}
		const_pointer base() const {return m_arr_ptr;}
		VectorRandomAccessIterator &operator+=(difference_type n) {
			m_arr_ptr += n;
			return (*this);
		}
		VectorRandomAccessIterator &operator-=(difference_type n) {
			m_arr_ptr -= n;
			return (*this);
		}
		operator VectorRandomAccessIterator<const T> () const {return (VectorRandomAccessIterator<const T>(m_arr_ptr));}
		reference operator[](difference_type i) const {return (*(m_arr_ptr + i));}
	};

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
