#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "ft_pair.hpp"
#include "ft_bidirectional_iterator.hpp"
#include "../ft_vector/ft_vector_reverse_iterator.hpp"

namespace ft {
	template <class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = ft::less<Key>,                     // map::key_compare
			class Allocator = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
	> class map {
		typedef Key                                       key_type;
		typedef T                                         mapped_type;
		typedef ft::pair<const key_type, mapped_type>     value_type;
        typedef std::size_t                               size_type;
        typedef std::ptrdiff_t                            difference_type;
		typedef Compare                                   key_compare;
		//typedef Compare                                   value_compare;
		typedef Allocator                                 allocator_type;
		typedef typename allocator_type::reference        reference;
		typedef typename allocator_type::const_reference  const_reference;
		typedef typename allocator_type::pointer          pointer;
		typedef typename allocator_type::const_pointer    const_pointer;
		typedef ft::BidirectionalIterator<value_type>     iterator;
		typedef ft::BidirectionalIterator<value_type>     const_iterator;
		typedef ft::VectorReverseIterator<iterator>       reverse_iterator;
		typedef ft::VectorReverseIterator<const_iterator> const_reverse_iterator;

        class value_compare {
            key_compare m_key_compare;

            value_compare(const key_compare &compare) {
                m_key_compare = compare;
            }
            bool operator() (const value_type &_x, const value_type &_y) const {
                return (m_key_compare(_x.first, _y.first));
            }
        };

		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) {

		}

		//range constructor
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) {

		}

		map (const map &ref) {

		}

		map &operator=(const map& x) {

		}

		~map() {}
	};
}

#endif