#ifndef MAP_ITER_HPP
#define MAP_ITER_HPP

#include "ft_pair.hpp"
#include "ft_node.hpp"

namespace ft {
	template <class K, class T>
	class MapIterator
	{
	public:
		typedef ft::pair<K, T> value_type;
		typedef ft::pair<K, T>& reference;
		typedef ft::node<value_type>* pointer;
	protected:
		pointer _ptr;
	private:
		pointer _successor(pointer ptr)
		{
			pointer next;
			if (!ptr->right)
			{
				next = ptr;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = ptr->right;
				while (next->left)
					next = next->left;
			}
			return (next);
		};
		pointer _predecessor(pointer ptr)
		{
			pointer next;

			if (!ptr->left)
			{
				next = ptr;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = ptr->left;
				while (next->right)
					next = next->right;
			}
			return (next);
		};
	public:
		MapIterator(void)
				: _ptr(0)
		{};
		MapIterator(const pointer ptr)
				: _ptr(ptr)
		{};
		MapIterator(const MapIterator &other)
		{
			*this = other;
		};
		MapIterator &operator=(const MapIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		pointer node(void)
		{
			return (_ptr);
		};
		value_type &operator*(void)
		{
			return (_ptr->value);
		};
		value_type *operator->(void)
		{
			return (&_ptr->value);
		};
		bool operator==(const MapIterator<K, T> &other)
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const MapIterator<K, T> &other)
		{
			return (!(*this == other));
		};
		MapIterator &operator++(void)
		{
			_ptr = _successor(_ptr);
			return (*this);
		};
		MapIterator &operator--(void)
		{
			_ptr = _predecessor(_ptr);
			return (*this);
		};
		MapIterator operator++(int)
		{
			MapIterator tmp(*this);
			this->operator++();
			return (tmp);
		};
		MapIterator operator--(int)
		{
			MapIterator tmp(*this);
			this->operator--();
			return (tmp);
		};
	};
}

#endif