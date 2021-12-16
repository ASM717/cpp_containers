#include "ft_map/ft_map.hpp"
#include <map>

void map_begin_end_test() {
	std::map<char,int> std_map;

	std_map['b'] = 100;
	std_map['a'] = 200;
	std_map['c'] = 300;

	// show content:
	for (std::map<char, int>::iterator it = std_map.begin(); it != std_map.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';


	ft::map<char,int> ft_map;

	ft_map['b'] = 100;
	ft_map['a'] = 200;
	ft_map['c'] = 300;

	// show content:
	for (ft::map<char, int>::iterator ft_it = ft_map.begin(); ft_it != ft_map.end(); ++ft_it)
		std::cout << ft_it->first << " => " << ft_it->second << '\n';
}

void map_insert_erase_test() {
	ft::map<int, std::string> test;
	for (size_t i = 0; i <= 5; i++) {

		test.insert(ft::pair<int, std::string>(i, "test"));
	}
//	std::cout << (test.begin()->first) << std::endl;
//	std::cout << (test.begin()->second) << std::endl;
//	std::cout << (test.end()->first) << std::endl;
//	std::cout << (test.end()->second) << std::endl;

	test.display();
}

int main() {
//    ft::map<int, std::string> test;
//    test.insert(ft::pair<int, std::string>(8, "test"));
//
//	std::cout << (test.begin()->first) << std::endl;



	//map_begin_end_test();
	map_insert_erase_test();
	return 0;

}

