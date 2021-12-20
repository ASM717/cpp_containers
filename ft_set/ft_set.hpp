#ifndef FT_SET_HPP
#define FT_SET_HPP

#include <iostream>
#include "../ft_map/ft_node.hpp"
#include "../ft_vector/ft_algorithm.hpp"
#include "ft_set_iterator.hpp"
#include "../ft_map/ft_pair.hpp"
#include "../ft_vector/ft_iterator_utils.hpp"
#include "ft_set_reverse_iterator.hpp"
//#include "../ft_vector/ft_vector_reverse_iterator.hpp"

namespace ft {
	template< class Key,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<Key>
	> class set {
	public:
		typedef Key                                                 value_type;
//        typedef Key key_type;
		typedef Compare                                             key_compare;
		typedef ft::Node<value_type>                                node;
		typedef typename Allocator::template rebind<node>::other    allocator_type;
		typedef typename Allocator::reference			            reference;
		typedef typename Allocator::const_reference	                const_reference;
		typedef typename Allocator::pointer                         pointer;
		typedef typename Allocator::const_pointer		            const_pointer;

		typedef ft::SetIterator<value_type>                         iterator;
		typedef ft::ConstSetIterator<const value_type>              const_iterator;
		typedef ft::ReverseSetIterator<value_type>                  reverse_iterator;
		typedef ft::ConstReverseSetIterator<const value_type>       const_reverse_iterator;
		typedef ptrdiff_t								            difference_type;
		typedef size_t									            size_type;

		class value_compare : public std::binary_function <value_type, value_type, bool> {
		public:
			Compare	comp;
			value_compare (Compare c): comp(c) {}

			typedef	bool		result_type;
			typedef	value_type	first_argument_type;
			typedef	value_type	second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const {
				return (comp(x.first, y.first));
			}
		};

	private:
		node				*root_tree;
		node				*last_elem;
		node				*elem;
		Compare				m_compare;
		allocator_type 		m_alloc;
		size_type			m_size;

	public:
		node *getRootTree() const {
			return (root_tree);
		}

		node *getLastElem() const {
			return (last_elem);
		}

		node *getElem() const {
			return (elem);
		}

		Compare getMCompare() const {
			return (m_compare);
		}

		allocator_type getMAlloc() const {
			return (m_alloc);
		}

		size_type getMSize() const {
			return (m_size);
		}

	public:
		set() : root_tree(NULL), last_elem(NULL), elem(NULL), m_compare(std::less<Key >()),
				m_alloc(std::allocator<node>()), m_size(0) {}

		explicit set(value_type value) : root_tree(m_alloc.allocate(1)), last_elem(NULL),
		elem(NULL), m_compare(std::less<Key >()), m_alloc(std::allocator<node>()), m_size(0) {
			m_alloc.construct(root_tree, node(value));
			root_tree->color = BLACK;
		}

		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
		const allocator_type alloc = allocator_type()) : m_alloc(alloc), m_compare(comp), m_size(0), elem(NULL),
		root_tree(m_alloc.allocate(1), m_compare = std::less<Key >()) {
			last = NULL;
			insert(first, last);
		};

		set(const set &ref) : m_alloc(ref.m_alloc), m_size(0), last_elem(NULL),
							  root_tree(NULL), elem(NULL), m_compare(std::less<Key >()) {
			*this = ref;
		}

		~set() {
			freeTree(root_tree);
		}

		set &operator=(const set &ref) {
			if (ref.getRootTree() == NULL || this == &ref)
				return (*this);
			freeTree(this->getRootTree());
			copyElement(ref.getRootTree());
			return (*this);
		}

		iterator begin() {
			if(this->getRootTree() != NULL)
				return(iterator(min(this->getRootTree())));
			return(NULL);
		}
		const_iterator begin() const {
//			node *tmp = getRootTree();
//			if (!tmp->left && !tmp->right)
//				return (end());
//			if (!tmp->left && tmp->right)
//				tmp = tmp->right;
//			while (tmp->left)
//				tmp = tmp->left;
//			return (const_iterator(tmp));

            if(this->getRootTree() != NULL)
                return(const_iterator(min(this->getRootTree())));
            return(NULL);
		}

