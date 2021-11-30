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
#include "ft_tester/tester_headers.cpp"
#include <string>
#include <ctime>
#include <iomanip>


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
    vector_string_swap_test();
	vector_string_back_test();

	// ft::vector<int> test;
	// ft::vector<const int>::iterator i = test.begin();

	// std::vector<const int> test;
	// std::vector<const int>::iterator i = test.begin();

	// std::vector<const int> test;
	// test.push_back(8);

	// ft::vector<const int> test1;
	// test1.push_back(7);
}

int main()
{
//	std::string container = argv[1];
//	//speed_erase_test();
//	if (argc == 1)
//		return (0);
//	if (container == "vector")
//	{

		vector_test();
		//system ("leaks a.out");
		return (0);
//	}
}

// int main()
// {
// 	unsigned int start_time =  clock();

// 	std::vector<int> *test
//
// 	= new std::vector<int>;
// 	for(int i= 0; i < 1000000; i++)
//     	test->push_back(i);

// 	std::vector<int>::iterator b = test->begin();
//     std::vector<int>::iterator e = test->end();

//     std::cout << "size = " << test->size() << std::endl;
//     std::cout << "cap = " << test->capacity() << std::endl;

//     b++;

//     e--;
//     std::cout << " erase here " << std::endl;
//     test->erase(b, e);
//     for(std::vector<int>::iterator i = test->begin(); i != test->end(); i++)
//     {
//         std::cout << " i = " << *i << std::endl;
//     }
// 	delete test;
// 	unsigned int end_time = clock();
// 	unsigned int search_time = end_time - start_time;
//     std::cout << search_time << std::endl;
// }

//void speed_erase_test()
//{
//	unsigned int start_time = clock();
//
//	ft::vector<int> *test = new ft::vector<int>;
//	for(int i= 0; i < 1000000; i++)
//		test->push_back(i);
//	ft::vector<int>::iterator b = test->begin();
//	ft::vector<int>::iterator e = test->end();
//	std::cout << "size = " << test->size() << std::endl;
//	std::cout << "cap = " << test->capacity() << std::endl;
//	b++;
//	e--;
//	std::cout << " erase here " << std::endl;
//	test->erase(b, e);
//	for(ft::vector<int>::iterator i = test->begin(); i != test->end(); i++)
//		std::cout << " i = " << *i << std::endl;
//	delete test;
//	unsigned int end_time = clock();
//	unsigned int search_time = end_time - start_time;
//	std::cout << search_time << std::endl;
//}

//ft::vector<int> vector2;
//vector2.push_back(20);
//vector2.push_back(22);
//vector2.push_back(48);
//vector2.push_back(0);
//vector2.push_back(-200);
//
//print_vector(vector2);
//
//std::vector<int> std_vector;
//std_vector.push_back(1);
//std_vector.push_back(41);
//std_vector.push_back(-71);
//std_vector.push_back(8);
//ft::vector<int> ft_vector(std_vector.begin(), std_vector.end());
//std::cout << "BEGIN" << std::endl;
//std::cout << "ft: " << *ft_vector.begin() << " | std: " << *std_vector.begin() << std::endl;
//std::cout << "END" << std::endl;
//std::cout << "ft: " << *(ft_vector.end() - 1) << " | std: " << *(std_vector.end() - 1) << std::endl;
//std::cout << "REV BEGIN" << std::endl;
//std::cout << "ft: " << *ft_vector.rbegin() << " | std: " << *std_vector.rbegin() << std::endl;
//std::cout << "REV END" << std::endl;
//std::cout << "ft: " << *(ft_vector.rend() - 1) << " | std: " << *(std_vector.rend() - 1) << std::endl;
//std::cout << "VECTOR SIZE" << std::endl;
//std::cout << "ft: " << ft_vector.size() << " | std: " << std_vector.size() << std::endl;
//std::cout << "VECTOR MAX_SIZE" << std::endl;
//std::cout << "ft: " << ft_vector.max_size() << " | std: " << std_vector.max_size() << std::endl;
//std::cout << "VECTOR CAPACITY" << std::endl;
//std::cout << "ft: " << ft_vector.capacity() << " | std: " << std_vector.capacity() << std::endl;
//
//ft_vector.resize(10);
//std_vector.resize(10);
//std::cout << "SIZE AFTER RESIZE" << std::endl;
//std::cout << "ft: " << ft_vector.size() << " | std: " << std_vector.size() << std::endl;
//print_vector(ft_vector);
//std::cout << "SIZE AFTER EMPTY FUNC USE" << std::endl;
//std::cout << "ft: " << ft_vector.empty()  << " | std: " << std_vector.empty() << std::endl;
//print_vector(ft_vector);
//std::cout << "SIZE AFTER EMPTY FUNC USE" << std::endl;
//std::cout << "ft: " << ft_vector.empty()  << " | std: " << std_vector.empty() << std::endl;
//print_vector(ft_vector);
//std::cout << "ft_vector[1]" << std::endl;
//std::cout << "ft: " << ft_vector[1]  << " | std: " << std_vector[1] << std::endl;
//print_vector(ft_vector);
//std::cout << "ft_vector.at(2)" << std::endl;
//std::cout << "ft: " << ft_vector.at(2) << " | std: " << std_vector.at(2) << std::endl;
//print_vector(ft_vector);
//std::cout << "ft_vector.front()" << std::endl;
//std::cout << "ft: " << ft_vector.front()  << " | std: " << std_vector.front() << std::endl;
//print_vector(ft_vector);
//std::cout << "ft_vector.back()" << std::endl;
//std::cout << "ft: " << ft_vector.back()  << " | std: " << std_vector.back() << std::endl;
//ft_vector.insert(ft_vector.begin(), 99);
//std_vector.insert(std_vector.begin(), 99);
//std::cout << "ft: " << ft_vector[0]  << " | std: " << std_vector[0] << std::endl;
//print_vector(ft_vector);
//
//ft_vector.erase(ft_vector.begin());
//std_vector.erase(std_vector.begin());
//std::cout << "ft: " << ft_vector[0]  << " | std: " << std_vector[0] << std::endl;
//print_vector(ft_vector);
//ft::vector<int> ft_swap(10,10);
//ft::vector<int>::iterator it = ft_swap.begin();
//ft_vector.swap(ft_swap);
//std::cout << "ft: " << (*(it + 2)) << std::endl;
//std::cout << "ft: " << (*(ft_swap.begin() + 2)) << std::endl;
//ft::vector<int>::const_iterator cit = ft_swap.begin() + 3;
//std::cout << "ft: " << ((ft_swap.begin() + 2) > cit) << std::endl;
//ft_swap.clear();
//std_vector.clear();
//std::cout << "ft: " << ft_swap.size()  << " | std: " << std_vector.size() << std::endl;
//std::cout << "ft: " << (ft_vector > ft_swap) << std::endl;
