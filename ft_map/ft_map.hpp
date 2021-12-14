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

#include "ft_pair.hpp"
#include "ft_less.hpp"
#include "ft_node.hpp"
#include "ft_bidirectional_iterator.hpp"
#include "../ft_vector/ft_vector_reverse_iterator.hpp"
#include "ft_red_black_tree.hpp"
#include "map_iter.hpp"

class RBTree;

namespace ft {
	template <class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Allocator = std::allocator<ft::pair<const Key,T> > // map::allocator_type
	> class map {
		typedef Key                                       key_type;
		typedef T                                         mapped_type;
		typedef ft::pair<const key_type, mapped_type>     value_type;
		typedef std::size_t                               size_type;
		typedef std::ptrdiff_t                            difference_type;
		typedef Compare                                   key_compare;
		//typedef Compare                                   value_compare;
		typedef Allocator                                 allocator_type;

		typedef ft::node<value_type>                      node_type;

		typedef ft::MapIterator<value_type, node_type>             iterator;
		typedef ft::MapIterator<const value_type, const node_type> const_iterator;
//		typedef ft::VectorReverseIterator<iterator>                          reverse_iterator;
//		typedef ft::VectorReverseIterator<const_iterator>                    const_reverse_iterator;

        typedef ft::RBTree<Key, T, Compare, Allocator> rb_tree;

	public:
		//typename Allocator = std::allocator<Pair>, typename Compare = ft::less<Key> >
		class value_compare {
			//key_compare m_key_compare;
		private:
			Compare m_value_compare;
		public:
			value_compare(const Compare &compare) {
				m_value_compare = compare;
			}
			bool operator() (const value_type &_x, const value_type &_y) const {
				return (m_value_compare(_x.first, _y.first));
			}
		};
	private:
        rb_tree m_rbTree;
//        allocator_type m_alloc;
        //key_compare m_comp;
//		value_compare m_value_comp;
		size_type m_size;
	public:
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : m_rbTree() {
//            this->m_alloc = alloc;
//            this->m_comp = comp;
			this->m_size = 0;
		}

		//range constructor
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                : m_rbTree() {
			insert(first, last);
		}

		map (const map &ref) : m_size(ref.m_size) {
            //insert(ref.begin(), ref.end()); //перепроверить
		}

		map &operator=(const map &ref) {
//            if(this != &ref)
//            {
//                clear();
//                m_alloc = ref._alloc;
//                m_comp = ref._comp;
//                this->insert(ref.begin(), ref.end());
//            }
//            return *this;
		}

		~map() {
			m_rbTree.deleteTree();
		}

		 iterator begin() {
			 if(m_rbTree.getRoot() != NULL)
				 return(iterator(m_rbTree.minimum(m_rbTree.getRoot())));
			 return(NULL);
//		 	return (iterator(m_rbTree.minimum(m_rbTree.getRoot())));
		 }
		 const_iterator begin() const {
			 if(m_rbTree.getRoot() != NULL)
				 return(const_iterator(m_rbTree.minimum(m_rbTree.getRoot())));
			 return(NULL);
//			return (const_iterator(m_rbTree.minimum(m_rbTree.getRoot())));
		 }

		 iterator end() {
//			 return (iterator(m_rbTree.maximum(m_rbTree.getRoot())));
			 return(iterator(m_rbTree.getLeft()));
		 }
		 const_iterator end() const {
//			 return (const_iterator(m_rbTree.maximum(m_rbTree.getRoot())));
			 return(const_iterator(m_rbTree.getLeft()));
		 }

		// reverse_iterator rbegin() {

		// }
		// const_reverse_iterator rbegin() const {

		// }

		// reverse_iterator rend() {

		// }
		// const_reverse_iterator rend() const {

		// }

		 bool empty() const {
			if (m_rbTree.getLeft() == 0)
				return (true);
			else (false);
		 }

		 size_type size() const {
			 return m_size;
		 }

		 size_type max_size() const {
			 return (m_rbTree._alloc.max_size());
			 // return (std::numeric_limits<size_type>::max() / (sizeof(node)));
		 }

		// // https://www.cplusplus.com/reference/map/map/operator[]/
		// mapped_type& operator[] (const key_type& k) {

		// }

		 pair<iterator,bool> insert (const value_type& val) {
			 bool boolVal = m_rbTree.insert(val);
			 iterator iter = find(val.first);
			 return (ft::pair<iterator, bool>(iter, boolVal));
		 }

		 iterator insert (iterator position, const value_type& val) {
			 iterator tmp = m_rbTree.insert(val);
			 if (position)
				 return (tmp);
			 return m_rbTree.insert(val).first;
		 }

		 template <class InputIterator>
		 void insert (InputIterator first, InputIterator last) {
			 while(first != last)
			 {
				 m_rbTree.insert(*(first++));
				 ++m_size;
			 }
		 }

		 void erase (iterator position) {
			m_rbTree.deleteElem(*position);
			if (m_size != 0) {
				--m_size;
			}
		 }

		 size_type erase (const key_type& k) {
			 iterator item;
			 item = m_rbTree.find(k);
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

		// void swap (map& x) {

		// }

		 void clear() {
			 erase(begin(), end());
			 m_size = 0;
		 }

		 key_compare key_comp() const {
			 return m_rbTree._comp;
		 }

		 iterator find (const key_type& k) {
			m_rbTree.find(k, m_rbTree.getRoot());

		 }
//
		 const_iterator find (const key_type& k) const {
			m_rbTree.find(k, m_rbTree.getRoot());
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
			 const_iterator it = begin();
			 while(it != end())
			 {
				 if (m_rbTree._comp((*it).first, k) == false)
					 break;
				 it++;
			 }
			 return (it);
		 }

		 const_iterator lower_bound (const key_type& k) const {
			 const_iterator it = begin();
			 while(it != end())
			 {
				 if (m_rbTree._comp((*it).first, k) == false)
					 break;
				 it++;
			 }
			 return (it);
		 }

		 iterator upper_bound (const key_type& k) {
			 iterator it = begin();
			 while(it != end())
			 {
				 if (m_rbTree._comp(k, (*it).first) == true)
					 break;
				 it++;
			 }
			 return (it);
		 }

		 const_iterator upper_bound (const key_type& k) const {
			 iterator it = begin();
			 while(it != end())
			 {
				 if (m_rbTree._comp(k, (*it).first) == true)
					 break;
				 it++;
			 }
			 return (it);
		 }

		 pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			 return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		 }
		 pair<iterator,iterator> equal_range (const key_type& k) {
			 return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		 }

		 allocator_type get_allocator() const {
			 return m_rbTree._alloc;
		 }
	};
}

#endif
