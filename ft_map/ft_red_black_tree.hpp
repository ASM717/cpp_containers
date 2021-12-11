/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_black_tree.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:42 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 16:07:15 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RED_BLACK_TREE_HPP
#define FT_RED_BLACK_TREE_HPP

#define REDC		"\x1B[31m"
#define BLACKC		"\x1B[37m"
#define RESETC		"\x1B[0m"

#include <iostream>

#include "ft_pair.hpp"
#include "ft_less.hpp"
#include "ft_node.hpp"

namespace ft {
	template<typename Key, typename Value, typename Pair = ft::pair<const Key, Value>,
		typename Allocator = std::allocator<Pair>, typename Compare = ft::less<Key> >
	class RBTree {
		typedef Node<ft::pair<const Key, Value> > node;
		typedef typename Allocator::template rebind<node>::other node_alloc_type;

		private:
			node_alloc_type _alloc;
			node *root;
			node *elem;
			Compare _comp;
		public:
			RBTree() : _alloc(std::allocator<node>()), root(NULL), elem(NULL), _comp(ft::less<Key >()) {}

			RBTree(Pair data) : _alloc(std::allocator<node>()), root(_alloc.allocate(1)), elem(NULL),
								_comp(ft::less<Key >()) {
				_alloc.construct(root, node(data));
				root->color = black;
			}

			RBTree(const RBTree &ref) : _alloc(ref._alloc), root(NULL), elem(NULL), _comp(ft::less<Key >()) {
				*this = ref;
			}

			/// Operator ///
			RBTree &operator=(const RBTree &ref) {
				if (ref.root == NULL || this == &ref)
					return (*this);
				deleteTree(root);
				copyElem(ref.root);
				return (*this);
			}
			/// Destructor ///
			~RBTree() {
				deleteTree(root);
			}

			/// Geters ///
			node *getRoot() {
				return (root);
			}

