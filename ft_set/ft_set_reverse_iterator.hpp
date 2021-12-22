#ifndef FT_SET_REVERSE_ITERATOR_HPP
#define FT_SET_REVERSE_ITERATOR_HPP

#include <iostream>
#include "../ft_map/ft_node.hpp"

namespace ft {
    template<class T>
    class ReverseSetIterator {
        typedef T value_type;
        typedef Node<value_type> *pointer;

    private:
        pointer node_pointer;

    public:
        ReverseSetIterator() : node_pointer(NULL) {};

        ReverseSetIterator(const pointer ptr) : node_pointer(ptr){};

        ReverseSetIterator(const ReverseSetIterator &ref) {*this = ref;}

        ReverseSetIterator &operator=(const ReverseSetIterator &ref) {
            node_pointer = ref.node_pointer;
            return (*this);
        }

        value_type &operator*() {
            return (node_pointer->data);
        }

        value_type *operator->() {
            return (&node_pointer->data);
        }

        bool operator==(const ReverseSetIterator<T> &ref) {
            return (node_pointer == ref.node_pointer);
        }

        bool operator!=(const ReverseSetIterator<T> &ref) {
            return (!(*this == ref));
        }

        ReverseSetIterator &operator++() {
            node_pointer = dec(node_pointer);
            return (*this);
        }

        ReverseSetIterator &operator--() {
            node_pointer = inc(node_pointer);
            return (*this);
        }

        ReverseSetIterator operator++(int) {
            ReverseSetIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        ReverseSetIterator operator--(int) {
            ReverseSetIterator tmp(*this);
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
        bool operator==(ReverseSetIterator const &ref) const {
            return (this->node_pointer == ref.node_pointer);
        }
        bool operator!=(ReverseSetIterator const &ref) const {
            return (this->node_pointer != ref.node_pointer);
        }
        bool operator<(ReverseSetIterator const &ref) const {
            return (this->node_pointer < ref.node_pointer);
        }
        bool operator<=(ReverseSetIterator const &ref) const {
            return (this->node_pointer <= ref.node_pointer);
        }
        bool operator>(ReverseSetIterator const &ref) const {
            return (this->node_pointer > ref.node_pointer);
        }
        bool operator>=(ReverseSetIterator const &ref) const {
            return (this->node_pointer >= ref.node_pointer);
        }
    };

    template<class T>
    class ConstReverseSetIterator {
        typedef T value_type;
        typedef Node<value_type> *const_pointer;

    private:
        const_pointer node_pointer;

    public:
        ConstReverseSetIterator() : node_pointer(NULL) {};

        ConstReverseSetIterator(const const_pointer ptr) : node_pointer(ptr){};

        ConstReverseSetIterator(const ConstReverseSetIterator &ref) {*this = ref;}

        ConstReverseSetIterator &operator=(const ConstReverseSetIterator &ref) {
            node_pointer = ref.node_pointer;
            return (*this);
        }

        value_type &operator*() {
            return (node_pointer->data);
        }

        value_type *operator->() {
            return (&node_pointer->data);
        }

        bool operator==(const ConstReverseSetIterator<T> &ref) {
            return (node_pointer == ref.node_pointer);
        }

        bool operator!=(const ConstReverseSetIterator<T> &ref) {
            return (!(*this == ref));
        }

        ConstReverseSetIterator &operator++() {
            node_pointer = dec(node_pointer);
            return (*this);
        }

        ConstReverseSetIterator &operator--() {
            node_pointer = inc(node_pointer);
            return (*this);
        }

        ConstReverseSetIterator operator++(int) {
            ConstReverseSetIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        ConstReverseSetIterator operator--(int) {
            ConstReverseSetIterator tmp(*this);
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
        bool operator==(ConstReverseSetIterator const &ref) const {
            return (this->node_pointer == ref.node_pointer);
        }
        bool operator!=(ConstReverseSetIterator const &ref) const {
            return (this->node_pointer != ref.node_pointer);
        }
        bool operator<(ConstReverseSetIterator const &ref) const {
            return (this->node_pointer < ref.node_pointer);
        }
        bool operator<=(ConstReverseSetIterator const &ref) const {
            return (this->node_pointer <= ref.node_pointer);
        }
        bool operator>(ConstReverseSetIterator const &ref) const {
            return (this->node_pointer > ref.node_pointer);
        }
        bool operator>=(ConstReverseSetIterator const &ref) const {
            return (this->node_pointer >= ref.node_pointer);
        }
    };
}

#endif