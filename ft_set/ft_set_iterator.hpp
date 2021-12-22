#ifndef FT_SET_ITERATOR_HPP
#define FT_SET_ITERATOR_HPP

#include "../ft_map/ft_node.hpp"

namespace ft {
	template<typename T>
	class SetIterator {
		typedef T value_type;
		typedef Node<value_type> *pointer;

	private:
		pointer node_pointer;

	public:
		SetIterator() : node_pointer(NULL) {};

		SetIterator(const pointer ptr) : node_pointer(ptr){};

		SetIterator(const SetIterator &ref) {*this = ref;}

		SetIterator &operator=(const SetIterator &ref) {
			node_pointer = ref.node_pointer;
			return (*this);
		}

		value_type &operator*() {
			return (node_pointer->data);
		}

		value_type *operator->() {
			return (&node_pointer->data);
		}

		bool operator==(const SetIterator<T> &ref) {
			return (node_pointer == ref.node_pointer);
		}

		bool operator!=(const SetIterator<T> &ref) {
			return (!(*this == ref));
		}

		SetIterator &operator++() {
			node_pointer = inc(node_pointer);
			return (*this);
		}

		SetIterator &operator--() {
			node_pointer = dec(node_pointer);
			return (*this);
		}

		SetIterator operator++(int) {
			SetIterator tmp(*this);
			this->operator++();
			return (tmp);
		}

		SetIterator operator--(int) {
			SetIterator tmp(*this);
			this->operator--();
			return (tmp);
		}

		pointer node_ptr()
		{
			return (node_pointer);
		}
	private:
		pointer inc(pointer ptr) {
			pointer nextPtr;
			if (!ptr->right)
			{
				nextPtr = ptr;
				while (nextPtr == nextPtr->parent->right && nextPtr->parent)
					nextPtr = nextPtr->parent;
				nextPtr = nextPtr->parent;
			} else {
				nextPtr = ptr->right;
				while (nextPtr->left)
					nextPtr = nextPtr->left;
			}
			return (nextPtr);
		}

		pointer dec(pointer ptr) {
			pointer prevPtr;
			if (!ptr->left) {
				prevPtr = ptr;
				while (prevPtr == prevPtr->parent->left && prevPtr->parent)
					prevPtr = prevPtr->parent;
				prevPtr = prevPtr->parent;
			} else {
				prevPtr = ptr->left;
				while (prevPtr->right)
					prevPtr = prevPtr->right;
			}
			return (prevPtr);
		}
	public:
		bool operator==(SetIterator const &ref) const {
			return (this->node_pointer == ref.node_pointer);
		}
		bool operator!=(SetIterator const &ref) const {
			return (this->node_pointer != ref.node_pointer);
		}
		bool operator<(SetIterator const &ref) const {
			return (this->node_pointer < ref.node_pointer);
		}
		bool operator<=(SetIterator const &ref) const {
			return (this->node_pointer <= ref.node_pointer);
		}
		bool operator>(SetIterator const &ref) const {
			return (this->node_pointer > ref.node_pointer);
		}
		bool operator>=(SetIterator const &ref) const {
			return (this->node_pointer >= ref.node_pointer);
		}
	};

	template<class T>
	class ConstSetIterator {
		typedef T value_type;
		typedef Node<value_type> *const_pointer;

	private:
        const_pointer node_pointer;

	public:
		ConstSetIterator() : node_pointer(NULL) {};

		ConstSetIterator(const const_pointer ptr) : node_pointer(ptr){};

		ConstSetIterator(const ConstSetIterator &ref) {*this = ref;}

		ConstSetIterator &operator=(const ConstSetIterator &ref) {
			node_pointer = ref.node_pointer;
			return (*this);
		}

		value_type &operator*() {
			return (node_pointer->data);
		}

		value_type *operator->() {
			return (&node_pointer->data);
		}

		bool operator==(const ConstSetIterator<T> &ref) {
			return (node_pointer == ref.node_pointer);
		}

		bool operator!=(const ConstSetIterator<T> &ref) {
			return (!(*this == ref));
		}

		ConstSetIterator &operator++() {
			node_pointer = inc(node_pointer);
			return (*this);
		}

		ConstSetIterator &operator--() {
			node_pointer = dec(node_pointer);
			return (*this);
		}

		ConstSetIterator operator++(int) {
			ConstSetIterator tmp(*this);
			this->operator++();
			return (tmp);
		}

		ConstSetIterator operator--(int) {
			ConstSetIterator tmp(*this);
			this->operator--();
			return (tmp);
		}

		const_pointer node_ptr()
		{
			return (node_pointer);
		}

	private:
		const_pointer inc(const_pointer ptr) {
			const_pointer nextPtr;
			if (!ptr->right)
			{
				nextPtr = ptr;
				while (nextPtr == nextPtr->parent->right && nextPtr->parent)
					nextPtr = nextPtr->parent;
				nextPtr = nextPtr->parent;
			} else {
				nextPtr = ptr->right;
				while (nextPtr->left)
					nextPtr = nextPtr->left;
			}
			return (nextPtr);
		}

		const_pointer dec(const_pointer ptr) {
			const_pointer prevPtr;
			if (!ptr->left) {
				prevPtr = ptr;
				while (prevPtr == prevPtr->parent->left && prevPtr->parent)
					prevPtr = prevPtr->parent;
				prevPtr = prevPtr->parent;
			} else {
				prevPtr = ptr->left;
				while (prevPtr->right)
					prevPtr = prevPtr->right;
			}
			return (prevPtr);
		}
	public:
		bool operator==(ConstSetIterator const &ref) const {
			return (this->node_pointer == ref.node_pointer);
		}
		bool operator!=(ConstSetIterator const &ref) const {
			return (this->node_pointer != ref.node_pointer);
		}
		bool operator<(ConstSetIterator const &ref) const {
			return (this->node_pointer < ref.node_pointer);
		}
		bool operator<=(ConstSetIterator const &ref) const {
			return (this->node_pointer <= ref.node_pointer);
		}
		bool operator>(ConstSetIterator const &ref) const {
			return (this->node_pointer > ref.node_pointer);
		}
		bool operator>=(ConstSetIterator const &ref) const {
			return (this->node_pointer >= ref.node_pointer);
		}
	};
}

#endif
