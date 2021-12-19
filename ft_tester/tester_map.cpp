#include "../ft_tester/tester_headers.hpp"

void map_all_test() {
    std::map<std::string, int> std_map;
    std_map["Morpheus"] = 1;
    std_map["Neo"] = 777;
    std_map["Agent Smith"] = 66;
    std_map["Trinity"] = 77;
    std_map["Niobe"] = 0;

    ft::map<std::string, int> ft_map;
    ft_map["Morpheus"] = 1;
    ft_map["Neo"] = 777;
    ft_map["Agent Smith"] = 66;
    ft_map["Trinity"] = 77;
    ft_map["Niobe"] = 0;

	ft::map<std::string, int>::iterator ft_it;
	for (ft_it = ft_map.begin(); ft_it != ft_map.end(); ++ft_it)
		std::cout << ft_it->first << " => " << ft_it->second << std::endl;

	std::cout << "--------------------------------------------------------" << std::endl;
	std::map<std::string, int>::iterator std_it;
	for (std_it = std_map.begin(); std_it != std_map.end(); ++std_it)
		std::cout << std_it->first << " => " << std_it->second << std::endl;

	std::cout << "========================= BEGIN ========================" << std::endl;
    std::cout << "FTM::begin() = " << (*ft_map.begin()).first << " " << (*ft_map.begin()).second << std::endl;
    std::cout << "STD::begin() = " << (*std_map.begin()).first << " " <<  (*std_map.begin()).second << std::endl;

	std::cout << "========================== END =========================" << std::endl;
    std::cout << "FTM::end() = " << (*(--ft_map.end())).first << " " << (*(--ft_map.end())).second << std::endl;
    std::cout << "STD::end() = " << (*(--std_map.end())).first << " " << (*(--std_map.end())).second  << std::endl;

	std::cout << "======================= REV BEGIN ======================" << std::endl;
	 std::cout << "FTM::begin() = " << (*ft_map.rbegin()).first << " " << (*ft_map.rbegin()).second << std::endl;
	 std::cout << "STD::begin() = " << (*std_map.rbegin()).first << " " <<  (*std_map.rbegin()).second << std::endl;

	std::cout << "======================== REV END =======================" << std::endl;
	std::cout << "FTM::end() = " << (*(--ft_map.rend())).first << " " << (*(--ft_map.rend())).second << std::endl;
	std::cout << "STD::end() = " << (*(--std_map.rend())).first << " " << (*(--std_map.rend())).second  << std::endl;

	std::cout << "======================= MAX SIZE =======================" << std::endl;
	std::cout << "FTM::max_size() = " << ft_map.max_size() << std::endl;
	std::cout << "STD::max_size() = " << std_map.max_size() << std::endl;

	std::cout << "========================= SIZE =========================" << std::endl;
	std::cout << "FTM::size() = " << ft_map.size() << std::endl;
	std::cout << "STD::size() = " << std_map.size() << std::endl;

	std::cout << "====================== INSERT + 1 ======================" << std::endl;

	ft_map.insert(ft::pair<std::string, int>("The Analyst", 1000));
	std_map.insert(std::pair<std::string, int>("The Analyst", 1000));

	std::cout << "========================= SIZE =========================" << std::endl;
	std::cout << "FTM::size() = " << ft_map.size() << std::endl;
	std::cout << "STD::size() = " << std_map.size() << std::endl;

	std::cout << "========================= FIND =========================" << std::endl;
	std::cout << "FTM::find value = " << ((ft_map.find("The Analyst")->second)) << std::endl;
	std::cout << "STD::find value = " << ((std_map.find("The Analyst")->second)) << std::endl;

	std::cout << "FTM::find value = " << ((ft_map.find("Neo")->second)) << std::endl;
	std::cout << "STD::find value = " << ((std_map.find("Neo")->second)) << std::endl;

	std::cout << "======================== EMPTY =========================" << std::endl;
	std::cout << "FTM::empty() = " << ft_map.empty() << std::endl;
	std::cout << "STD::empty() = " << std_map.empty() << std::endl;

	std::cout << "======================= ERASE - 1 ======================" << std::endl;

	ft_it = ft_map.find("Agent Smith");
	ft_map.erase(ft_it);

	std_it = std_map.find("Agent Smith");
	std_map.erase(std_it);


	for (ft_it = ft_map.begin(); ft_it != ft_map.end(); ++ft_it)
		std::cout << ft_it->first << " => " << ft_it->second << std::endl;

	std::cout << "--------------------------------------------------------" << std::endl;

	for (std_it = std_map.begin(); std_it != std_map.end(); ++std_it)
		std::cout << std_it->first << " => " << std_it->second << std::endl;

	std::cout << "========================= SIZE =========================" << std::endl;
	std::cout << "FTM::size() = " << ft_map.size() << std::endl;
	std::cout << "STD::size() = " << std_map.size() << std::endl;

	std::cout << "======================== CLEAR =========================" << std::endl;
	ft_map.clear();
	std_map.clear();

	std::cout << "========================= SIZE =========================" << std::endl;
	std::cout << "FTM::size() = " << ft_map.size() << std::endl;
	std::cout << "STD::size() = " << std_map.size() << std::endl;
}

