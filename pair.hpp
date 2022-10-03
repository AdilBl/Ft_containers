#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{
    template <class key, class value>
    class pair
    {
        public:
        key         first;
        value       second;
        pair() : first(), second() {}

        pair(_T1 const& __t1, _T2 const& __t2) : first(__t1), second(__t2) {}

        pair(const pair<key, value>& __p) : first(__p.first), second(__p.second) {}

        pair& operator=(pair const& __p) {
            if (this != &__p)
            {
                first = __p.first;
                second = __p.second;
            }
            return *this;
        }
        virtual ~pair()                     {}
        bool operator<(const pair<key,value>& lhs, const pair<key,value>& rhs)   {return(ft::lexicographical_compare(lhs.first.begin(), lhs.first.end(), rhs.first.begin(), rhs.first.end()));}
		bool operator<=(const pair<key,value>& lhs, const pair<key,value>& rhs)   {return(!ft::lexicographical_compare(rhs.first.begin(), rhs.first.end(), lhs.first.begin(), lhs.first.end()));}
		bool operator>(const pair<key,value>& lhs, const pair<key,value>& rhs)   {return(ft::lexicographical_compare(rhs.first.begin(), rhs.first.end(), lhs.first.begin(), lhs.first.end()));}
		bool operator>=(const pair<key,value>& lhs, const pair<key,value>& rhs)   {return(!ft::lexicographical_compare(lhs.first.begin(), lhs.first.end(), rhs.first.begin(), rhs.first.end()));}
    };
}

#endif