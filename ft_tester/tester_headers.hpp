/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_headers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:54 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 14:02:55 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_VECTOR_HPP
#define TESTER_VECTOR_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <ctime>
#include <iomanip>
#include "../ft_vector/ft_vector.hpp"
#include "../ft_stack/ft_stack.hpp"
#include "../ft_map/ft_map.hpp"

/*prototype test vector integer */
void vector_swap_rela_test();
void vector_relational_operators_test();
void vector_get_allocator_test();
void vector_clear_test();
void vector_swap_test();
void vector_erase_test();
void vector_insert_test();
void vector_push_pop_test();
void vector_assign_test();
void vector_back_test();
void vector_front_test();
void vector_at_test();
void vector_operator_el_pos_test();
void vector_reserve_test();
void vector_empty_test();
void vector_resize_test();
void vector_reverse_iterator_test();
void vector_iterator_test();
void vector_operator_equel_test();
void vector_constructor_test();
void vector_size_test();
void vector_max_size_test();
void vector_resize_yard_test();

/*prototype test vector string*/
void vector_string_begin_end_test();
void vector_string_swap_test();
void vector_string_resize_reserve_test();
void vector_string_insert_erase_test();

/*STACK*/
void stack_constructor_test();
void stack_empty_test();
void stack_top_test();
void stack_push_pop_test();

/* MAP */
void map_all_test();
void map_swap_test();
void map_bound_test();
void map_count_test();
void map_equal_range_test();
void map_value_compare_test();
void map_key_compare_test();
void map_get_allocator_test();
void map_comparison_operator_test();
void map_make_pair_test();
void map_speed_test();

void map_spec_test();

/* VISUAL TREE*/
void map_red_black_tree_test();

/* SET */
void set_all_test();
void set_swap_test();
void set_count_test();
void set_bound_test();
void set_equal_range_test();
void set_get_allocator_test();
void set_comparison_operator_test();
void set_speed_test();

#endif
