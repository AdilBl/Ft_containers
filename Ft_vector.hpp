#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include "header.hpp"

template <typename T>
class Ft_vector
{
    private:
        size_t _size;
        size_t _maxsize;
        int _pointer;
        T *_tab;
    public:
        Ft_vector<T>(void){
            std::cout <<"Constructeur 1 variable" << std::endl;
            this->_size = 0;
            this->_maxsize = 1;
            this->_pointer = 0;
            this->_tab = firstallocate(1);
        };
        virtual ~Ft_vector<T>(void){
            deallocate(this->_tab, this->_maxsize);
            return;
        };
        T   *firstallocate(size_t maxsize){
            std::cout << "Allocating => " <<maxsize<< std::endl;
            return new T[maxsize];
        }
        void deallocate(T *tab, size_t size){
            std::cout << "Deallocating => " <<size<< std::endl;
            delete[] tab;
        }
        void push_back(T n){
            this->_tab[this->_size] = n;
            std::cout << this->_tab[this->_size] << std::endl;
            this->_size++;
        }
};

#endif