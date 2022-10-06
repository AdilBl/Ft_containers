#ifndef THREE_HPP
#define THREE_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include <iostream>
# include "pair.hpp"
# include "node.hpp"
# include "utils.hpp"

namespace  ft
{
    template<class Key, class T, class Compare = ft::less<Key>,class Alloc = std::allocator<ft::node<Key,T> > >
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
            this->start = this->allocator.allocate(1);
            this->end = this->allocator.allocate(1);
            node temp(nullptr, nullptr, nullptr, nullptr);
            node temp2(nullptr, nullptr, nullptr, nullptr);
            this->allocator.construct(this->start, temp);
            this->allocator.construct(this->end, temp2);
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
            hidefakenode(this->mother);
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
            addfakenode(this->mother);
            this->nwnode = insertnode;
            return instancenode;
        }

        node * minValueNode(node* src)
        {
            node* current = src;
        
            /* loop down to find the leftmost leaf */
            while (current->left != nullptr)
                current = current->left;
        
            return current;
        }

        node* deleteNode(node* root, key_type key)
        {
            hidefakenode(this->mother);
            if (root == nullptr)
                return root;
            if (root->getkey() != key)
            {
                if (this->comparator(root->getkey() , key) == 0)
                    root->left = deleteNode(root->left, key);
                else
                    root->right = deleteNode(root->right, key);
            }
            else
            {
                // std::cout << "| " << key << "\n";
                if( (root->left == nullptr) ||
                    (root->right == nullptr) )
                {
                    node *temp;
                    if (root->left)
                        temp = root->left;
                    else
                        temp = root->right;
                    if (temp == nullptr)
                    {
                        temp = root;
                        root = nullptr;
                    }
                    else
                        *root = *temp;
                    this->allocator.destroy(temp);
                    this->allocator.deallocate(temp, 1);
                    temp = nullptr;
                }
                else
                {
                    node* temp = minValueNode(root->right);
                    root->content = temp->content;
                    root->right = deleteNode(root->right, key);
                }
            }
            if (root == nullptr)
                return root;
            root->uptdatebalance();
            int balance = root->getdeep();
            if (balance > 1 && root->left != nullptr &&root->left->getdeep() >= 0)
                return rightRotate(root); 
            if (balance > 1 && root->left != nullptr && root->left->getdeep() < 0)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (root->right != nullptr)
            {
                if (balance < -1 && root->right != nullptr && root->right->getdeep() <= 0)
                    return leftRotate(root);
                if (balance < -1 && root->right != nullptr && root->right->getdeep() > 0)
                {
                    if (root->right != nullptr)
                    {
                        return leftRotate(root);
                    }
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
            }
            addfakenode(this->mother);
            return root;
    }

    mapped_type find(const key_type&src)
    {
        node    *actualnode(this->mother);
        while (actualnode->getkey() != src && actualnode != nullptr)
        {
            if (this->comparator(actualnode->getkey() , src) == 0)
            {
                actualnode == actualnode->left;
            }
            else
                actualnode == actualnode->right;
        }
        return(actualnode->getvalue());
    }

    void    addfakenode(node *actualnode)
    {
        while (actualnode->left != nullptr)
        {
            actualnode = actualnode->left;
        }
        actualnode->left = this->start;
        this->start->parent = actualnode;
        actualnode = this->mother;
        while (actualnode->right != nullptr)
        {
            actualnode = actualnode->parent;
        }
        actualnode->right = this->end;
        this->end->parent = actualnode;
    }

    void    hidefakenode(node *actualnode)
    {
        this->start->parent->left   = nullptr;
        this->end->parent->right    = nullptr;
        this->start->parent         = nullptr;
        this->end->parent           = nullptr;
    }

    node    *getstart(void) const           {return(this->start->parent);}
    node    *getend(void)const              {return(this->end);}
    node    *getrbegin(void)const           {return(this->end->parent);}
    node    *getrend(void)const             {return(this->start);}
    node    *getmother(void) const          {return(this->mother);}
    node    *getnewnode(void) const         {return(this->nwnode);}
    private:
        node            *mother;
        node            *start;
        node            *end;
        node            *nwnode;
        allocator_type  allocator;
        key_compare     comparator;
        size_type       size;   
};
}



#endif