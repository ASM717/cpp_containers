/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:34 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 16:41:08 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_HPP
#define FT_NODE_HPP

#include <iostream>
//#include <cstddef> // для std::nullptr_t

namespace ft {
//	enum Color {
//		black,
//		red
//	};

//	template <class T>
//	struct Node
//	{
//		T           data;
//		struct Node *parent;
//		struct Node *left;
//		struct Node *right;
//		Color       color;
//
//		Node (T data_node, Node* m_parent, Node *m_left, Node *m_right, Color color) :
//				data(data_node), parent(m_parent), left(m_left), right(m_right), color(color) {}
//
//		Node(const T &data) : data(data) {
//			this->parent = NULL;
//			this->left = NULL;
//			this->right = NULL;
//			this->color = red;
//		}
//
//		~Node() {}
//	};

	enum e_color
	{
		black, red
	};

	template <typename P>
	struct node
	{
		P data;
		node *left;
		node *right;
		node *parent;
		e_color color;

		/// Constructor ///
		node(const P &cp) : data(cp) {
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->color = red;
		}
		~node() {}
	};

}

#endif
