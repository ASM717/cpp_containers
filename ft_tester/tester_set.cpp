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

	std::cout << "======================= ERASE - 1 ======================" << std::endl;
	ft_set.erase(ft_iter);
	std_set.erase(std_it);

	std::cout << "FT SET contains: ";
	for (ft::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "STD SET contains:";
	for (std::set<int>::iterator st_it = std_set.begin(); st_it != std_set.end(); ++st_it)
		std::cout << ' ' << *st_it;
	std::cout << std::endl;

	std::cout << "======================== EMPTY =========================" << std::endl;
	std::cout << "FTS::empty() = " << ft_set.empty() << std::endl;
	std::cout << "STD::empty() = " << std_set.empty() << std::endl;

	std::cout << "========================= SIZE =========================" << std::endl;
	std::cout << "FTS::size() = " << ft_set.size() << std::endl;
	std::cout << "STD::size() = " << std_set.size() << std::endl;

	std::cout << "======================== CLEAR =========================" << std::endl;
	ft_set.clear();
	std_set.clear();

	std::cout << "========================= SIZE =========================" << std::endl;
	std::cout << "FTS::size() = " << ft_set.size() << std::endl;
	std::cout << "STD::size() = " << std_set.size() << std::endl;
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
	std::cout << "ft_first_set contains:  ";
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
	ft::set<int> ft_set;

	for (int i = 1; i < 5; ++i)
		ft_set.insert(i * 3);    // set: 3 6 9 12

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i;
		if (ft_set.count(i) != 0)
			std::cout << " is an element of ft_set.\n";
		else
			std::cout << " is not an element of ft_set.\n";
	}

	std::cout << "--------------------------------------------------------" << std::endl;

	std::set<int> std_set;

	for (int i = 1; i < 5; ++i)
		std_set.insert(i * 3);    // set: 3 6 9 12

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i;
		if (std_set.count(i) != 0)
			std::cout << " is an element of std_set.\n";
		else
			std::cout << " is not an element of std_set.\n";
	}
}

void set_bound_test() {
	std::cout << "========================= BOUND ========================" << std::endl;
	ft::set<int> ft_set;
	ft::set<int>::iterator ft_itlow, ft_itup;

	for (int i = 1; i < 10; i++)
		ft_set.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	ft_itlow = ft_set.lower_bound (30);
	ft_itup = ft_set.upper_bound (60);

	ft_set.erase(ft_itlow, ft_itup); // 10 20 70 80 90

	std::cout << "ft_set contains: ";
	for (ft::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "--------------------------------------------------------" << std::endl;

	std::set<int> std_set;
	std::set<int>::iterator std_itlow, std_itup;

	for (int i = 1; i < 10; i++)
		std_set.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	std_itlow = std_set.lower_bound (30);
	std_itup = std_set.upper_bound (60);

	std_set.erase(std_itlow, std_itup); // 10 20 70 80 90

	std::cout << "std_set contains:";
	for (std::set<int>::iterator std_it = std_set.begin(); std_it != std_set.end(); ++std_it)
		std::cout << ' ' << *std_it;
	std::cout << std::endl;

}

void set_equal_range_test() {
	std::cout << "====================== EQUAL RANGE =====================" << std::endl;
	ft::set<int> ft_set;
	for (int i = 1; i <= 5; i++)
		ft_set.insert(i * 10);   // ft_set: 10 20 30 40 50
	ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> cret;
	cret = ft_set.equal_range(30);

	std::cout << "FT SET :: the lower bound points to: " << *cret.first << std::endl;
	std::cout << "FT SET :: the upper bound points to: " << *cret.second << std::endl;

	std::cout << "--------------------------------------------------------" << std::endl;

	std::set<int> std_set;
	for (int i = 1; i <= 5; i++)
		std_set.insert(i * 10);   // ft_set: 10 20 30 40 50
	std::pair<std::set<int>::iterator, std::set<int>::iterator> ret;
	ret = std_set.equal_range(30);

	std::cout << "STD SET:: the lower bound points to: " << *ret.first << std::endl;
	std::cout << "STD SET:: the upper bound points to: " << *ret.second << std::endl;
}

//void set_get_allocator_test() {
//    std::cout << "===================== GET ALLOCATOR ====================" << std::endl;
//    ft::set<int> ft_set;
//    int * p;
//    int i;
//
//    // allocate an array of 5 elements using ft_set's allocator:
//    p = ft_set.get_allocator().allocate(5);
//
//    // assign some values to array
//    for (i = 0; i < 5; i++)
//        p[i] = (i + 1) * 10;
//
//    std::cout << "The allocated array contains:";
//    for (i = 0; i < 5; i++)
//        std::cout << ' ' << p[i];
//    std::cout << '\n';
//
//    ft_set.get_allocator().deallocate(p, 5);
//}

void set_comparison_operator_test() {
    std::cout << "================== COMPARISON OPERATOR =================" << std::endl;
//
//    ft::set<int> ft_set_1;
//    ft_set_1.insert(1);
//    ft_set_1.insert(2);
//    ft_set_1.insert(3);
//    ft_set_1.insert(4);
//    ft_set_1.insert(5);
//
//    ft::set<int> ft_set_2;
//    ft_set_2.insert(1);
//    ft_set_2.insert(2);
//    ft_set_2.insert(3);
//    ft_set_2.insert(4);
//    ft_set_2.insert(5);
//    ft_set_2.insert(6);
//    ft_set_2.insert(7);
//
//    ft::set<int> ft_set_3;
//    ft_set_3.insert(1);
//    ft_set_3.insert(2);
//    ft_set_3.insert(3);
//    ft_set_3.insert(4);
//    ft_set_3.insert(5);
//
//    std::cout << "ft_set_1 == ft_set_2 return " << (ft_set_1 == ft_set_2) << std::endl;
//    std::cout << "ft_set_1 != ft_set_2 return " << (ft_set_1 != ft_set_2) << std::endl;
//    std::cout << "ft_set_1 <  ft_set_2 return " << (ft_set_1 < ft_set_2) << std::endl;
//    std::cout << "ft_set_1 <= ft_set_2 return " << (ft_set_1 <= ft_set_2) << std::endl;
//    std::cout << "ft_set_1 >  ft_set_2 return " << (ft_set_1 > ft_set_2) << std::endl;
//    std::cout << "ft_set_1 >= ft_set_2 return " << (ft_set_1 >= ft_set_2) << std::endl;
//    std::cout << "--------------------------------------------------------" << std::endl;
//    std::cout << "ft_set_1 == ft_map_3 return " << (ft_set_1 == ft_set_3) << std::endl;
//    std::cout << "ft_set_1 != ft_map_3 return " << (ft_set_1 != ft_set_3) << std::endl;
//    std::cout << "ft_set_1 <  ft_map_3 return " << (ft_set_1 < ft_set_3) << std::endl;
//    std::cout << "ft_set_1 <= ft_map_3 return " << (ft_set_1 <= ft_set_3) << std::endl;
//    std::cout << "ft_set_1 >  ft_map_3 return " << (ft_set_1 > ft_set_3) << std::endl;
//    std::cout << "ft_set_1 >= ft_map_3 return " << (ft_set_1 >= ft_set_3) << std::endl;
}