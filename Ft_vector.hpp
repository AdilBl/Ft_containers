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

        //get

        // T   gettabvalue(void) const
        // {
        //     return(*this->_tab);
        // }
};

// template <typename T>
// std::ostream &  operator<<(std::ostream & o, Ft_vector<T> const & i);

// template <typename T>
// std::ostream &  operator<<(std::ostream & o, Ft_vector<T> const & i)
// {
//     o << i.gettabvalue();
//     return(o);
// }

#endif