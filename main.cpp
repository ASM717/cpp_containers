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
//    vector_resize_yard_test();

	/*string*/
	vector_string_begin_end_test();
	vector_string_resize_reserve_test();
	vector_string_swap_test();
	vector_string_insert_erase_test();


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

void stack_test() {
	std::cout << "========================= STACK ========================" << std::endl;
	stack_constructor_test();
	stack_empty_test();
	stack_top_test();
	stack_push_pop_test();
}

#include <map>
#include <vector>

int main()
{
//	std::string container = argv[1];
//	//speed_erase_test();
//	if (argc == 1)
//		return (0);
//	if (container == "vector")
//	{

		//vector_test();
		//stack_test();
		//system ("leaks ft_containers");

	unsigned long start = clock();
	std::vector<int> std_vector(10);
	std_vector.resize(2000000000);
	std::cout << std_vector.capacity() << std::endl;
	// std_vector.resize(10);
	// std::cout << std_vector.capacity() << std::endl;
	std_vector.~vector();
	unsigned long finish = clock();
	unsigned long diff = finish - start;
	std::cout << "STD TIME = " << diff << std::endl;

	// unsigned long ft_start = clock();
	// ft::vector<int> ft_vector(10);
	// ft_vector.resize(2000000000);
	// std::cout << ft_vector.capacity() << std::endl;
	// ft_vector.resize(10);
	// std::cout << std_vector.capacity() << std::endl;
	// ft_vector.~vector();
	// unsigned long ft_finish = clock();
	// unsigned long ft_diff = ft_finish - ft_start;
	// std::cout << "FTV TIME = " << ft_diff << std::endl;

	// unsigned long res = ft_diff / diff;
	// std::cout << "RESULT TIME = " << res << std::endl;

	return (0);
//	}
}
