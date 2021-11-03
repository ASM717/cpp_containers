#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP

namespace ft {
	template <class T, class Pointer, class Reference>
	class vectorRandomAccessIterator {
		public:
			typedef T                                 value_type;
			typedef ptrdiff_t                         difference_type;
			typedef Pointer                           pointer;
			typedef Reference                         reference;
			typedef std::random_access_iterator_tag   iterator_category;
	};
}

#endif
