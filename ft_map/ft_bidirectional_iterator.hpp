#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
#define FT_BIDIRECTIONAL_ITERATOR_HPP

#include "../ft_vector/ft_iterator_utils.hpp"

#define Col_RED		"\e[31m"
#define Col_BLACK	"\e[30m\e[47m"

// # include <type_traits>
namespace ft {

	//template <class Iterator, class Node>
	template <typename T, typename N>
	// : public ft::iterator<ft::bidirectional_iterator_tag>
	class BidirectionalIterator {
		typedef T value_type;
		// typedef ft::Node<T>* pointer;
		// typedef T& reference;
		// typedef ft::Node<T>* const_pointer;
		// typedef T& const_reference;
		// typedef std::bidirectional_iterator_tag iterator_category;
		// typedef typename ft::iterator_traits<T>::difference_type difference_type;

		typedef typename ft::iterator_traits<T>::size_type size_type;
		typedef typename ft::iterator_traits<T>::pointer pointer;
		typedef typename ft::iterator_traits<T>::reference reference;
		typedef typename ft::iterator_traits<T>::const_reference const_reference;
		typedef typename ft::iterator_traits<T>::const_pointer const_pointer;
		typedef typename ft::iterator_traits<T>::difference_type difference_type;
		typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
		//typedef typename std::bidirectional_iterator_tag iterator_category;
		typedef N  node_type;
		typedef N* node_pointer;
	private:
		node_pointer node_point;
	public:
		BidirectionalIterator() : node_point(NULL) {}

		BidirectionalIterator(node_pointer ptr) : node_point(ptr) {}

		BidirectionalIterator(const BidirectionalIterator &ref) : node_point(ref.node_point) {}

		BidirectionalIterator &operator=(BidirectionalIterator const &ref)
		{
			if (this !=&ref)
			{
				node_point = ref.node_point;
			}
			return (*this);
		}

		// operator BidirectionalIterator<const value_type, const node_type>()const
		// {
		// 	return BidirectionalIterator<const value_type, const node_type>(_ptr, _root, _nill);
		// }

		virtual ~BidirectionalIterator(){} //destructor

		reference operator*() {
			return (node_point->data_node);
		}
		const_reference operator*() const {
			return (node_point->data_node);
		}
		pointer operator->() {
			return (&node_point->data_node);
		}
		const_pointer operator->() const {
			return (&node_point->data_node);
		}

		BidirectionalIterator operator++(int) {
			BidirectionalIterator tmp(*this);
			this->inc();
			return (tmp);
		}
		BidirectionalIterator &operator++() {
			this->inc();
			return (*this);
		}
		BidirectionalIterator operator--(int) {
			BidirectionalIterator tmp(*this);
			this->dec();
			return (tmp);
		}
		BidirectionalIterator &operator--() {
			this->dec();
			return (*this);
		}

		BidirectionalIterator operator+(int value) const {
			BidirectionalIterator tmp(*this);
			return (tmp += value);
		}

		BidirectionalIterator operator-(int value) const {
			BidirectionalIterator tmp(*this);
			return (tmp -= value);
		}

		bool operator==(BidirectionalIterator const &ref) const {
			return (this->node_point == ref.node_point);
		}
		bool operator!=(BidirectionalIterator const &ref) const {
			return (this->node_point != ref.node_point);
		}
		bool operator<(BidirectionalIterator const &ref) const {
			return (this->node_point < ref.node_point);
		}
		bool operator<=(BidirectionalIterator const &ref) const {
			return (this->node_point <= ref.node_point);
		}
		bool operator>(BidirectionalIterator const &ref) const {
			return (this->node_point > ref.node_point);
		}
		bool operator>=(BidirectionalIterator const &ref) const {
			return (this->node_point >= ref.node_point);
		}

		void dec() {
		if (this->node_point->m_left) {
			this->node_point = this->node_point->m_left;
			while (this->node_point->m_right)
				this->node_point = this->node_point->m_right;
		} else
			this->node_point = this->node_point->m_parent;
		}

		void inc() {
			if (this->node_point->m_right) {
				this->node_point = this->node_point->m_right;
				while (this->node_point->m_left)
					this->node_point = this->node_point->m_left;
			} else {
				pointer tmp = this->node_point;
				this->node_point = this->node_point->m_parent;
				while (this->node_point->m_left != tmp)
				{
					tmp = this->node_point;
					this->node_point = this->node_point->m_parent;
				}
			}
		}
	};
}

#endif
