#include "rb_tree.hpp"
#include "map.hpp"

int main() {

	ft::map<int, std::string> test;
	test.insert(ft::pair<int, std::string>(8, "test"));
	test.insert(ft::pair<int, std::string>(11, "test"));
	test.insert(ft::pair<int, std::string>(12, "test"));
	test.insert(ft::pair<int, std::string>(5, "test"));
//	test.test_show_tree();
	std::cout << test.begin()->first << std::endl;

}