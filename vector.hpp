#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

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
        // template <class InputIterator>         
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
        // {
        //     ;
        // }
        // vector (const vector& x)
        // {
        //     ;
        // }

        //Capacity
        size_type size() const      {return(this->_size);}
        size_type max_size() const  {return(1073741823);}
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
            if (n < 0)
                throw std::length_error("Reserve error size");
            if (n > max_size())
                throw std::length_error("Size is outrun max size");
            value_type *n_tab = this->allocator.allocate(n);
            for (size_type i = 0; i < n; i++)
                this->allocator.construct(n_tab + i, this->_tab[i]);
            for (size_type i = 0; i < n; i++)
                this->allocator.deallocate(this->_tab + i, 1);
            for (size_type i = 0; i < n; i++)
                this->allocator.destroy(this->_tab + i);
            this->_tab = n_tab;
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
            else if (n > this->_size && val)
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

        void push_back (const value_type& val)
        {
            if (this->_size == 0)
            {
                this->allocator.allocate(1);
                this->allocator.construct(this->_tab + this->_size, val);
                this->_size++;
                return;
            }
            if (this->_size == this->_capacity)
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
            reference front(void)           {return(this->_tab[0]);}
            const_reference front() const   {return(this->_tab[0]);}
            reference back()                {return(this->_tab[this->_size - 1]);}
            const_reference back() const    {return(this->_tab[this->_size - 1]);}
    private:

        size_type _size;
        size_type _capacity;
        allocator_type allocator;
        value_type *_tab;
};


}
#endif