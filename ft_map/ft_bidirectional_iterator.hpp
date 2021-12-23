#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
#define FT_BIDIRECTIONAL_ITERATOR_HPP

#include "../ft_vector/ft_iterator_utils.hpp"
#include "../ft_vector/ft_type_traits.hpp"
#include "ft_pair.hpp"
#include "ft_node.hpp"

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

    BidirectionalIterator operator++(int) {
        BidirectionalIterator tmp(*this);
        this->operator++();
        return (tmp);
    }

    BidirectionalIterator operator--(int) {
        BidirectionalIterator tmp(*this);
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
    };

    template<class K, class T>
    class ConstBidirectionalIterator {
    public:
        typedef ft::pair<K, T> value_type;
        typedef Node<value_type> *const_pointer;
    private:
        const_pointer node_pointer;
    public:
        ConstBidirectionalIterator() : node_pointer(NULL) {};

        ConstBidirectionalIterator(const const_pointer ptr) : node_pointer(ptr){};

        ConstBidirectionalIterator(const ConstBidirectionalIterator &ref) {*this = ref;}

        ConstBidirectionalIterator &operator=(const ConstBidirectionalIterator &ref) {
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

        ConstBidirectionalIterator &operator++() {
            node_pointer = inc(node_pointer);
            return (*this);
        }

        ConstBidirectionalIterator &operator--() {
            node_pointer = dec(node_pointer);
            return (*this);
        }

        ConstBidirectionalIterator operator++(int) {
            ConstBidirectionalIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        ConstBidirectionalIterator operator--(int) {
            ConstBidirectionalIterator tmp(*this);
            this->operator--();
            return (tmp);
        }
    private:
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
    public:
        bool operator==(ConstBidirectionalIterator const &ref) const {
            return (this->node_pointer == ref.node_pointer);
        }
        bool operator!=(ConstBidirectionalIterator const &ref) const {
            return (this->node_pointer != ref.node_pointer);
        }
        bool operator<(ConstBidirectionalIterator const &ref) const {
            return (this->node_pointer < ref.node_pointer);
        }
        bool operator<=(ConstBidirectionalIterator const &ref) const {
            return (this->node_pointer <= ref.node_pointer);
        }
        bool operator>(ConstBidirectionalIterator const &ref) const {
            return (this->node_pointer > ref.node_pointer);
        }
        bool operator>=(ConstBidirectionalIterator const &ref) const {
            return (this->node_pointer >= ref.node_pointer);
        }
    };
}

#endif
