/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:26 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/10 10:05:12 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <vector>
#include <iostream>
#include <limits>
//#include "../ft_vector/ft_iterator_utils.hpp"
#include "../ft_vector/ft_algorithm.hpp"
#include "ft_pair.hpp"
#include "ft_bidirectional_iterator.hpp"
#include "../ft_vector/ft_vector_reverse_iterator.hpp"

#define REDC		"\x1B[31m"
#define BLACKC		"\x1B[37m"
#define RESETC		"\x1B[0m"

namespace ft {
	template < typename Key, typename T,
			typename Compare = std::less<Key>,
			typename Allocator = std::allocator<pair<const Key,T> >
	> class map {
	public:
		typedef Key                                               key_type;
		typedef T                                                 mapped_type;
		typedef Compare                                           key_compare;
		typedef ft::pair<const Key, T>                            value_type;
		typedef ft::Node<value_type>                              node;
		typedef typename Allocator::template rebind<node>::other  allocator_type;
		typedef typename Allocator::reference			          reference;
		typedef typename Allocator::const_reference	              const_reference;
		typedef typename Allocator::pointer                       pointer;
		typedef typename Allocator::const_pointer		          const_pointer;
		typedef ft::BidirectionalIterator<const Key, T>           iterator;
		typedef ft::ConstBidirectionalIterator<const Key, T>      const_iterator;
		typedef ft::VectorReverseIterator<iterator>               reverse_iterator;
		typedef ft::VectorReverseIterator<const_iterator>         const_reverse_iterator;
		typedef ptrdiff_t								          difference_type;
		typedef size_t									          size_type;


		class value_compare: public std::binary_function <value_type, value_type, bool> {
		protected:
			Compare	comp;
			value_compare (Compare c): comp(c) {}
		public:
			typedef	bool		result_type;
			typedef	value_type	first_argument_type;
			typedef	value_type	second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const {
				return (comp(x.first, y.first));
			}
		};

	private:
		node				*root;
		node				*last;
		node				*elem;
		Compare				m_compare;
		allocator_type 		m_alloc;
		size_type			m_size;
		int					_flag;

	public:

		map() : root(NULL), last(NULL), elem(NULL), m_compare(std::less<Key >()),
			m_alloc(std::allocator<node>()), m_size(0), _flag(0) {}

		explicit map(value_type value) : root(m_alloc.allocate(1)), last(NULL), elem(NULL), m_compare(std::less<Key >()),
			m_alloc(std::allocator<node>()), m_size(0), _flag(0) {
			m_alloc.construct(root, node(value));
			root->color = BLACK;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
			const allocator_type alloc = allocator_type()) : m_alloc(alloc), m_compare(comp) {
			m_size = 0;
			last = NULL;
			_flag = 0;
			root = m_alloc.allocate(1);
			elem = NULL;
			m_compare = std::less<Key >();
			insert(first, last);
		};

		map(const map& val) : m_alloc(val.m_alloc), m_size(0), last(NULL),
							  root(NULL), _flag(0), elem(NULL), m_compare(std::less<Key >()) {
			*this = val;
		}

		~map () {
			deleteTree(root);
		}

		map& operator=(const map& val) {
			if (val.root == NULL || this == &val)
				return (*this);
			deleteTree(root);
			copyElem(val.root);
			return (*this);
		}

		iterator begin() {
			if(this->root != NULL)
				return(iterator(minimum(this->root)));
			return(NULL);
//		 	return (iterator(minimum(getRoot())));
		}
		const_iterator begin() const {
//			if(this->root != NULL)
//				return(const_iterator(minimum(this->root)));
//			return(NULL);
			node *tmp = root;
			if (!tmp->left && !tmp->right)
				return (end());
			if (!tmp->left && tmp->right)
				tmp = tmp->right;
			while (tmp->left)
				tmp = tmp->left;
			return (const_iterator(tmp));
		}

		iterator end() {
			return(iterator(this->last));
		}
		const_iterator end() const {
			return(const_iterator(this->last));
		}

		// reverse_iterator rbegin() {
		// 	return reverse_iterator(this->last);
		// }
		// const_reverse_iterator rbegin() const {
		// 	return const_reverse_iterator(this->last);
		// }

		// reverse_iterator rend() {

		// }
		// const_reverse_iterator rend() const {

		// }

		bool empty() const {
			if (root == NULL)
				return (true);
			return (false);
		}

		size_type size() const {
			return (m_size);
		}

		size_type max_size() const {
			return (std::numeric_limits<size_type>::max() / (sizeof(node)));
		}

		// // https://www.cplusplus.com/reference/map/map/operator[]/
		mapped_type& operator[] (const key_type& k) {
			if(!this->root) {
				ft::pair<key_type, mapped_type> tmp_pair;
				tmp_pair.first = k;
				node *tmp = _insert(tmp_pair);
//				m_size++;
				return(tmp->data.second);
			} else {
				node *tmp = _find(k, this->root);
				if(!tmp)
				{
					ft::pair<key_type, mapped_type> tmp_pair;
					tmp_pair.first = k;
					tmp = _insert(tmp_pair);
//					m_size++;
					return(tmp->data.second);
				}
				return (tmp->data.second);
			}
		}

		pair<iterator, bool> insert (const value_type& val) {
			iterator tmp = _insert(val);
//			if (tmp != NULL && _flag == 0)
//				m_size++;
			_flag = 0;
			return (ft::make_pair(tmp, true));
		}

		iterator insert (iterator position, const value_type& val) {
			iterator tmp = _insert(val);
			if (position)
				return (tmp);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		void erase (iterator position) {
			deleteElem(*position);
			if (m_size != 0)
				--m_size;
		}

		size_type erase (const key_type& k) {
			iterator 		item;

			item = find(k);
			if (item != end())
			{
				erase(item);
				return (1);
			}
			return (0);
		}
		void erase (iterator first, iterator last) {
			while (first != last)
				erase(first++);
			if (m_size == 0)
				erase(last);
		}

		void swap (map& x) {
			ft::swap(root, x.root);
			ft::swap(elem, x.elem);
			ft::swap(last, x.last);
			ft::swap(m_compare, x.m_compare);
			ft::swap(m_alloc, x.m_alloc);
			ft::swap(m_size, x.m_size);
			ft::swap(_flag, x._flag);
		}

		void clear() {
			erase(begin(), end());
		}

		key_compare key_comp() const {
			return (m_compare);
		}

		value_compare value_comp() const {
			return (this->value_compare);
		}

		iterator find (const key_type& k) {
			if (empty())
				return (end());
			node *tmp = _find(k, root);
			if (tmp == NULL)
				return (end());
			return (iterator(tmp));
		}

		const_iterator find (const key_type& k) const {
			if (empty())
				return (end());
			node *tmp = _find(k, root);
			if (tmp == NULL)
				return (end());
			return (const_iterator(tmp));
		}

		size_type count (const key_type& k) const {
			size_t c = 0;
			const_iterator it = begin();

			while (it != end())
			{
				if (it->first == k)
					++c;
				++it;
			}
			return (c);
		}

		iterator lower_bound (const key_type& k) {
			iterator it = begin();
			while (it != end())
			{
				if (this->m_compare(it->first, k) <= 0)
					return (it);
				++it;
			}
			return (end());
		}

		const_iterator lower_bound (const key_type& k) const {
			const_iterator it = begin();
			while (it != end())
			{
				if (this->m_compare(it->first, k) <= 0)
					return (it);
				++it;
			}
			return (end());
		}

		iterator upper_bound (const key_type& k) {
			iterator it = begin();

			while (it != end())
			{
				if (it->first != k && this->m_compare(it->first, k) <= 0)
					return (it);
				++it;
			};
			return (end());
		}

		const_iterator upper_bound (const key_type& k) const {
			const_iterator it = begin();
			while (it != end())
			{
				if (it->first != k && this->m_compare(it->first, k) <= 0)
					return (it);
				++it;
			};
			return (end());
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}
		pair<iterator,iterator> equal_range (const key_type& k) {
			return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}

		allocator_type get_allocator() const {
			return (m_alloc);
		}
		// RED BLACK TREE FUNC //

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
				std::string sColor = root->color ? REDC : BLACKC;
				std::cout << sColor << root->data.first << RESETC << std::endl;
				displayTree(root->left, indent, false);
				displayTree(root->right, indent, true);
			}
		}

