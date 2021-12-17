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
#include "../ft_vector/ft_type_traits.hpp"
#include "ft_pair.hpp"
#include "ft_node.hpp"


//namespace ft {
//	template <typename V, typename N>
//	class BidirectionalIterator {
//		typedef V value_type;
//		typedef V* pointer;
//		typedef V* const_pointer;
//		typedef V& reference;
//		typedef V& const_reference;
//		typedef N* node_pointer;
//	private:
//		node_pointer node_point;
//	public:
//		BidirectionalIterator() : node_point(NULL) {}
//
//		BidirectionalIterator(node_pointer ptr) : node_point(ptr) {}
//
//		BidirectionalIterator(const BidirectionalIterator &ref) : node_point(ref.node_point) {}
//
//		BidirectionalIterator &operator=(BidirectionalIterator const &ref)
//		{
//			if (this !=&ref)
//			{
//				node_point = ref.node_point;
//			}
//			return (*this);
//		}
//
//		virtual ~BidirectionalIterator(){} //destructor
//
//		reference operator*() {
//			return (node_point->data);
//		}
//		const_reference operator*() const {
//			return (node_point->data);
//		}
//		pointer operator->() {
//			return (&node_point->data);
//		}
//		const_pointer operator->() const {
//			return (&node_point->data);
//		}
//
//		BidirectionalIterator operator++(int) {
//			BidirectionalIterator tmp(*this);
//			this->inc();
//			return (tmp);
//		}
//		BidirectionalIterator &operator++() {
//			this->inc();
//			return (*this);
//		}
//		BidirectionalIterator operator--(int) {
//			BidirectionalIterator tmp(*this);
//			this->dec();
//			return (tmp);
//		}
//		BidirectionalIterator &operator--() {
//			this->dec();
//			return (*this);
//		}
//
//		BidirectionalIterator operator+(int value) const {
//			BidirectionalIterator tmp(*this);
//			return (tmp += value);
//		}
//
//		BidirectionalIterator operator-(int value) const {
//			BidirectionalIterator tmp(*this);
//			return (tmp -= value);
//		}
//
//		void dec() {
//		if (this->node_point->left) {
//			this->node_point = this->node_point->left;
//			while (this->node_point->right)
//				this->node_point = this->node_point->right;
//		} else
//			this->node_point = this->node_point->parent;
//		}
//
//		void inc() {
//			if (this->node_point->right) {
//				this->node_point = this->node_point->right;
//				while (this->node_point->left)
//					this->node_point = this->node_point->left;
//			} else {
//				pointer tmp = this->node_point;
//				this->node_point = this->node_point->parent;
//				while (this->node_point->left != tmp)
//				{
//					tmp = this->node_point;
//					this->node_point = this->node_point->parent;
//				}
//			}
//		}
//		bool operator==(BidirectionalIterator const &ref) const {
//			return (this->node_point == ref.node_point);
//		}
//		bool operator!=(BidirectionalIterator const &ref) const {
//			return (this->node_point != ref.node_point);
//		}
//		bool operator<(BidirectionalIterator const &ref) const {
//			return (this->node_point < ref.node_point);
//		}
//		bool operator<=(BidirectionalIterator const &ref) const {
//			return (this->node_point <= ref.node_point);
//		}
//		bool operator>(BidirectionalIterator const &ref) const {
//			return (this->node_point > ref.node_point);
//		}
//		bool operator>=(BidirectionalIterator const &ref) const {
//			return (this->node_point >= ref.node_point);
//		}
//	};
//}

namespace ft {
	template<class K, class T>
	class BidirectionalIterator {
	public:
		typedef ft::pair<K, T> value_type;
		typedef Node<value_type> *pointer;
    private:
        pointer node_pointer;
    public:
        BidirectionalIterator() : node_pointer(NULL) {};

        BidirectionalIterator(const pointer ptr) : node_pointer(ptr){};

        BidirectionalIterator(const BidirectionalIterator &ref) {*this = ref;}

        BidirectionalIterator &operator=(const BidirectionalIterator &ref) {
            node_pointer = ref.node_pointer;
            return (*this);
        }

        value_type &operator*() {
            return (node_pointer->data);
        }

        value_type *operator->() {
            return (&node_pointer->data);
        }

        bool operator==(const BidirectionalIterator<K, T> &ref) {
            return (node_pointer == ref.node_pointer);
        }

        bool operator!=(const BidirectionalIterator<K, T> &ref) {
            return (!(*this == ref));
        }

