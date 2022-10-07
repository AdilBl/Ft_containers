#ifndef CONST_VECTOR_ITERATOR_HPP
# define CONST_VECTOR_ITERATOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft
{
    template <class T>
    class const_vector_iterator
    {
        public:
            typedef T                   value_type;
            typedef value_type&         reference;
            typedef const value_type&   const_reference;
            typedef value_type*         pointer;
            typedef const value_type*   const_pointer;
            typedef std::size_t         size_type;
            typedef ptrdiff_t           difference_type;
            const_vector_iterator(void)           {this->index = nullptr;}
            const_vector_iterator(pointer i)      {this->index = i;}
            const_vector_iterator (const const_vector_iterator<value_type>& x)        {*this = x;}

            virtual ~const_vector_iterator()            {}
            
            const_vector_iterator& operator= (const vector_iterator<T>& x)
            {
                if (this == &x)
                    return (*this);
                this->index = x.index;
            }
            const_vector_iterator& operator= (const const_vector_iterator<T>& x)
            {
                if (this == &x)
                    return (*this);
                this->index = x.base();
                return (*this);
            }
            pointer base (void) const   {return (this->index);}
            //bool
            bool    operator<(const const_vector_iterator& x)     {return (this->index < x.index);}
            bool    operator<=(const const_vector_iterator& x)     {return (this->index <= x.index);}
            bool    operator>=(const const_vector_iterator& x)     {return (this->index >= x.index);}
            bool    operator>(const const_vector_iterator& x)     {return (this->index > x.index);}
            bool    operator==(const const_vector_iterator& x)     {return (this->index == x.index);}
            bool    operator!=(const const_vector_iterator& x)     {return (this->index != x.index);}
            //
            difference_type    operator+(const const_vector_iterator& x)  {return (this->index + x.index);}
            difference_type    operator-(const const_vector_iterator& x)  {return (this->index - x.index);}
            const_vector_iterator    operator+(const difference_type& x)  {return const_vector_iterator(this->index + x);}
            const_vector_iterator    operator-(const difference_type& x)  {return const_vector_iterator(this->index - x);}

            void    operator+=(const const_vector_iterator& x)  {return (this->index += x.index);}
            void    operator-=(const const_vector_iterator& x)  {return (this->index -= x.index);}

            //
            const_vector_iterator     operator++(void)        {this->index++; return(*this);}
            const_vector_iterator     operator++(int)         {const_vector_iterator tamp(*this); ++this->index; return(tamp);}
            const_vector_iterator     operator--(void)        {this->index--; return(*this);}
            const_vector_iterator     operator--(int)         {const_vector_iterator tamp(*this); --this->index; return(tamp);}

            //
            const_reference     operator*() {return (*this->index);}
            const_pointer     operator->() const {return (this->index);}
            const_reference     operator[](const difference_type& x) {return (*(this->index + x));}
        private:
            pointer     index;
            
    };

    template <typename T>
    bool    operator<(const const_vector_iterator<T> &lhs, const const_vector_iterator<T> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T, typename U>
    bool    operator<(const const_vector_iterator<T> &lhs, const const_vector_iterator<U> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T>
    bool    operator<=(const const_vector_iterator<T> &lhs, const const_vector_iterator<T> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T, typename U>
    bool    operator<=(const const_vector_iterator<T> &lhs, const const_vector_iterator<U> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T>
    bool    operator>(const const_vector_iterator<T> &lhs, const const_vector_iterator<T> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T, typename U>
    bool    operator>(const const_vector_iterator<T> &lhs, const const_vector_iterator<U> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T>
    bool    operator>=(const const_vector_iterator<T> &lhs, const const_vector_iterator<T> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T, typename U>
    bool    operator>=(const const_vector_iterator<T> &lhs, const const_vector_iterator<U> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T>
    bool    operator==(const const_vector_iterator<T> &lhs, const const_vector_iterator<T> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T, typename U>
    bool    operator==(const const_vector_iterator<T> &lhs, const const_vector_iterator<U> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T>
    bool    operator!=(const const_vector_iterator<T> &lhs, const const_vector_iterator<T> &rhs)     {return (lhs.base() != rhs.base());}
    template <typename T, typename U>
    bool    operator!=(const const_vector_iterator<T> &lhs, const const_vector_iterator<U> &rhs)     {return (lhs.base() != rhs.base());}

    template <typename T>
    bool    operator<(const const_vector_iterator<T> &lhs, const  vector_iterator<T> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T, typename U>
    bool    operator<(const const_vector_iterator<T> &lhs, const  vector_iterator<U> &rhs)     {return (lhs.base() < rhs.base());}
    template <typename T>
    bool    operator<=(const const_vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T, typename U>
    bool    operator<=(const const_vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() <= rhs.base());}
    template <typename T>
    bool    operator>(const const_vector_iterator<T> &lhs, const  vector_iterator<T> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T, typename U>
    bool    operator>(const const_vector_iterator<T> &lhs, const  vector_iterator<U> &rhs)     {return (lhs.base() > rhs.base());}
    template <typename T>
    bool    operator>=(const const_vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T, typename U>
    bool    operator>=(const const_vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() >= rhs.base());}
    template <typename T>
    bool    operator==(const const_vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T, typename U>
    bool    operator==(const const_vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() == rhs.base());}
    template <typename T>
    bool    operator!=(const const_vector_iterator<T> &lhs, const vector_iterator<T> &rhs)     {return (lhs.base() != rhs.base());}
    template <typename T, typename U>
    bool    operator!=(const const_vector_iterator<T> &lhs, const vector_iterator<U> &rhs)     {return (lhs.base() != rhs.base());}

    template <typename T>
    ft::const_vector_iterator<T> operator+(typename ft::const_vector_iterator<T >::difference_type rhs, const ft::const_vector_iterator<T > &lhs)                        { return (lhs.base() + rhs); }

    template <typename T>
    ft::const_vector_iterator<T> operator+(const ft::const_vector_iterator<T > &rhs, typename ft::const_vector_iterator<T>::difference_type lhs)                        { return (rhs.base() + lhs); }
    template <typename T>
    ft::const_vector_iterator<T> operator-(const ft::const_vector_iterator<T > &rhs, typename ft::const_vector_iterator<T>::difference_type lhs)                        { return (rhs.base() - lhs); }

    template <typename T>
    typename ft::const_vector_iterator<T >::difference_type operator-(const ft::const_vector_iterator<T > &rhs, const ft::const_vector_iterator<T > &lhs)                { return (rhs.base() - lhs.base()); }
    template <typename U, typename V  >
    typename ft::const_vector_iterator<U >::difference_type operator-(const ft::const_vector_iterator<V > &rhs, const ft::const_vector_iterator<U > &lhs)    { return (rhs.base() - lhs.base()); }
}

#endif