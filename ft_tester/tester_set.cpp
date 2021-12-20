#include "tester_headers.hpp"
#include "../ft_set/ft_set.hpp"
#include <set>

void set_all_test() {
	ft::set<int> ft_set;
	ft_set.insert(99);
	ft_set.insert(1);
	ft_set.insert(1);
	ft_set.insert(7);
	ft_set.insert(5);
	ft_set.insert(2);
	ft_set.insert(10);

	std::set<int> std_set;
	std_set.insert(99);
	std_set.insert(1);
	std_set.insert(1);
	std_set.insert(7);
	std_set.insert(5);
	std_set.insert(2);
	std_set.insert(10);

	std::cout << "FT SET contains: ";
	for (ft::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "STD SET contains:";
	for (std::set<int>::iterator std_it = std_set.begin(); std_it != std_set.end(); ++std_it)
		std::cout << ' ' << *std_it;
	std::cout << std::endl;

	std::cout << "========================= BEGIN ========================" << std::endl;
	std::cout << "FTS::begin() = " << (*ft_set.begin()) << std::endl;
	std::cout << "STD::begin() = " << (*std_set.begin()) << std::endl;

	std::cout << "========================== END =========================" << std::endl;
	std::cout << "FTS::end() = " << (*(--ft_set.end())) << std::endl;
	std::cout << "STD::end() = " << (*(--std_set.end())) << std::endl;

	std::cout << "======================= REV BEGIN ======================" << std::endl;
	std::cout << "FTS::begin() = " << (*ft_set.rbegin()) << std::endl;
	std::cout << "STD::begin() = " << (*std_set.rbegin()) << std::endl;

	std::cout << "======================== REV END =======================" << std::endl;
	std::cout << "FTS::end() = " << (*(--ft_set.rend())) << std::endl;
	std::cout << "STD::end() = " << (*(--std_set.rend())) << std::endl;

	std::cout << "======================= MAX SIZE =======================" << std::endl;
	std::cout << "FTS::max_size() = " << ft_set.max_size() << std::endl;
	std::cout << "STD::max_size() = " << std_set.max_size() << std::endl;

	std::cout << "========================= SIZE =========================" << std::endl;
	std::cout << "FTS::size() = " << ft_set.size() << std::endl;
	std::cout << "STD::size() = " << std_set.size() << std::endl;

	std::cout << "========================= FIND =========================" << std::endl;
	ft::set<int>::iterator ft_iter;
	ft_iter = ft_set.find(1);
	std::set<int>::iterator std_it;
	std_it = std_set.find(1);

//	std::cout << "======================= ERASE - 1 ======================" << std::endl;
//	ft_set.erase(ft_iter);
//	std_set.erase(std_it);
//
//	std::cout << "FT SET contains: ";
//	for (ft::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << std::endl;
//
//	std::cout << "STD SET contains:";
//	for (std::set<int>::iterator st_it = std_set.begin(); st_it != std_set.end(); ++st_it)
//		std::cout << ' ' << *st_it;
//	std::cout << std::endl;
//
//	std::cout << "======================== EMPTY =========================" << std::endl;
//	std::cout << "FTS::empty() = " << ft_set.empty() << std::endl;
//	std::cout << "STD::empty() = " << std_set.empty() << std::endl;
//
//	std::cout << "========================= SIZE =========================" << std::endl;
//	std::cout << "FTS::size() = " << ft_set.size() << std::endl;
//	std::cout << "STD::size() = " << std_set.size() << std::endl;
//
//	std::cout << "======================== CLEAR =========================" << std::endl;
//	ft_set.clear();
//	std_set.clear();
//
//	std::cout << "========================= SIZE =========================" << std::endl;
//	std::cout << "FTS::size() = " << ft_set.size() << std::endl;
//	std::cout << "STD::size() = " << std_set.size() << std::endl;
}

void set_swap_test() {
	std::cout << "========================= SWAP =========================" << std::endl;
	ft::set<int> ft_first_set, ft_second_set;
	for (int i = 0; i < 10; i++) {
		ft_first_set.insert(i);
	}
	ft_first_set.swap(ft_second_set);
	std::cout << "ft_first_set contains: ";
	for (ft::set<int>::iterator it = ft_first_set.begin(); it != ft_first_set.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "ft_second_set contains: ";
	for (ft::set<int>::iterator it = ft_second_set.begin(); it != ft_second_set.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	ft_second_set.swap(ft_first_set);
	std::cout << "ft_first_set contains: ";
	for (ft::set<int>::iterator it = ft_first_set.begin(); it != ft_first_set.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "ft_second_set contains: ";
	for (ft::set<int>::iterator it = ft_second_set.begin(); it != ft_second_set.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

void set_count_test() {
	std::cout << "========================= COUNT ========================" << std::endl;
//	ft::set<int> ft_set;
//
//	for (int i = 1; i < 5; ++i) ft_set.insert(i * 3);    // set: 3 6 9 12
//
//	for (int i = 0; i < 10; ++i)
//	{
//		std::cout << i;
//		if (ft_set.count(i) != 0)
//			std::cout << " is an element of ft_set.\n";
//		else
//			std::cout << " is not an element of ft_set.\n";
//	}
}