        BidirectionalIterator &operator++() {
            node_pointer = inc(node_pointer);
            return (*this);
        }

        BidirectionalIterator &operator--() {
            node_pointer = dec(node_pointer);
            return (*this);
        }

        BidirectionalIterator operator++(int)
        {
            BidirectionalIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        BidirectionalIterator operator--(int)
        {
            BidirectionalIterator tmp(*this);
            this->operator--();
            return (tmp);
        }

		pointer inc(pointer ptr) {
			pointer next;
			if (!ptr->right)
			{
				next = ptr;
				while (next == next->parent->right && next->parent)
					next = next->parent;
				next = next->parent;
			} else {
				next = ptr->right;
				while (next->left)
					next = next->left;
			}
			return (next);

		}

		pointer dec(pointer ptr) {
			pointer prev;
			if (!ptr->left) {
                prev = ptr;
				while (prev == prev->parent->left && prev->parent)
                    prev = prev->parent;
                prev = prev->parent;
			} else {
                prev = ptr->left;
				while (prev->right)
                    prev = prev->right;
			}
			return (prev);
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
	};


//    template<class K, class T>
//    class ConstBidirectionalIterator {
//    public:
//        typedef ft::pair<K, T> value_type;
//        typedef Node<value_type> *pointer;
//
//    private:
//        pointer node_pointer;
//    public:
//        ConstBidirectionalIterator() : node_pointer(0) {};
//
//        ConstBidirectionalIterator(const pointer ptr) : node_pointer(ptr){};
//
//        ConstBidirectionalIterator(const ConstBidirectionalIterator &ref) {*this = ref;}
//
//        ConstBidirectionalIterator &operator=(const ConstBidirectionalIterator &ref) {
//            node_pointer = ref.node_pointer;
//            return (*this);
//        }
//
//        value_type &operator*() {
//            return (node_pointer->data);
//        }
//
//        value_type *operator->() {
//            return (&node_pointer->data);
//        }
//
//        bool operator==(const BidirectionalIterator<K, T> &ref) {
//            return (node_pointer == ref.node_pointer);
//        }
//
//        bool operator!=(const BidirectionalIterator<K, T> &ref) {
//            return (!(*this == ref));
//        }
//
//        ConstBidirectionalIterator &operator++() {
//            node_pointer = inc(node_pointer);
//            return (*this);
//        }
//
//        ConstBidirectionalIterator &operator--() {
//            node_pointer = dec(node_pointer);
//            return (*this);
//        }
//
//        ConstBidirectionalIterator operator++(int) {
//            ConstBidirectionalIterator tmp(*this);
//            this->operator++();
//            return (tmp);
//        }
//
//        ConstBidirectionalIterator operator--(int) {
//            ConstBidirectionalIterator tmp(*this);
//            this->operator--();
//            return (tmp);
//        }
//    private:
//        pointer inc(pointer ptr) {
//            pointer next;
//            if (!ptr->right) {
//                next = ptr;
//                while (next == next->parent->right && next->parent)
//                    next = next->parent;
//                next = next->parent;
//            } else {
//                next = ptr->right;
//                while (next->left)
//                    next = next->left;
//            }
//            return (next);
//        }
//
//        pointer dec(pointer ptr) {
//            pointer prev;
//            if (!ptr->left) {
//                prev = ptr;
//                while (prev == prev->parent->left && prev->parent)
//                    prev = prev->parent;
//                prev = prev->parent;
//            } else {
//                prev = ptr->left;
//                while (prev->right)
//                    prev = prev->right;
//            }
//            return (prev);
//        }
//    public:
//        bool operator==(ConstBidirectionalIterator const &ref) const {
//            return (this->node_point == ref.node_point);
//        }
//        bool operator!=(ConstBidirectionalIterator const &ref) const {
//            return (this->node_point != ref.node_point);
//        }
//        bool operator<(ConstBidirectionalIterator const &ref) const {
//            return (this->node_point < ref.node_point);
//        }
//        bool operator<=(ConstBidirectionalIterator const &ref) const {
//            return (this->node_point <= ref.node_point);
//        }
//        bool operator>(ConstBidirectionalIterator const &ref) const {
//            return (this->node_point > ref.node_point);
//        }
//        bool operator>=(ConstBidirectionalIterator const &ref) const {
//            return (this->node_point >= ref.node_point);
//        }
//    };
}
#endif