	private:
		node *_find(Key key, node *start){
			if (start == NULL)
				return (NULL);
			else if (key == start->data.first)
				return (start);
			else if (m_compare(key, start->data.first))
				return (_find(key, start->left));
			else
				return (_find(key, start->right));
		}

		bool notExist(value_type data, node *start){
			if (start == NULL)
				return(true);
			else if (data.first == start->data.first)
				return (false);
			else if (m_compare(data.first, start->data.first))
				return (notExist(data, start->left));
			else
				return (notExist(data, start->right));
		}

		node *findKey(value_type data, node *start) {
			if (start == NULL)
				return (NULL);
			else if (data.first == start->data.first)
				return (start);
			else if (m_compare(data.first, start->data.first))
				return (findKey(data, start->left));
			else
				return (findKey(data, start->right));
		}

		node *createElem(const value_type data) {
			elem = m_alloc.allocate(1);
			m_alloc.construct(elem, node(data));
			return (elem);
		}

		void copyElem(node *toCopy) {
			if (toCopy == NULL)
				return ;
			insertElem(createElem(toCopy->data), root);
			copyElem(toCopy->right);
			copyElem(toCopy->left);
		}
		node *insertElem(node *elem, node *start) {

			if (elem == NULL) {
				return (NULL);
			}
			if (start == NULL) {
				root = elem;
				last = m_alloc.allocate(1);
				m_alloc.construct(last, node(elem->data));
				root->right = last;
				last->parent = root;
				return (root);
			} else {
				node *tmp;
				tmp = last->parent;
				tmp->right = NULL;
				if (m_compare(elem->data.first, start->data.first))
				{
					if (start->left)
						insertElem(elem, start->left);
					else
					{
						elem->parent = start;
						start->left = elem;
						insertFix(elem);


						last->parent = tmp;
						tmp->right = last;
					}
				} else if (elem->data.first == start->data.first) {
					last->parent = tmp;
					tmp->right = last;
					return (NULL);
				} else {
					if (start->right)
						insertElem(elem, start->right);
					else {
						elem->parent = start;
						start->right = elem;
						insertFix(elem);
						if (elem->data.first > tmp->data.first) {
							elem->right = last;
							last->parent = elem;
						} else {
							tmp->right = last;
							last->parent = tmp;
						}
					}
				}
			}
			return (elem);
		}

