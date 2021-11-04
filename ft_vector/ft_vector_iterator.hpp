#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP

//https://www.cplusplus.com/reference/iterator/iterator_traits/
//https://www.cplusplus.com/reference/iterator/


namespace ft {
	template <class T, class Pointer, class Reference>
	class vectorRandomAccessIterator {
	private:
		pointer m_arr;
	public:
		typedef T                                 value_type;
		typedef ptrdiff_t                         difference_type;
		typedef Pointer                           pointer;
		typedef Reference                         reference;
		//typedef std::random_access_iterator_tag   iterator_category;
		typedef std::random_access_iterator_tag   iterator_category;
		//typedef Category                          iterator_category;
		typedef vectorRandomAccessIterator<T, Pointer, Reference>  type_class;
		pointer getArrPointer() const {return  m_arr;}
		vectorRandomAccessIterator() {
			m_arr = NULL;
		}
		vectorRandomAccessIterator(pointer array) : m_arr(array) {}
		vectorRandomAccessIterator(vectorRandomAccessIterator<T, Pointer*, Reference&> const &ref)
			: m_arr(ref.getArrPointer()) {}
		virtual ~vectorRandomAccessIterator() {}

		//==
		bool operator==(const type_class *ref) const {
			return (this->m_arr == ref->m_arr);
		}
		//==
		bool operator!=(const type_class *ref) const {
			return (this->m_arr != ref->m_arr);
		}
		// =
		type_class &operator=(type const &ref) {
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
