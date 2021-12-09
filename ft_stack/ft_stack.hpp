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

// last-in first-out (LIFO)
namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		typedef T         value_type;
		typedef Container container_type;
		typedef size_t    size_type;

	private:
		container_type m_cont;

	public:
		explicit stack (const container_type& cont = container_type()) : m_cont(cont) {}
		stack(const stack &ref) {
			m_cont = ref.m_cont;
		}
		stack &operator=(const stack &ref) {
			if (this == ref)
				return (*this);
			m_cont = ref.m_cont;
			return (*this);
		}

		~stack() {

		}

		bool empty() const {
			return (m_cont.empty());
		}

		size_type size() const {
			return (m_cont.size());
		}

		value_type& top() {
			return (m_cont.back());
		}

		const value_type& top() const {
			return (m_cont.back());
		}

		void push (const value_type& val) {
			m_cont.push_back(val);
		}

		void pop() {
			m_cont.pop_back();
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
