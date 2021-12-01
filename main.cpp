/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 04:50:06 by amuriel           #+#    #+#             */
/*   Updated: 2021/11/29 10:47:52 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
//#include "ft_vector/ft_vector.hpp"
#include "ft_tester/tester_vector.cpp"
#include "ft_tester/tester_stack.cpp"
#include <string>
#include <ctime>
#include <iomanip>

template<typename T>
void std_print_vector(const std::vector<T> &std_vector) {
	typename std::vector<T>::const_iterator it;
	for (it = std_vector.begin(); it != std_vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void ft_print_vector(const ft::vector<T> &ft_vector) {
	typename ft::vector<T>::const_iterator it;
	for (it = ft_vector.begin(); it != ft_vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

//template<typename T>
//void print_vector(const ft::vector<T> &vct) {
//    typename ft::vector<T>::const_iterator it;
//    for (it = vct.begin(); it != vct.end(); it++) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;
//}
//
//template<typename T>
//void print_vector_reverse(const ft::vector<T> &vct) {
//    typename ft::vector<T>::const_reverse_iterator it;
//    for (it = vct.rbegin(); it != vct.rend(); it++) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;
//}

void stack_test() {
	std::cout << "========================= STACK ========================" << std::endl;
	stack_constructor_test();
	stack_empty_test();
}

void vector_test() {
	std::cout << "======================== VECTOR ========================" << std::endl;
	/*int*/
	vector_constructor_test();
	vector_operator_equel_test();
	vector_iterator_test();
	vector_reverse_iterator_test();
	vector_size_test();
	vector_max_size_test();
	vector_resize_test();
	vector_empty_test();
	vector_reserve_test();
	vector_operator_el_pos_test();
	vector_at_test();
	vector_front_test();
	vector_back_test();
	vector_assign_test();
	vector_push_pop_test();
	vector_insert_test();
	vector_erase_test();
	vector_swap_test();
	vector_clear_test();
	vector_get_allocator_test();
	vector_relational_operators_test();
	vector_swap_rela_test();

	/*string*/
	vector_string_begin_end_test();
	vector_string_resize_reserve_test();
	vector_string_swap_test();
	vector_string_insert_erase_test();

	//stack




//	ft::vector<std::string> ft_vector;
//	for (int i = 0; i < 10; i++)
//	{
//		ft_vector.push_back("test");
//	}
//	ft_vector.push_back("test2");
//
//	std::cout << *ft_vector.rbegin() << std::endl;

//	 std::vector<const int> test;
//	 std::vector<const int>::iterator i = test.begin();
//
//	 std::vector<const int> test1;
//	 test1.push_back(8);
//
//	 ft::vector<const int> test2;
//	 ft::vector<const int>::iterator it = test2.begin();
//
//	 ft::vector<const int> test12;
//	 test12.push_back(7);
}

int main()
{
//	std::string container = argv[1];
//	//speed_erase_test();
//	if (argc == 1)
//		return (0);
//	if (container == "vector")
//	{

		//vector_test();
		stack_test();
		//system ("leaks a.out");
		return (0);
//	}
}
