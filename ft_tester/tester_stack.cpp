#include "../ft_tester/tester_headers.hpp"

void stack_constructor_test() {
	std::cout << "====================== CONSTRUCTOR =====================" << std::endl;
	std::vector<int> std_vector (2,200); // vector with 2 elements
	std::stack<int, std::vector<int> > third;  // empty stack using vector
	std::stack<int, std::vector<int> > fourth (std_vector);
	std::cout << "STD::size of third: " << third.size() << std::endl;
	std::cout << "STD::size of fourth: " << fourth.size() << std::endl;


	ft::vector<int> ft_vector (2,200); // vector with 2 elements
	ft::stack<int, ft::vector<int> > ft_third;   // empty stack using vector
	ft::stack<int, ft::vector<int> > ft_fourth (ft_vector);
	std::cout << "FTS::size of third: " << ft_third.size() << std::endl;
	std::cout << "FTS::size of fourth: " << ft_fourth.size() << std::endl;
}

void stack_empty_test() {
	std::cout << "========================= EMPTY ========================" << std::endl;
	unsigned int start_time = clock();
	std::stack<int> std_stack;
	int sum (0);
	for (int i = 1; i <= 10000; i++) std_stack.push(i);
	while (!std_stack.empty())
	{
		sum += std_stack.top();
		std_stack.pop();
	}
	std::cout << "STD::total: " << sum << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::stack<int> ft_stack;
	int ft_sum (0);
	for (int i = 1; i <= 10000; i++) ft_stack.push(i);
	while (!ft_stack.empty())
	{
		ft_sum += ft_stack.top();
		ft_stack.pop();
	}
	std::cout << "FTS::total: " << ft_sum << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTS TIME = " << ft_diff_time << std::endl;
}

void stack_top_test() {
	std::cout << "========================== TOP =========================" << std::endl;
	unsigned int start_time = clock();
	std::stack<int> std_stack;
	std_stack.push(10);
	std_stack.push(20);
	std_stack.top() -= 5;
	std::cout << "STD::stack.top() is now " << std_stack.top() << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::stack<int> ft_stack;
	ft_stack.push(10);
	ft_stack.push(20);
	ft_stack.top() -= 5;
	std::cout << "FTS::stack.top() is now " << ft_stack.top() << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTS TIME = " << ft_diff_time << std::endl;
}

void stack_push_pop_test() {
	std::cout << "======================= PUSH POP =======================" << std::endl;
	unsigned int start_time = clock();
	std::stack<int> std_stack;
	for (int i = 0; i < 5; ++i) std_stack.push(i);
	std::cout << "STD::Popping out elements...";
	while (!std_stack.empty())
	{
		std::cout << ' ' << std_stack.top();
		std_stack.pop();
	}
	std::cout << std::endl;
	unsigned int finish_time = clock();
	unsigned int diff_time = finish_time - start_time;
	std::cout << "STD TIME = " << diff_time << std::endl;

	unsigned int ft_start_time = clock();
	ft::stack<int> ft_stack;
	for (int i = 0; i < 5; ++i) ft_stack.push(i);
	std::cout << "FTS::Popping out elements...";
	while (!ft_stack.empty())
	{
		std::cout << ' ' << ft_stack.top();
		ft_stack.pop();
	}
	std::cout << std::endl;
	unsigned int ft_finish_time = clock();
	unsigned int ft_diff_time = ft_finish_time - ft_start_time;
	std::cout << "FTS TIME = " << ft_diff_time << std::endl;
}
