#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP

#include "ft_iterator_utils.hpp"

namespace ft {
	template <typename T>
	class VectorRandomAccessIterator : public ft::iterator<ft::random_access_iterator_tag, T> {
	public:
		typedef T  value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;

	private:
		pointer m_arr_ptr;
	public:
		VectorRandomAccessIterator (pointer m_arr_ptr = 0) : m_arr_ptr(m_arr_ptr) {};

		VectorRandomAccessIterator (VectorRandomAccessIterator const &ref)
			: m_arr_ptr (ref.m_arr_ptr) {}

		VectorRandomAccessIterator &operator=(VectorRandomAccessIterator const &ref) {
			if (this != &ref)
				this->m_arr_ptr = ref.base();
			return (*this);
		}

		virtual ~VectorRandomAccessIterator() {}

		pointer base() {return m_arr_ptr;}
		pointer const &base() const { return (this->m_arr_ptr); }
		reference operator*() {return(*m_arr_ptr);}
		//const_reference operator*() const {return(*m_arr_ptr);}
		pointer operator->() {return (m_arr_ptr);}
		//const_pointer operator->() const {return (m_arr_ptr);}
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
		bool operator==(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr == ref.m_arr_ptr);}
		bool operator!=(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr != ref.m_arr_ptr);}
		bool operator>=(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr >= ref.m_arr_ptr);}
		bool operator<=(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr <= ref.m_arr_ptr);}
		bool operator>(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr > ref.m_arr_ptr);}
		bool operator<(VectorRandomAccessIterator const &ref) const {return (m_arr_ptr < ref.m_arr_ptr);}

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
