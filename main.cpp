#include <iostream>
#include <vector>
#include "ft_vector/ft_vector.hpp"
#include "ft_vector/ft_type_traits.hpp"
#include "ft_vector/ft_iterator_utils.hpp"

#include <string>

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

void vector_test() {
	// ft::vector<int> vector2;
	// vector2.push_back(20);
	// vector2.push_back(22);
	// vector2.push_back(48);
	// vector2.push_back(0);
	// vector2.push_back(-200);

	// print_vector(vector2);

	std::vector<int> std_vector;
	std_vector.push_back(1);
	std_vector.push_back(41);
	std_vector.push_back(-71);
	std_vector.push_back(8);
	ft::vector<int> ft_vector(std_vector.begin(), std_vector.end());
	std::cout << "BEGIN" << std::endl;
	std::cout << "ft: " << *ft_vector.begin() << " | std: " << *std_vector.begin() << std::endl;
	std::cout << "END" << std::endl;
	std::cout << "ft: " << *(ft_vector.end() - 1) << " | std: " << *(std_vector.end() - 1) << std::endl;
	std::cout << "REV BEGIN" << std::endl;
	std::cout << "ft: " << *ft_vector.rbegin() << " | std: " << *std_vector.rbegin() << std::endl;
	std::cout << "REV END" << std::endl;
	std::cout << "ft: " << *(ft_vector.rend() - 1) << " | std: " << *(std_vector.rend() - 1) << std::endl;
	std::cout << "VECTOR SIZE" << std::endl;
	std::cout << "ft: " << ft_vector.size() << " | std: " << std_vector.size() << std::endl;
	std::cout << "VECTOR MAX_SIZE" << std::endl;
	std::cout << "ft: " << ft_vector.max_size() << " | std: " << std_vector.max_size() << std::endl;
	std::cout << "VECTOR CAPACITY" << std::endl;
	std::cout << "ft: " << ft_vector.capacity() << " | std: " << std_vector.capacity() << std::endl;

	ft_vector.resize(10);
	std_vector.resize(10);
	std::cout << "SIZE AFTER RESIZE" << std::endl;
	std::cout << "ft: " << ft_vector.size() << " | std: " << std_vector.size() << std::endl;
	print_vector(ft_vector);
	std::cout << "SIZE AFTER EMPTY FUNC USE" << std::endl;
	std::cout << "ft: " << ft_vector.empty()  << " | std: " << std_vector.empty() << std::endl;
	print_vector(ft_vector);
}

