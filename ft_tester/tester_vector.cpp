#include "tester_headers.hpp"

void vector_max_size_test() {
	std::cout << "====================== MAX SIZE ========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	// set some content in the vector:
	for (int i = 0; i < 100; i++)
		std_vector.push_back(i);
	std::cout << "STD::size: " << std_vector.size() << std::endl;
	std::cout << "STD::capacity: " << std_vector.capacity() << std::endl;
	std::cout << "STD::max_size: " << std_vector.max_size() << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;
	std::cout << "----------------------------------" << std::endl;
	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	// set some content in the vector:
	for (int i = 0; i < 100; i++)
		ft_vector.push_back(i);
	std::cout << "FTV::size: " << ft_vector.size() << std::endl;
	std::cout << "FTV::capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "FTV::max_size: " << ft_vector.max_size() << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_size_test() {
	std::cout << "========================= SIZE =========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	std::cout << "STD::0. size: " << std_vector.size() << std::endl;
	for (int i = 0; i < 10; i++)
		std_vector.push_back(i);
	std::cout << "STD::1. size: " << std_vector.size() << std::endl;
	std_vector.insert(std_vector.end(), 10, 100);
	std::cout << "STD::2. size: " << std_vector.size() << std::endl;
	std_vector.pop_back();
	std::cout << "STD::3. size: " << std_vector.size() << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;
	std::cout << "-----------------" << std::endl;
	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	std::cout << "FTV::0. size: " << ft_vector.size() << std::endl;
	for (int i = 0; i < 10; i++)
		ft_vector.push_back(i);
	std::cout << "FTV::1. size: " << ft_vector.size() << std::endl;
	ft_vector.insert(ft_vector.end(), 10, 100);
	std::cout << "FTV::2. size: " << ft_vector.size() << std::endl;
	ft_vector.pop_back();
	std::cout << "FTV::3. size: " << ft_vector.size() << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_constructor_test() {
	std::cout << "===================== CONSTRUCTOR ======================" << std::endl;
	// constructors used in the same order as described above:
	unsigned int start_time = clock();
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {17,1,78,14};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "STD::The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> first1;                                // empty vector of ints
	ft::vector<int> second2 (4,100);                       // four ints with value 100
	ft::vector<int> third3 (second2.begin(),second2.end());  // iterating through second
	ft::vector<int> fourth4 (third3);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints_v[] = {17,1,78,14};
	ft::vector<int> fifth5 (myints_v, myints_v + sizeof(myints_v) / sizeof(int) );

	std::cout << "FTV::The contents of fifth are:";
	for (ft::vector<int>::iterator it_ft = fifth5.begin(); it_ft != fifth5.end(); ++it_ft)
		std::cout << ' ' << *it_ft;
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_operator_equel_test() {
	std::cout << "=================== ASSIGN  OPERATOR ===================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> foo (3,0);
	std::vector<int> bar (5,0);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "STD::Size of foo: " << int(foo.size()) << std::endl;
	std::cout << "STD::Size of bar: " << int(bar.size()) << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_foo (3,0);
	ft::vector<int> ft_bar (5,0);

	ft_bar = ft_foo;
	ft_foo = ft::vector<int>();

	std::cout << "FTV::Size of foo: " << int(ft_foo.size()) << std::endl;
	std::cout << "FTV::Size of bar: " << int(ft_bar.size()) << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_iterator_test() {
	std::cout << "======================= ITERATOR =======================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	for (int i = 1; i <= 5; i++) std_vector.push_back(i);

	std::cout << "STD::vector contains:";
	for (std::vector<int>::iterator it = std_vector.begin() ; it != std_vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);

	std::cout << "FTV::vector contains:";
	for (ft::vector<int>::iterator ft_it = ft_vector.begin() ; ft_it != ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_reverse_iterator_test() {
	std::cout << "=================== REVERSE ITERATOR ===================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector (5);  // 5 default-constructed ints
	int i = 0;
	std::vector<int>::reverse_iterator std_rit = std_vector.rbegin();
	for (; std_rit != std_vector.rend(); ++std_rit)
		*std_rit = ++i;
	std::cout << "STD::vector contains:";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector (5);  // 5 default-constructed ints
	int j = 0;
	ft::vector<int>::reverse_iterator ft_rit = ft_vector.rbegin();
	for (; ft_rit != ft_vector.rend(); ++ft_rit)
		*ft_rit = ++j;
	std::cout << "FTV::vector contains:";
	for (ft::vector<int>::iterator ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_resize_test() {
	std::cout << "======================= RESIZE =========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	// set some initial content:
	for (unsigned long i = 1; i < 10; i++) std_vector.push_back(i);
	std_vector.resize(5);
	std_vector.resize(8, 100);
	std_vector.resize(12);
	std::cout << "STD::vector contains:";
	for (unsigned long i = 0; i < std_vector.size(); i++)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	// set some initial content:
	for (unsigned long i = 1; i < 10; i++) ft_vector.push_back(i);
	ft_vector.resize(5);
	ft_vector.resize(8, 100);
	ft_vector.resize(12);
	std::cout << "FTV::vector contains:";
	for (unsigned long i = 0; i < ft_vector.size(); i++)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_empty_test() {
	std::cout << "======================= EMPTY ==========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	int sum (0);
	for (int i = 1; i <= 10; i++)
		std_vector.push_back(i);
	while (!std_vector.empty())
	{
		sum += std_vector.back();
		std_vector.pop_back();
	}
	std::cout << "STD::total: " << sum << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	int ft_sum (0);
	for (int i = 1; i <= 10; i++)
		ft_vector.push_back(i);
	while (!ft_vector.empty())
	{
		ft_sum += ft_vector.back();
		ft_vector.pop_back();
	}
	std::cout << "FTV::total: " << ft_sum << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_reserve_test() {
	std::cout << "====================== RESERVE =========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int>::size_type sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "STD::making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "STD::capacity changed: " << sz << std::endl;
		}
	}
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "STD::making bar grow:\n";
	for (int i = 0; i < 100; ++i) {
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			std::cout << "STD::capacity changed: " << sz << std::endl;
		}
	}
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;
	std::cout << "------------------------------------" << std::endl;
	unsigned int ft_start_time = clock();
	ft::vector<int>::size_type ft_sz;
	ft::vector<int> ft_foo;
	ft_sz = ft_foo.capacity();
	std::cout << "FTV::making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		ft_foo.push_back(i);
		if (ft_sz != ft_foo.capacity()) {
			ft_sz = ft_foo.capacity();
			std::cout << "FTV::capacity changed: " << ft_sz << std::endl;
		}
	}
	ft::vector<int> ft_bar;
	ft_sz = ft_bar.capacity();
	ft_bar.reserve(100);   // this is the only difference with foo above
	std::cout << "FTV::making bar grow:\n";
	for (int i = 0; i < 100; ++i) {
		ft_bar.push_back(i);
		if (ft_sz != ft_bar.capacity()) {
			ft_sz = ft_bar.capacity();
			std::cout << "FTV::capacity changed: " << ft_sz << std::endl;
		}
	}
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

// vector::operator[]
void vector_operator_el_pos_test() {
	std::cout << "====================== OPERATOR[] ======================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector (10);   // 10 zero-initialized elements
	std::vector<int>::size_type sz = std_vector.size();
	// assign some values:
	for (unsigned i = 0; i < sz; i++)
		std_vector[i] = i;
	// reverse vector using operator[]:
	for (unsigned i = 0; i < sz/2; i++)
	{
		int temp;
		temp = std_vector[sz - 1 - i];
		std_vector[sz - 1 - i] = std_vector[i];
		std_vector[i] = temp;
	}
	std::cout << "STD::vector contains:";
	for (unsigned i = 0; i < sz; i++)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector (10);   // 10 zero-initialized elements
	ft::vector<int>::size_type ft_sz = ft_vector.size();
	// assign some values:
	for (unsigned i = 0; i < ft_sz; i++)
		ft_vector[i] = i;
	// reverse vector using operator[]:
	for (unsigned i = 0; i < ft_sz/2; i++)
	{
		int temp;
		temp = ft_vector[ft_sz - 1 - i];
		ft_vector[ft_sz - 1 - i] = ft_vector[i];
		ft_vector[i] = temp;
	}
	std::cout << "FTV::vector contains:";
	for (unsigned i = 0; i < ft_sz; i++)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_at_test() {
	std::cout << "========================== AT ==========================" << std::endl;
	std::vector<int> std_vector (10);   // 10 zero-initialized ints
	// assign some values:
	for (unsigned int i = 0; i < std_vector.size(); i++)
		std_vector.at(i) = i;
	std::cout << "STD::vector contains:";
	for (unsigned int i = 0; i < std_vector.size(); i++)
		std::cout << ' ' << std_vector.at(i);
	std::cout << std::endl;

	ft::vector<int> ft_vector (10);   // 10 zero-initialized ints
	// assign some values:
	for (unsigned int i = 0; i < ft_vector.size(); i++)
		ft_vector.at(i) = i;
	std::cout << "FTV::vector contains:";
	for (unsigned int i = 0; i < ft_vector.size(); i++)
		std::cout << ' ' << ft_vector.at(i);
	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	//error range (at)
	std::vector<int> std_err_v(10);
	try {
		std_err_v.at(20) = 100;      // vector::at throws an out-of-range
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "STD::Out of Range error: " << oor.what() << std::endl;
	}

	ft::vector<int> ft_err_v(10);
	try {
		ft_err_v.at(20) = 100;      // vector::at throws an out-of-range
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "FTV::Out of Range error: " << oor.what() << std::endl;
	}
}

void vector_front_test() {
	std::cout << "======================== FRONT =========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	std_vector.push_back(78);
	std_vector.push_back(16);
	// now front equals 78, and back 16
	std_vector.front() -= std_vector.back();
	std::cout << "STD::vector.front() is now " << std_vector.front() << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	ft_vector.push_back(78);
	ft_vector.push_back(16);
	// now front equals 78, and back 16
	ft_vector.front() -= ft_vector.back();
	std::cout << "FTV::vector.front() is now " << ft_vector.front() << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_back_test() {
	std::cout << "========================= BACK =========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	std_vector.push_back(10);
	while (std_vector.back() != 0)
	{
		std_vector.push_back (std_vector.back() - 1);
	}
	std::cout << "STD::vector contains:";
	for (unsigned i = 0; i < std_vector.size(); i++)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	ft_vector.push_back(10);
	while (ft_vector.back() != 0)
	{
		ft_vector.push_back (ft_vector.back() - 1);
	}
	std::cout << "FTV::vector contains:";
	for (unsigned i = 0; i < ft_vector.size(); i++)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_assign_test() {
	std::cout << "======================== ASSIGN ========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;
	first.assign (7,100);             // 7 ints with a value of 100
	std::vector<int>::iterator it;
	it = first.begin() + 1;
	second.assign (it, first.end() - 1); // the 5 central values of first

	int std_ints[] = {1776, 7, 4};
	third.assign(std_ints, std_ints + 3);   // assigning from array.

	std::cout << "STD::Size of first: " << int (first.size()) << std::endl;
	std::cout << "STD::Size of second: " << int (second.size()) << std::endl;
	std::cout << "STD::Size of third: " << int (third.size()) << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	std::cout << "-------------------------------" << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_first;
	ft::vector<int> ft_second;
	ft::vector<int> ft_third;
	ft_first.assign(7,100);             // 7 ints with a value of 100
	ft::vector<int>::iterator ft_it;
	ft_it = ft_first.begin() + 1;
	ft_second.assign(ft_it, ft_first.end() - 1); // the 5 central values of first

	int ft_ints[] = {1776, 7, 4};
	ft_third.assign(ft_ints, ft_ints + 3);   // assigning from array.

	std::cout << "FTV::Size of first: " << int (ft_first.size()) << std::endl;
	std::cout << "FTV::Size of second: " << int (ft_second.size()) << std::endl;
	std::cout << "FTV::Size of third: " << int (ft_third.size()) << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_push_pop_test() {
	std::cout << "====================== PUSH _ POP ======================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	int sum (0);
	std_vector.push_back (100);
	std_vector.push_back (200);
	std_vector.push_back (300);
	while (!std_vector.empty())
	{
		sum += std_vector.back();
		std_vector.pop_back();
	}
	std::cout << "STD::The elements of vector add up to " << sum << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	int ft_sum (0);
	ft_vector.push_back (100);
	ft_vector.push_back (200);
	ft_vector.push_back (300);
	while (!ft_vector.empty())
	{
		ft_sum += ft_vector.back();
		ft_vector.pop_back();
	}
	std::cout << "FTV::The elements of vector add up to " << ft_sum << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_insert_test() {
	std::cout << "======================== INSERT ========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector (3, 1000000);
	std::vector<int>::iterator it;

	it = std_vector.begin();
	it = std_vector.insert (it , 200 );

	std_vector.insert (it, 2, 300);

	// "it" no longer valid, get a new one:
	it = std_vector.begin();

	std::vector<int> std_anothervector (2, 400);
	std_vector.insert(it + 2, std_anothervector.begin(), std_anothervector.end());

	int myarray [] = {707,717,777};
	std_vector.insert (std_vector.begin(), myarray, myarray + 3);

	std::cout << "STD::vector contains:";
	for (it = std_vector.begin(); it < std_vector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector (3, 1000000);
	ft::vector<int>::iterator ft_it;

	ft_it = ft_vector.begin();
	ft_it = ft_vector.insert(ft_it , 200 );

	ft_vector.insert(ft_it, 2, 300);

	// "ft_it" no longer valid, get a new one:
	ft_it = ft_vector.begin();

	ft::vector<int> ft_anothervector (2, 400);
	ft_vector.insert(ft_it + 2, ft_anothervector.begin(), ft_anothervector.end());

	int ft_myarray [] = {707,717,777};
	ft_vector.insert(ft_vector.begin(), ft_myarray, ft_myarray + 3);

	std::cout << "FTV::vector contains:";
	for (ft_it = ft_vector.begin(); ft_it < ft_vector.end(); ft_it++)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_erase_test() {
	std::cout << "======================== ERASE =========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++) std_vector.push_back(i);
	std::cout << "STD::vector contains after push back:";
	for (unsigned int i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;

	// erase the 6th element
	std_vector.erase(std_vector.begin() + 5);
	std::cout << "STD::vector contains after erase:";
	for (unsigned int i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;

	// erase the first 3 elements:
	std_vector.erase(std_vector.begin(), std_vector.begin() + 3);

	std::cout << "STD::vector contains:";
	for (unsigned int i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++) ft_vector.push_back(i);

	std::cout << "FTV::vector contains after push back:";
	for (unsigned int i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;
	// erase the 6th element
	ft_vector.erase(ft_vector.begin() + 5);
	std::cout << "FTV::vector contains after erase:";
	for (unsigned int i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;

	// erase the first 3 elements:
	ft_vector.erase(ft_vector.begin(), ft_vector.begin() + 3);

	std::cout << "FTV::vector contains:";
	for (unsigned int i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_swap_test() {
	std::cout << "========================= SWAP =========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_foo (3, 100);   // three ints with a value of 100
	std::vector<int> std_bar (5, 200);   // five ints with a value of 200

	std_foo.swap(std_bar);

	std::cout << "STD::std_foo contains:";
	for (unsigned int i = 0; i < std_foo.size(); i++)
		std::cout << ' ' << std_foo[i];
	std::cout << std::endl;

	std::cout << "STD::std_bar contains:";
	for (unsigned int i = 0; i < std_bar.size(); i++)
		std::cout << ' ' << std_bar[i];
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	unsigned int ft_start_time = clock();
	ft::vector<int> ft_foo (3, 100);   // three ints with a value of 100
	ft::vector<int> ft_bar (5, 200);   // five ints with a value of 200

	ft_foo.swap(ft_bar);

	std::cout << "FTV::std_foo contains:";
	for (unsigned int i = 0; i < ft_foo.size(); i++)
		std::cout << ' ' << ft_foo[i];
	std::cout << std::endl;

	std::cout << "FTV::std_bar contains:";
	for (unsigned int i = 0; i < ft_bar.size(); i++)
		std::cout << ' ' << ft_bar[i];
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_clear_test() {
	std::cout << "======================== CLEAR ========================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	std_vector.push_back (100);
	std_vector.push_back (200);
	std_vector.push_back (300);

	std::cout << "STD::vector contains:";
	for (unsigned int i = 0; i < std_vector.size(); i++)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;

	std_vector.clear();
	std_vector.push_back (1101);
	std_vector.push_back (2202);

	std::cout << "STD::vector contains:";
	for (unsigned i = 0; i < std_vector.size(); i++)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	std::cout << "------------------------------------------" << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	ft_vector.push_back (100);
	ft_vector.push_back (200);
	ft_vector.push_back (300);

	std::cout << "FTV::vector contains:";
	for (unsigned int i = 0; i < ft_vector.size(); i++)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;

	ft_vector.clear();
	ft_vector.push_back (1101);
	ft_vector.push_back (2202);

	std::cout << "FTV::vector contains:";
	for (unsigned i = 0; i < ft_vector.size(); i++)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_get_allocator_test() {
	std::cout << "==================== GET ALLOCATOR ====================" << std::endl;
	unsigned int start_time = clock();
	std::vector<int> std_vector;
	int *p;

	// allocate an array with space for 5 elements using vector's allocator:
	p = std_vector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (unsigned int i = 0; i < 5; i++) std_vector.get_allocator().construct(&p[i], i);

	std::cout << "STD::The allocated array contains:";
	for (unsigned int i = 0; i < 5; i++) std::cout << ' ' << p[i];
	std::cout << std::endl;

	// destroy and deallocate:
	for (unsigned int i = 0; i < 5; i++) std_vector.get_allocator().destroy(&p[i]);
	std_vector.get_allocator().deallocate(p, 5);
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::vector<int> ft_vector;
	int *q;

	// allocate an array with space for 5 elements using vector's allocator:
	q = ft_vector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (unsigned int i = 0; i < 5; i++) ft_vector.get_allocator().construct(&q[i], i);

	std::cout << "FTV::The allocated array contains:";
	for (unsigned int i = 0; i < 5; i++) std::cout << ' ' << q[i];
	std::cout << std::endl;

	// destroy and deallocate:
	for (unsigned int i = 0; i < 5; i++) ft_vector.get_allocator().destroy(&q[i]);
	ft_vector.get_allocator().deallocate(q, 5);
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_relational_operators_test() {
	std::cout << "================= RELATIONAL OPERATORS =================" << std::endl;
	std::vector<int> std_foo (3, 100);   // three ints with a value of 100
	std::vector<int> std_bar (2, 200);   // two ints with a value of 200

	if (std_foo == std_bar) std::cout << "std_foo and std_bar are equal\n";
	if (std_foo != std_bar) std::cout << "std_foo and std_bar are not equal\n";
	if (std_foo < std_bar) std::cout << "std_foo is less than std_bar\n";
	if (std_foo > std_bar) std::cout << "std_foo is greater than std_bar\n";
	if (std_foo <= std_bar) std::cout << "std_foo is less than or equal to std_bar\n";
	if (std_foo >= std_bar) std::cout << "std_foo is greater than or equal to std_bar\n";

	std::cout << "------------------------------------------" << std::endl;
	ft::vector<int> ft_foo (3, 100);   // three ints with a value of 100
	ft::vector<int> ft_bar (2, 200);   // two ints with a value of 200

	if (ft_foo == ft_bar) std::cout << "ft_foo and ft_bar are equal\n";
	if (ft_foo != ft_bar) std::cout << "ft_foo and ft_bar are not equal\n";
	if (ft_foo < ft_bar) std::cout << "ft_foo is less than ft_bar\n";
	if (ft_foo > ft_bar) std::cout << "ft_foo is greater than ft_bar\n";
	if (ft_foo <= ft_bar) std::cout << "ft_foo is less than or equal to ft_bar\n";
	if (ft_foo >= ft_bar) std::cout << "ft_foo is greater than or equal to ft_bar\n";
}

void vector_swap_rela_test() {
	std::cout << "======================= SWAP REL =======================" << std::endl;
	std::vector<int> std_foo (3, 100);   // three ints with a value of 100
	std::vector<int> std_bar (5, 200);   // five ints with a value of 200

	std_foo.swap(std_bar);

	std::cout << "STD::foo contains:";
	for (std::vector<int>::iterator it = std_foo.begin(); it != std_foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "STD::bar contains:";
	for (std::vector<int>::iterator it = std_bar.begin(); it != std_bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ft::vector<int> ft_foo (3, 100);   // three ints with a value of 100
	ft::vector<int> ft_bar (5, 200);   // five ints with a value of 200

	ft_foo.swap(ft_bar);

	std::cout << "FTV::foo contains:";
	for (ft::vector<int>::iterator it = ft_foo.begin(); it != ft_foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "FTV::bar contains:";
	for (ft::vector<int>::iterator it = ft_bar.begin(); it != ft_bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}
// STRING
void vector_string_begin_end_test() {
	std::cout << "=================== STRING BEGIN END ===================" << std::endl;
    unsigned int start_time = clock();
	std::vector<std::string> std_vector;
	std_vector.push_back("Zendaya"); // 0
	std_vector.push_back("Monika"); // 1
	std_vector.push_back("Tom"); // 2
	std_vector.push_back("Jason"); // 3
	std_vector.push_back("Penelopa"); // 4
	std::cout << "STD::vector contains(begin): " << *std_vector.begin() << std::endl;
	std::cout << "STD::vector contains(end): " << *(std_vector.end() - 1) << std::endl;
    std::cout << "STD::vector contains(reverse begin): " << *std_vector.rbegin() << std::endl;
	std::cout << "STD::vector contains(reverse end): " << *(std_vector.rend() - 1) << std::endl;
    std::cout << "STD::vector contains(at): " << std_vector.at(3) << std::endl;
    //std::cout << "STD::vector contains(at_error): " << std_vector.at(6) << std::endl;
    std::cout << "STD::vector contains(front): " << std_vector.front() << std::endl;
    std::cout << "STD::vector contains(back): " << std_vector.back() << std::endl;
    //std_vector.swap()
//    std::cout << "STD::vector contains(swap): " << std_vector.swa << std::endl;
    unsigned int finish_time = clock();
    unsigned int diff_time = finish_time - start_time;
    std::cout << "STD TIME = " << diff_time << std::endl;

	std::cout << "------------------------------------------" << std::endl;
    unsigned int ft_start_time = clock();
	ft::vector<std::string> ft_vector;
	ft_vector.push_back("Zendaya"); // 0
	ft_vector.push_back("Monika"); // 1
	ft_vector.push_back("Tom"); // 2
	ft_vector.push_back("Jason"); // 3
	ft_vector.push_back("Penelopa"); // 4
	std::cout << "FTV::vector contains(begin): " << *ft_vector.begin() << std::endl;
	std::cout << "FTV::vector contains(end): " << *(ft_vector.end() - 1) << std::endl;
	std::cout << "FTV::vector contains(reverse begin): " << *ft_vector.rbegin() << std::endl;
	std::cout << "FTV::vector contains(reverse end): " << *(ft_vector.rend() - 1) << std::endl;
    std::cout << "FTV::vector contains(at): " << ft_vector.at(3) << std::endl;
    //std::cout << "FTV::vector contains(at_error): " << ft_vector.at(6) << std::endl;
    std::cout << "FTV::vector contains(front): " << ft_vector.front() << std::endl;
    std::cout << "FTV::vector contains(back): " << ft_vector.back() << std::endl;

    unsigned int ft_finish_time = clock();
    unsigned int ft_diff_time = ft_finish_time - ft_start_time;
    std::cout << "FTV TIME = " << ft_diff_time << std::endl;

}

void vector_string_swap_test() {
    //std::vector<std::string> std_vector;
    std::cout << "======================= SWAP STR =======================" << std::endl;
    unsigned int start_time = clock();
    std::vector<std::string> std_foo (10, "stl_1");   // three ints with a value of 100
    std::vector<std::string> std_bar (5, "stl_2");   // five ints with a value of 200
    std_foo.swap(std_bar);
    std::cout << "STD::std_foo contains:";
    for (unsigned int i = 0; i < std_foo.size(); i++)
        std::cout << ' ' << std_foo[i];
    std::cout << std::endl;
    std::cout << "STD::std_bar contains:";
    for (unsigned int i = 0; i < std_bar.size(); i++)
        std::cout << ' ' << std_bar[i];
    std::cout << std::endl;
    unsigned int finish_time = clock();
    unsigned int diff_time = finish_time - start_time;
    std::cout << "STD TIME = " << diff_time << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    unsigned int ft_start_time = clock();
    ft::vector<std::string> ft_foo (10, "stl_1");   // three ints with a value of 100
    ft::vector<std::string> ft_bar (5, "stl_2");   // five ints with a value of 200
    ft_foo.swap(ft_bar);
    std::cout << "FTV::std_foo contains:";
    for (unsigned int i = 0; i < ft_foo.size(); i++)
        std::cout << ' ' << ft_foo[i];
    std::cout << std::endl;
    std::cout << "FTV::std_bar contains:";
    for (unsigned int i = 0; i < ft_bar.size(); i++)
        std::cout << ' ' << ft_bar[i];
    std::cout << std::endl;
    unsigned int ft_finish_time = clock();
    unsigned int ft_diff_time = ft_finish_time - ft_start_time;
    std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_string_resize_reserve_test() {
	std::cout << "============ STRING RESIZE RESERVE CAP SIZE ============" << std::endl;
	unsigned int start_time = clock();
	std::vector<std::string> std_vector;
	for (int i = 0; i < 1000000; i++)
		std_vector.push_back("Test");
	std::cout << "STD::vector contains:";
	for (int i = 999995; i < 1000000; i++)
		std::cout << ' ' << std_vector[i] << i;
	std::cout << std::endl;
	//std::cout << ' ' << std_vector[1048575];
	std::cout << "STD::vector capacity: " << std_vector.capacity() << std::endl;
	std::cout << "STD::vector size: " << std_vector.size() << std::endl;
	std::cout << "STD::vector max_size: " << std_vector.max_size() << std::endl;
	std_vector.resize(2000000);
	std::cout << "STD::vector capacity after resize: " << std_vector.capacity() << std::endl;
	std::cout << "STD::vector empty: " << std_vector.empty() << std::endl;
	std_vector.reserve(3000000);
	std::cout << "STD::vector capacity after reserve: " << std_vector.capacity() << std::endl;
    unsigned int finish_time = clock();
    unsigned int diff_time = finish_time - start_time;
    std::cout << "STD TIME = " << diff_time << std::endl;

	std::cout << "------------------------------------------" << std::endl;

    unsigned int ft_start_time = clock();
	ft::vector<std::string> ft_vector;
	for (int i = 0; i < 1000000; i++)
		ft_vector.push_back("Test");
	std::cout << "FTV::vector contains:";
	for (int i = 999995; i < 1000000; i++)
		std::cout << ' ' << ft_vector[i] << i;
	std::cout << std::endl;
	//std::cout << ' ' << ft_vector[1048575];
	std::cout << "FTV::vector capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "FTV::vector size: " << std_vector.size() << std::endl;
	std::cout << "FTV::vector max_size: " << std_vector.max_size() << std::endl;
	ft_vector.resize(2000000);
	std::cout << "FTV::vector capacity after resize: " << ft_vector.capacity() << std::endl;
	std::cout << "FTV::vector empty: " << ft_vector.empty() << std::endl;
	ft_vector.reserve(3000000);
	std::cout << "FTV::vector capacity after reserve: " << ft_vector.capacity() << std::endl;
    unsigned int ft_finish_time = clock();
    unsigned int ft_diff_time = ft_finish_time - ft_start_time;
    std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}

void vector_string_insert_erase_test() {
	std::cout << "================== STRING INSERT ERASE =================" << std::endl;
	unsigned int start_time = clock();
	std::vector<std::string> std_vector (3, "STL");
	std::vector<std::string>::iterator it;
	it = std_vector.begin();
	it = std_vector.insert (it , "STL_2");
	std_vector.insert (it, 2, "STL_3");
	// "it" no longer valid, get a new one:
	it = std_vector.begin();
	std::vector<std::string> std_anothervector (2, "STL_4");
	std_vector.insert(it + 2, std_anothervector.begin(), std_anothervector.end());
	std::string myarray [] = {"STL_717", "STL_707", "STL_777"};
	std_vector.insert (std_vector.begin(), myarray, myarray + 3);
	std::cout << "STD::vector contains:";
	for (it = std_vector.begin(); it < std_vector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std_vector.erase(std_vector.begin() + 4);
	std_vector.erase(std_vector.begin(), std_vector.begin() + 3);
	std::cout << "STD::vector contains after erase:";
	for (unsigned int i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	std::cout << "------------------------------------------" << std::endl;

	unsigned int ft_start_time = clock();
	std::vector<std::string> ft_vector (3, "STL");
	std::vector<std::string>::iterator ft_it;
	ft_it = ft_vector.begin();
	ft_it = ft_vector.insert (ft_it , "STL_2");
	ft_vector.insert (ft_it, 2, "STL_3");
	// "it" no longer valid, get a new one:
	ft_it = ft_vector.begin();
	std::vector<std::string> ft_anothervector (2, "STL_4");
	ft_vector.insert(ft_it + 2, ft_anothervector.begin(), ft_anothervector.end());
	std::string ft_myarray [] = {"STL_717", "STL_707", "STL_777"};
	ft_vector.insert (ft_vector.begin(), ft_myarray, ft_myarray + 3);
	std::cout << "FTV::vector contains:";
	for (ft_it = ft_vector.begin(); ft_it < ft_vector.end(); ft_it++)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	ft_vector.erase(ft_vector.begin() + 4);
	ft_vector.erase(ft_vector.begin(), ft_vector.begin() + 3);
	std::cout << "FTV::vector contains after erase:";
	for (unsigned int i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTV TIME = " << ft_diff_time << std::endl;
}