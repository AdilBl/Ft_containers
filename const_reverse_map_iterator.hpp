#ifndef CONST_REVERSE_MAP_ITERATOR_HPP
#define CONST_REVERSE_MAP_ITERATOR_HPP

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

template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >

class const_reverse_map_iterator
{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef ft::pair<Key, T>				value_type;
		typedef	Compare								key_compare;
		typedef	Alloc								allocator_type;
		typedef value_type&							reference;
		typedef	const value_type&					const_reference;
		typedef value_type*							pointer;
		typedef const value_type*					const_pointer;
		typedef	ptrdiff_t							difference_type;
		typedef size_t								size_type;
        typedef node<key_type, mapped_type>         node;
        const_reverse_map_iterator(void)                          {this->index = nullptr;}
        const_reverse_map_iterator(node *i)                       {this->index = i;}
        const_reverse_map_iterator (const const_reverse_map_iterator& x)        {*this = x;}
        virtual ~const_reverse_map_iterator()                     {}

        const_reverse_map_iterator& operator= (const const_reverse_map_iterator& x)
        {
            if (this == &x)
                return (*this);
            this->index = x.index;
            return (*this);
        }

        node *base (void) const     {return (this->index);}
        //bool
        bool    operator<(const const_reverse_map_iterator& x)     {return (this->index <  x.index);}
        bool    operator<=(const const_reverse_map_iterator& x)    {return (this->index <= x.index);}
        bool    operator>=(const const_reverse_map_iterator& x)    {return (this->index >= x.index);}
        bool    operator>(const const_reverse_map_iterator& x)     {return (this->index >  x.index);}
        bool    operator==(const const_reverse_map_iterator& x)    {return (this->index == x.index);}
        bool    operator!=(const const_reverse_map_iterator& x)    {return (this->index != x.index);}
        //
        const_reverse_map_iterator     operator--(void)
        {
            if (this->index->right == nullptr)
            {
                while (this->index->parent != nullptr && this->index == this->index->parent->right)
                {
                    this->index = this->index->parent;
                }
                this->index = this->index->parent;
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
        const_reverse_map_iterator     operator--(int)
        {
            const_reverse_map_iterator tamp(*this);
            if (this->index->right == nullptr)
            {
                while (this->index->parent != nullptr && this->index == this->index->parent->right)
                {
                    this->index = this->index->parent;
                }
                this->index = this->index->parent;
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
        const_reverse_map_iterator     operator++(void)
        {
            if (this->index->left == nullptr)
            {
                while (this->index->parent != nullptr && this->index->parent->left == this->index)
                {
                    this->index = this->index->parent;
                }
                this->index = this->index->parent;
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
        const_reverse_map_iterator     operator++(int)
        {
            const_reverse_map_iterator tamp(*this);
            if (this->index->left == nullptr)
            {
                while (this->index->parent != nullptr && this->index->parent->left == this->index)
                {
                    this->index = this->index->parent;
                }
                this->index = this->index->parent;
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
        reference           operator*()         {return (*this->index->content);}
        pointer             operator->()        {return (this->index->get_ptr_pair());}

        private:
            node *     index;
            
    };


    template <class key, class T>
    bool    operator<(const const_reverse_map_iterator<key, T> &lhs, const const_reverse_map_iterator<key, T> &rhs)     {return (lhs.base() < rhs.base());}
    template <class key, class T>
    bool    operator<=(const const_reverse_map_iterator<key, T> &lhs, const const_reverse_map_iterator<key, T> &rhs)     {return (lhs.base() <= rhs.base());}
    template <class key, class T>
    bool    operator>(const const_reverse_map_iterator<key, T> &lhs, const const_reverse_map_iterator<key, T> &rhs)     {return (lhs.base() > rhs.base());}
    template <class key, class T>
    bool    operator>=(const const_reverse_map_iterator<key, T> &lhs, const const_reverse_map_iterator<key, T> &rhs)     {return (lhs.base() >= rhs.base());}
    template <class key, class T>
    bool    operator==(const const_reverse_map_iterator<key, T> &lhs, const const_reverse_map_iterator<key, T> &rhs)     {return (lhs.base() == rhs.base());}
    template <class key, class T>
    bool    operator!=(const const_reverse_map_iterator<key, T> &lhs, const const_reverse_map_iterator<key, T> &rhs)     {return (lhs.base() != rhs.base());}

    // template <typename T  >
    // ft::const_reverse_map_iterator<T > operator+(typename ft::const_reverse_map_iterator<T >::difference_type rhs, const ft::const_reverse_map_iterator<T > &lhs)                        { return (lhs.base() + rhs); }

    // template <typename T  >
    // ft::const_reverse_map_iterator<T > operator+(const ft::const_reverse_map_iterator<T > &rhs, typename ft::const_reverse_map_iterator<T >::difference_type lhs)                        { return (rhs.base() + lhs); }

    // template <typename T  >
    // ft::const_reverse_map_iterator<T > operator-(const ft::const_reverse_map_iterator<T > &rhs, typename ft::const_reverse_map_iterator<T >::difference_type lhs)                        { return (rhs.base() - lhs); }

    // template <typename T  >
    // typename ft::const_reverse_map_iterator<T >::difference_type operator-(const ft::const_reverse_map_iterator<T > &rhs, const ft::const_reverse_map_iterator<T > &lhs)                { return (rhs.base() - lhs.base()); }
    // template <typename U, typename V  >
    // typename ft::const_reverse_map_iterator<U >::difference_type operator-(const ft::const_reverse_map_iterator<V > &rhs, const ft::const_reverse_map_iterator<U > &lhs)    { return (rhs.base() - lhs.base()); }
}


#endif