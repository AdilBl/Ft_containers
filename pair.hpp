#ifndef PAIR_HPP
# define PAIR_HPP

// #include "utils.hpp"

namespace ft
{
    template <class U, class L>
    struct pair
    {
        typedef U         key_type;
        typedef L       value_type;

        key_type         first;
        value_type       second;
        pair() : first(), second() {}

        pair(key_type const& __t1,value_type const& __t2) : first(__t1), second(__t2) {}

        pair(const pair<key_type, value_type>& __p) : first(__p.first), second(__p.second) {}

        pair& operator=(pair const& __p) {
            if (this != &__p)
            {
                first = __p.first;
                second = __p.second;
            }
            return *this;
        }
        virtual ~pair()                     {;}
        // bool operator<(const pair<key_type,value_type>& lhs, const pair<key_type,value_type>& rhs)   {return(ft::lexicographical_compare(lhs.first.begin(), lhs.first.end(), rhs.first.begin(), rhs.first.end()));}
		// bool operator<=(const pair<key_type,value_type>& lhs, const pair<key_type,value_type>& rhs)   {return(!ft::lexicographical_compare(rhs.first.begin(), rhs.first.end(), lhs.first.begin(), lhs.first.end()));}
		// bool operator>(const pair<key_type,value_type>& lhs, const pair<key_type,value_type>& rhs)   {return(ft::lexicographical_compare(rhs.first.begin(), rhs.first.end(), lhs.first.begin(), lhs.first.end()));}
		// bool operator>=(const pair<key_type,value_type>& lhs, const pair<key_type,value_type>& rhs)   {return(!ft::lexicographical_compare(lhs.first.begin(), lhs.first.end(), rhs.first.begin(), rhs.first.end()));}
    };

    template <class key,class value>
    ft::pair<key,value> 	make_pair (key x, value y)		{return (ft::pair<key,value>(x,y));}
}

#endif