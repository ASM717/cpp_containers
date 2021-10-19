/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FTVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:30:42 by amuriel           #+#    #+#             */
/*   Updated: 2021/10/19 15:08:56 by amuriel          ###   ########.fr       */
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
					std::cerr << e.what() << std::endl;
				}
			}
			//range constructor
			// Constructs a container with as many elements as the range [first,last),
			// with each element constructed from its corresponding element in that range, in the same order.
			template <class InputIterator>
			vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				:
			{
				///// дописать
			}
			// copy constructor
			// Constructs a container with a copy of each of the elements in ref, in the same order.
			vector (const vector& ref)
				: m_alloc(ref.m_alloc), m_size(ref.m_size), m_capacity(ref.m_capacity) {
				try
				{
					m_array = m_alloc.allocate(m_capacity);
					for (size_type i = 0; i < _size; i++)
						m_array[i] = ref.m_array[i];
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}

			//destuctor
			~vector () {
				if (m_array != NULL) {
					for (size_type i = 0 ; index < m_size ; i++ ) {
						m_alloc.destroy( &m_array[i]);
					}
					m_alloc.deallocate(m_array, m_capacity);
				}
			}
	};
}

#endif
