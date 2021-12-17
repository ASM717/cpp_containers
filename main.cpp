/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 04:50:06 by amuriel           #+#    #+#             */
/*   Updated: 2021/12/09 13:55:02 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "ft_tester/tester_vector.cpp"
#include "ft_tester/tester_stack.cpp"
#include "ft_tester/tester_map.cpp"
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
	//vector_resize_yard_test();

	/*string*/
	vector_string_begin_end_test();
	vector_string_resize_reserve_test();
	vector_string_swap_test();
	vector_string_insert_erase_test();

}

void stack_test() {
	std::cout << "========================= STACK ========================" << std::endl;
	stack_constructor_test();
	stack_empty_test();
	stack_top_test();
	stack_push_pop_test();
}

void map_test() {
	std::cout << "========================== MAP =========================" << std::endl;
	map_all_test();
	map_swap_test();
	map_count_test();
	map_speed_test();
}

int main()
{
//	std::string container = argv[1];
//	//speed_erase_test();
//	if (argc == 1)
//		return (0);
//	if (container == "vector")
//	{

		// vector_test();
		// stack_test();
		map_test();
		// system ("leaks ft_containers");

	 return (0);
	// 	}
}


// std::map<int, int> gquiz1;

// insert elements in random order
// gquiz1.insert(std::pair<int, int>(1, 40));
// gquiz1.insert(std::pair<int, int>(2, 30));
// gquiz1.insert(std::pair<int, int>(3, 60));
// gquiz1.insert(std::pair<int, int>(4, 20));
// gquiz1.insert(std::pair<int, int>(5, 50));
// gquiz1.insert(std::pair<int, int>(6, 50));
// gquiz1.insert(std::pair<int, int>(7, 10));

// printing map gquiz1
// ft::map<int, int>::iterator itr;
// std::cout << "\nThe map gquiz1 is : \n";
// std::cout << "\tKEY\tELEMENT\n";
// for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
//     std::cout << '\t' << itr->first
//          << '\t' << itr->second << '\n';
// }
// std::cout << std::endl;