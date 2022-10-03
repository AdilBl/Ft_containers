#ifndef THREE_HPP
#define THREE_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "pair.hpp"
# include "utils.cpp"
# include "node.hpp"

namespace  ft
{
    template<class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<ft::node<class Key, class T> > >
    class three
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
        typedef node<class key, class value>        node;

        three()
        {
            this->mother = nullptr;
            this->allocator = allocator_type();
            this->comparator = key_compare();
            this->size = 0;
        }
        ~three();

        node *rightRotate(node *y)
        {
            node *x = y->left;
            node *T2 = x->right;
        
            // Perform rotation
            x->right = y;
            y->left = T2;

            x->parent = y->parent;
            y->parent = x;
            if (y->right)
                y->right->parent = y;
            if (y == this->mother)
                this->mother = x;
        
            // Update heights
            y->uptdatebalance();
            x->uptdatebalance();
        
            // Return new root
            return x;
        }

        node *leftRotate(node *x)
        {
            node *y = x->right;
            node *T2 = y->left;
        
            // Perform rotation
            y->left = x;
            x->right = T2;

            y->parent = x->parent;
            x->parent = y;
            if (x->right)
                x->right->parent = x;
            if (x == this->mother)
                this->mother = y;
        
            // Update heights
            x->uptdatebalance();
            y->uptdatebalance();
        
            // Return new root
            return y;
        }

        node    *getmother(void) const          {return (this->mother);}
        private:
            node            *mother;
            allocator_type  allocator;
            key_compare     comparator;
            size_type       size;
        
    };
}

#endif