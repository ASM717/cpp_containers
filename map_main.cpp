#include <iostream>

#include "./ft_vector/ft_vector.hpp"

int main() {
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it1;

	it1 = myvector.begin();
	it1 = myvector.insert ( it1 , 200 );

	myvector.insert (it1,2,300);

	it1 = myvector.begin();

	ft::vector<int> anothervector1 (2,400);
	myvector.insert (it1 + 2,anothervector1.begin(), anothervector1.end());

	int myarray1 [] = { 501,502,503 };
	myvector.insert(myvector.begin(), myarray1, myarray1 + 3);

	std::cout << "myvector contains:";
	for (it1 = myvector.begin(); it1 < myvector.end(); it1++)
	std::cout << ' ' << *it1;
	std::cout << '\n';
}