		node *_insert(value_type data) {
			if (notExist(data, root)) {
				m_size++;
				return (insertElem(createElem(data), root));
			}

			return (findKey(data, root));
		}

		void insertFix(node *elem) {
			if (elem == NULL || elem->parent == NULL)
				return;
			while (elem->parent->color == RED) {
				if (elem->parent->parent && elem->parent == elem->parent->parent->left) {
					if (elem->parent->parent->right && elem->parent->parent->right->color == RED) {
						elem->parent->parent->right->color = BLACK;
						elem->parent->color = BLACK;
						elem->parent->parent->color = RED;
						elem = elem->parent->parent;
					} else {
						if (elem == elem->parent->right) {
							node *tmp = elem->parent;
							rotateLeft(elem);
							elem = tmp;
						}
						elem->parent->color = BLACK;
						if (elem->parent->parent)
							elem->parent->parent->color = RED;
						rotateRight(elem->parent);
					}
				} else {
					if (elem->parent->parent && elem->parent->parent->left && elem->parent->parent->left->color == RED) {
						elem->parent->parent->left->color = BLACK;
						elem->parent->color = BLACK;
						elem->parent->parent->color = RED;
						elem = elem->parent->parent;
					} else {
						if (elem == elem->parent->left) {
							node *tmp = elem->parent;
							rotateRight(elem);
							elem = tmp;
						}
						elem->parent->color = BLACK;
						if (elem->parent->parent)
							elem->parent->parent->color = RED;
						rotateLeft(elem->parent);
					}
				}
				if (elem == root)
					break;
			}
			root->color = BLACK;
		}
		void transplant(node *u, node *v) {
			if (u->parent == NULL)
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

		void deleteElem(value_type data) {
			node *x;
			node *y;
			node *toDel = root;
			node *parent = NULL;
			rb_tree_color saveColor;
			while (toDel != NULL) {
				if (toDel->data.first == data.first)
					break;
				if (!m_compare(toDel->data.first, data.first))
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
			if (saveColor == BLACK && parent) {
				deleteFix(x, parent);
			}
		}

		bool isBlack(node *ptr) {
			return ((ptr == NULL) || (ptr && ptr->color == BLACK));
		}

		void deleteFix(node* x, node *parent) {
			node *s;
			while (parent && x != root && isBlack(x)) {
				if (x == parent->left) {
					s = parent->right;
					if (s && s->color == RED) {
						s->color = BLACK;
						parent->color = RED;
						rotateLeft(s);
						s = parent->right;
					}
					if (s && isBlack(s->left) && isBlack(s->right)) {
						s->color = RED;
						x = parent;
						parent = parent->parent;
					} else {
						if (s && isBlack(s->right)) {
							if (s->left)
								s->left->color = BLACK;
							s->color = RED;
							rotateRight(s->left);
							s = parent->right;
						}
						if (s)
							s->color = parent->color;
						parent->color = BLACK;
						if (s && s->right)
							s->right->color = BLACK;
						rotateLeft(parent->right);
						x = root;
					}
				} else {
					s = parent->left;
					if (s && s->color == RED) {
						s->color = BLACK;
						parent->color = RED;
						rotateRight(s);
						s = parent->left;
					}
					if (s && isBlack(s->left) && isBlack(s->right)) {
						s->color = RED;
						x = parent;
						parent = parent->parent;
					} else {
						if (s && isBlack(s->left)) {
							if (s->right)
								s->right->color = BLACK;
							s->color = RED;
							rotateLeft(s->right);
							s = parent->left;
						}
						if (s)
							s->color = parent->color;
						parent->color = BLACK;
						if (s && s->left)
							s->left->color = BLACK;
						rotateRight(parent->left);
						x = root;
					}
				}
			}
			if (x)
				x->color = BLACK;
		}

		void ft_delete(node *toDel) {
			m_alloc.destroy(toDel);
			m_alloc.deallocate(toDel, 1);
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

	template<class Key, class T, class Compare, class Allocator>
	bool operator==(const ft::map<Key,T,Compare,Allocator>& lhs,
					 const ft::map<Key,T,Compare,Allocator>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		size_t i = 0;
		while (i < lhs.size())
		{
			if (lhs[i] != rhs[i])
				return (false);
			i++;
		}
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator!=(const ft::map<Key,T,Compare,Allocator>& lhs,
					 const ft::map<Key,T,Compare,Allocator>& rhs) {
		return (!(lhs == rhs)) ? true : false;
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator<(const ft::map<Key,T,Compare,Allocator>& lhs,
					const ft::map<Key,T,Compare,Allocator>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator<=(const ft::map<Key,T,Compare,Allocator>& lhs,
					 const ft::map<Key,T,Compare,Allocator>& rhs) {
		return (lhs.size() <= rhs.size()) ? true : false;
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator>(const ft::map<Key,T,Compare,Allocator>& lhs,
					const ft::map<Key,T,Compare,Allocator>& rhs) {
		return (lhs.size() > rhs.size()) ? true : false;
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator>=(const ft::map<Key,T,Compare,Allocator>& lhs,
					 const ft::map<Key,T,Compare,Allocator>& rhs) {
		return (lhs.size() >= rhs.size()) ? true : false;
	}

	template<class Key, class T, class Compare, class Allocator>
	void swap(ft::map<Key,T,Compare,Allocator>& lhs,
			   ft::map<Key,T,Compare,Allocator>& rhs) {
		lhs.swap(rhs);
	}

}

#endif