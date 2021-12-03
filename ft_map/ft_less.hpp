#ifndef FT_LESS_HPP
#define FT_LESS_HPP

namespace ft {
	template <class T>
	struct less
	{
		typedef T       first_argument_type;
		typedef T       second_argument_type;
		typedef bool    result_type;

		bool operator()(const T& x, const T& y) const {
			return (x < y);
		}
	};

	//тест на проверку потом

//	int foo[]={10,20,5,15,25};
//	int bar[]={15,10,20};
//	std::sort (foo, foo+5, std::less<int>());  // 5 10 15 20 25
//	std::sort (bar, bar+3, std::less<int>());  //   10 15 20
//	if (std::includes (foo, foo+5, bar, bar+3, std::less<int>()))
//	std::cout << "foo includes bar.\n";
//	return 0;
}

#endif