		iterator end() {
			return(iterator(this->getLastElem()));
		}

		const_iterator end() const {
			return(const_iterator(this->getLastElem()));
		}

		reverse_iterator rbegin() {
			iterator i = end();
			i--;
            //std::cout << i.node()->data << std::endl;
			return (reverse_iterator(i.node()));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(rbegin()));
		}

		reverse_iterator rend() {
//            std::cout << this->getRootTree()->data << std::endl;
			return (reverse_iterator(this->getRootTree()));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(this->getRootTree()));
		}

		bool empty() const {
			if (this->getRootTree() == NULL)
				return (true);
			return (false);
		}

		size_type size() const {
			return (this->getMSize());
		}

		size_type max_size() const {
//			return (std::numeric_limits<size_type>::max() / (sizeof(node)));
			return (this->getMAlloc().max_size());
		}

		pair<iterator, bool> insert (const value_type& val) {
			iterator tmp = insert_for_map_func(val);
			return (ft::make_pair(tmp, true));
		}

		iterator insert (iterator position, const value_type& val) {
			iterator tmp = insert_for_map_func(val);
			if (position)
				return (tmp);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			for (; first != last; ++first)
				insert(*first);
		}

		void erase (iterator position) {
			deleteElementTree(*position);
			if (this->getMSize() != 0)
				--m_size;
		}

		size_type erase (const value_type& val) {
			iterator iter;

			iter = find(val);
			if (iter != end()) {
				erase(iter);
				return (true);
			}
			return (false);
		}

		void erase (iterator first, iterator last) {
			while (first != last)
				erase(first++);
			if (this->getMSize() == 0)
				erase(last);
		}

		void swap (set &ref) {
			ft::swap(root_tree, ref.root_tree);
			ft::swap(last_elem, ref.last_elem);
			ft::swap(elem, ref.elem);
			ft::swap(m_compare, ref.m_compare);
			ft::swap(m_alloc, ref.m_alloc);
			ft::swap(m_size, ref.m_size);
		}

		void clear() {
			erase(begin(), end());
		}

		key_compare key_comp() const {
			return (this->getMCompare());
		}

		value_compare value_comp() const {
			return (value_compare(getMCompare()));
		}

		iterator find (const value_type& val) const{
			if (empty())
				return (end());
			node *tmp = find_need_elem(val, this->getRootTree());
			if (tmp == NULL)
				return (end());
			return (iterator(tmp));
		}

//		size_type count (const value_type& val) const {
//			size_type counter = 0;
//
//			for (iterator iter = begin(); iter != end(); ++iter) {
//				if (iter.node()->data == val)
//					++counter;
//			}
//			return (counter);


