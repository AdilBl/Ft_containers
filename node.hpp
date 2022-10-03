#ifndef NODE_HPP
#define NODE_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "pair.hpp"
# include "utils.cpp"

namespace ft
{
	template <class key, class value>
	class node
	{
		public:
			typedef ft::pair<key,value> 	pair;
			node		*left;
			node		*right;
			node		*parent;
			pair		*content;

			node(node   *prent, node    *lft,node   *rght, pair	*val)
			{
				parent = prent;
				left = lft;
				right = rght;
				content = val;
			}
			node (const node& x)			{*this = x;}
			virtual	~node()					{}
			node& operator= (const node& x)
			{
				parent = x.parent;
				left = x.left;
				right = x.right;
				content = x.content;
			}
			bool operator<(const node<key,value>& lhs, const node<key,value>& rhs)   {return(ft::lexicographical_compare(lhs.content.first.begin(), lhs.content.first.end(), rhs.content.first.begin(), rhs.content.first.end()));}
			bool operator<=(const node<key,value>& lhs, const node<key,value>& rhs)   {return(!ft::lexicographical_compare(rhs.content.first.begin(), rhs.content.first.end(), lhs.content.first.begin(), lhs.content.first.end()));}
			bool operator>(const node<key,value>& lhs, const node<key,value>& rhs)   {return(ft::lexicographical_compare(rhs.content.first.begin(), rhs.content.first.end(), lhs.content.first.begin(), lhs.content.first.end()));}
			bool operator>=(const node<key,value>& lhs, const node<key,value>& rhs)   {return(!ft::lexicographical_compare(lhs.content.first.begin(), lhs.content.first.end(), rhs.content.first.begin(), rhs.content.first.end()));}
	};
}

#endif