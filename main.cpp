#include <iostream>
#include <vector>
#include "./ft_vector/ft_vector.hpp"
//#include "./ft_vector/ft_vector_iterator.hpp"
//#include "./ft_vector/ft_vector_reverse_iterator.hpp"

int main() {
	std::vector<int> std_vec;
	std_vec.push_back(1);
	std_vec.push_back(41);
	std_vec.push_back(-71);
	std_vec.push_back(8);
	ft::vector<int> ft_vec(std_vec.begin(), std_vec.end());
	std::cout << "BEGIN" << std::endl;
	std::cout << "ft: " << *ft_vec.begin()  << " | std: " << *std_vec.begin() << std::endl;
	std::cout << "END" << std::endl;
	std::cout << "ft: " << *(ft_vec.end() - 1)  << " | std: " << *(std_vec.end() - 1) << std::endl;
	std::cout << "REV BEGIN" << std::endl;
	std::cout << "ft: " << *ft_vec.rbegin()  << " | std: " << *std_vec.rbegin() << std::endl;
	std::cout << "REV END" << std::endl;
	std::cout << "ft: " << *(ft_vec.rend() - 1)  << " | std: " << *(std_vec.rend() - 1) << std::endl;
	std::cout << "VECTOR SIZE" << std::endl;
	std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
	std::cout << "VECTOR MAX_SIZE" << std::endl;
	std::cout << "ft: " << ft_vec.max_size()  << " | std: " << std_vec.max_size() << std::endl;
	std::cout << "VECTOR CAPACITY" << std::endl;
	std::cout << "ft: " << ft_vec.capacity()  << " | std: " << std_vec.capacity() << std::endl;

	ft_vec.resize(10);
	std_vec.resize(10);
	std::cout << "SIZE AFTER RESIZE" << std::endl;
	std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
	std::cout << "now" << std::endl;
	//std::cout << "ft: " << ft_vec.empty()  << " | std: " << std_vec.empty() << std::endl;

	return (0);
}