//			iterator it = find(val);
//			return (it == end() ? 0 : 1);
//		}

		iterator lower_bound (const value_type& val) const {
			for (iterator iter = begin(); iter != end(); ++iter) {
				if (this->m_compare(iter->first, val) <= 0)
					return (iter);
			}
			return (end());
		}

		iterator upper_bound (const value_type& val) const {
			for (iterator iter = begin(); iter != end(); ++iter) {
				if (iter->first != val && this->m_compare(iter->first, val) <= 0)
					return (iter);
			}
			return (end());
		}

		pair<iterator, iterator> equal_range (const value_type& val) const {
			return (ft::pair<iterator, iterator>(lower_bound(val), upper_bound(val)));
		}

		allocator_type get_allocator() const {
			return (this->getMAlloc());
		}

	private:
		node *find_need_elem(Key key, node *entry_pos) {
			if (entry_pos == NULL)
				return (NULL);
			else if (key == entry_pos->data)
				return (entry_pos);
			else if (m_compare(key, entry_pos->data))
				return (find_need_elem(key, entry_pos->left));
			else
				return (find_need_elem(key, entry_pos->right));
		}

		bool toPass(value_type data, node *entry_pos) {
			if (entry_pos == NULL)
				return(true);
			else if (data == entry_pos->data)
				return (false);
			else if (m_compare(data, entry_pos->data))
				return (toPass(data, entry_pos->left));
			else
				return (toPass(data, entry_pos->right));
		}

		node *keyFound(value_type data, node *entry_pos) {
			if (entry_pos == NULL)
				return (NULL);
			else if (data == entry_pos->data)
				return (entry_pos);
			else if (m_compare(data, entry_pos->data))
				return (keyFound(data, entry_pos->left));
			else
				return (keyFound(data, entry_pos->right));
		}

		node *creationElement(const value_type data) {
			elem = this->getMAlloc().allocate(1);
			this->getMAlloc().construct(this->getElem(), node(data));
			return (this->getElem());
		}

		void copyElement(node *copy) {
			if (copy == NULL)
				return ;
			insertElement(creationElement(copy->data), this->getRootTree());
			copyElement(copy->right);
			copyElement(copy->left);
		}

		void *insert_1(node *node_elem) {
			root_tree = node_elem;
			last_elem = this->getMAlloc().allocate(1);
			this->getMAlloc().construct(this->getLastElem(), node(node_elem->data));
			this->getRootTree()->right = last_elem;
			this->getLastElem()->parent = root_tree;
			return (this->getRootTree());
		}

		void *insert_2(node *node_elem, node *entry_pos, node *tmp) {
			if (entry_pos->left)
				insertElement(node_elem, entry_pos->left);
			else {
				node_elem->parent = entry_pos;
				entry_pos->left = node_elem;
				insert_node_fix(node_elem);
				this->getLastElem()->parent = tmp;
				tmp->right = last_elem;
			}
			return (node_elem);
		}

		void *insert_3(node *node_elem, node *entry_pos, node *tmp) {
			node_elem->parent = entry_pos;
			entry_pos->right = node_elem;
			insert_node_fix(node_elem);
			if (node_elem->data > tmp->data) {
				node_elem->right = last_elem;
				this->getLastElem()->parent = node_elem;
			} else {
				tmp->right = last_elem;
				this->getLastElem()->parent = tmp;
			}
			return (node_elem);
		}

		node *insertElement(node *node_elem, node *entry_pos) {
			if (node_elem == NULL)
				return (NULL);
			if (entry_pos == NULL) {
				insert_1(node_elem);
			} else {
				node *tmp;
				tmp = this->getLastElem()->parent;
				tmp->right = NULL;
				if (m_compare(node_elem->data, entry_pos->data)) {
					insert_2(node_elem, entry_pos, tmp);
				} else if (node_elem->data == entry_pos->data) {
					this->getLastElem()->parent = tmp;
					tmp->right = last_elem;
					return (NULL);
				} else {
					if (entry_pos->right)
						insertElement(node_elem, entry_pos->right);
					else {
						insert_3(node_elem, entry_pos, tmp);
					}
				}
			}
			return (node_elem);
		}

		node *insert_for_map_func(value_type data) {
			if (toPass(data, this->getRootTree())) {
				m_size++;
				return (insertElement(creationElement(data), this->getRootTree()));
			}
			return (keyFound(data, this->getRootTree()));
		}

		void change(node *pNode, node *pNode2) {
			if (pNode->parent == NULL)
				root_tree = pNode2;
			else if (pNode == pNode->parent->left)
				pNode->parent->left = pNode2;
			else
				pNode->parent->right = pNode2;
			if (pNode2)
				pNode2->parent = pNode->parent;
		}

		void insert_node_fix_2(node *node_elem) {
			if (node_elem == node_elem->parent->right) {
				node *tmp = node_elem->parent;
				leftRotate(node_elem);
				node_elem = tmp;
			}
			node_elem->parent->color = BLACK;
			if (node_elem->parent->parent)
				node_elem->parent->parent->color = RED;
			rightRotate(node_elem->parent);
		}

		void insert_node_fix_1(node *node_elem) {
			node_elem->parent->parent->right->color = BLACK;
			node_elem->parent->color = BLACK;
			node_elem->parent->parent->color = RED;
			node_elem = node_elem->parent->parent;
		}

		void insert_node_fix(node *node_elem) {
			if (node_elem == NULL || node_elem->parent == NULL)
				return;
			while (node_elem->parent->color == RED) {
				if (node_elem->parent->parent && node_elem->parent == node_elem->parent->parent->left) {
					if (node_elem->parent->parent->right && node_elem->parent->parent->right->color == RED) {
						insert_node_fix_1(node_elem);
					} else {
						insert_node_fix_2(node_elem);
					}
				} else {
					if (node_elem->parent->parent && node_elem->parent->parent->left
						&& node_elem->parent->parent->left->color == RED) {
						node_elem->parent->parent->left->color = BLACK;
						node_elem->parent->color = BLACK;
						node_elem->parent->parent->color = RED;
						node_elem = node_elem->parent->parent;
					} else {
						if (node_elem == node_elem->parent->left) {
							node *tmp = node_elem->parent;
							rightRotate(node_elem);
							node_elem = tmp;
						}
						node_elem->parent->color = BLACK;
						if (node_elem->parent->parent)
							node_elem->parent->parent->color = RED;
						leftRotate(node_elem->parent);
					}
				}
				if (node_elem == root_tree)
					break;
			}
			getRootTree()->color = BLACK;
		}

		node *min(node *root) {
			return (recursiveMin(root));
		}

		node *recursiveMin(node *entry_pos) {
			if (entry_pos->left)
				return (recursiveMin(entry_pos->left));
			return (entry_pos);
		}

		void deleteElementTree(value_type data) {
			node *del = getRootTree();
			rb_tree_color rbTreeColor;
			node *parent = NULL;
			node *x;
			node *y;
			while (del != NULL) {
				if (del->data == data)
					break;
				if (!m_compare(del->data, data))
					del = del->left;
				else
					del = del->right;
			}
			if (del == NULL)
				return;
			rbTreeColor = del->color;
			if (del->left == NULL) {
				x = del->right;
				parent = del->parent;
				change(del, x);
			}
			else if (del->right == NULL) {
				x = del->left;
				parent = del->parent;
				change(del, x);
			}
			else {
				y = min(del->right);
				rbTreeColor = y->color;
				x = y->right;
				if (y->parent == del)
					parent = y;
				else {
					parent = y->parent;
					change(y, y->right);
					y->right = del->right;
					y->right->parent = y;
				}
				change(del, y);
				y->left = del->left;
				y->left->parent = y;
				y->color = del->color;
			}
			destroy_deallocate_tree(del);
			if (rbTreeColor == BLACK && parent) {
				delete_node_fix(x, parent);
			}
		}

		bool nodeIsBlack(node *ptr) {
			return ((ptr == NULL) || (ptr && ptr->color == BLACK));
		}

		void delete_node_fix(node* ptr, node *parent_elem) {
			node *nodik;
			while (parent_elem && ptr != root_tree && nodeIsBlack(ptr)) {
				if (ptr == parent_elem->left) {
					nodik = parent_elem->right;
					if (nodik && nodik->color == RED) {
						nodik->color = BLACK;
						parent_elem->color = RED;
						leftRotate(nodik);
						nodik = parent_elem->right;
					}
					if (nodik && nodeIsBlack(nodik->left) && nodeIsBlack(nodik->right)) {
						nodik->color = RED;
						ptr = parent_elem;
						parent_elem = parent_elem->parent;
					} else {
						if (nodik && nodeIsBlack(nodik->right)) {
							if (nodik->left)
								nodik->left->color = BLACK;
							nodik->color = RED;
							rightRotate(nodik->left);
							nodik = parent_elem->right;
						}
						if (nodik)
							nodik->color = parent_elem->color;
						parent_elem->color = BLACK;
						if (nodik && nodik->right)
							nodik->right->color = BLACK;
						leftRotate(parent_elem->right);
						ptr = root_tree;
					}
				} else {
					nodik = parent_elem->left;
					if (nodik && nodik->color == RED) {
						nodik->color = BLACK;
						parent_elem->color = RED;
						rightRotate(nodik);
						nodik = parent_elem->left;
					}
					if (nodik && nodeIsBlack(nodik->left) && nodeIsBlack(nodik->right)) {
						nodik->color = RED;
						ptr = parent_elem;
						parent_elem = parent_elem->parent;
					} else {
						if (nodik && nodeIsBlack(nodik->left)) {
							if (nodik->right)
								nodik->right->color = BLACK;
							nodik->color = RED;
							leftRotate(nodik->right);
							nodik = parent_elem->left;
						}
						if (nodik)
							nodik->color = parent_elem->color;
						parent_elem->color = BLACK;
						if (nodik && nodik->left)
							nodik->left->color = BLACK;
						rightRotate(parent_elem->left);
						ptr = root_tree;
					}
				}
			}
			if (ptr)
				ptr->color = BLACK;
		}

		void destroy_deallocate_tree(node *del) {
			m_alloc.destroy(del);
			m_alloc.deallocate(del, 1);
		}

		void freeTree(node *root) {
			if (root == NULL)
				return;
			freeTree(root->left);
			freeTree(root->right);
			destroy_deallocate_tree(root);
			root = (NULL);
		}

		void leftRotate(node *node_elem) {
			if (node_elem == NULL || node_elem->parent == NULL || node_elem->parent->left == node_elem)
				return;
			node *parent_element = node_elem->parent;
			node *grand_par_element = node_elem->parent->parent;
			parent_element->right = node_elem->left;
			if (node_elem->left) {
				node_elem->left->parent = parent_element;
				node_elem->left = NULL;
			}
			node_elem->parent = grand_par_element;
			if (grand_par_element == NULL)
				root_tree = node_elem;
			else if (grand_par_element->left == parent_element)
				grand_par_element->left = node_elem;
			else
				grand_par_element->right = node_elem;
			node_elem->left = parent_element;
			parent_element->parent = node_elem;
		}

		void rightRotate(node *node_elem) {
			if (node_elem->parent->right == node_elem ||
				node_elem == NULL || node_elem->parent == NULL)
				return;
			node *parent_element = node_elem->parent;
			node *grand_par_element = node_elem->parent->parent;
			parent_element->left = node_elem->right;
			if (node_elem->right) {
				node_elem->right->parent = parent_element;
				node_elem->right = NULL;
			}
			node_elem->parent = grand_par_element;
			if (grand_par_element == NULL)
				root_tree = node_elem;
			else if (grand_par_element->left == parent_element)
				grand_par_element->left = node_elem;
			else
				grand_par_element->right = node_elem;
			node_elem->right = parent_element;
			parent_element->parent = node_elem;
		}
	};

	template<class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key,Compare,Alloc>& lhs,
					 const ft::set<Key,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key,Compare,Alloc>& lhs,
					 const ft::set<Key,Compare,Alloc>& rhs) {
		return (!(lhs == rhs)) ? (true) : (false);
	}

	template<class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key,Compare,Alloc>& lhs,
					const ft::set<Key,Compare,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key,Compare,Alloc>& lhs,
					 const ft::set<Key,Compare,Alloc>& rhs) {
		return (lhs.size() <= rhs.size()) ? (true) : (false);
	}

	template<class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key,Compare,Alloc>& lhs,
					const ft::set<Key,Compare,Alloc>& rhs) {
		return (lhs.size() > rhs.size()) ? (true) : (false);
	}

	template<class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key,Compare,Alloc>& lhs,
					 const ft::set<Key,Compare,Alloc>& rhs) {
		return (lhs.size() >= rhs.size()) ? (true) : (false);
	}

	template<class Key, class Compare, class Alloc>
	void swap(ft::set<Key,Compare,Alloc>& lhs,
			   ft::set<Key,Compare,Alloc>& rhs) {
		lhs.swap(rhs);
	}
}

#endif