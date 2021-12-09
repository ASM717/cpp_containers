/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_black_tree.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:42 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 14:02:43 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RED_BLACK_TREE_HPP
#define FT_RED_BLACK_TREE_HPP

#include <iostream>

#include "ft_pair.hpp"
#include "ft_less.hpp"
#include "ft_node.hpp"

namespace ft {
	template<typename Key, typename Value, typename Pair = ft::pair<const Key, Value>,
		typename Allocator = std::allocator<Pair>, typename Compare = ft::less<Key> >
	class RBTree {
		typedef Node<ft::pair<const Key,T> > node;
		typedef typename Allocator::template rebind<Node>::other node_alloc_type;

		private:
			node_alloc_type m_alloc;
			Node *m_root;
			Node *m_elem;
			Compare m_compare;
		public:
			RBTree() : m_alloc(std::allocator<Node>()), m_root(NULL), m_elem(NULL), m_compare(ft::less<Key >()) {}

			RBTree(Pair pair_data) : m_alloc(std::allocator<Node>()), m_root(m_alloc.allocate(1)), m_elem(NULL), m_compare(ft::less<Key >()) {
				m_alloc.construct(m_root, Node(pair_data));
				m_root->color = black;
			}
		void printTreeHelper(Node *root, int space)
		{
			int i;
			if(root != NULL)
			{
				space = space + 10;
				printTreeHelper(root->right, space);
				std::cout << std::endl;
				for ( i = 10; i < space; i++)
				{
					std::cout << " ";
				}
				if(root == this->root)
					// std::cout << "root  " << root->color << "  "<< root->_pair.first << std::endl;
					std::cout << "root  " << root->color << "  "<< root->data.first << std::endl;
				else
					// std::cout << root->color << "  " << root->_pair.first << std::endl;
					std::cout << root->color << "  " << root->data.first << std::endl;
				std::cout << std::endl;
				printTreeHelper(root->left, space);
			}
		}
	};
}

#endif
