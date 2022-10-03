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

    template <class key,class value>
    ft::pair<key,value> 	make_pair (key x, value y)		{return (ft::pair<key,value>(x,y));}
}