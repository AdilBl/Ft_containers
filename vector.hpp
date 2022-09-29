#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "header.hpp"
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft
{

template <class T, class Alloc= std::allocator<T> >
class vector
{
    private:

        //Typedef
        //All Constructor

        //All Destructor
        size_t _size;
        size_t _capacity;
        int _pointer;
        // T *_tab;
    public:
        typedef T                   value_type;
        typedef Alloc               allocator_type;
        typedef value_type&         reference;
        typedef const value_type&   const_reference;
        typedef value_type*         pointer;
        typedef const value_type*   const_pointer
        typedef size_t              size_type;

};


}
#endif