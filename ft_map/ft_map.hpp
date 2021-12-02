#ifndef FT_MAP_HPP
#define FT_MAP_HPP

namespace ft {
	template <class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = less<Key>,                     // map::key_compare
			class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
	> class map {

	};
}

#endif