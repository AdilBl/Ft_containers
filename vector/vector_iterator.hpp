#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft
{
    template <class T>
    class vector_iterator
    {
        public:
            typedef T                   value_type;
            typedef value_type&         reference;
            typedef const value_type&   const_reference;
            typedef value_type*         pointer;
            typedef const value_type*   const_pointer;
            typedef std::size_t         size_type;
            typedef ptrdiff_t           difference_type;
            vector_iterator(void)           {this->index = NULL;}
            vector_iterator(pointer i)      {this->index = i;}
            vector_iterator (const vector_iterator& x)        {*this = x;}
            virtual ~vector_iterator()          {}
            
            vector_iterator& operator= (const vector_iterator& x)
            {
                if (this == &x)
                    return (*this);
                this->index = x.index;
                return (*this);
            }
            pointer base (void) const     {return (this->index);}
            //bool
            bool    operator<(const vector_iterator& x)     {return (this->index < x.index);}
            bool    operator<=(const vector_iterator& x)     {return (this->index <= x.index);}
            bool    operator>=(const vector_iterator& x)     {return (this->index >= x.index);}
            bool    operator>(const vector_iterator& x)     {return (this->index > x.index);}
            bool    operator==(const vector_iterator& x)     {return (this->index == x.index);}
            bool    operator!=(const vector_iterator& x)     {return (this->index != x.index);}
            //
            difference_type    operator+(const vector_iterator& x)  {return (this->index + x.index);}
            difference_type    operator-(const vector_iterator& x)  {return (this->index - x.index);}
            vector_iterator    operator+(const difference_type& x)  {return vector_iterator(this->index + x);}
            vector_iterator    operator-(const difference_type& x)  {return vector_iterator(this->index - x);}

            vector_iterator    &operator+=(const difference_type& x)  {this->index += x;return *this;}
            vector_iterator    &operator-=(const difference_type& x)  {this->index -= x;return *this;}

            //
            vector_iterator     operator++(void)        {this->index++; return(*this);}
            vector_iterator     operator++(int)         {vector_iterator tamp(*this); ++this->index; return(tamp);}
            vector_iterator     operator--(void)        {this->index--; return(*this);}
            vector_iterator     operator--(int)         {vector_iterator tamp(*this); --this->index; return(tamp);}

            //
            reference           operator*() {return (*this->index);}
            const_reference     operator*() const {return (*this->index);}
            pointer             operator->() {return (this->index);}
            pointer             operator->() const {return (this->index);}
            reference           operator[](const difference_type& x) {return (*(this->index + x));}
            const_reference     operator[](const difference_type& x) const {return (*(this->index + x));}
        private:
            pointer     index;
            
    };

    template <typename T>
    bool    operator<(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T, typename U>
    bool    operator<(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T>
    bool    operator<=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T, typename U>
    bool    operator<=(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T>
    bool    operator>(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T, typename U>
    bool    operator>(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T>
    bool    operator>=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T, typename U>
    bool    operator>=(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T>
    bool    operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T, typename U>
    bool    operator==(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T>
    bool    operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() != rhs.base());}
    template <typename T, typename U>
    bool    operator!=(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() != rhs.base());}

    template <typename T  >
    ft::vector_iterator<T > operator+(typename ft::vector_iterator<T >::difference_type rhs, const ft::vector_iterator<T > &lhs)                        { return (lhs.base() + rhs); }

    template <typename T  >
    ft::vector_iterator<T > operator+(const ft::vector_iterator<T > &rhs, typename ft::vector_iterator<T >::difference_type lhs)                        { return (rhs.base() + lhs); }

    template <typename T  >
    ft::vector_iterator<T > operator-(const ft::vector_iterator<T > &rhs, typename ft::vector_iterator<T >::difference_type lhs)                        { return (rhs.base() - lhs); }

    template <typename T  >
    typename ft::vector_iterator<T >::difference_type operator-(const ft::vector_iterator<T > &rhs, const ft::vector_iterator<T > &lhs)                { return (rhs.base() - lhs.base()); }
    template <typename U, typename V  >
    typename ft::vector_iterator<U >::difference_type operator-(const ft::vector_iterator<V > &rhs, const ft::vector_iterator<U > &lhs)    { return (rhs.base() - lhs.base()); }
}

#endif