#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{
    template <class _U1, class _U2>
    class pair
    {
        public:
        _U1     first;
        _U2     second;
        pair() : first(), second() {}

        pair(_T1 const& __t1, _T2 const& __t2) : first(__t1), second(__t2) {}

        pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}

        pair& operator=(pair const& __p) {
            first = __p.first;
            second = __p.second;
            return *this;
        }

        virtual ~pair()                     {}
    };
}

#endif