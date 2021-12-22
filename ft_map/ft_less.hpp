/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:21 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/22 15:36:28 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LESS_HPP
#define FT_LESS_HPP

namespace ft {
	template <class T>
	struct less
	{
		typedef T    first_argument_type;
		typedef T    second_argument_type;
		typedef bool result_type;

		bool operator()(const T& first, const T& second) const {
			return (first < second);
		}
	};
}

#endif
