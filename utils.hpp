#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include "pair.hpp"

namespace ft
{
    template <bool Cond, class T = void> struct enable_if{};

    template<class T> struct enable_if<true, T> { typedef T type; };

    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (*first1 == *first2)
            {
                first1++;
                first2++;
            }
            else
                return (false);
        }
        return (true);
    }
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1) return false;
            else if (*first1<*first2) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    template <class Arg1, class Arg2, class Result>
    struct binary_function {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };
    template <class T> struct less : binary_function <T,T,bool> {
    bool operator() (const T& x, const T& y) const {return x<y;}
    };

    template <class It1, class It2> 
    size_t distance(It1 first, It2 last)
    {
        size_t result = 0;
        while (first != last) {
            ++first;
            ++result;
        }
        return result;
    }
}

#endif