/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:34 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 14:02:35 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_HPP
#define FT_NODE_HPP

namespace ft {
	enum Color {
		BLACK,
		RED
	};

	template <class T>
	struct Node
	{
		T           data_node;
		struct Node *m_parent;
		struct Node *m_left;
		struct Node *m_right;
		Color       color;

		Node (T data_node, Node* m_parent, Node *m_left, Node *m_right, Color color) :
			data_node(data_node), m_parent(m_parent), m_left(m_left), m_right(m_right), color(color) {}

		Node(const T &data) : data_node(data) {
		this->m_parent = NULL;
		this->m_left = NULL;
		this->m_right = NULL;
		this->color = RED;
		}

		~Node() {}
	};
}

#endif
