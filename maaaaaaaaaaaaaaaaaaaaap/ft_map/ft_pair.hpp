#ifndef FT_PAIR_HPP
#define FT_PAIR_HPP

#include <iostream>

// https://www.cplusplus.com/reference/utility/pair/?kw=pair
namespace ft {
    enum e_color
    {
        black, red
    };

    template <typename P>
    struct node
    {
        P data;
        node *left;
        node *right;
        node *parent;
        e_color color;

        node(const P &cp) : data(cp) {
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
            this->color = red;
        }

        ~node() {}

    };

    template<class T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

	template <class T1, class T2>
	struct pair {
	public:
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		pair(): first(T1()), second(T2()) {}

		template<class U, class V> pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}

		pair (const first_type& a, const second_type& b): first(a), second(b) {}

		pair &operator=(const pair& pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		}

		~pair() {}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first == rhs.first && lhs.second == rhs.second; }

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs < lhs); }

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs < lhs; }

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs < rhs); }

    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return (pair<T1,T2>(x,y));
    }
}

#endif