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
        vector<T>(void){
            std::cout <<"Constructeur 1 variable" << std::endl;
            this->_size = 0;
            this->_maxsize = 1;
            this->_pointer = 0;
            this->_tab = firstallocate(1);
        };
        virtual ~vector<T>(void){
            deallocate(this->_tab);
            return;
        };

        //Allocation
        T   *firstallocate(size_t maxsize){
            std::cout << "First Allocating => " <<maxsize<< std::endl;
            return new T[maxsize];
        }
        T   *allocate(size_t  size){
            std::cout << "Allocating => " <<this->_maxsize<< std::endl;
            return new T[size];
        }

        //Deallocation
        void deallocate(T *tab){
            std::cout << "Deallocating => " <<this->_maxsize<< std::endl;
            delete[] tab;
        }

        //Fonction for vector
        void push_back(T n){
            if (this->_size >= this->_maxsize)
            {
                this->_maxsize = this->_maxsize * 2;
                T *nw = allocate(this->_maxsize);           //Reallocation de mémoire quand elle depasse la maxsize *2
                copy(this->_tab, nw);
                deallocate(this->_tab);
                this->_tab = nw;
            }
            this->_tab[this->_size] = n;
            std::cout << this->_tab[this->_size] << std::endl;
            this->_size++;
        }

        T   *copy(T *src, T *cpy){
            int i=0;
            while (src[i])
            {
                cpy[i] = src[i];
                i++;
            }
            return (cpy);
        }
};


}
#endif