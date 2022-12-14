#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "../utils.hpp"
# include "pair.hpp"
# include "three.hpp"
# include "map.hpp"

namespace ft
{

template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::node<Key, T> > >

class map_iterator
{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef ft::pair<Key, T>			    	value_type;
		typedef	Compare								key_compare;
		typedef	Alloc								allocator_type;
        // typedef	typename Alloc::template rebind< ft::three<Key, T> >::other		allocator_type;
		typedef value_type&							reference;
		typedef	const value_type&					const_reference;
		typedef value_type*							pointer;
		typedef const value_type*					const_pointer;
		typedef	ptrdiff_t							difference_type;
		typedef size_t								size_type;
        typedef node<key_type, mapped_type>         node;
        map_iterator(void)                          {this->index = NULL;}
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
        bool    operator<(const map_iterator& x)     {return (this->index <  x.index);}
        bool    operator<=(const map_iterator& x)    {return (this->index <= x.index);}
        bool    operator>=(const map_iterator& x)    {return (this->index >= x.index);}
        bool    operator>(const map_iterator& x)     {return (this->index >  x.index);}
        bool    operator==(const map_iterator& x)    {return (this->index == x.index);}
        bool    operator!=(const map_iterator& x)    {return (this->index != x.index);}
        //

        map_iterator     operator++(void)
        {
            if (this->index->right == NULL)
            {
                while (this->index->parent != NULL && this->index == this->index->parent->right)
                {
                    this->index = this->index->parent;
                }
                this->index = this->index->parent;
            }
            else
            {
                this->index = this->index->right;
                while (this->index->left != NULL)
                {
                    this->index = this->index->left;
                }
            }
            return(*this);
        }
        map_iterator     operator++(int)
        {
            map_iterator tamp(*this);
            if (this->index->right == NULL)
            {
                while (this->index->parent != NULL && this->index == this->index->parent->right)
                {
                    this->index = this->index->parent;
                }
                this->index = this->index->parent;
            }
            else
            {
                this->index = this->index->right;
                while (this->index->left != NULL)
                {
                    this->index = this->index->left;
                }
            }
            return(tamp);
        }
        map_iterator     operator--(void)
        {
            if (this->index->left == NULL)
            {
                while (this->index->parent != NULL && this->index->parent->left == this->index)
                {
                    this->index = this->index->parent;
                }
                this->index = this->index->parent;
            }
            else
            {
                this->index = this->index->left;
                while (this->index->right != NULL)
                {
                    this->index = this->index->right;
                }
            }
            return(*this);
        }
        map_iterator     operator--(int)
        {
            map_iterator tamp(*this);
            if (this->index->left == NULL)
            {
                while (this->index->parent != NULL && this->index->parent->left == this->index)
                {
                    this->index = this->index->parent;
                }
                this->index = this->index->parent;
            }
            else
            {
                this->index = this->index->left;
                while (this->index->right != NULL)
                {
                    this->index = this->index->right;
                }
            }
            return(tamp);
            }

        //
        reference           operator*()         {return (*this->index->get_ptr_pair());}
        const_reference     operator*() const   {return (*this->index->get_ptr_pair());}
        pointer             operator->()        {return (this->index->get_ptr_pair());}
        pointer             operator->()const   {return (this->index->get_ptr_pair());}

        private:
            node *     index;
            
    };


    template <class key, class T>
    bool    operator<(const map_iterator<key, T> &lhs, const map_iterator<key, T> &rhs)     {return (lhs.base() < rhs.base());}
    template <class key, class T>
    bool    operator<=(const map_iterator<key, T> &lhs, const map_iterator<key, T> &rhs)     {return (lhs.base() <= rhs.base());}
    template <class key, class T>
    bool    operator>(const map_iterator<key, T> &lhs, const map_iterator<key, T> &rhs)     {return (lhs.base() > rhs.base());}
    template <class key, class T>
    bool    operator>=(const map_iterator<key, T> &lhs, const map_iterator<key, T> &rhs)     {return (lhs.base() >= rhs.base());}
    template <class key, class T>
    bool    operator==(const map_iterator<key, T> &lhs, const map_iterator<key, T> &rhs)     {return (lhs.base() == rhs.base());}
    template <class key, class T>
    bool    operator!=(const map_iterator<key, T> &lhs, const map_iterator<key, T> &rhs)     {return (lhs.base() != rhs.base());}

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