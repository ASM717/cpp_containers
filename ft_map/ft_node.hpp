#ifndef FT_NODE_HPP
#define FT_NODE_HPP
#define RED_COLOR		"\x1B[31m"
#define BLACK_COLOR		"\x1B[37m"
#define RESET_COLOR		"\x1B[0m"

#include <iostream>

namespace ft {
	enum rb_tree_color
	{
		BLACK,
		RED
	};

	template <typename P>
	struct Node {
		P data;
		Node *parent;
		Node *left;
		Node *right;
		rb_tree_color color;

		Node(const P &ref) : data(ref) {
			this->parent = NULL;
			this->left = NULL;
			this->right = NULL;
			this->color = RED; //0
		}

		~Node() {}
	};
}

#endif
