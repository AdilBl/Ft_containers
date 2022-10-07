#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "node.hpp"
#include <iomanip>
#include <iostream>

namespace ft
{
    template <class Key, class mapped_value>
    void debug_tree(ft::node<Key, mapped_value> * p, int indent)
    {
        if(p != NULL) 
        {
            if(p->right)
                debug_tree(p->right, indent+4);
            if (indent) 
                std::cout << std::setw(indent) << ' ';
            if (p->right)
                std::cout<<" /\n" << std::setw(indent) << ' ';
            std::cout<< p->getkey();
            if (p->parent)
                std::cout << " | p : " << p->parent->getkey() << std::endl;
            else
                std::cout << " | p : (nullptr)" << std::endl;
            if(p->left)
            {
                std::cout << std::setw(indent) << ' ' <<" \\ \n";
                debug_tree(p->left, indent+4);
            }
        }
    }
}

#endif