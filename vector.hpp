#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "vector_iterator.hpp"
# include "const_vector_iterator.hpp"
# include "vector_reverseiterator.hpp"
# include "const_reverseiterator.hpp"
# include "utils.hpp"

namespace ft
{
    template <class T, class Alloc= std::allocator<T> >
    class vector
    {
        public:
            //Typedef
            typedef T                   value_type;
            typedef Alloc               allocator_type;
            typedef value_type&         reference;
            typedef const value_type&   const_reference;
            typedef value_type*         pointer;
            typedef const value_type*   const_pointer;
            typedef std::size_t         size_type;

            typedef vector_iterator<value_type>                iterator;
            typedef const_vector_iterator<value_type>          const_iterator;
            typedef vector_reverseiterator<value_type>         reverse_iterator;
            typedef const_vector_reverseiterator<value_type>   const_reverse_iterator;

            //All Constructor
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                this->_size = 0;
                this->_capacity = 0;
                this->allocator = alloc;
            }
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                this->allocator = alloc;
                if (n > 0)
                {
                    this->_tab = this->allocator.allocate(n);
                    for (size_type i = 0; i < n; i++)
                    {
                        this->allocator.construct(this->_tab + i, val);
                    }
                    this->_capacity = n;
                    this->_size = n;
                }
                else if (n == 0)
                    return ;
                else
                    throw std::length_error("Error size");
            }
            template <class InputIterator>         
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!std::is_same<InputIterator, int>::value>::type* = 0)
            {
                this->allocator = alloc;
                this->_capacity = 0;
                this->_size = 0;
                while (first != last)
                    push_back(*first++);
            }

            vector (const vector& x)
            {
                this->_size = 0;
                this->_capacity = 0;
                this->allocator = x.allocator;
                *this = x;
            }

            virtual ~vector()
            {
                this->allocator.deallocate(this->_tab, this->_capacity);
            }

            vector& operator= (const vector& x)
            {
                if (this == &x)
                    return (*this);
                clear();
                this->_capacity = x._capacity;
                this->_size = x._size;
                this->allocator = x.allocator;
                this->_tab = this->allocator.allocate(this->_capacity);
                for (size_type i = 0; i < this->_capacity; i++)
                {
                    this->allocator.construct(this->_tab + i, x._tab[i]);
                }
                return (*this);
            }
            //Capacity
            size_type size() const      {return(this->_size);}
            size_type max_size() const  {return(this->allocator.max_size());}
            size_type capacity() const  {return(this->_capacity);}
            bool empty() const
            {
                if (this->_size == 0)
                    return true;
                else
                    return false;
            }
            void reserve (size_type n)
            {
                if (n > this->max_size())
                    throw std::length_error("Capacity overflow");
                if (n <= this->_capacity)
                    return ;
                T * t_Data = this->allocator.allocate(n);

                for (size_type i = 0; i < this->_size; i++)
                    this->allocator.construct(t_Data + i, this->_tab[i]);
                if (this->_capacity > 0)
                    this->allocator.deallocate(this->_tab, this->_capacity);
                this->_tab = t_Data;
                this->_capacity = n;
            }

            void resize (size_type n, value_type val = value_type())
            {
                if (n < 0)
                    throw std::length_error("resize size impossible");
                if (n < this->_size)
                {
                    for (size_type i = this->_size; i > n; i--)
                    {
                        this->allocator.destroy(this->_tab + i);
                    }
                    this->_size = n;
                    return;
                }
                else if (n > this->_size)
                {
                    while (n > this->_size)
                        push_back(val);
                }
                else
                {
                    while (n > this->_size)
                        push_back(0);
                }
            }

            //Modifiers

            template <class InputIterator>  
            void assign (InputIterator first, InputIterator last, typename ft::enable_if<!std::is_same<InputIterator, int>::value>::type* = 0)
            {
                clear();
                while (first != last)
                    push_back(*first++);
            }

            void assign (size_type n, const value_type& val)
            {
                clear();
                for (size_type i = 0; i < n; i++)
                    push_back(val);
            }

            void push_back (const value_type& val)
            {
                if (this->_capacity == 0)
                {
                    this->_tab = this->allocator.allocate(1);
                    this->allocator.construct(this->_tab, val);
                    this->_size++;
                    this->_capacity = 1;
                    return;
                }
                else if (this->_size >= this->_capacity)
                    reserve(this->_size * 2);
                this->allocator.construct(this->_tab + this->_size, val);
                this->_size++;
                return;
            }

            void pop_back(void)
            {
                if (this->_size == 0)
                    throw std::length_error("Vector is empty");
                else
                {
                    this->_size--;
                    this->allocator.destroy(this->_tab + this->_size);
                }
            }

            void clear()
            {
                for (size_type i = 0; i < this->_capacity ; i++)
                    this->allocator.destroy(this->_tab + i);
                this->_size = 0;
            }

            iterator insert (iterator position, const value_type& val)
            {
                ft::vector<value_type> t_Data(*this);

                iterator it = begin();
                size_type   i = 0;
                size_type   end = this->_size;
                while (it != position)
                {
                    it++;
                    i++;
                }
                clear();
                for (size_type n = 0; n < i; n++)
                    push_back(t_Data[n]);
                push_back(val);
                for (size_type n = i; n < end; n++)
                    push_back(t_Data[n]);
                it = begin();
                return(it + i);
            }

            void insert (iterator position, size_type k, const value_type& val)
            {
                ft::vector<value_type> t_Data(*this);

                iterator it = begin();
                size_type   i = 0;
                size_type   end = this->_size;
                while (it != position)
                {
                    it++;
                    i++;
                }
                clear();
                for (size_type n = 0; n < i; n++)
                    push_back(t_Data[n]);
                for (size_type n = 0; n < k; n++)
                    push_back(val);
                for (size_type n = i; n < end; n++)
                    push_back(t_Data[n]);
            }

            template <class InputIterator>    
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::is_same<InputIterator, int>::value>::type* = 0)
            {
                ft::vector<value_type> t_Data(*this);

                iterator it = begin();
                size_type   i = 0;
                size_type   end = this->_size;
                while (it != position)
                {
                    it++;
                    i++;
                }
                clear();
                for (size_type n = 0; n < i; n++)
                    push_back(t_Data[n]);
                while (first != last)
                    push_back(*first++);
                for (size_type n = i; n < end; n++)
                    push_back(t_Data[n]);
            }
            
            iterator erase (iterator position)
            {
                ft::vector<value_type> t_Data(*this);

                iterator it = begin();
                size_type   i = 0;
                size_type   end = this->_size;
                while (it != position)
                {
                    it++;
                    i++;
                }
                clear();
                for (size_type n = 0; n < i; n++)
                    push_back(t_Data[n]);
                for (size_type n = i + 1; n < end; n++)
                    push_back(t_Data[n]);
                return(++position);
            }


            iterator erase (iterator first, iterator last)
            {
                ft::vector<value_type> t_Data(*this);

                iterator it = begin();
                iterator fakefirst = first;

                size_type   i = 0;
                size_type   p = 0;
                size_type   end = this->_size;
                while (it != first)
                {
                    it++;i++;
                }
                while (first != last)
                {
                    first++;p++;
                }
                clear();
                for (size_type n = 0; n < i; n++)
                    push_back(t_Data[n]);
                for (size_type n = i + p; n < end; n++)
                    push_back(t_Data[n]);
                return(last);
            }

            void swap (vector& x)
            {
                std::swap(x._capacity, this->_capacity);
                std::swap(x._size, this->_size);
                std::swap(x._tab, this->_tab);
                std::swap(x.allocator, this->allocator);
            }

            //Element acces
                reference operator[] (size_type n)              {return(this->_tab[n]);}
                const_reference operator[] (size_type n) const  {return(this->_tab[n]);}
                reference at (size_type n)
                {
                    if (n < 0 || n >= this->_size)
                        throw std::out_of_range("Out of range");
                    else
                        return(this->_tab[n]);
                }
                const_reference at (size_type n) const
                {
                    if (n < 0 || n >= this->_size)
                        throw std::out_of_range("Out of range");
                    else
                        return(this->_tab[n]);
                }
                reference front(void)                   {return(this->_tab[0]);}
                const_reference front() const           {return(this->_tab[0]);}
                reference back()                        {return(this->_tab[this->_size - 1]);}
                const_reference back() const            {return(this->_tab[this->_size - 1]);}
                value_type* data()                      {return(this->_tab);}
                const value_type* data() const          {return(this->_tab);}
                allocator_type get_allocator() const    {return(this->allocator);}

            //Iterator
                iterator begin()                        {return(iterator(this->_tab));}
                const_iterator begin() const            {return(const_iterator(this->_tab));}
                iterator end()                          {return(iterator(this->_tab + this->_size));}
                const_iterator end() const              {return(const_iterator(this->_tab + this->_size));}
                reverse_iterator rbegin()               {return(reverse_iterator(this->_tab + this->_size - 1));}
                const_reverse_iterator rbegin() const   {return(const_reverse_iterator(this->_tab + this->_size - 1));}
                reverse_iterator rend()                 {return(reverse_iterator(this->_tab - 1));}
                const_reverse_iterator rend() const     {return(const_reverse_iterator(this->_tab - 1));}
        private:

            size_type _size;
            size_type _capacity;
            allocator_type allocator;
            value_type *_tab;
    };

    template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)   {return(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}

    template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)   {return(!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}

    template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)   {return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)   {return(!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));}

    template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)   {return(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));}

    template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)   {return(!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)                         {std::swap(x, y);}
}
#endif