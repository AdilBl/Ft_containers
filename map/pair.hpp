#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
    template <class U, class L>
    struct pair
    {
        typedef U                           key_type;
        typedef L                           value_type;
        typedef pair<key_type,value_type>   paire;

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
        bool    operator==(const paire& x)     {return (x.first == this->first && x.second == this->second);}
        bool    operator!=(const paire& x)     {return (x.first != this->first && x.second != this->second);}


    };

    template <class _T1, class _T2>
    bool
    operator==(const pair<_T1,_T2>& x, const pair<_T1,_T2>& y)
    {
        return x.first == y.first && x.second == y.second;
    }

    template <class _T1, class _T2>
    bool
    operator!=(const pair<_T1,_T2>& x, const pair<_T1,_T2>& y)
    {
        return !(x == y);
    }

    template <class _T1, class _T2>
    bool
    operator< (const pair<_T1,_T2>& x, const pair<_T1,_T2>& y)
    {
        return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
    }

    template <class _T1, class _T2>
    bool
    operator> (const pair<_T1,_T2>& x, const pair<_T1,_T2>& y)
    {
        return y < x;
    }

    template <class _T1, class _T2>
    bool
    operator>=(const pair<_T1,_T2>& x, const pair<_T1,_T2>& y)
    {
        return !(x < y);
    }

    template <class _T1, class _T2>
    bool
    operator<=(const pair<_T1,_T2>& x, const pair<_T1,_T2>& y)
    {
        return !(y < x);
    }
    
    // template <class key_type, class value_type>
    // bool operator< (const pair<key_type,value_type>& lhs, const pair<key_type,value_type>& rhs)   {return(lhs.first < rhs.first && (!(rhs.first < lhs.first))  && lhs.seconde < rhs.second);}
    // template <class key_type, class value_type>
    // bool operator<=(const pair<key_type,value_type>& lhs, const pair<key_type,value_type>& rhs)   {return(lhs.first <= rhs.first && (!(rhs.first <= lhs.first))  && lhs.seconde <= rhs.second);}
    // template <class key_type, class value_type>
    // bool operator> (const pair<key_type,value_type>& lhs, const pair<key_type,value_type>& rhs)   {return(lhs.first > rhs.first && (!(rhs.first > lhs.first))  && lhs.seconde > rhs.second);}
    // template <class key_type, class value_type>
    // bool operator>=(const pair<key_type,value_type>& lhs, const pair<key_type,value_type>& rhs)   {return(lhs.first >= rhs.first && (!(rhs.first >= lhs.first))  && lhs.seconde >= rhs.second);}
    template <class key,class value>
    ft::pair<key,value> 	make_pair (key x, value y)		{return (ft::pair<key,value>(x,y));}
}

#endif