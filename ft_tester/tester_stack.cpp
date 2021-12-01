#include "../ft_tester/tester_headers.hpp"

void stack_constructor_test() {
	std::cout << "====================== CONSTRUCTOR =====================" << std::endl;
	std::vector<int> std_vector (2,200);        // vector with 2 elements
	std::stack<int, std::vector<int> > third;  // empty stack using vector
	std::stack<int, std::vector<int> > fourth (std_vector);
	std::cout << "STD::size of third: " << third.size() << std::endl;
	std::cout << "STD::size of fourth: " << fourth.size() << std::endl;


	ft::vector<int> ft_vector (2,200);        // vector with 2 elements
	ft::stack<int, ft::vector<int> > ft_third;  // empty stack using vector
	ft::stack<int, ft::vector<int> > ft_fourth (ft_vector);
	std::cout << "FTS::size of third: " << ft_third.size() << std::endl;
	std::cout << "FTS::size of fourth: " << ft_fourth.size() << std::endl;
}

void stack_empty_test() {
	std::cout << "========================= EMPTY ========================" << std::endl;
	std::stack<int> std_stack;
	int sum (0);
	for (int i = 1; i <= 10; i++) std_stack.push(i);
	while (!std_stack.empty())
	{
		sum += std_stack.top();
		std_stack.pop();
	}
	std::cout << "STD::total: " << sum << std::endl;

	ft::stack<int> ft_stack;
	int ft_sum (0);
	for (int i = 1; i <= 10; i++) ft_stack.push(i);
	while (!ft_stack.empty())
	{
		ft_sum += ft_stack.top();
		ft_stack.pop();
	}
	std::cout << "FTS::total: " << ft_sum << std::endl;
}