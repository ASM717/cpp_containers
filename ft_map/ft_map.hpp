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

class RBTree;

namespace ft {
	template <class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = ft::less<Key>,                     // map::key_compare
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
		typedef typename allocator_type::reference        reference;
		typedef typename allocator_type::const_reference  const_reference;
		typedef typename allocator_type::pointer          pointer;
		typedef typename allocator_type::const_pointer    const_pointer;
		typedef ft::Node<value_type>                      node_type;

		typedef ft::BidirectionalIterator<value_type, node_type>             iterator;
		typedef ft::BidirectionalIterator<const value_type, const node_type> const_iterator;
		typedef ft::VectorReverseIterator<iterator>                          reverse_iterator;
		typedef ft::VectorReverseIterator<const_iterator>                    const_reverse_iterator;

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
        allocator_type m_alloc;
        key_compare m_comp;
	public:
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : m_rbTree() {
            this->m_alloc = alloc;
            this->m_comp = comp;
		}

		//range constructor
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                : m_alloc(alloc), m_comp(comp), m_rbTree() {
			insert(first, last);
		}

		map (const map &ref) {
            insert(ref.begin(), ref.end()); //перепроверить
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

		~map() {}

		// iterator begin() {
		// 	return (iterator(rb_tree.min(), rb_tree.getRoot(), rb_tree.getNill()));
		// }
		// const_iterator begin() const {

		// }

		// iterator end() {

		// }
		// const_iterator end() const {

		// }

		// reverse_iterator rbegin() {

		// }
		// const_reverse_iterator rbegin() const {

		// }

		// reverse_iterator rend() {

		// }
		// const_reverse_iterator rend() const {

		// }

		// bool empty() const {

		// }

		// size_type size() const {

		// }

		// size_type max_size() const {

		// }

		// // https://www.cplusplus.com/reference/map/map/operator[]/
		// mapped_type& operator[] (const key_type& k) {

		// }

		// pair<iterator,bool> insert (const value_type& val) {

		// }

		// iterator insert (iterator position, const value_type& val) {

		// }

		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last) {

		// }

		// void erase (iterator position) {

		// }
		// size_type erase (const key_type& k) {

		// }
		// void erase (iterator first, iterator last) {

		// }

		// void swap (map& x) {

		// }

		// void clear() {

		// }

		// key_compare key_comp() const {

		// }

		// value_compare value_comp() const {

		// }

		// iterator find (const key_type& k) {

		// }
		// const_iterator find (const key_type& k) const {

		// }

		// size_type count (const key_type& k) const {

		// }

		// iterator lower_bound (const key_type& k) {

		// }

		// const_iterator lower_bound (const key_type& k) const {

		// }

		// iterator upper_bound (const key_type& k) {

		// }
		// const_iterator upper_bound (const key_type& k) const {

		// }

		// pair<const_iterator,const_iterator> equal_range (const key_type& k) const {

		// }
		// pair<iterator,iterator> equal_range (const key_type& k) {

		// }

		// allocator_type get_allocator() const {

		// }
	};
}

#endif
