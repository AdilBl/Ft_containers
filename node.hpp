#ifndef NODE_HPP
#define NODE_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "pair.hpp"
// # include "utils.hpp"

namespace ft
{
	template <class key, class value>
	class node
	{
		public:
			typedef ft::pair<key,value>		pair;
			node							*left;
			node							*right;
			node							*parent;
			pair							content;
			int								deep;


			key getkey()		{return(content.first);}
			value	getvalue()	{return(content.second);}
			node(node   *prent, node    *lft,node   *rght, pair	val)
			{
				parent = prent;
				left = lft;
				right = rght;
				content = val;
				deep = 1;
			}
			node (const node& x)			{*this = x;}
			virtual	~node()					{}
			node& operator= (const node& x)
			{
				if (this != &x)
				{
					parent = x.parent;
					left = x.left;
					right = x.right;
					content = x.content;
					deep = x.deep;
				}
				return(*this);
			}
			// bool operator< (const node<key,value>& lhs, const node<key,value>& rhs)   {return(ft::lexicographical_compare(lhs.content.first.begin(), lhs.content.first.end(), rhs.content.first.begin(), rhs.content.first.end()));}
			// bool operator<=(const node<key,value>& lhs, const node<key,value>& rhs)   {return(!ft::lexicographical_compare(rhs.content.first.begin(), rhs.content.first.end(), lhs.content.first.begin(), lhs.content.first.end()));}
			// bool operator> (const node<key,value>& lhs, const node<key,value>& rhs)   {return(ft::lexicographical_compare(rhs.content.first.begin(), rhs.content.first.end(), lhs.content.first.begin(), lhs.content.first.end()));}
			// bool operator>=(const node<key,value>& lhs, const node<key,value>& rhs)   {return(!ft::lexicographical_compare(lhs.content.first.begin(), lhs.content.first.end(), rhs.content.first.begin(), rhs.content.first.end()));}

			int height(node *n)
			{
				if (n == nullptr)
					return 0;
				return (n->deep);
			}

			void	uptdatebalance(void)
			{
				deep = std::max(height(left) , height(right)) + 1;
			}

			size_t getdeep(void)
			{
    			return (height(left) - height(right));
			}
	};
}

#endif