int main() {

	std::cout << std::endl << "====== VECTOR ======" << std::endl;
	vector_test();

// 	ft::vector<int> my;
// 	my.push_back(3);
// 	my.push_back(4);
// 	my.push_back(5);
// 	my.push_back(6);
// 	my.push_back(77);

// 	my.insert(my.begin(), 99);
// 	my.insert(my.end(), 921319);

// 	ft::vector<int>::iterator j = my.end();
// 	j--;

// 	my.insert(j, 921319);
// 	ft::vector<int>::iterator h = my.begin();

// 	my.insert(h, 5, 0);

// 	ft::vector<int>::iterator i = my.begin();
// 	std::cout << "begin " << *i << std::endl;
// 	i += 1;
// 	i += 1;

// 	my.insert(my.begin(), i, my.end());
// ///////////////////////////////////////////

// 	ft::vector<int> myvector (3,100);
// 	ft::vector<int>::iterator it;

// 	it = myvector.begin();
// 	it = myvector.insert ( it , 200 );

// 	myvector.insert (it,2,300);

// 	// "it" no longer valid, get a new one:
// 	it = myvector.begin();

// 	ft::vector<int> anothervector (2,400);
// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());

// 	int myarray [] = { 501,502,503 };
// 	myvector.insert (myvector.begin(), myarray, myarray+3);

// 	std::cout << "myvector contains:";
// 	for (it=myvector.begin(); it<myvector.end(); it++)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	std::vector<int> std_vector;
// 	std_vector.push_back(1);
// 	std_vector.push_back(41);
// 	std_vector.push_back(-71);
// 	std_vector.push_back(8);
// 	ft::vector<int> ft_vector(std_vector.begin(), std_vector.end());
// 	std::cout << "BEGIN" << std::endl;
// 	std::cout << "ft: " << *ft_vector.begin() << " | std: " << *std_vector.begin() << std::endl;
// 	std::cout << "END" << std::endl;
// 	std::cout << "ft: " << *(ft_vector.end() - 1) << " | std: " << *(std_vector.end() - 1) << std::endl;
// 	std::cout << "REV BEGIN" << std::endl;
// 	std::cout << "ft: " << *ft_vector.rbegin() << " | std: " << *std_vector.rbegin() << std::endl;
// 	std::cout << "REV END" << std::endl;
// 	std::cout << "ft: " << *(ft_vector.rend() - 1) << " | std: " << *(std_vector.rend() - 1) << std::endl;
// 	std::cout << "VECTOR SIZE" << std::endl;
// 	std::cout << "ft: " << ft_vector.size() << " | std: " << std_vector.size() << std::endl;
// 	std::cout << "VECTOR MAX_SIZE" << std::endl;
// 	std::cout << "ft: " << ft_vector.max_size() << " | std: " << std_vector.max_size() << std::endl;
// 	std::cout << "VECTOR CAPACITY" << std::endl;
// 	std::cout << "ft: " << ft_vector.capacity() << " | std: " << std_vector.capacity() << std::endl;
// 	ft_vector.resize(10);
// 	std_vector.resize(10);
// 	std::cout << "SIZE AFTER RESIZE" << std::endl;
// 	std::cout << "ft: " << ft_vector.size() << " | std: " << std_vector.size() << std::endl;
// 	std::cout << "SIZE AFTER EMPTY FUNC USE" << std::endl;
// 	std::cout << "ft: " << ft_vector.empty()  << " | std: " << std_vector.empty() << std::endl;
// 	std::cout << "ft_vector[1]" << std::endl;
// 	std::cout << "ft: " << ft_vector[1]  << " | std: " << std_vector[1] << std::endl;
// 	std::cout << "ft_vector.at(2)" << std::endl;
// 	std::cout << "ft: " << ft_vector.at(2) << " | std: " << std_vector.at(2) << std::endl;
// 	std::cout << "ft_vector.front()" << std::endl;
// 	std::cout << "ft: " << ft_vector.front()  << " | std: " << std_vector.front() << std::endl;

// 	std::cout << "ft_vector.back()" << std::endl;
// 	std::cout << "ft: " << ft_vector.back()  << " | std: " << std_vector.back() << std::endl;
// 	ft_vector.insert(ft_vector.begin(), 99);
// 	std_vector.insert(std_vector.begin(), 99);
// 	std::cout << "ft: " << ft_vector[0]  << " | std: " << std_vector[0] << std::endl;

// 	ft_vector.erase(ft_vector.begin());
// 	std_vector.erase(std_vector.begin());
// 	std::cout << "ft: " << ft_vector[0]  << " | std: " << std_vector[0] << std::endl;
// 	ft::vector<int> ft_swap(10,10);
// 	ft::vector<int>::iterator it = ft_swap.begin();
// 	ft_vector.swap(ft_swap);
// 	std::cout << "ft: " << (*(it + 2)) << std::endl;
// 	std::cout << "ft: " << (*(ft_swap.begin() + 2)) << std::endl;
// 	ft::vector<int>::const_iterator cit = ft_swap.begin() + 3;
// 	std::cout << "ft: " << ((ft_swap.begin() + 2) > cit) << std::endl;
// 	ft_swap.clear();
// 	std_vector.clear();
// 	std::cout << "ft: " << ft_swap.size()  << " | std: " << std_vector.size() << std::endl;
// 	std::cout << "ft: " << (ft_vector > ft_swap) << std::endl;


// 	return (0);
}

