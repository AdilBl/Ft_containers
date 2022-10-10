#ifndef NODE_HPP
#define NODE_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "pair.hpp"

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

			node()
			{
				parent = NULL;
				left = NULL;
				right = NULL;
				deep = 1;
			}

			node(pair	val)
			{
				parent = NULL;
				left = NULL;
				right = NULL;
				content = val;
				deep = 1;
			}

			pair * get_ptr_pair(void)
            {
                return ((reinterpret_cast<pair *>((&this->content))));
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

			int height(node *n)
			{
				if (n == NULL)
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
			bool    operator==(const node& x)     {return (x.content == this->content);}
        	bool    operator!=(const node& x)     {return (x.content != this->content);}
	};
	template <class key, class value>
	bool operator< (const node<key,value>& lhs, const node<key,value>& rhs)   {return(lhs.content < rhs.content);}
	template <class key, class value>
	bool operator<=(const node<key,value>& lhs, const node<key,value>& rhs)   {return(lhs.content <= rhs.content);}
	template <class key, class value>
	bool operator> (const node<key,value>& lhs, const node<key,value>& rhs)   {return(lhs.content > rhs.content);}
	template <class key, class value>
	bool operator>=(const node<key,value>& lhs, const node<key,value>& rhs)   {return(lhs.content >= rhs.content);}
}

#endif