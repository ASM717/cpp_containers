#include <iostream>
#include <vector>
#include "./ft_vector/ft_vector.hpp"

int main() {
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
	std::cout << "SIZE AFTER EMPTY FUNC USE" << std::endl;
	std::cout << "ft: " << ft_vector.empty()  << " | std: " << std_vector.empty() << std::endl;

	return (0);
}
