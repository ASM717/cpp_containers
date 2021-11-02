#include <iostream>
#include <vector>
#include "./ft_vector/ft_vector.hpp"

int main() {
	std::vector<int> std_vec;
	std_vec.push_back(1);
	std_vec.push_back(41);
	std_vec.push_back(-71);
	std_vec.push_back(8);
	ft::vector<int> ft_vec(std_vec.begin(), std_vec.end());
}
