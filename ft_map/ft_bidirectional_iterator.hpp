#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
#define FT_BIDIRECTIONAL_ITERATOR_HPP

#include "../ft_vector/ft_iterator_utils.hpp"

// # include <type_traits>
namespace ft {
	template <class T>
	struct Node
	{
		//typedef T value_type;

		int        color;
		value_type value_data;
		Node*      parent;
		Node*      left;
		Node*      right;

		Node() : value_data(value_type()) {}
		Node(const value_type &value) : value_data(value) {}
		Node(const Node &ref) : value_data(ref.value_data), parent(ref.parent), left(ref.left), right(ref.right), color(ref.color) {}
		~Node() {}

		Node &operator=(const Node& ref)
		{
			if (this != &ref)
			{
				value_data = ref.value_data;
				parent = ref.parent;
				left = ref.left;
				right = ref.right;
				color = ref.color;
			}
			return (*this);
		}
	};

	template <class Iterator, class Node>
	class BidirectionalIterator {
		typedef T value_type;
		typedef typename ft::iterator_traits<Iterator>::size_type size_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
		typedef typename ft::iterator_traits<Iterator>::const_reference const_reference;
		typedef typename ft::iterator_traits<Iterator>::const_pointer const_pointer;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		// typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		// typedef N  node_type;
		// typedef N* node_pointer;
	private:
		pointer node_pointer;
	public:
		BidirectionalIterator() : node_pointer(NULL) {}

		BidirectionalIterator(pointer ptr) {
			node_pointer(ptr);
		}

		template <class Iterator>
		BidirectionalIterator(const BidirectionalIterator<Iterator> &ref) {
			node_pointer = ref.node_pointer;
		}

		BidirectionalIterator& operator=(const BidirectionalIterator &ref) {
			if (this != &ref)
				node_pointer = ref.node_pointer;
			return (*this);
		}

		virtual ~BidirectionalIterator() {
			node_pointer = NULL;
		}

		reference operator*() {
			return (node_pointer->value_data);
		}
		const_reference operator*() const {
			return (node_pointer->value_data);
		}
		pointer operator->() {
			return (&node_pointer->value_data);
		}
		const_pointer operator->() const {
			return (&node_pointer->value_data);
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
		BidirectionalIterator &operator-=(int value) {
			operator+=(-value);
			return (*this);
		}
		BidirectionalIterator operator-(int value) const {
			BidirectionalIterator tmp(*this);
			return (tmp -= value);
		}

		bool operator==(BidirectionalIterator const &ref) const {
			return (this->node_pointer == ref.node_pointer);
		}
		bool operator!=(BidirectionalIterator const &ref) const {
			return (this->node_pointer != ref.node_pointer);
		}
		bool operator<(BidirectionalIterator const &ref) const {
			return (this->node_pointer < ref.node_pointer);
		}
		bool operator<=(BidirectionalIterator const &ref) const {
			return (this->node_pointer <= ref.node_pointer);
		}
		bool operator>(BidirectionalIterator const &ref) const {
			return (this->node_pointer > ref.node_pointer);
		}
		bool operator>=(BidirectionalIterator const &ref) const {
			return (this->node_pointer >= ref.node_pointer);
		}

		void dec() {
		if (this->node_pointer->left) {
			this->node_pointer = this->node_pointer->left;
			while (this->node_pointer->right)
				this->node_pointer = this->node_pointer->right;
		} else
			this->node_pointer = this->node_pointer->parent;
		}

		void inc() {
			if (this->node_pointer->right) {
				this->node_pointer = this->node_pointer->right;
				while (this->node_pointer->left)
					this->node_pointer = this->node_pointer->left;
			} else {
				pointer tmp = this->node_pointer;
				this->node_pointer = this->node_pointer->parent;
				while (this->node_pointer->left != tmp)
				{
					tmp = this->node_pointer;
					this->node_pointer = this->node_pointer->parent;
				}
			}
		}
	};
}

#endif
