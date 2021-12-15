#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "ft_pair.hpp"

namespace ft {
    //template <class Iterator, class Node>
    template <typename V, typename T>
    // : public ft::iterator<ft::bidirectional_iterator_tag>
    class BidirectionalIterator {
        typedef ft::pair<V, T> value_type;
        typedef ft::pair<V, T> &reference;
        typedef node <value_type> *pointer;
    private:
        pointer node_point;
    public:
        BidirectionalIterator() : node_point(NULL) {}

        BidirectionalIterator(pointer ptr) : node_point(ptr) {}

        BidirectionalIterator(const BidirectionalIterator &ref) : node_point(ref.node_point) {}

        BidirectionalIterator &operator=(const BidirectionalIterator &ref)
        {
            node_point = ref.node_point;
            return (*this);
        }

        virtual ~BidirectionalIterator(){

        } //destructor

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

    template <typename V, typename T>
    // : public ft::iterator<ft::bidirectional_iterator_tag>
    class ConstBidirectionalIterator {
        typedef ft::pair<V, T> value_type;
        typedef ft::pair<V, T> &const_reference;
        typedef node <value_type> *const_pointer;
    private:
        const_pointer node_point;
    public:
        ConstBidirectionalIterator() : node_point(NULL) {}

        ConstBidirectionalIterator(const const_pointer ptr) : node_point(ptr) {}

        ConstBidirectionalIterator(const ConstBidirectionalIterator &ref) : node_point(ref.node_point) {}

        ConstBidirectionalIterator &operator=(const ConstBidirectionalIterator &ref)
        {
            node_point = ref.node_point;
            return (*this);
        }

        virtual ~ConstBidirectionalIterator(){

        } //destructor

		const_reference operator*() const {
			return (node_point->data);
		}

		const_pointer operator->() const {
			return (&node_point->data);
		}

        ConstBidirectionalIterator operator++(int) {
            ConstBidirectionalIterator tmp(*this);
            this->inc();
            return (tmp);
        }
        ConstBidirectionalIterator &operator++() {
            this->inc();
            return (*this);
        }
        ConstBidirectionalIterator operator--(int) {
            ConstBidirectionalIterator tmp(*this);
            this->dec();
            return (tmp);
        }
        ConstBidirectionalIterator &operator--() {
            this->dec();
            return (*this);
        }

        ConstBidirectionalIterator operator+(int value) const {
            ConstBidirectionalIterator tmp(*this);
            return (tmp += value);
        }

        ConstBidirectionalIterator operator-(int value) const {
            ConstBidirectionalIterator tmp(*this);
            return (tmp -= value);
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
                const_pointer tmp = this->node_point;
                this->node_point = this->node_point->parent;
                while (this->node_point->left != tmp)
                {
                    tmp = this->node_point;
                    this->node_point = this->node_point->parent;
                }
            }
        }

        bool operator==(ConstBidirectionalIterator const &ref) const {
            return (this->node_point == ref.node_point);
        }
        bool operator!=(ConstBidirectionalIterator const &ref) const {
            return (this->node_point != ref.node_point);
        }
        bool operator<(ConstBidirectionalIterator const &ref) const {
            return (this->node_point < ref.node_point);
        }
        bool operator<=(ConstBidirectionalIterator const &ref) const {
            return (this->node_point <= ref.node_point);
        }
        bool operator>(ConstBidirectionalIterator const &ref) const {
            return (this->node_point > ref.node_point);
        }
        bool operator>=(ConstBidirectionalIterator const &ref) const {
            return (this->node_point >= ref.node_point);
        }
    };
}

#endif