#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP

//https://www.cplusplus.com/reference/iterator/iterator_traits/
//https://www.cplusplus.com/reference/iterator/

#include <cstddef>
#include <cstdlib>

namespace ft {
	template <class T, class Pointer, class Reference>
	class VectorRandomAccessIterator {
	public:
		typedef T                                 value_type;
		typedef ptrdiff_t                         difference_type;
		typedef Pointer                           pointer;
		typedef Reference                         reference;
		//typedef std::random_access_iterator_tag   iterator_category;
		typedef std::random_access_iterator_tag   iterator_category;
		//typedef Category                          iterator_category;
		typedef VectorRandomAccessIterator<T, Pointer, Reference>  type_class;
	private:
		pointer m_arr;
	public:
		pointer getArrPointer() const {return  m_arr;}
		VectorRandomAccessIterator() {
			m_arr = NULL;
		}
		VectorRandomAccessIterator(pointer array) : m_arr(array) {}
		VectorRandomAccessIterator(VectorRandomAccessIterator<T, Pointer*, Reference&> const &ref)
			: m_arr(ref.getArrPointer()) {}
		virtual ~VectorRandomAccessIterator() {}

		//==
		bool operator==(const type_class *ref) const {
			return (this->m_arr == ref->m_arr);
		}
		//==
		bool operator!=(const type_class *ref) const {
			return (this->m_arr != ref->m_arr);
		}
		// =
		type_class &operator=(type_class const &ref) {
			if (this == &ref)
				return (*this);
			m_arr = ref.m_arr;
			return (*this);
		}
		// ++iterator
		type_class operator++() {
			this->m_arr++;
			return (*this);
		}
		// iterator++
		type_class operator++(int) {
			type_class tmp = (*this);
			++this->m_arr;
			return (tmp);
		}
		//--iterator
		type_class operator--() {
			this->m_arr--;
			return (*this);
		}
		//iterator--
		type_class operator--(int) {
			type_class tmp = (*this);
			--this->m_arr;
			return (tmp);
		}
		//+=
		type_class &operator+=(difference_type n) {
			this->m_arr = this->m_arr + n;
			return (*this);
		}
		//-=
		type_class &operator-=(difference_type n) {
			this->m_arr = this->m_arr - n;
			return (*this);
		}
		//+
		type_class operator+(difference_type n) const {
			type_class tmp = (*this);
			tmp.m_arr = tmp.m_arr + n;
			return (tmp);
		}
		//- надо затестить !!!!
		type_class operator-(difference_type n) const {
			type_class tmp = (*this);
			tmp.m_arr = tmp.m_arr - n;
			return (tmp);
		}
		//*
		reference operator*() {return (*this->m_arr);}
		//->
		pointer operator->() {return (this->m_arr);}

		reference operator[](difference_type n) {
			return (*(this->m_arr + n));
		}
	};
}

#endif
