#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "utils.hpp"
# include "pair.hpp"
# include "three.hpp"
# include "map.hpp"

namespace ft
{

template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >

class map_iterator
{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef std::pair<const Key, T>				value_type;
		typedef	Compare								key_compare;
		typedef	Alloc								allocator_type;
		typedef value_type&							reference;
		typedef	const value_type&					const_reference;
		typedef value_type*							pointer;
		typedef const value_type*					const_pointer;
		typedef	ptrdiff_t							difference_type;
		typedef size_t								size_type;
        typedef node<key_type, mapped_type>         node;
        map_iterator(void)                          {this->index = nullptr;}
        map_iterator(node *i)                       {this->index = i;}
        map_iterator (const map_iterator& x)        {*this = x;}
        virtual ~map_iterator()                     {}

        map_iterator& operator= (const map_iterator& x)
        {
            if (this == &x)
                return (*this);
            this->index = x.index;
            return (*this);
        }

        node *base (void) const     {return (this->index);}
        //bool
        bool    operator<(const map_iterator& x)     {return (this->index->content.second < x.index.content.second);}
        bool    operator<=(const map_iterator& x)     {return (this->index->content.second <= x.index.content.second);}
        bool    operator>=(const map_iterator& x)     {return (this->index->content.second >= x.index.content.second);}
        bool    operator>(const map_iterator& x)     {return (this->index->content.second > x.index.content.second);}
        bool    operator==(const map_iterator& x)     {return (this->index == x.index);}
        bool    operator!=(const map_iterator& x)     {return (this->index != x.index);}
        //
        difference_type    operator+(const map_iterator& x)  {return (this->index->content.second + x.index.content.second);}
        difference_type    operator-(const map_iterator& x)  {return (this->index->content.second - x.index.content.second);}
        map_iterator    operator+(const difference_type& x)  {return map_iterator(this->index->content.second + x.content.second);}
        map_iterator    operator-(const difference_type& x)  {return map_iterator(this->index->content.second - x.content.second);}

        void    operator+=(const map_iterator& x)  {return (this->index += x.index);}
        void    operator-=(const map_iterator& x)  {return (this->index -= x.index);}

        //
        map_iterator     operator++(void)
        {
            if (this->index->right == nullptr)
            {
                this->index = this->index->parent;
                while (this->index->parent != nullptr && this->index->parent->right == this->index)
                {
                    this->index = this->index->parent;
                }
            }
            else
            {
                this->index = this->index->right;
                while (this->index->left != nullptr)
                {
                    this->index = this->index->left;
                }
            }
            return(*this);
        }
        map_iterator     operator++(int)
        {
            map_iterator tamp(*this);
                        if (this->index->right == nullptr)
            {
                this->index = this->index->parent;
                while (this->index->parent != nullptr && this->index->parent->right == this->index)
                {
                    this->index = this->index->parent;
                }
            }
            else
            {
                this->index = this->index->right;
                while (this->index->left != nullptr)
                {
                    this->index = this->index->left;
                }
            }
            return(tamp);
        }
        map_iterator     operator--(void)
        {
            if (this->index->left == nullptr)
            {
                this->index = this->index->parent;
                while (this->index->parent != nullptr && this->index->parent->left == this->index)
                {
                    this->index = this->index->parent;
                }
            }
            else
            {
                this->index = this->index->left;
                while (this->index->right != nullptr)
                {
                    this->index = this->index->right;
                }
            }
            return(*this);
        }
        map_iterator     operator--(int)
        {
            map_iterator tamp(*this);
            if (this->index->left == nullptr)
            {
                this->index = this->index->parent;
                while (this->index->parent != nullptr && this->index->parent->left == this->index)
                {
                    this->index = this->index->parent;
                }
            }
            else
            {
                this->index = this->index->left;
                while (this->index->right != nullptr)
                {
                    this->index = this->index->right;
                }
            }
            return(tamp);
            }

        //
        reference           operator*() {return (*this->index->content.second);}
        const_reference     operator*() const {return (*this->index->content.second));}
        pointer             operator->() {return (this->index->content.second));}
        pointer             operator->() const {return (this->index->content.second));}

        private:
            node *     index;
            
    };

    // template <typename T>
    // bool    operator<(const map_iterator<T> &lhs, const map_iterator<T> &rhs)     {return (lhs.index < rhs.index);}
    // template <typename T, typename U>
    // bool    operator<(const map_iterator<T> &lhs, const map_iterator<U> &rhs)     {return (lhs.index < rhs.index);}
    // template <typename T>
    // bool    operator<=(const map_iterator<T> &lhs, const map_iterator<T> &rhs)     {return (lhs.index <= rhs.index);}
    // template <typename T, typename U>
    // bool    operator<=(const map_iterator<T> &lhs, const map_iterator<U> &rhs)     {return (lhs.index <= rhs.index);}
    // template <typename T>
    // bool    operator>(const map_iterator<T> &lhs, const map_iterator<T> &rhs)     {return (lhs.index > rhs.index);}
    // template <typename T, typename U>
    // bool    operator>(const map_iterator<T> &lhs, const map_iterator<U> &rhs)     {return (lhs.index > rhs.index);}
    // template <typename T>
    // bool    operator>=(const map_iterator<T> &lhs, const map_iterator<T> &rhs)     {return (lhs.index >= rhs.index);}
    // template <typename T, typename U>
    // bool    operator>=(const map_iterator<T> &lhs, const map_iterator<U> &rhs)     {return (lhs.index >= rhs.index);}
    // template <typename T>
    // bool    operator==(const map_iterator<T> &lhs, const map_iterator<T> &rhs)     {return (lhs.index == rhs.index);}
    // template <typename T, typename U>
    // bool    operator==(const map_iterator<T> &lhs, const map_iterator<U> &rhs)     {return (lhs.index == rhs.index);}
    // template <typename T>
    // bool    operator!=(const map_iterator<T> &lhs, const map_iterator<T> &rhs)     {return (lhs.index != rhs.index);}
    // template <typename T, typename U>
    // bool    operator!=(const map_iterator<T> &lhs, const map_iterator<U> &rhs)     {return (lhs.index != rhs.index);}

    // template <typename T  >
    // ft::map_iterator<T > operator+(typename ft::map_iterator<T >::difference_type rhs, const ft::map_iterator<T > &lhs)                        { return (lhs.base() + rhs); }

    // template <typename T  >
    // ft::map_iterator<T > operator+(const ft::map_iterator<T > &rhs, typename ft::map_iterator<T >::difference_type lhs)                        { return (rhs.base() + lhs); }

    // template <typename T  >
    // ft::map_iterator<T > operator-(const ft::map_iterator<T > &rhs, typename ft::map_iterator<T >::difference_type lhs)                        { return (rhs.base() - lhs); }

    // template <typename T  >
    // typename ft::map_iterator<T >::difference_type operator-(const ft::map_iterator<T > &rhs, const ft::map_iterator<T > &lhs)                { return (rhs.base() - lhs.base()); }
    // template <typename U, typename V  >
    // typename ft::map_iterator<U >::difference_type operator-(const ft::map_iterator<V > &rhs, const ft::map_iterator<U > &lhs)    { return (rhs.base() - lhs.base()); }
}


#endif