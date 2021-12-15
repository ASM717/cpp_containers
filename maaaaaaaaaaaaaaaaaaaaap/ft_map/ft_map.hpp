#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <vector>
#include <iostream>
#include <limits>
#include <map>
#include "ft_pair.hpp"
#include "ft_bidirectional_iterator.hpp"
//#include "iterator.hpp"

#define REDC		"\x1B[31m"
#define BLACKC		"\x1B[37m"
#define RESETC		"\x1B[0m"

namespace ft {
    template < typename Key, typename T,
        typename Compare = std::less<Key>, 
        typename Allocator = std::allocator<pair<const Key,T> >
    > class map {
        public:
            typedef Key                                               key_type;
            typedef T                                                 mapped_type;
            typedef Compare                                           key_compare;
            typedef ft::pair<const Key, T>                            value_type;
            typedef ft::node<ft::pair<const Key, T> >                 node;
            typedef typename Allocator::template rebind<node >::other allocator_type;
            typedef typename Allocator::reference			          reference;
            typedef typename Allocator::const_reference	              const_reference;
            typedef typename Allocator::pointer                       pointer;
            typedef typename Allocator::const_pointer		          const_pointer;
            typedef ft::MapIterator<const Key, T>             iterator;
            typedef ft::ConstMapIterator<const Key, T>       const_iterator;
//            typedef ft::reverse_iterator<iterator>                       reverse_iterator;
//            typedef ft::reverse_iterator<const_iterator>                 const_reverse_iterator;
            typedef ptrdiff_t								              difference_type;
            typedef size_t									size_type;


        class value_compare: public std::binary_function <value_type, value_type, bool> {
        protected:
            Compare	comp;
            value_compare (Compare c): comp(c) {}
        public:
            typedef	bool		result_type;
            typedef	value_type	first_argument_type;
            typedef	value_type	second_argument_type;
            bool operator() (const value_type& x, const value_type& y) const {
                return (comp(x.first, y.first));
            }
        };

    private:
        node				*root;
        node				*last;
        node				*elem;
        Compare				_comp;
        allocator_type 		_allocator;
        size_type			_length;
        int					_flag;

    public:

        map() : root(NULL), last(NULL), elem(NULL), _comp(std::less<Key >()),
            _allocator(std::allocator<node>()), _length(0), _flag(0) {}

        explicit map(value_type value) : root(_allocator.allocate(1)), last(NULL), elem(NULL), _comp(std::less<Key >()),
            _allocator(std::allocator<node>()), _length(0), _flag(0) {
            _allocator.construct(root, node(value));
            root->color = black;
        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
            const allocator_type alloc = allocator_type()) : _allocator(alloc), _comp(comp) {
            _length = 0;
            last = NULL;
            _flag = 0;
            root = _allocator.allocate(1);
            elem = NULL;
            _comp = std::less<Key >();
            insert(first, last);
        };

        map(const map& val) : _allocator(val._allocator), _length(0), last(NULL),
            root(NULL), _flag(0), elem(NULL), _comp(std::less<Key >()) {
            *this = val;
        }

        ~map () {
            deleteTree(root);
        }

        map& operator=(const map& val) {
            if (val.root == NULL || this == &val)
                return (*this);
            deleteTree(root);
            copyElem(val.root);
            return (*this);
        }

        iterator begin() {
            if(this->root != NULL)
                return(iterator(minimum(this->root)));
            return(NULL);
//		 	return (iterator(minimum(getRoot())));
        }
        const_iterator begin() const {
            if(this->root != NULL)
                return(const_iterator(minimum(this->root)));
            return(NULL);
        }

        iterator end() {
            return(iterator(this->last));
        }
        const_iterator end() const {
            return(const_iterator(this->last));
        }

        // reverse_iterator rbegin() {

        // }
        // const_reverse_iterator rbegin() const {

        // }

        // reverse_iterator rend() {

        // }
        // const_reverse_iterator rend() const {

        // }

        bool empty() const {
            if (root == NULL)
                return (true);
            return (false);
        }

        size_type size() const {
            return (_length);
        }

        size_type max_size() const {
            return (std::numeric_limits<size_type>::max() / (sizeof(node)));
        }

        // // https://www.cplusplus.com/reference/map/map/operator[]/
         mapped_type& operator[] (const key_type& k) {
            if(!this->root) {
                ft::pair<key_type, mapped_type> tmp_pair;
                tmp_pair.first = k;
                node *tmp = _insert(tmp_pair);
                return(tmp->value.second);
            } else {
                node *tmp = _find(k, this->root);
                if(!tmp)
                {
                    ft::pair<key_type, mapped_type> tmp_pair;
                    tmp_pair.first = k;
                    tmp = _insert(tmp_pair);
                    return(tmp->value.second);
                }
                return (tmp->value.second);
            }
         }

        pair<iterator, bool> insert (const value_type& val) {
            iterator tmp = _insert(val);

//            tmp = _insert(val);
            if (tmp != NULL && _flag == 0)
                _length++;
            _flag = 0;
            return (ft::make_pair(tmp, true));

        }

        iterator insert (iterator position, const value_type& val) {
            iterator tmp = _insert(val);
            if (position)
                return (tmp);
        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last) {
            while (first != last)
            {
                insert(*first);
                ++first;
            }
        }

        void erase (iterator position) {
            deleteElem(*position);
            if (_length != 0)
                --_length;
        }

        size_type erase (const key_type& k) {
            iterator 		item;

            item = find(k);
            if (item != end())
            {
                erase(item);
                return (1);
            }
            return (0);
        }
        void erase (iterator first, iterator last) {
            while (first != last)
                erase(first++);
            if (_length == 0)
                erase(last);
        }

         void swap (map& x) {
             ft::swap(root, x.root);
             ft::swap(elem, x.elem);
             ft::swap(last, x.last);
             ft::swap(_comp, x._comp);
             ft::swap(_allocator, x._allocator);
             ft::swap(_length, x._length);
             ft::swap(_flag, x._flag);
         }

        void clear() {
            erase(begin(), end());
        }

        key_compare key_comp() const {
            return (_comp);
        }

        value_compare value_comp() const {
            return (this->value_compare);
        }

        iterator find (const key_type& k) {
            if (empty())
                return (end());
            node *tmp = _find(k, root);
            if (tmp == NULL)
                return (end());
            return (iterator(tmp));
        }

        const_iterator find (const key_type& k) const {
            if (empty())
                return (end());
            node *tmp = _find(k, root);
            if (tmp == NULL)
                return (end());
            return (const_iterator(tmp));
        }

        size_type count (const key_type& k) const {
            size_t c = 0;
            const_iterator it = begin();

            while (it != end())
            {
                if (it->first == k)
                    ++c;
                ++it;
            }
            return (c);
        }

        iterator lower_bound (const key_type& k) {
            iterator it = begin();
            while (it != end())
            {
                if (this->_comp(it->first, k) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        const_iterator lower_bound (const key_type& k) const {
            const_iterator it = begin();
            while (it != end())
            {
                if (this->_comp(it->first, k) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        iterator upper_bound (const key_type& k) {
            iterator it = begin();

            while (it != end())
            {
                if (it->first != k && this->_comp(it->first, k) <= 0)
                    return (it);
                ++it;
            };
            return (end());
        }

        const_iterator upper_bound (const key_type& k) const {
            const_iterator it = begin();
            while (it != end())
            {
                if (it->first != k && this->_comp(it->first, k) <= 0)
                    return (it);
                ++it;
            };
            return (end());
        }

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
            return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
        }
        pair<iterator,iterator> equal_range (const key_type& k) {
            return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
        }

        allocator_type get_allocator() const {
            return (_allocator);
        }
    // RED BLACK TREE FUNC //
    private:
        node *_find(Key key, node *start){
            if (start == NULL)
                return (NULL);
            else if (key == start->data.first)
                return (start);
            else if (_comp(key, start->data.first))
                return (_find(key, start->left));
            else
                return (_find(key, start->right));
        }

        bool notExist(value_type data, node *start){
            if (start == NULL)
                return(true);
            else if (data.first == start->data.first)
                return (false);
            else if (_comp(data.first, start->data.first))
                return (notExist(data, start->left));
            else
                return (notExist(data, start->right));
        }

        node *findKey(value_type data, node *start) {
            if (start == NULL)
                return (NULL);
            else if (data.first == start->data.first)
                return (start);
            else if (_comp(data.first, start->data.first))
                return (findKey(data, start->left));
            else
                return (findKey(data, start->right));
        }

        node *createElem(const value_type data) {
            elem = _allocator.allocate(1);
            _allocator.construct(elem, node(data));
            return (elem);
        }

        void copyElem(node *toCopy) {
            if (toCopy == NULL)
                return ;
            insertElem(createElem(toCopy->data), root);
            copyElem(toCopy->right);
            copyElem(toCopy->left);
        }
        node *insertElem(node *elem, node *start) {
            if (elem == NULL) {
                return (NULL);
            }
            if (start == NULL) {
                root = elem;
                return (root);
            }
            if (_comp(elem->data.first, start->data.first)) {
                if (start->left)
                    insertElem(elem, start->left);
                else {
                    elem->parent = start;
                    start->left = elem;
                    insertFix(elem);
                }
            } else if (elem->data.first == start->data.first)
                return (NULL);
            else {
                if (start->right)
                    insertElem(elem, start->right);
                else {
                    elem->parent = start;
                    start->right = elem;
                    insertFix(elem);
                }
            }
            return (elem);
        }

        node *_insert(value_type data) {
            if (notExist(data, root))
                return (insertElem(createElem(data), root));
            return (findKey(data, root));
        }

        void insertFix(node *elem) {
            if (elem == NULL || elem->parent == NULL)
                return;
            while (elem->parent->color == red) {
                if (elem->parent->parent && elem->parent == elem->parent->parent->left) {
                    if (elem->parent->parent->right && elem->parent->parent->right->color == red) {
                        elem->parent->parent->right->color = black;
                        elem->parent->color = black;
                        elem->parent->parent->color = red;
                        elem = elem->parent->parent;
                    } else {
                        if (elem == elem->parent->right) {
                            node *tmp = elem->parent;
                            rotateLeft(elem);
                            elem = tmp;
                        }
                        elem->parent->color = black;
                        if (elem->parent->parent)
                            elem->parent->parent->color = red;
                        rotateRight(elem->parent);
                    }
                } else {
                    if (elem->parent->parent && elem->parent->parent->left && elem->parent->parent->left->color == red) {
                        elem->parent->parent->left->color = black;
                        elem->parent->color = black;
                        elem->parent->parent->color = red;
                        elem = elem->parent->parent;
                    } else {
                        if (elem == elem->parent->left) {
                            node *tmp = elem->parent;
                            rotateRight(elem);
                            elem = tmp;
                        }
                        elem->parent->color = black;
                        if (elem->parent->parent)
                            elem->parent->parent->color = red;
                        rotateLeft(elem->parent);
                    }
                }
                if (elem == root)
                    break;
            }
            root->color = black;
        }
        void transplant(node *u, node *v) {
            if (u->parent == nullptr)
                root = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            if (v)
                v->parent = u->parent;
        }

        node *maximum() {
            return (maximumRec(root));
        }

        node *maximumRec(node *start) {
            if (start->right)
                return (maximumRec(start->right));
            return (start);
        }

        node *minimum(node *root) {
            return (minimumRec(root));
        }

        node *minimumRec(node *start) {
            if (start->left)
                return (minimumRec(start->left));
            return (start);
        }

        void deleteElem(value_type data) {
            node *x;
            node *y;
            node *toDel = root;
            node *parent = NULL;
            e_color saveColor;
            while (toDel != NULL) {
                if (toDel->data.first == data.first)
                    break;
                if (!_comp(toDel->data.first, data.first))
                    toDel = toDel->left;
                else
                    toDel = toDel->right;
            }
            if (toDel == NULL)
                return;
            saveColor = toDel->color;
            if (toDel->left == NULL) {
                x = toDel->right;
                parent = toDel->parent;
                transplant(toDel, x);
            }
            else if (toDel->right == NULL) {
                x = toDel->left;
                parent = toDel->parent;
                transplant(toDel, x);
            }
            else {
                y = minimum(toDel->right);
                saveColor = y->color;
                x = y->right;
                if (y->parent == toDel)
                    parent = y;
                else {
                    parent = y->parent;
                    transplant(y, y->right);
                    y->right = toDel->right;
                    y->right->parent = y;
                }
                transplant(toDel, y);
                y->left = toDel->left;
                y->left->parent = y;
                y->color = toDel->color;
            }
            ft_delete(toDel);
            if (saveColor == black && parent) {
                deleteFix(x, parent);
            }
        }

        bool isBlack(node *ptr) {
            return ((ptr == NULL) || (ptr && ptr->color == black));
        }

        void deleteFix(node* x, node * parent) {
            node *s;
            while (parent && x != root && isBlack(x)) {
                if (x == parent->left) {
                    s = parent->right;
                    if (s && s->color == red) {
                        s->color = black;
                        parent->color = red;
                        rotateLeft(s);
                        s = parent->right;
                    }
                    if (s && isBlack(s->left) && isBlack(s->right)) {
                        s->color = red;
                        x = parent;
                        parent = parent->parent;
                    } else {
                        if (s && isBlack(s->right)) {
                            if (s->left)
                                s->left->color = black;
                            s->color = red;
                            rotateRight(s->left);
                            s = parent->right;
                        }
                        if (s)
                            s->color = parent->color;
                        parent->color = black;
                        if (s && s->right)
                            s->right->color = black;
                        rotateLeft(parent->right);
                        x = root;
                    }
                } else {
                    s = parent->left;
                    if (s && s->color == red) {
                        s->color = black;
                        parent->color = red;
                        rotateRight(s);
                        s = parent->left;
                    }
                    if (s && isBlack(s->left) && isBlack(s->right)) {
                        s->color = red;
                        x = parent;
                        parent = parent->parent;
                    } else {
                        if (s && isBlack(s->left)) {
                            if (s->right)
                                s->right->color = black;
                            s->color = red;
                            rotateLeft(s->right);
                            s = parent->left;
                        }
                        if (s)
                            s->color = parent->color;
                        parent->color = black;
                        if (s && s->left)
                            s->left->color = black;
                        rotateRight(parent->left);
                        x = root;
                    }
                }
            }
            if (x)
                x->color = black;
        }

        void display(void) {
            displayTree(root, "", true);
        }
        void displayTree(node *root, std::string indent, bool last) {
            if (root != NULL) {
                std::cout << indent;
                if (last) {
                    std::cout << "R----";
                    indent += "   ";
                } else {
                    std::cout << "L----";
                    indent += "|  ";
                }
                std::string sColor = root->color ? REDC : BLACKC;
                std::cout << sColor << root->data.first << RESETC << std::endl;
                displayTree(root->left, indent, false);
                displayTree(root->right, indent, true);
            }
        }

        void ft_delete(node *toDel) {
            _allocator.destroy(toDel);
            _allocator.deallocate(toDel, 1);
        }

        void deleteTree(node *root) {
            if (root == NULL)
                return;
            deleteTree(root->left);
            deleteTree(root->right);
            ft_delete(root);
            root = NULL;
        }

        void rotateLeft(node *elem) {
            if (elem == NULL || elem->parent == NULL || elem->parent->left == elem)
                return;
            node *parentElem = elem->parent;
            node *gparentElem = elem->parent->parent;
            parentElem->right = elem->left;
            if (elem->left) {
                elem->left->parent = parentElem;
                elem->left = NULL;
            }
            elem->parent = gparentElem;
            if (gparentElem == NULL)
                root = elem;
            else if (gparentElem->left == parentElem)
                gparentElem->left = elem;
            else
                gparentElem->right = elem;
            elem->left = parentElem;
            parentElem->parent = elem;
        }

        void rotateRight(node *elem) {
            if (elem == NULL || elem->parent == NULL || elem->parent->right == elem)
                return;
            node *parentElem = elem->parent;
            node *gparentElem = elem->parent->parent;
            parentElem->left = elem->right;
            if (elem->right) {
                elem->right->parent = parentElem;
                elem->right = NULL;
            }
            elem->parent = gparentElem;
            if (gparentElem == NULL)
                root = elem;
            else if (gparentElem->left == parentElem)
                gparentElem->left = elem;
            else
                gparentElem->right = elem;
            elem->right = parentElem;
            parentElem->parent = elem;
        }
    };

    template <typename T, typename Alloc>
    bool operator== (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin())); }
    template <typename T, typename Alloc>
    bool operator!= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(lhs == rhs)); }
    template <typename T, typename Alloc>
    //исправить стд
    bool operator< (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
    template <typename T, typename Alloc>
    bool operator<= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(rhs < lhs)); }
    template <typename T, typename Alloc>
    bool operator> (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (rhs < lhs); }
    template <typename T, typename Alloc>
    bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(lhs < rhs)); }
    template <typename T, typename Alloc>
    void swap (map<T,Alloc>& x, map<T,Alloc>& y)						{ x.swap(y); }

