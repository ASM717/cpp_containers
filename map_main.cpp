#include <iostream>
#include "ft_map/ft_red_black_tree.hpp"

#include "ft_map/ft_map.hpp"

int main() {

//	ft::RBTree<int, std::string> test;
//	test.insert(ft::pair<int, std::string>(8, "test"));
//	test.test_show_tree();
//	std::cout << "-------------------------------------------------" << std::endl;
//	test.insert(ft::pair<int, std::string>(11, "test"));
//	test.test_show_tree();
//	std::cout << "-------------------------------------------------" << std::endl;
//	test.insert(ft::pair<int, std::string>(20, "test"));
//	test.test_show_tree();
//	std::cout << "-------------------------------------------------" << std::endl;
//	test.insert(ft::pair<int, std::string>(25, "test"));
//	test.test_show_tree();
//	std::cout << "-------------------------------------------------" << std::endl;
//	test.insert(ft::pair<int, std::string>(30, "test"));
//	test.test_show_tree();
//	std::cout << "-------------------------------------------------" << std::endl;
//	test.insert(ft::pair<int, std::string>(19, "test"));
//	test.test_show_tree();
//	std::cout << "-------------------------------------------------" << std::endl;
//	test.insert(ft::pair<int, std::string>(18, "test"));
//	test.test_show_tree();
//	std::cout << "-------------------------------------------------" << std::endl;
//	test.insert(ft::pair<int, std::string>(17, "test"));
//	test.test_show_tree();
//	std::cout << "-------------------------------------------------" << std::endl;
//	test.display();

	ft::map<int, std::string> test;
	test.insert(ft::pair<int, std::string>(8, "test"));
	test.insert(ft::pair<int, std::string>(11, "test"));
	test.insert(ft::pair<int, std::string>(12, "test"));
	test.insert(ft::pair<int, std::string>(5, "test"));
//	test.test_show_tree();
	std::cout << test.begin()->first << std::endl;

}
