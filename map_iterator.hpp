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

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >

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
        bool    operator<(const map_iterator& x)     {return (this->index < x.index);}
        bool    operator<=(const map_iterator& x)     {return (this->index <= x.index);}
        bool    operator>=(const map_iterator& x)     {return (this->index >= x.index);}
        bool    operator>(const map_iterator& x)     {return (this->index > x.index);}
        bool    operator==(const map_iterator& x)     {return (this->index == x.index);}
        bool    operator!=(const map_iterator& x)     {return (this->index != x.index);}
        //
        difference_type    operator+(const map_iterator& x)  {return (this->index + x.index);}
        difference_type    operator-(const map_iterator& x)  {return (this->index - x.index);}
        map_iterator    operator+(const difference_type& x)  {return map_iterator(this->index + x);}
        map_iterator    operator-(const difference_type& x)  {return map_iterator(this->index - x);}

        void    operator+=(const map_iterator& x)  {return (this->index += x.index);}
        void    operator-=(const map_iterator& x)  {return (this->index -= x.index);}

        //
        map_iterator     operator++(void)        {this->index++; return(*this);}
        map_iterator     operator++(int)         {map_iterator tamp(*this); ++this->index; return(tamp);}
        map_iterator     operator--(void)        {this->index--; return(*this);}
        map_iterator     operator--(int)         {map_iterator tamp(*this); --this->index; return(tamp);}

        //
        reference           operator*() {return (*this->index);}
        const_reference     operator*() const {return (*this->index);}
        pointer             operator->() {return (this->index);}
        pointer             operator->() const {return (this->index);}
        reference           operator[](const difference_type& x) {return (*(this->index + x));}
        const_reference     operator[](const difference_type& x) const {return (*(this->index + x));}
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


};

#endif