//    template <class Key, class T, class Compare, class Alloc>
//    void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
//    {
//        x.swap(y);
//    };
//
//    template <typename T, typename S>
//    bool operator==(ft::map<T, S> &a, std::map<T, S> &b)
//    {
//        if (a.size() != b.size())
//            return (false);
//        if (a.empty() != b.empty())
//            return (false);
//        typename ft::map<T, S>::iterator it = a.begin();
//        typename std::map<T, S>::iterator it2 = b.begin();
//        while (it != a.end())
//        {
//            if (it->first != it2->first || it->second != it2->second)
//                return (false);
//            ++it;
//            ++it2;
//        }
//        return (true);
//    };
//
//    template <class Key, class T, class Compare, class Alloc>
//    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
//    {
//        return (!(lhs == rhs));
//    };
//
//    template <class Key, class T, class Compare, class Alloc>
//    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
//    {
//        if (lhs.size() > rhs.size())
//            return (true);
//        typename ft::map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
//        typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
//        while (it != lhs.end() && it2 != rhs.end())
//        {
//            if (*it > *it2)
//                return (true);
//            ++it2;
//            ++it;
//        }
//        return (false);
//    };
//
//    template <class Key, class T, class Compare, class Alloc>
//    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
//    {
//        return (!(lhs > rhs) && !(lhs == rhs));
//    };
//
//    template <class Key, class T, class Compare, class Alloc>
//    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
//    {
//        return (!(lhs < rhs));
//    };
//
//    template <class Key, class T, class Compare, class Alloc>
//    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
//    {
//        return (!(lhs > rhs));
//    };
}

#endif