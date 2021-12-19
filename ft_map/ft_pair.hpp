/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:38 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 14:02:39 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_HPP
#define FT_PAIR_HPP

// https://www.cplusplus.com/reference/utility/pair/?kw=pair
namespace ft {
	template <class T1, class T2>
	struct pair {
	public:
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

        pair() {}

        template<class U, class V>
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}

		pair &operator=(const pair& pr) {
			first = pr.first;
			second = pr.second;
			return (*this);
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

    // https://www.cplusplus.com/reference/utility/make_pair/?kw=make_pair
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {return (pair<T1,T2>(x,y));}
}

#endif