			void printTreeHelper(node *root, int space) {
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

			void test_show_tree()
			{
				printTreeHelper(this->root, 0);
			}

			node *find(Key key, node *start) {
				if (start == NULL)
					return (NULL);
				else if (key == start->data.first)
					return (start);
				else if (_comp(key, start->data.first))
					return (find(key, start->left));
				else
					return (find(key, start->right));
			}

			bool notExist(Pair data, node *start) {
				if (start == NULL)
					return(true);
				else if (data.first == start->data.first)
					return (false);
				else if (_comp(data.first, start->data.first))
					return (notExist(data, start->left));
				else
					return (notExist(data, start->right));
			}

			node *findKey(Pair data, node *start) {
				if (start == NULL)
					return (NULL);
				else if (data.first == start->data.first)
					return (start);
				else if (_comp(data.first, start->data.first))
					return (findKey(data, start->left));
				else
					return (findKey(data, start->right));
			}

			node *createElem(const Pair data) {
				elem = _alloc.allocate(1);
				_alloc.construct(elem, node(data));
				return elem;
			}

			void copyElem(node *toCopy) {
				if (toCopy == NULL)
					return ;
				insertElem(createElem(toCopy->data), root);
				copyElem(toCopy->right);
				copyElem(toCopy->left);
			}

			node *getParent(node *elem) {
				return (elem->parent);
			}

			node *getLeft(node *elem) {
				return (elem->left);
			}

			node *getRight(node *elem) {
				return (elem->right);
			}

			node *insertElem(node *elem, node *start) {
				if (elem == NULL) {
					return (NULL);
				}
				if (start == NULL) {
					root = elem;
					return (root);
				}
				if (_comp(elem->data.first, start->data.first)) {
					if (start->left)
						insertElem(elem, start->left);
					else {
						elem->parent = start;
						start->left = elem;
						insertFix(elem);
					}
				} else if (elem->data.first == start->data.first)
					return (NULL);
				else {
					if (start->right)
						insertElem(elem, start->right);
					else {
						elem->parent = start;
						start->right = elem;
						insertFix(elem);
					}
				}
				return (elem);
			}

			node *insert(Pair data) {
				if (notExist(data, root))
					return (insertElem(createElem(data), root));
				return (findKey(data, root));
			}

			void insertFix(node *elem) {
				if (elem == NULL || elem->parent == NULL)
					return;
				while (elem->parent->color == red) {
					if (elem->parent->parent && elem->parent == elem->parent->parent->left) {
						if (elem->parent->parent->right && elem->parent->parent->right->color == red) {
							elem->parent->parent->right->color = black;
							elem->parent->color = black;
							elem->parent->parent->color = red;
							elem = elem->parent->parent;
						} else {
							if (elem == elem->parent->right) {
								node *tmp = elem->parent;
								rotateLeft(elem);
								elem = tmp;
							}
							elem->parent->color = black;
							if (elem->parent->parent)
								elem->parent->parent->color = red;
							rotateRight(elem->parent);
						}
					} else {
						if (elem->parent->parent && elem->parent->parent->left && elem->parent->parent->left->color == red) {
							elem->parent->parent->left->color = black;
							elem->parent->color = black;
							elem->parent->parent->color = red;
							elem = elem->parent->parent;
						} else {
							if (elem == elem->parent->left) {
								node *tmp = elem->parent;
								rotateRight(elem);
								elem = tmp;
							}
							elem->parent->color = black;
							if (elem->parent->parent)
								elem->parent->parent->color = red;
							rotateLeft(elem->parent);
						}
					}
					if (elem == root)
						break;
				}
				root->color = black;
			}

			void transplant(node *u, node *v) {
				if (u->parent == nullptr)
					root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				if (v)
					v->parent = u->parent;
			}

			node *maximum() {
				return (maximumRec(root));
			}

			node *maximumRec(node *start) {
				if (start->right)
					return (maximumRec(start->right));
				return (start);
			}

			node *minimum(node *root) {
				return (minimumRec(root));
			}

			node *minimumRec(node *start) {
				if (start->left)
					return (minimumRec(start->left));
				return (start);
			}

			void deleteElem(Pair data) {
				node *x;
				node *y;
				node *toDel = root;
				node *parent = NULL;
				Color saveColor;
				while (toDel != NULL) {
					if (toDel->data.first == data.first)
						break;
					if (!_comp(toDel->data.first, data.first))
						toDel = toDel->left;
					else
						toDel = toDel->right;
				}
				if (toDel == NULL)
					return;
				saveColor = toDel->color;
				if (toDel->left == NULL) {
					x = toDel->right;
					parent = toDel->parent;
					transplant(toDel, x);
				}
				else if (toDel->right == NULL) {
					x = toDel->left;
					parent = toDel->parent;
					transplant(toDel, x);
				}
				else {
					y = minimum(toDel->right);
					saveColor = y->color;
					x = y->right;
					if (y->parent == toDel)
						parent = y;
					else {
						parent = y->parent;
						transplant(y, y->right);
						y->right = toDel->right;
						y->right->parent = y;
					}
					transplant(toDel, y);
					y->left = toDel->left;
					y->left->parent = y;
					y->color = toDel->color;
				}
				ft_delete(toDel);
				if (saveColor == black && parent) {
					deleteFix(x, parent);
				}
			}

			bool isBlack(node *ptr) {
				return ((ptr == NULL) || (ptr && ptr->color == black));
			}

			void deleteFix(node* x, node * parent) {
				node *s;
				while (parent && x != root && isBlack(x)) {
					if (x == parent->left) {
						s = parent->right;
						if (s && s->color == red) {
							s->color = black;
							parent->color = red;
							rotateLeft(s);
							s = parent->right;
						}
						if (s && isBlack(s->left) && isBlack(s->right)) {
							s->color = red;
							x = parent;
							parent = parent->parent;
						} else {
							if (s && isBlack(s->right)) {
								if (s->left)
									s->left->color = black;
								s->color = red;
								rotateRight(s->left);
								s = parent->right;
							}
							if (s)
								s->color = parent->color;
							parent->color = black;
							if (s && s->right)
								s->right->color = black;
							rotateLeft(parent->right);
							x = root;
						}
					} else {
						s = parent->left;
						if (s && s->color == red) {
							s->color = black;
							parent->color = red;
							rotateRight(s);
							s = parent->left;
						}
						if (s && isBlack(s->left) && isBlack(s->right)) {
							s->color = red;
							x = parent;
							parent = parent->parent;
						} else {
							if (s && isBlack(s->left)) {
								if (s->right)
									s->right->color = black;
								s->color = red;
								rotateLeft(s->right);
								s = parent->left;
							}
							if (s)
								s->color = parent->color;
							parent->color = black;
							if (s && s->left)
								s->left->color = black;
							rotateRight(parent->left);
							x = root;
						}
					}
				}
				if (x)
					x->color = black;
			}

			void display(void) {
				displayTree(root, "", true);
			}

			void displayTree(node *root, std::string indent, bool last) {
				if (root != NULL) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "   ";
					} else {
						std::cout << "L----";
						indent += "|  ";
					}
					std::string sColor = root->color ? REDC : BLACKC; //цвета
					std::cout << sColor << root->data.first << RESETC << std::endl;
					displayTree(root->left, indent, false);
					displayTree(root->right, indent, true);
				}
			}

			void ft_delete(node *toDel) {
				_alloc.destroy(toDel);
				_alloc.deallocate(toDel, 1);
			}
			void deleteTree(node *root) {
				if (root == NULL)
					return;
				deleteTree(root->left);
				deleteTree(root->right);
				ft_delete(root);
				root = NULL;
			}

			void rotateLeft(node *elem) {
				if (elem == NULL || elem->parent == NULL || elem->parent->left == elem)
					return;
				node *parentElem = elem->parent;
				node *gparentElem = elem->parent->parent;
				parentElem->right = elem->left;
				if (elem->left) {
					elem->left->parent = parentElem;
					elem->left = NULL;
				}
				elem->parent = gparentElem;
				if (gparentElem == NULL)
					root = elem;
				else if (gparentElem->left == parentElem)
					gparentElem->left = elem;
				else
					gparentElem->right = elem;
				elem->left = parentElem;
				parentElem->parent = elem;
			}

			void rotateRight(node *elem) {
				if (elem == NULL || elem->parent == NULL || elem->parent->right == elem)
					return;
				node *parentElem = elem->parent;
				node *gparentElem = elem->parent->parent;
				parentElem->left = elem->right;
				if (elem->right) {
					elem->right->parent = parentElem;
					elem->right = NULL;
				}
				elem->parent = gparentElem;
				if (gparentElem == NULL)
					root = elem;
				else if (gparentElem->left == parentElem)
					gparentElem->left = elem;
				else
					gparentElem->right = elem;
				elem->right = parentElem;
				parentElem->parent = elem;
			}
	};
}

#endif
