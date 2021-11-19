/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:30:42 by amuriel           #+#    #+#             */
/*   Updated: 2021/11/17 21:15:57 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include "ft_vector_iterator.hpp"
#include "ft_vector_reverse_iterator.hpp"
#include "ft_type_traits.hpp"
#include "ft_algorithm.hpp"
#include "ft_iterator_utils.hpp"
#include <iostream>
#include <memory>  // allocator
#include <cstddef> // ptrdiff_t
#include <stdexcept> // exception

namespace ft {
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::VectorRandomAccessIterator<T> iterator;
		typedef ft::VectorRandomAccessIterator<const T> const_iterator;
		typedef ft::VectorReverseIterator<iterator> reverse_iterator;
		typedef ft::VectorReverseIterator<const_iterator> const_reverse_iterator;
		typedef typename allocator_type::difference_type difference_type;

	private:
		Allocator m_alloc;
		size_type m_capacity, m_size;
		pointer m_array;
	public:

		/*	https://www.cplusplus.com/reference/vector/vector/vector/
			empty container constructor (default constructor) */
		explicit vector(const Allocator &alloc = Allocator())
				: m_alloc(alloc), m_capacity(0), m_size(0), m_array(0)
		{}

		/*	fill constructor
		 	Constructs a container with n elements. Each element is a copy of val.*/
		explicit vector(size_type n, const value_type &value = value_type(), const Allocator &alloc = Allocator())
				: m_alloc(alloc), m_capacity(n), m_size(n)
		{
			try
			{
				m_array = m_alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					m_alloc.construct(&m_array[i], value);
				}
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

		/*	range constructor
			Constructs a container with as many elements as the range [first,last),
			with each element constructed from its corresponding element in that range, in the same order. */

		template<class InputIterator>
		vector(InputIterator first, InputIterator last, Allocator const &alloc = Allocator(),
			   typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0): m_alloc(alloc)
		{
			m_size = 0;
			for (InputIterator i = first; i != last; i++)
				m_size++;
			for (m_capacity = 1; m_capacity < m_size;)
				m_capacity *= 2;
			m_array = m_alloc.allocate(m_capacity);
			for (size_type i = 0; i < m_size; i++, first++)
				m_alloc.construct(m_array + i, *first);
		}

		// copy constructor
		// Constructs a container with a copy of each of the elements in ref, in the same order.
		vector(const vector &ref)
				: m_alloc(ref.m_alloc), m_capacity(ref.m_capacity), m_size(ref.m_size)
		{
			try
			{
				m_array = m_alloc.allocate(m_capacity);
				for (size_type i = 0; i < m_size; i++)
					m_array[i] = ref.m_array[i];
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		vector &operator=(const vector &ref) {
			if (this == &ref)
				return (*this);
			if (m_capacity != 0) {
				for (size_type i = 0; i < m_size; i++)
					m_alloc.destroy(m_array + i);
				m_alloc.deallocate(m_array, m_capacity);
			}
			m_capacity = ref.m_capacity;
			m_size = ref.m_size;
			m_alloc = ref.m_alloc;
			m_array = m_alloc.allocate(m_capacity);
			for (size_type i = 0; i < m_size; i++)
				m_alloc.construct(m_array + i, ref[i]);
			return (*this);
		}

		//destuctor
		~vector () {
			for (size_type i = 0; i < m_size; i++)
				m_alloc.destroy(m_array + i);
			m_alloc.deallocate(m_array, m_capacity);
		}

		// Iterators
		iterator begin() {return (m_array);}
		iterator end() {return (begin() + m_size);}
		reverse_iterator rbegin() {return reverse_iterator(end());}
		reverse_iterator rend() {return reverse_iterator(begin());}

		const_iterator begin() const {return (m_array);}
		const_iterator end() const {return (begin() + m_size);}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
		const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

		// Capacity
		size_type size() const {return m_size;}

		size_type max_size() const {return (m_alloc.max_size());}

		void resize (size_type n, value_type val = value_type()) {
			if (n > m_capacity) {
				if (n < m_capacity * 2)
					reserve(m_capacity * 2);
				else
					reserve(n);
			}
			for (size_type i = m_size; i < n; i++)
				m_alloc.construct(&m_array[i], val);
			for (size_type i = n; i < m_size; i++)
				m_alloc.destroy(&m_array[i]);
			m_size = n;

		}

		size_type capacity() const {
			return (m_capacity);
		}

		bool empty() const {
			return (begin() == end());
		}

		void reserve (size_type n) {
			if (n > m_capacity) {
				pointer update = m_alloc.allocate(n);
				for (size_type i = 0; i < m_size; i++) {
					m_alloc.construct(&update[i], m_array[i]);
					m_alloc.destroy(&m_array[i]);
				}
				m_alloc.deallocate(m_array, m_capacity = n);
				m_array = update;
				m_capacity = n;
			}
		}
		// Element access:
		reference operator[] (size_type n) {
			return *(m_array + n);
		}

		const_reference operator[] (size_type n) const {
			return *(m_array + n);
		}

		void ft_range_check(size_type n) const
		{
			if (n >= this->size() || n < 0)
				throw(std::out_of_range("vector"));
		}

		reference at (size_type n) {
			ft_range_check(n);
			return (*(this->m_array + n));
		}

		const_reference at (size_type n) const {
			ft_range_check(n);
			return (*(this->m_array + n));
		}

		reference front() {return *begin();}
		const_reference front() const {return *begin();}

		reference back() {return *(end() - 1);}
		const_reference back() const {return *(end() - 1);}

		// Modifiers:

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
					 typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
			clear();
			while (first != last)
				push_back(*first++);
		}

		void assign (size_type n, const value_type& val) {
			size_t i = 0;
			while (i < n) {
				push_back(val);
				++i;
			}
		}

		void push_back (const value_type& val) {
			insert(end(), val);
		}

		void pop_back() {
			erase(end() - 1);
		}

		iterator insert(iterator pos, const value_type &val) {
			difference_type move = pos - begin();
			size_type n = 1;

			if (m_capacity < m_size + n)
				reserve(ft::max(m_size * 2, m_size + n));
			pos = begin() + move;
			for (iterator ptr = end() + n - 1; ptr >= pos + n; ptr--) {
				m_alloc.construct(ptr.base(), *(ptr - n));
				m_alloc.destroy(ptr.base() - n);
			}
			for (iterator ptr = pos + n - 1; ptr >= pos; --ptr)
				m_alloc.construct(ptr.base(), val);
			m_size += n;

			return pos;
		}

		void insert (iterator pos, size_type n, const value_type& val) {
			difference_type move = pos - begin();

			if (n == 0 || move < 0)
				return;
			if (m_capacity < m_size + n)
				reserve(ft::max(m_size * 2, m_size + n));
			pos = begin() + move;
			for (iterator ptr = end() + n - 1; ptr >= pos + n; ptr--)
			{
				m_alloc.construct(ptr.base(), *(ptr - n));
				m_alloc.destroy(ptr.base() - n);
			}
			for (iterator ptr = pos + n - 1; ptr >= pos; --ptr)
				m_alloc.construct(ptr.base(), val);
			m_size += n;
		}

		template <class InputIterator>
		typename enable_if<!is_integral<InputIterator>::value, void>::type
		insert (iterator pos, InputIterator f, InputIterator l) {
			vector<T> vec(f, l);
			iterator first = vec.begin();
			iterator last = vec.end();
			difference_type dist = 0;
			difference_type position = pos - begin();

			for (iterator i = first; i != last; i++)
				dist++;
			if (m_capacity < m_size + dist)
				reserve(std::max(m_size * 2, m_size + dist));
			pos = begin() + position;
			for (iterator ptr = m_array + dist + m_size - 1; ptr >= pos + dist; ptr--)
			{
				m_alloc.construct(ptr.base(), *(ptr - dist));
				m_alloc.destroy(ptr.base() - dist);
			}
//			for (iterator ptr = pos ; ptr != position + dist; ptr++, first++)
//				m_alloc.construct(ptr.base(), *first);
			m_size += dist;
		}


		iterator erase(iterator position) {
			return (erase(position, position + 1));
		}

		iterator erase (iterator first, iterator last) {

			if (last <= first)
				return last;

			difference_type dist = last - first;
			for (iterator i = first; i != last; i++)
				m_alloc.destroy(i.operator->());
			for (iterator i = last; i != end(); i++ ) {
				m_alloc.construct((i - dist).operator->(), *i);
				m_alloc.destroy(i.operator->());
			}
			m_size -= dist;
			return first;
		}

		void swap (vector &ref) {
			if (*this == ref)
				return;
			ft::swap(m_array, ref.m_array);
			ft::swap(m_size, ref.m_size);
			ft::swap(m_capacity, ref.m_capacity);
			ft::swap(m_alloc, ref.m_alloc);
		}

		void clear() {
			while (m_size) {pop_back();}
		}

		allocator_type get_allocator() const {
			return (m_alloc);
		}
	};

	// relational operators (vector)
	template <typename T, typename Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && lhs.size() == rhs.size());
	}

	template <typename T, typename Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <typename T, typename Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(),lhs.end()));
	}

	template <typename T, typename Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(),lhs.end()));
	}

	template <typename T, typename Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Alloc>
	void swap (vector<T,Alloc> &x, vector<T,Alloc> &y) {
		x.swap(y);
	}
}

#endif
