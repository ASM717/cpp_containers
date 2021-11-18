#include <iostream>
#include <vector>
#include "ft_vector/ft_vector.hpp"

#include <string>
#include <ctime>
#include <iomanip>

template<typename T>
void print_vector(const ft::vector<T> &vct) {
    typename ft::vector<T>::const_iterator it;
    for (it = vct.begin(); it != vct.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void print_vector_reverse(const ft::vector<T> &vct) {
    typename ft::vector<T>::const_reverse_iterator it;
    for (it = vct.rbegin(); it != vct.rend(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// void my_vector() {
// 	ft::vector<int> vector;
// }

void vector_max_size_test() {
	std::cout << "====================== MAX SIZE ========================" << std::endl;

	std::vector<int> std_vector;
	// set some content in the vector:
	for (int i = 0; i < 100; i++)
		std_vector.push_back(i);
	std::cout << "STD::size: " << std_vector.size() << std::endl;
	std::cout << "STD::capacity: " << std_vector.capacity() << std::endl;
	std::cout << "STD::max_size: " << std_vector.max_size() << std::endl;

	std::cout << "----------------------------------" << std::endl;

	ft::vector<int> ft_vector;
	// set some content in the vector:
	for (int i = 0; i < 100; i++)
		ft_vector.push_back(i);
	std::cout << "FTV::size: " << ft_vector.size() << std::endl;
	std::cout << "FTV::capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "FTV::max_size: " << ft_vector.max_size() << std::endl;

}

void vector_size_test() {
	std::cout << "========================= SIZE =========================" << std::endl;
	std::vector<int> std_vector;
	std::cout << "STD::0. size: " << std_vector.size() << std::endl;
	for (int i = 0; i < 10; i++)
		std_vector.push_back(i);
	std::cout << "STD::1. size: " << std_vector.size() << std::endl;
	std_vector.insert(std_vector.end(), 10, 100);
	std::cout << "STD::2. size: " << std_vector.size() << std::endl;
	std_vector.pop_back();
	std::cout << "STD::3. size: " << std_vector.size() << std::endl;

	std::cout << "-----------------" << std::endl;
	std::vector<int> ft_vector;
	std::cout << "FTV::0. size: " << ft_vector.size() << std::endl;
	for (int i = 0; i < 10; i++)
		ft_vector.push_back(i);
	std::cout << "FTV::1. size: " << ft_vector.size() << std::endl;
	ft_vector.insert(ft_vector.end(), 10, 100);
	std::cout << "FTV::2. size: " << ft_vector.size() << std::endl;
	ft_vector.pop_back();
	std::cout << "FTV::3. size: " << ft_vector.size() << std::endl;
}

void vector_constructor_test()
{
	std::cout << "===================== CONSTRUCTOR ======================" << std::endl;
	// constructors used in the same order as described above:
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
	std::cout << '\n';

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
	std::cout << '\n';
}

void vector_operator_equel_test() {
	std::cout << "=================== ASSIGN  OPERATOR ===================" << std::endl;
	std::vector<int> foo (3,0);
	std::vector<int> bar (5,0);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "STD::Size of foo: " << int(foo.size()) << '\n';
	std::cout << "STD::Size of bar: " << int(bar.size()) << '\n';

	ft::vector<int> ft_foo (3,0);
	ft::vector<int> ft_bar (5,0);

	ft_bar = ft_foo;
	ft_foo = ft::vector<int>();

	std::cout << "FTV::Size of foo: " << int(ft_foo.size()) << '\n';
	std::cout << "FTV::Size of bar: " << int(ft_bar.size()) << '\n';
}

void vector_iterator_test() {
	std::cout << "======================= ITERATOR =======================" << std::endl;
	std::vector<int> std_vector;
	for (int i = 1; i <= 5; i++) std_vector.push_back(i);

	std::cout << "STD::vector contains:";
	for (std::vector<int>::iterator it = std_vector.begin() ; it != std_vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> ft_vector;
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);

	std::cout << "FTV::vector contains:";
	for (ft::vector<int>::iterator ft_it = ft_vector.begin() ; ft_it != ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';
}

void vector_reverse_iterator_test() {
	std::cout << "=================== REVERSE ITERATOR ===================" << std::endl;
	std::vector<int> std_vector (5);  // 5 default-constructed ints
	int i = 0;
	std::vector<int>::reverse_iterator std_rit = std_vector.rbegin();
	for (; std_rit != std_vector.rend(); ++std_rit)
		*std_rit = ++i;
	std::cout << "STD::vector contains:";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> ft_vector (5);  // 5 default-constructed ints
	int j = 0;
	ft::vector<int>::reverse_iterator ft_rit = ft_vector.rbegin();
	for (; ft_rit != ft_vector.rend(); ++ft_rit)
		*ft_rit = ++j;
	std::cout << "FTV::vector contains:";
	for (ft::vector<int>::iterator ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';
}

void vector_resize_test() {
	std::cout << "======================= RESIZE =========================" << std::endl;
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
}

void vector_empty_test() {
	std::cout << "======================= EMPTY ==========================" << std::endl;
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
}

void vector_reserve_test() {
	std::cout << "====================== RESERVE =========================" << std::endl;
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

	std::cout << "------------------------------------" << std::endl;

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
}

void vector_test() {
	std::cout << "======================== VECTOR ========================" << std::endl;
	vector_constructor_test();
	vector_operator_equel_test();
	vector_iterator_test();
	vector_reverse_iterator_test();
	vector_size_test();
	vector_max_size_test();
	vector_resize_test();
	vector_empty_test();
	vector_reserve_test();
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
//	}
}

// int main()
// {
// 	unsigned int start_time =  clock();

// 	std::vector<int> *test = new std::vector<int>;
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