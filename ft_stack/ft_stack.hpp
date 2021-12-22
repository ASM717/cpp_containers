/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:48 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 14:02:49 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "../ft_vector/ft_vector.hpp"

// last_elem-in first-out (LIFO)
namespace ft {
	template <class T, class Container = ft::vector<T>
	> class stack {
	public:
		typedef T         value_type;
		typedef Container container_type;
		typedef size_t    size_type;
	protected:
		container_type c;
	public:
		explicit stack (const container_type& cont = container_type()) : c(cont) {}
		stack(const stack &ref) {
			c = ref.c;
		}
		stack &operator=(const stack &ref) {
			if (this == ref)
				return (*this);
			c = ref.c;
			return (*this);
		}

		~stack() {

		}

		bool empty() const {
			return (c.empty());
		}

		size_type size() const {
			return (c.size());
		}

		value_type& top() {
			return (c.back());
		}

		const value_type& top() const {
			return (c.back());
		}

		void push (const value_type& val) {
			c.push_back(val);
		}

		void pop() {
			c.pop_back();
		}
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.m_cont == rhs.m_cont);
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.m_cont != rhs.m_cont);
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.m_cont < rhs.m_cont);
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.m_cont <= rhs.m_cont);
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.m_cont > rhs.m_cont);
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.m_cont >= rhs.m_cont);
	}
}

#endif
