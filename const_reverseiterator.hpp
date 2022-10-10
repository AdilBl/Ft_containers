#ifndef CONST_VECTOR_REVERSEITERATOR_HPP
# define CONST_VECTOR_REVERSEITERATOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "vector_iterator.hpp"
# include "vector_reverseiterator.hpp"

namespace ft
{
    template <class T>
    class const_vector_reverseiterator
    {
        public:
            typedef T                   value_type;
            typedef value_type&         reference;
            typedef const value_type&   const_reference;
            typedef value_type*         pointer;
            typedef const value_type*   const_pointer;
            typedef std::size_t         size_type;
            typedef ptrdiff_t           difference_type;
            const_vector_reverseiterator(void)           {this->index = nullptr;}
            const_vector_reverseiterator(pointer i)      {this->index = i;}
            const_vector_reverseiterator (const vector_iterator<value_type>& x)         {this->index = x.index;}
            const_vector_reverseiterator (const vector_reverseiterator<value_type>& x)  {this->index = x.base();}
            const_vector_reverseiterator (const const_vector_reverseiterator& x)        {*this = x;}
            virtual ~const_vector_reverseiterator()         {}
            
            const_vector_reverseiterator& operator= (const const_vector_reverseiterator& x)
            {
                if (this == &x)
                    return (*this);
                this->index = x.index;
                return (*this);
            }

            pointer base (void) const     {return (this->index);}
            //bool
            bool    operator<(const const_vector_reverseiterator& x)     {return (this->index < x.index);}
            bool    operator<=(const const_vector_reverseiterator& x)     {return (this->index <= x.index);}
            bool    operator>=(const const_vector_reverseiterator& x)     {return (this->index >= x.index);}
            bool    operator>(const const_vector_reverseiterator& x)     {return (this->index > x.index);}
            bool    operator==(const const_vector_reverseiterator& x)     {return (this->index == x.index);}
            bool    operator!=(const const_vector_reverseiterator& x)     {return (this->index != x.index);}
            //
            difference_type    operator+(const const_vector_reverseiterator& x)  {return (this->index - x.index);}
            difference_type    operator-(const const_vector_reverseiterator& x)  {return (this->index + x.index);}
            const_vector_reverseiterator    operator+(const difference_type& x)  {return const_vector_reverseiterator(this->index - x);}
            const_vector_reverseiterator    operator-(const difference_type& x)  {return const_vector_reverseiterator(this->index + x);}

            const_vector_reverseiterator    &operator+=(const difference_type& x)  {this->index -= x;return *this;}
            const_vector_reverseiterator    &operator-=(const difference_type& x)  {this->index += x;return *this;}

            //
            const_vector_reverseiterator     operator++(void)        {this->index--; return(*this);}
            const_vector_reverseiterator     operator++(int)         {const_vector_reverseiterator tamp(*this); --this->index; return(tamp);}
            const_vector_reverseiterator     operator--(void)        {this->index++; return(*this);}
            const_vector_reverseiterator     operator--(int)         {const_vector_reverseiterator tamp(*this); ++this->index; return(tamp);}

            //
            const_reference     operator*() {return (*this->index);}
            const_pointer     operator->()  {return (this->index);}
            const_reference     operator[](const difference_type& x) {return (*(this->index + x));}
        private:
            pointer     index;
            
    };

    template <typename T>
    bool    operator<(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<T> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T, typename U>
    bool    operator<(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<U> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T>
    bool    operator<=(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<T> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T, typename U>
    bool    operator<=(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<U> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T>
    bool    operator>(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<T> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T, typename U>
    bool    operator>(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<U> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T>
    bool    operator>=(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<T> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T, typename U>
    bool    operator>=(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<U> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T>
    bool    operator==(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<T> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T, typename U>
    bool    operator==(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<U> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T>
    bool    operator!=(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<T> &rhs)     {return (lhs.base() != rhs.base());}
    template <typename T, typename U>
    bool    operator!=(const const_vector_reverseiterator<T> &lhs, const const_vector_reverseiterator<U> &rhs)     {return (lhs.base() != rhs.base());}

    
    template <typename T>
    bool    operator<(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T, typename U>
    bool    operator<(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T>
    bool    operator<=(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T, typename U>
    bool    operator<=(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T>
    bool    operator>(const const_vector_reverseiterator<T> &lhs, const  vector_reverseiterator<T> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T, typename U>
    bool    operator>(const const_vector_reverseiterator<T> &lhs, const  vector_reverseiterator<U> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T>
    bool    operator>=(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T, typename U>
    bool    operator>=(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T>
    bool    operator==(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T, typename U>
    bool    operator==(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T>
    bool    operator!=(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<T> &rhs)     {return (lhs.base() != rhs.base());}
    template <typename T, typename U>
    bool    operator!=(const const_vector_reverseiterator<T> &lhs, const vector_reverseiterator<U> &rhs)     {return (lhs.base() != rhs.base());}

    template <typename T>
    ft::const_vector_reverseiterator<T> operator+(typename ft::const_vector_reverseiterator<T >::difference_type rhs, const ft::const_vector_reverseiterator<T > &lhs)                        { return (lhs.base() + rhs); }

    template <typename T>
    ft::const_vector_reverseiterator<T> operator+(const ft::const_vector_reverseiterator<T > &rhs, typename ft::const_vector_reverseiterator<T>::difference_type lhs)                        { return (rhs.base() + lhs); }
    template <typename T>
    ft::const_vector_reverseiterator<T> operator-(const ft::const_vector_reverseiterator<T > &rhs, typename ft::const_vector_reverseiterator<T>::difference_type lhs)                        { return (rhs.base() - lhs); }

    template <typename T>
    typename ft::const_vector_reverseiterator<T >::difference_type operator-(const ft::const_vector_reverseiterator<T > &rhs, const ft::const_vector_reverseiterator<T > &lhs)                { return (rhs.base() - lhs.base()); }
    template <typename U, typename V  >
    typename ft::const_vector_reverseiterator<U >::difference_type operator-(const ft::const_vector_reverseiterator<V > &rhs, const ft::const_vector_reverseiterator<U > &lhs)    { return (rhs.base() - lhs.base()); }
}

#endif


