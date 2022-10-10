#ifndef VECTOR_REVERSEITERATOR_HPP
# define VECTOR_REVERSEITERATOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "vector_iterator.hpp"

namespace ft
{
    template <class T>
    class vector_reverseiterator
    {
        public:
            typedef T                   value_type;
            typedef value_type&         reference;
            typedef const value_type&   const_reference;
            typedef value_type*         pointer;
            typedef const value_type*   const_pointer;
            typedef std::size_t         size_type;
            typedef ptrdiff_t           difference_type;
            vector_reverseiterator(void)           {this->index = NULL;}
            vector_reverseiterator(pointer i)      {this->index = i;}
            vector_reverseiterator (const vector_iterator<value_type>& x)        {this->index = x.index;}
            vector_reverseiterator (const vector_reverseiterator& x)        {*this = x;}
            virtual ~vector_reverseiterator()               {}
            
            vector_reverseiterator& operator= (const vector_reverseiterator& x)
            {
                if (this == &x)
                    return (*this);
                this->index = x.index;
                return(*this);
            }

            pointer base (void) const     {return (this->index);}
            //bool
            bool    operator<(const vector_reverseiterator& x)     {return (this->index < x.index);}
            bool    operator<=(const vector_reverseiterator& x)     {return (this->index <= x.index);}
            bool    operator>=(const vector_reverseiterator& x)     {return (this->index >= x.index);}
            bool    operator>(const vector_reverseiterator& x)     {return (this->index > x.index);}
            bool    operator==(const vector_reverseiterator& x)     {return (this->index == x.index);}
            bool    operator!=(const vector_reverseiterator& x)     {return (this->index != x.index);}
            //
            difference_type    operator+(const vector_reverseiterator& x)  {return (this->index - x.index);}
            difference_type    operator-(const vector_reverseiterator& x)  {return (this->index + x.index);}
            vector_reverseiterator    operator+(const difference_type& x)  {return vector_reverseiterator(this->index - x);}
            vector_reverseiterator    operator-(const difference_type& x)  {return vector_reverseiterator(this->index + x);}

            vector_reverseiterator    &operator+=(const difference_type& x)  {this->index -= x;return *this;}
            vector_reverseiterator    &operator-=(const difference_type& x)  {this->index += x;return *this;}

            //
            vector_reverseiterator     operator++(void)        {this->index--; return(*this);}
            vector_reverseiterator     operator++(int)         {vector_reverseiterator tamp(*this); --this->index; return(tamp);}
            vector_reverseiterator     operator--(void)        {this->index++; return(*this);}
            vector_reverseiterator     operator--(int)         {vector_reverseiterator tamp(*this); ++this->index; return(tamp);}

            //
            reference     operator*() {return (*this->index);}
            const_reference     operator*() const {return (*this->index);}
            pointer     operator->() {return (this->index);}
            pointer     operator->() const {return (this->index);}
            reference     operator[](const difference_type& x) {return (*(this->index + x));}
            const_reference     operator[](const difference_type& x) const {return (*(this->index + x));}
        private:
            pointer     index;
            
    };

    template <typename T>
    bool    operator<(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T, typename U>
    bool    operator<(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T>
    bool    operator<=(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T, typename U>
    bool    operator<=(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T>
    bool    operator>(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T, typename U>
    bool    operator>(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T>
    bool    operator>=(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T, typename U>
    bool    operator>=(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T>
    bool    operator==(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T, typename U>
    bool    operator==(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T>
    bool    operator!=(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() != rhs.base());}
    template <typename T, typename U>
    bool    operator!=(const vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() != rhs.base());}


    template <typename T>
    ft::vector_reverseiterator<T> operator+(typename ft::vector_reverseiterator<T >::difference_type rhs, const ft::vector_reverseiterator<T > &lhs)                        { return (lhs.base() + rhs); }

    template <typename T>
    ft::vector_reverseiterator<T> operator+(const ft::vector_reverseiterator<T > &rhs, typename ft::vector_reverseiterator<T>::difference_type lhs)                        { return (rhs.base() + lhs); }
    template <typename T>
    ft::vector_reverseiterator<T> operator-(const ft::vector_reverseiterator<T > &rhs, typename ft::vector_reverseiterator<T>::difference_type lhs)                        { return (rhs.base() - lhs); }

    template <typename T>
    typename ft::vector_reverseiterator<T >::difference_type operator-(const ft::vector_reverseiterator<T > &rhs, const ft::vector_reverseiterator<T > &lhs)                { return (rhs.base() - lhs.base()); }
    template <typename U, typename V  >
    typename ft::vector_reverseiterator<U >::difference_type operator-(const ft::vector_reverseiterator<V > &rhs, const ft::vector_reverseiterator<U > &lhs)    { return (rhs.base() - lhs.base()); }
}

#endif