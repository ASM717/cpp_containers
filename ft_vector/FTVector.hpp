/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FTVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:30:42 by amuriel           #+#    #+#             */
/*   Updated: 2021/10/18 16:30:43 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTVECTOR_HPP
#define FTVECTOR_HPP

#include <iostream>

namespace ft {
	template <class T, class Alloc = std::allocator<T> > // generic template
	class vector {
		private:
			allocator_type m_alloc;
			size_type m_capacity;
			pointer_type m_array;
			size_type m_size;

		public:
			typedef size_t                                size_type;
			typedef T                                     value_type;
			typedef Alloc                                 allocator_type;
			typedef allocator_type::reference             reference;
			typedef allocator_type::const_reference       const_reference;
			typedef allocator_type::pointer               pointer;
			typedef allocator_type::const_pointer         const_pointer;
			typedef vector_iterator<value_type, value_type*, value_type&>                   iterator;
			typedef const_vector_iterator<value_type, const value_type*, const value_type&> const_iterator;
			typedef reverse_vector_iterator<iterator>                                       reverse_iterator;
			typedef const_reverse_vector_iterator<const_iterator>                           const_reverse_iterator;
			typedef iterator_traits<iterator>::difference_type                              difference_type;

			//https://www.cplusplus.com/reference/vector/vector/vector/
			//empty container constructor (default constructor)
			explicit vector (const allocator_type& alloc = allocator_type())
				: m_alloc(alloc), m_array(NULL), m_size(0), m_capacity(0) {}
			//fill constructor
			// Constructs a container with n elements. Each element is a copy of val.
			explicit vector (size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
				: m_alloc(alloc), m_size(n), m_capacity(n) {
				try
				{
					m_array = m_alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						m_array[i] = value;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			//range constructor
			// Constructs a container with as many elements as the range [first,last),
			// with each element constructed from its corresponding element in that range, in the same order.
			template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				:
			{

			}
	};
}

#endif
