/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:30:42 by amuriel           #+#    #+#             */
/*   Updated: 2021/11/03 14:48:43 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include "ft_vector_iterator.hpp"
#include <iostream>

namespace ft {
	template <class T, class Alloc = std::allocator<T> > // generic template
	class vector {
		private:
			Allocator m_alloc;
			size_type m_capacity, m_size;
			pointer m_array;

		public:
			typedef size_t                                size_type;
			typedef T                                     value_type;
			typedef Alloc                                 allocator_type;
			typedef typename allocator_type::reference             reference;
			typedef typename allocator_type::const_reference       const_reference;
			typedef typename allocator_type::pointer               pointer;
			typedef typename allocator_type::const_pointer         const_pointer;
			typedef ft::vectorRandomAccessIterator<T, T*, T&>                 iterator;
			typedef ft::vectorRandomAccessIterator<T, const T*, const T&>     const_iterator;
			// typedef ft::reverseVectorIterator<iterator>                       reverse_iterator;
			// typedef ft::reverseVectorIterator<const_iterator>                 const_reverse_iterator;
			// typedef typename iterator_traits<iterator>::difference_type                         difference_type;

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
					{
						m_alloc.construct(&m_array[i], value);
					}
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}

			}
			//range constructor
			// Constructs a container with as many elements as the range [first,last),
			// with each element constructed from its corresponding element in that range, in the same order.

			// template <class InputIterator>
			// vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
			// 	const allocator_type& alloc = allocator_type()) : m_alloc(alloc), m_array(NULL), m_size(0), m_capacity(0) {
			// 	size_type i = 0;
			// 	size_type j = 0;
			// 	for (InputIterator it = first; it != last; it++)
			// 		i++;
			// 	try
			// 	{
			// 		reserve(i);
			// 	}
			// 	catch(const std::exception& e)
			// 	{
			// 		std::cerr << e.what() << '\n';
			// 	}
			// 	for (InputIterator it = first; it != last; it++, j++)
			// 		m_alloc.construct(&m_array[i], *it);
			// 	m_size = i;
			// }
			// copy constructor
			// Constructs a container with a copy of each of the elements in ref, in the same order.
			vector (const vector& ref)
				: m_alloc(ref.m_alloc), m_size(ref.m_size), m_capacity(ref.m_capacity) {
				try
				{
					m_array = m_alloc.allocate(m_capacity);
					for (size_type i = 0; i < m_size; i++)
						m_array[i] = ref.m_array[i];
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			vector &operator=(const vector &ref) {
				if (this == &ref)
					return (*this);
				if (m_size < ref.m_size) {
					reserve(ref.m_size);
					resize(ref.m_size);
				} else {
					for (size_type i = 0; i < m_size; i++)
					{
						m_alloc.destroy(&m_array[i]);
					}
				}
				m_size = ref.size;
				for (size_type i = 0; i < m_size; i++) {
					m_alloc.construct(&m_array[i], ref.m_array[i]);
				}
				return *this;
			}
			//destuctor
			~vector () {
				if (m_array != NULL) {
					for (size_type i = 0; i < m_size; i++) {
						m_alloc.destroy(&m_array[i]);
					}
					m_alloc.deallocate(m_array, m_capacity);
				}
			}

			//iterators
			iterator begin() {
				return iterator(m_array);
			}
			const_iterator begin() const {
				return const_iterator(m_array);
			}

			iterator end() {
				return iterator(m_array + m_size);
			}
			const_iterator end() const {
				return const_iterator(m_array + m_size);
			}

			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			}

			reverse_iterator rend() {
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
			}

			void reserve (size_type n) {
				if (n <= m_capacity)
					return ;
				pointer new_array = m_alloc.allocate(n);
				for (size_type i = 0; i < m_size; i++) {
					m_alloc.construct(m_array + i, this->m_array[i]);
				}
				this->~vector();
				this->m_array = m_array;
				m_capacity = n;
			}

			// void vector<T, Alloc>::realloc(size_type n) {
			// 	if (n <= m_capacity)
			// 		return;
			// 	T *new_cap = m_alloc.allocate(n); //указатель
			// 	for (size_type i = 0; i < m_size; i++) {
			// 		m_alloc.construct(new_cap + i, m_array[i]);
			// 		m_alloc.destroy(m_array + i);
			// 	}
			// 	m_alloc.deallocate(m_array, m_capacity);
			// 	m_array = new_cap;
			// 	m_capacity = n;
			// }
	};
}

#endif