void map_swap_test() {
	std::cout << "========================= SWAP =========================" << std::endl;
	ft::map<int, std::string> ft_first_map, ft_second_map;
	for (int i = 0; i < 10; i++) {
		ft_first_map.insert(ft::pair<int, std::string>(i, "test_swap"));
	}

	ft_first_map.swap(ft_second_map);

	std::cout << "ft_first_map contains:\n";
	for (ft::map<int, std::string>::iterator it = ft_first_map.begin(); it != ft_first_map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << std::endl;

	std::cout << "ft_second_map contains:\n";
	for (ft::map<int, std::string>::iterator it = ft_second_map.begin(); it != ft_second_map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << std::endl;

	ft_second_map.swap(ft_first_map);

	std::cout << "ft_first_map contains:\n";
	for (ft::map<int, std::string>::iterator it = ft_first_map.begin(); it != ft_first_map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << std::endl;

	std::cout << "ft_second_map contains:\n";
	for (ft::map<int, std::string>::iterator it = ft_second_map.begin(); it != ft_second_map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << std::endl;
}

void map_count_test() {
	std::cout << "========================= COUNT ========================" << std::endl;
	ft::map<char, int> ft_map;
	char ch;

	ft_map['a'] = 101;
	ft_map['c'] = 202;
	ft_map['f'] = 303;

    std::cout << "FT MAP contains:" << std::endl;
	for (ch = 'a'; ch < 'h'; ch++)
	{
		std::cout << "\t" << ch;
		if (ft_map.count(ch) > 0)
			std::cout << " is an element of ft_map.\n";
		else
			std::cout << " is not an element of ft_map.\n";
	}

	std::cout << "--------------------------------------------------------" << std::endl;

	std::map<char, int> std_map;
	char c;

	std_map['a'] = 101;
	std_map['c'] = 202;
	std_map['f'] = 303;

    std::cout << "STD MAP contains:" << std::endl;
	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << "\t" << c;
		if (std_map.count(c) > 0)
			std::cout << " is an element of std_map.\n";
		else
			std::cout << " is not an element of std_map.\n";
	}
}

void map_bound_test() {
	std::cout << "========================= BOUND ========================" << std::endl;
	ft::map<std::string, int> ft_map;
	ft::map<std::string, int>::iterator ft_itlow, ft_itup;

    ft_map.insert(ft::pair<std::string, int>("Vector", 100));
    ft_map.insert(ft::pair<std::string, int>("Stack", 120));
    ft_map.insert(ft::pair<std::string, int>("Deque", 140));
    ft_map.insert(ft::pair<std::string, int>("Map", 160));
    ft_map.insert(ft::pair<std::string, int>("Set", 180));
    ft_map.insert(ft::pair<std::string, int>("MultiSet", 200));

	ft_itlow = ft_map.lower_bound("Stack");
	ft_itup = ft_map.upper_bound("Set");

	ft_map.erase(ft_itlow, ft_itup);
    std::cout << "FT MAP contains:" << std::endl;
	for (ft::map<std::string, int>::iterator it = ft_map.begin(); it != ft_map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;

	std::map<std::string, int> std_map;
	std::map<std::string, int>::iterator std_itlow, std_itup;

    std_map.insert(std::pair<std::string, int>("Vector", 100));
    std_map.insert(std::pair<std::string, int>("Stack", 120));
    std_map.insert(std::pair<std::string, int>("Deque", 140));
    std_map.insert(std::pair<std::string, int>("Map", 160));
    std_map.insert(std::pair<std::string, int>("Set", 180));
    std_map.insert(std::pair<std::string, int>("MultiSet", 200));

	std_itlow = std_map.lower_bound("Stack");
	std_itup = std_map.upper_bound("Set");

	std_map.erase(std_itlow, std_itup);
    std::cout << "STD MAP contains:" << std::endl;
	for (std::map<std::string, int>::iterator it = std_map.begin(); it != std_map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << std::endl;

}

void map_equal_range_test() {
    std::cout << "====================== EQUAL RANGE =====================" << std::endl;
    ft::map<int, const char*> ft_map;
    ft_map.insert(ft::pair<int, const char*>(0, "zero"));
    ft_map.insert(ft::pair<int, const char*>(1, "one"));
    ft_map.insert(ft::pair<int, const char*>(2, "two"));
    ft_map.insert(ft::pair<int, const char*>(3, "three"));
    ft_map.insert(ft::pair<int, const char*>(4, "four"));
    ft_map.insert(ft::pair<int, const char*>(5, "five"));

    ft::pair<ft::map<int, const char*>::iterator, ft::map<int, const char*>::iterator> ret;
    ret = ft_map.equal_range(4);
    std::cout << "FT MAP contains:" << std::endl;
    std::cout << "\tlower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << std::endl;

    std::cout << "\tupper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;

    std::map<int, const char*> std_map;
    std_map.insert(std::pair<int, const char*>(0, "zero"));
    std_map.insert(std::pair<int, const char*>(1, "one"));
    std_map.insert(std::pair<int, const char*>(2, "two"));
    std_map.insert(std::pair<int, const char*>(3, "three"));
    std_map.insert(std::pair<int, const char*>(4, "four"));
    std_map.insert(std::pair<int, const char*>(5, "five"));

    std::pair<std::map<int, const char*>::iterator, std::map<int, const char*>::iterator> std_ret;
    std_ret = std_map.equal_range(4);
    std::cout << "STD MAP contains:" << std::endl;
    std::cout << "\tlower bound points to: ";
    std::cout << std_ret.first->first << " => " << std_ret.first->second << std::endl;

    std::cout << "\tupper bound points to: ";
    std::cout << std_ret.second->first << " => " << std_ret.second->second << std::endl;
}

void map_value_compare_test() {
    std::cout << "===================== VALUE COMPARE ====================" << std::endl;
    ft::map<char,int> ft_map;
    ft_map['x'] = 1001;
    ft_map['y'] = 2002;
    ft_map['z'] = 3003;
    std::cout << "STD MAP contains:" << std::endl;
    ft::pair<char,int> ft_highest = *ft_map.rbegin();          // last element
    ft::map<char,int>::iterator ft_it = ft_map.begin();
    do {
        std::cout << "\t" << ft_it->first << " => " << ft_it->second << std::endl;
    } while ( ft_map.value_comp()(*ft_it++, ft_highest) );
    std::cout << "--------------------------------------------------------" << std::endl;
    std::map<char,int> std_map;
    std_map['x'] = 1001;
    std_map['y'] = 2002;
    std_map['z'] = 3003;
    std::cout << "STD MAP contains:" << std::endl;
    std::pair<char,int> highest = *std_map.rbegin();          // last element
    std::map<char,int>::iterator it = std_map.begin();
    do {
        std::cout << "\t" << it->first << " => " << it->second << std::endl;
    } while ( std_map.value_comp()(*it++, highest) );
}

void map_key_compare_test() {
    std::cout << "====================== KEY COMPARE =====================" << std::endl;
    ft::map<char, int> ft_map;
    ft::map<char, int>::key_compare my_comp = ft_map.key_comp();
    ft_map['a'] = 100;
    ft_map['b'] = 200;
    ft_map['c'] = 300;
    std::cout << "FT MAP contains:\n";
    char highest = ft_map.rbegin()->first; // key value of last element
    ft::map<char,int>::iterator it = ft_map.begin();
    do {
        std::cout << "\t" << it->first << " => " << it->second << std::endl;
    } while (my_comp((*it++).first, highest));
    std::cout << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;

    std::map<char, int> std_map;
    std::map<char, int>::key_compare std_comp = std_map.key_comp();
    std_map['a'] = 100;
    std_map['b'] = 200;
    std_map['c'] = 300;
    std::cout << "STD MAP contains:\n";
    char _highest = std_map.rbegin()->first; // key value of last element
    std::map<char,int>::iterator iter = std_map.begin();
    do {
        std::cout << "\t" << iter->first << " => " << iter->second << std::endl;
    } while (std_comp((*iter++).first, _highest));
    std::cout << std::endl;
}

void map_get_allocator_test() {
    std::cout << "===================== GET ALLOCATOR ====================" << std::endl;
    int psize;
    ft::map<char, int> ft_map;
    ft::pair<const char, int>* p;
    // allocate an array of 5 elements using ft_map's allocator:
    p = reinterpret_cast<ft::pair<const char, int> *>(ft_map.get_allocator().allocate(10));
    // assign some values to array
    psize = sizeof(ft::map<char, int>::value_type) * 10;
    std::cout << "FT MAP::The allocated array has a size of " << psize << " bytes.\n";
    ft_map.get_allocator().deallocate(reinterpret_cast<ft::Node<ft::pair<const char, int> > *>(p), 10);

    std::cout << "--------------------------------------------------------" << std::endl;

    int _psize;
    std::map<char, int> std_map;
    std::pair<const char, int>* po;
    // allocate an array of 5 elements using ft_map's allocator:
    po = reinterpret_cast<std::pair<const char, int> *>(std_map.get_allocator().allocate(10));
    // assign some values to array
    _psize = sizeof(ft::map<char, int>::value_type) * 10;
    std::cout << "STD MAP::The allocated array has a size of " << _psize << " bytes.\n";
    std_map.get_allocator().deallocate(po, 10);
}

void map_comparison_operator_test() {
    std::cout << "================== COMPARISON OPERATOR =================" << std::endl;
    ft::map<int, char> ft_map_1;
    ft_map_1.insert(ft::pair<char, int>('a', 1));
    ft_map_1.insert(ft::pair<char, int>('b', 2));
    ft_map_1.insert(ft::pair<char, int>('c', 3));
    ft_map_1.insert(ft::pair<char, int>('d', 4));
    ft_map_1.insert(ft::pair<char, int>('e', 5));

    ft::map<int, char> ft_map_2;
    ft_map_2.insert(ft::pair<char, int>('S', 6));
    ft_map_2.insert(ft::pair<char, int>('T', 7));
    ft_map_2.insert(ft::pair<char, int>('E', 8));
    ft_map_2.insert(ft::pair<char, int>('P', 9));
    ft_map_2.insert(ft::pair<char, int>('A', 10));
    ft_map_2.insert(ft::pair<char, int>('N', 11));

    ft::map<int, char> ft_map_3;
    ft_map_3.insert(ft::pair<char, int>('a', 1));
    ft_map_3.insert(ft::pair<char, int>('b', 2));
    ft_map_3.insert(ft::pair<char, int>('c', 3));
    ft_map_3.insert(ft::pair<char, int>('d', 4));
    ft_map_3.insert(ft::pair<char, int>('e', 5));

    std::cout << "ft_map_1 == ft_map_2 return " << (ft_map_1 == ft_map_2) << std::endl;
    std::cout << "ft_map_1 != ft_map_2 return " << (ft_map_1 != ft_map_2) << std::endl;
    std::cout << "ft_map_1 <  ft_map_2 return " << (ft_map_1 < ft_map_2) << std::endl;
    std::cout << "ft_map_1 <= ft_map_2 return " << (ft_map_1 <= ft_map_2) << std::endl;
    std::cout << "ft_map_1 >  ft_map_2 return " << (ft_map_1 > ft_map_2) << std::endl;
    std::cout << "ft_map_1 >= ft_map_2 return " << (ft_map_1 >= ft_map_2) << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "ft_map_1 == ft_map_3 return " << (ft_map_1 == ft_map_3) << std::endl;
    std::cout << "ft_map_1 != ft_map_3 return " << (ft_map_1 != ft_map_3) << std::endl;
    std::cout << "ft_map_1 <  ft_map_3 return " << (ft_map_1 < ft_map_3) << std::endl;
    std::cout << "ft_map_1 <= ft_map_3 return " << (ft_map_1 <= ft_map_3) << std::endl;
    std::cout << "ft_map_1 >  ft_map_3 return " << (ft_map_1 > ft_map_3) << std::endl;
    std::cout << "ft_map_1 >= ft_map_3 return " << (ft_map_1 >= ft_map_3) << std::endl;
}

void map_make_pair_test() {
    std::cout << "======================= MAKE PAIR ======================" << std::endl;

    ft::pair <int, int> ft_foo;
    ft::pair <int, int> ft_bar;

    ft_foo = ft::make_pair (100, 200);
    ft_bar = ft::make_pair (100.5, 'W'); // ok: implicit conversion from pair<double,char>

    std::cout << "ft_foo: " << ft_foo.first << ", " << ft_foo.second << std::endl;
    std::cout << "ft_bar: " << ft_bar.first << ", " << ft_bar.second << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;

    std::pair <int, int> std_foo;
    std::pair <int, int> std_bar;

    std_foo = std::make_pair (100, 200);
    std_bar = std::make_pair (100.5, 'W'); // ok: implicit conversion from pair<double,char>

    std::cout << "std_foo: " << std_foo.first << ", " << std_foo.second << std::endl;
    std::cout << "std_bar: " << std_bar.first << ", " << std_bar.second << std::endl;
}

void map_speed_test() {
	std::cout << "====================== SPEED TEST ======================" << std::endl;
	unsigned int ft_start_time = clock();
	ft::map<int, std::string>::iterator ft_it;
	ft::map<int, std::string> ft_map;
	for (int i = 0; i < 1000000; i++) {
		ft_map.insert(ft::pair<int, std::string>(i, "test"));
	}
	ft_it = ft_map.find (500000);
	ft_map.erase(ft_it, ft_map.end());
	std::cout << "FTM::size() = " << ft_map.size() << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTM TIME = " << ft_diff_time << std::endl;

	std::cout << "--------------------------------------------------------" << std::endl;

	unsigned int std_start_time = clock();
	std::map<int, std::string>::iterator std_it;
	std::map<int, std::string> std_map;
	for (int i = 0; i < 1000000; i++) {
		std_map.insert(std::pair<int, std::string>(i, "test"));
	}
	std_it = std_map.find (500000);
	std_map.erase(std_it, std_map.end());
	std::cout << "STD::size() = " << std_map.size() << std::endl;
	unsigned int std_finish_time = clock();
	unsigned int std_diff_time = std_finish_time - std_start_time;
	std::cout << "STD TIME = " << std_diff_time << std::endl;
}