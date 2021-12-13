#ifndef FT_MAP_HPP
#define FT_MAP_HPP


#include "bidirectional_iterator.hpp"
#include "rb_tree.hpp"

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
		typedef typename allocator_type::reference        reference;
		typedef typename allocator_type::const_reference  const_reference;
		typedef typename allocator_type::pointer          pointer;
		typedef typename allocator_type::const_pointer    const_pointer;
		typedef ft::node<value_type>                      node_type;

		typedef ft::BidirectionalIterator<value_type, node_type>             iterator;
		typedef ft::BidirectionalIterator<const value_type, const node_type> const_iterator;
//		typedef ft::VectorReverseIterator<iterator>                          reverse_iterator;
//		typedef ft::VectorReverseIterator<const_iterator>                    const_reverse_iterator;

		typedef ft::tree<Key, T, Compare, Allocator> rb_tree;

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
		size_type m_size;
	public:
		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) : m_rbTree() {
			this->m_alloc = alloc;
			this->m_comp = comp;
			this->m_size = 0;
		}

		//range constructor
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: m_alloc(alloc), m_comp(comp), m_rbTree() {
			insert(first, last);
		}

		map (const map &ref) {
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

		~map() {}

		iterator begin() {
			return (iterator(m_rbTree.minimum(m_rbTree.getRoot())));
		}
		const_iterator begin() const {
			return (const_iterator(m_rbTree.minimum(m_rbTree.getRoot())));
		}

		iterator end() {
			return (iterator(m_rbTree.maximum(m_rbTree.getRoot())));
		}
		const_iterator end() const {
			return (const_iterator(m_rbTree.maximum(m_rbTree.getRoot())));
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
			if (m_size == 0)
				return (true);
			else (false);
		}

		size_type size() const {
			return m_size;
		}

		size_type max_size() const {
			return (m_alloc.max_size());
		}

		// // https://www.cplusplus.com/reference/map/map/operator[]/
		// mapped_type& operator[] (const key_type& k) {

		// }

		pair<iterator,bool> insert (const value_type& val) {
			bool el = m_rbTree.insert(val);
			iterator iter = find(val.first);
			return (ft::pair<iterator, bool>(iter, el));
		}

		iterator insert (iterator position, const value_type& val) {
			return insert(val).first;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			while(first != last)
			{
				m_rbTree.insert(*(first++));
				m_size++;
			}
		}

		void erase (iterator position) {
			erase((*position).first);
		}

		size_type erase (const key_type& k) {
			if(m_rbTree.deleteElem(k))
				return (1);
			else return (0);
		}
		void erase (iterator first, iterator last) {
			while(first != last)
			{
				erase(first++);
				m_size--;
			}
		}

		// void swap (map& x) {

		// }

		void clear() {
			erase(begin(), end());
			m_size = 0;
		}

		key_compare key_comp() const {
			return m_comp;
		}

		value_compare value_comp() const {
			return m_comp;
		}

//		 iterator find (const key_type& k) {
//			m_rbTree.find(k);
//		 }
//
//		 const_iterator find (const key_type& k) const {
//			 m_rbTree.find(k);
//		 }

		// size_type count (const key_type& k) const {

		// }

		iterator lower_bound (const key_type& k) {
			const_iterator it = begin();
			while(it != end())
			{
				if (m_comp((*it).first, k) == false)
					break;
				it++;
			}
			return (it);
		}

		const_iterator lower_bound (const key_type& k) const {
			const_iterator it = begin();
			while(it != end())
			{
				if (m_comp((*it).first, k) == false)
					break;
				it++;
			}
			return (it);
		}

		iterator upper_bound (const key_type& k) {
			iterator it = begin();
			while(it != end())
			{
				if (m_comp(k, (*it).first) == true)
					break;
				it++;
			}
			return (it);
		}

		const_iterator upper_bound (const key_type& k) const {
			iterator it = begin();
			while(it != end())
			{
				if (m_comp(k, (*it).first) == true)
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
			return m_alloc;
		}
	};
}

#endif