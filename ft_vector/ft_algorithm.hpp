#ifndef FT_ALGORITHM
#define FT_ALGORITHM

// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare

namespace ft {
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (*first2 < *first1)
				return false;
			if (*first1 < *first2)
				return true;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (comp(*first2, *first1))
				return false;
			if (comp(*first1, *first2))
				return true;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class Ite1, class Ite2>
	bool equal(Ite1 first1, Ite1 last1, Ite2 first2) {
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <typename U>
	void swap(U& a, U&b) {
		U tmp = a;
		a = b;
		b = tmp;
	}

}

#endif