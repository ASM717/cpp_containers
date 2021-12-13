/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bidirectional_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:14 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 14:02:15 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
#define FT_BIDIRECTIONAL_ITERATOR_HPP

#include "../ft_vector/ft_iterator_utils.hpp"

#define Col_RED		"\e[31m"
#define Col_BLACK	"\e[30m\e[47m"

namespace ft {
	//template <class Iterator, class Node>
	template <typename T, typename N>
	// : public ft::iterator<ft::bidirectional_iterator_tag>
	class BidirectionalIterator {
//		typedef T value_type;
//		typedef typename ft::iterator_traits<T>::size_type size_type;
//		typedef typename ft::iterator_traits<T>::pointer pointer;
//		typedef typename ft::iterator_traits<T>::reference reference;
//		typedef typename ft::iterator_traits<T>::const_reference const_reference;
//		typedef typename ft::iterator_traits<T>::const_pointer const_pointer;
//		typedef typename ft::iterator_traits<T>::difference_type difference_type;
//		typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
//		//typedef typename std::bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;

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
			return (node_point->data);
		}
//		const_reference operator*() const {
//			return (node_point->data);
//		}
		pointer operator->() {
			return (&node_point->data);
		}
//		const_pointer operator->() const {
//			return (&node_point->data);
//		}

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
		if (this->node_point->left) {
			this->node_point = this->node_point->left;
			while (this->node_point->right)
				this->node_point = this->node_point->right;
		} else
			this->node_point = this->node_point->parent;
		}

		void inc() {
			if (this->node_point->right) {
				this->node_point = this->node_point->right;
				while (this->node_point->left)
					this->node_point = this->node_point->left;
			} else {
				pointer tmp = this->node_point;
				this->node_point = this->node_point->parent;
				while (this->node_point->left != tmp)
				{
					tmp = this->node_point;
					this->node_point = this->node_point->parent;
				}
			}
		}
	};
}

#endif
