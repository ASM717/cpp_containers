#ifndef FT_REV_BIDIR_ITER_HPP
#define FT_REV_BIDIR_ITER_HPP

#include "../ft_vector/ft_iterator_utils.hpp"
#include "../ft_vector/ft_type_traits.hpp"
#include "ft_pair.hpp"
#include "ft_node.hpp"

namespace ft {
    template<class K, class T>
    class ReverseBidirectionalIterator {
    public:
        typedef ft::pair<K, T> value_type;
        typedef Node<value_type> *pointer;
    private:
        pointer node_pointer;
    public:
        ReverseBidirectionalIterator() : node_pointer(NULL) {};

        ReverseBidirectionalIterator(const pointer ptr) : node_pointer(ptr){};

        ReverseBidirectionalIterator(const ReverseBidirectionalIterator &ref) { *this = ref;}

        ReverseBidirectionalIterator &operator=(const ReverseBidirectionalIterator &ref) {
            node_pointer = ref.node_pointer;
            return (*this);
        }

        value_type &operator*() {
            return (node_pointer->data);
        }

        value_type *operator->() {
            return (&node_pointer->data);
        }

        bool operator==(const ReverseBidirectionalIterator<K, T> &ref) {
            return (node_pointer == ref.node_pointer);
        }

        bool operator!=(const ReverseBidirectionalIterator<K, T> &ref) {
            return (!(*this == ref));
        }

        ReverseBidirectionalIterator &operator++() {
            node_pointer = dec(node_pointer);
            return (*this);
        }

        ReverseBidirectionalIterator &operator--() {
            node_pointer = inc(node_pointer);
            return (*this);
        }

        ReverseBidirectionalIterator operator++(int) {
            ReverseBidirectionalIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        ReverseBidirectionalIterator operator--(int) {
            ReverseBidirectionalIterator tmp(*this);
            this->operator--();
            return (tmp);
        }

        pointer inc(pointer ptr) {
            pointer nextPtr;
            if (!ptr->right) {
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

        bool operator==(ReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer == ref.node_pointer);
        }
        bool operator!=(ReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer != ref.node_pointer);
        }
        bool operator<(ReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer < ref.node_pointer);
        }
        bool operator<=(ReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer <= ref.node_pointer);
        }
        bool operator>(ReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer > ref.node_pointer);
        }
        bool operator>=(ReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer >= ref.node_pointer);
        }
    };

    template<class K, class T>
    class ConstReverseBidirectionalIterator {
    public:
        typedef ft::pair<K, T> value_type;
        typedef Node<value_type> *const_pointer;
    private:
        const_pointer node_pointer;
    public:
        ConstReverseBidirectionalIterator() : node_pointer(NULL) {};

        ConstReverseBidirectionalIterator(const const_pointer ptr) : node_pointer(ptr){};

        ConstReverseBidirectionalIterator(const ConstReverseBidirectionalIterator &ref) { *this = ref;}

        ConstReverseBidirectionalIterator &operator=(const ConstReverseBidirectionalIterator &ref) {
            node_pointer = ref.node_pointer;
            return (*this);
        }

        value_type &operator*() {
            return (node_pointer->data);
        }

        value_type *operator->() {
            return (&node_pointer->data);
        }

        bool operator==(const ReverseBidirectionalIterator<K, T> &ref) {
            return (node_pointer == ref.node_pointer);
        }

        bool operator!=(const ReverseBidirectionalIterator<K, T> &ref) {
            return (!(*this == ref));
        }

        ConstReverseBidirectionalIterator &operator++() {
            node_pointer = dec(node_pointer);
            return (*this);
        }

        ConstReverseBidirectionalIterator &operator--() {
            node_pointer = inc(node_pointer);
            return (*this);
        }

        ConstReverseBidirectionalIterator operator++(int) {
            ConstReverseBidirectionalIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        ConstReverseBidirectionalIterator operator--(int) {
            ConstReverseBidirectionalIterator tmp(*this);
            this->operator--();
            return (tmp);
        }

        const_pointer inc(const_pointer ptr) {
            const_pointer nextPtr;
            if (!ptr->right) {
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

        bool operator==(ConstReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer == ref.node_pointer);
        }
        bool operator!=(ConstReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer != ref.node_pointer);
        }
        bool operator<(ConstReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer < ref.node_pointer);
        }
        bool operator<=(ConstReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer <= ref.node_pointer);
        }
        bool operator>(ConstReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer > ref.node_pointer);
        }
        bool operator>=(ConstReverseBidirectionalIterator const &ref) const {
            return (this->node_pointer >= ref.node_pointer);
        }
    };
}

#endif
