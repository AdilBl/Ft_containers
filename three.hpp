#ifndef THREE_HPP
#define THREE_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include <iostream>
# include "pair.hpp"
# include "node.hpp"

namespace  ft
{
    template<class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<ft::node<Key,T> > >
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
        typedef node<key_type, mapped_type>         node;

        three()
        {
            this->mother = nullptr;
            this->allocator = allocator_type();
            this->comparator = key_compare();
            this->size = 0;
        }
        ~three()        {}

        void r_insert(node &newnode)
        {
            insert(this->mother, newnode, nullptr);
        }

        node* newNode(node &p ,node *parent)
        {
            node* newnode = this->allocator.allocate(1);
            node temp(parent, nullptr, nullptr, ft::make_pair(p.content.first, p.content.second));

            this->allocator.construct(newnode, temp);
            this->size++;
            if (this->mother == nullptr)
            {
                this->mother = newnode;
                return (newnode);
            }
            if (this->comparator(parent->getkey() , p.getkey()) == 0)
                parent->left = newnode;
            else
                parent->right = newnode;
            return(newnode);
        }

        node *rightRotate(node *y)
        {
            node *x = y->left;
            node *T2 = x->right;
            x->right = y;
            y->left = T2;
            x->parent = y->parent;
            y->parent = x;
            if (y->right)
                y->right->parent = y;
            if (y == this->mother)
                this->mother = x;
            y->uptdatebalance();
            x->uptdatebalance();
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

    node* insert(node* instancenode, node  insertnode , node   *parent)
    {
        if (instancenode == NULL)
            return(newNode(insertnode, parent));
        if (this->comparator(instancenode->getkey() , insertnode.getkey()) == 0)
            instancenode->left = insert(instancenode->left, insertnode, instancenode);
        else
            instancenode->right = insert(instancenode->right, insertnode, instancenode);
        instancenode->uptdatebalance();
        int balance = instancenode->getdeep();
        if (balance > 1 && this->comparator(instancenode->getkey() , insertnode.getkey()) == 0)
            return rightRotate(instancenode);
        if (balance < -1 && this->comparator(instancenode->getkey() , insertnode.getkey()) == 1)
            return leftRotate(instancenode);
        if (balance > 1 && this->comparator(instancenode->getkey() , insertnode.getkey()) == 1)
        {
            instancenode->left = leftRotate(instancenode->left);
            return rightRotate(instancenode);
        }
        if (balance < -1 && this->comparator(instancenode->getkey() , insertnode.getkey()) == 0)
        {
            instancenode->right = rightRotate(instancenode->right);
            return leftRotate(instancenode);
        }
        return instancenode;
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