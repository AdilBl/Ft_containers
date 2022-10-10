#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include <map>
# include "utils.hpp"
# include "pair.hpp"
# include "three.hpp"
# include "node.hpp"
# include "const_map_iterator.hpp"
# include "map_iterator.hpp"
# include "reverse_map_iterator.hpp"
# include "const_reverse_map_iterator.hpp"
# include <iterator>

namespace ft
{

template<class Key, class T, class Compare = ft::less<Key>,class Alloc = std::allocator<ft::node<Key, T> > >

class map
{
	public:
		typedef Key																key_type;
		typedef T																mapped_type;
		typedef ft::pair<Key, T>												value_type;
		typedef	Compare															key_compare;
		typedef	Alloc															allocator_type;
		typedef value_type&														reference;
		typedef	const value_type&												const_reference;
		typedef value_type*														pointer;
		typedef const value_type*												const_pointer;
		typedef	ptrdiff_t														difference_type;
		typedef size_t															size_type;
		typedef ft::map_iterator<key_type, mapped_type>							iterator;
		typedef ft::const_map_iterator<key_type, mapped_type>					const_iterator;
		typedef ft::reverse_map_iterator<key_type, mapped_type>					reverse_iterator;
		typedef ft::const_reverse_map_iterator<key_type, mapped_type>			const_reverse_iterator;

		
		class value_compare : public ft::binary_function<value_type,value_type,bool>
		{
			friend class map<key_type, mapped_type, key_compare>;
			protected:
				key_compare comp;
				value_compare (key_compare c) : comp(c) {}
			public:
				bool operator() (const value_type& x, const value_type& y) const{return comp(x.first, y.first);}
		};

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):three()
		{
			this->_allocator = alloc;
			this->comp = comp;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
		{
			this->_allocator = alloc;
			this->comp = comp;
			while (first != last)
			{
				insert(ft::make_pair(first->first, first->second));
				first++;
			}
		}
		map (const map& x)
		{
			*this = x;
		}
		map& operator= (const map& x)
		{
			if(this != &x)
			{
				this->_allocator = x._allocator;
				this->comp = x.comp;
				clear();
				for(const_iterator it = x.begin(); it != x.end(); it++)
					insert(ft::make_pair(it->first, it->second));
			}
			return(*this);
		}
		virtual ~map()
		{
			clear();
			this->three.~three();	
		}
		//Capacity
		bool empty() const			{return(this->three.getsize() == 0);}
		size_type size() const		{return(this->three.getsize());}
		size_type max_size() const	{return(std::map<key_type, mapped_type>().max_size());}

		//Element acces
		mapped_type& operator[] (const key_type& k)	
		{
			if(count(k))
				return(this->three.findm(k));
			else
			{
				ft::node<key_type, mapped_type> nw(ft::pair<key_type, mapped_type>(k, mapped_type()));
				this->three.r_insert(nw);
				return(at(k));
			}
		}
		mapped_type& at (const key_type& k)	
		{
			ft::node<key_type, mapped_type> * finded = this->three.find(k);

			if (finded != nullptr)
				return(finded->content.second);
			throw(std::out_of_range("Not found"));
		}
		const mapped_type& at (const key_type& k) const
		{
			ft::node<key_type, mapped_type> * finded = this->three.find(k);
			if (finded != nullptr)
				return(finded->content.second);
			throw(std::out_of_range("Not found"));
		}

		//Iterator

		iterator begin()								
		{
			// this->three.addfakenode();
			if (this->getmom() == nullptr)
				return(iterator(this->three.getend()));
			return(iterator(this->three.getstart()));
		}
		const_iterator begin() const					
		{
			if (this->getmom() == nullptr)
				return(const_iterator(this->three.getend()));
			return(const_iterator(this->three.getstart()));
		}
		iterator end()									{return(iterator(this->three.getend()));}
		const_iterator end() const						{return(const_iterator(this->three.getend()));}
		const_iterator cbegin() const					{return(const_iterator(this->three.getstart()));}
		const_iterator cend() const 					{return(const_iterator(this->three.getend()));}
		reverse_iterator rbegin()						{return(reverse_iterator(this->three.getrbegin()));}
		const_reverse_iterator rbegin() const			{return(const_reverse_iterator(this->three.getrbegin()));}
		reverse_iterator rend()							
		{
			if (this->getmom() == nullptr)
				return(reverse_iterator(this->three.getend()->parent));	
			return(reverse_iterator(this->three.getrend()));
		}
		const_reverse_iterator rend() const
		{
			if (this->getmom() == nullptr)
				return(const_reverse_iterator(this->three.getend()->parent));	
			return(const_reverse_iterator(this->three.getrend()));
		}
		const_reverse_iterator crbegin() const 			{return(const_reverse_iterator(this->three.getrbegin()));}
		const_reverse_iterator crend() const 			{return(const_reverse_iterator(this->three.getrend()));}

		//Modifiers
		pair<iterator,bool> insert (const_reference val)
		{
			if (count(val.first) == 1)
				return pair<iterator,bool>(find(val.first), false);
			ft::node<key_type, mapped_type> nw(nullptr, nullptr, nullptr, ft::make_pair(val.first, val.second));
			this->three.r_insert(nw);
			return	pair<iterator,bool>(this->three.getnewnode(), true);
		}
		iterator insert (iterator position, const value_type& val)
		{
			(void) position;
			return insert(val).first;
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				node<key_type, mapped_type> nw(*first);
				this->three.r_insert(nw);
				first++;
			}
		}
		
		void erase (iterator position)
		{
			this->three.r_delete(position->first);
		}

		size_type erase (const key_type& k)
		{
			this->three.r_delete(k);
			return(1);
		}
		void erase (iterator first, iterator last)
		{
			size_type i = ft::distance(first, last);
			for(size_type k = 0; k < i && first != last ; k++)
			{
				erase(first++);
			}
		}
		void swap (map& x)
		{
			ft::three <key_type, mapped_type>   tamp(false);
        
			tamp = this->three;
			this->three = x.three;
			x.three = tamp;

			tamp.setstartnull();
			tamp.setendnull();
			std::swap(this->comp, x.comp);
			std::swap(this->_allocator, x._allocator);
		}
		void clear()
		{
			if (this->three.getsize() != 0)
			{
				this->three.hidefakenode();
				this->three.clear_three(this->three.getmother());
			}
			this->three.setsize(0);
			this->three.setmom();
		}
		//Obserbvers
		key_compare key_comp() const					{return (key_compare());}
		value_compare value_comp() const				{return (value_comp());}

		//Operations
		iterator find (const key_type& k)
		{
			return(this->three.find(k));
		}
		const_iterator find (const key_type& k) const
		{
			this->three.find(k);
		}
		size_type count (const key_type& k) const
		{
			try
			{
				at(k);
			}
			catch(const std::exception& e)
			{
				return	(0);
			}
			return(1);
		}
		iterator lower_bound (const key_type& k)
		{
			iterator it = begin();
			while (this->comp(it->first, k) && it != end())
			{
				it++;
			}
			return (it);
		}
		const_iterator lower_bound (const key_type& k) const
		{
			iterator it = begin();
			while (this->comp(it->first, k) && it != end())
			{
				it++;
			}
			return (it);
		}
		iterator upper_bound (const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if(this->comp(k, it->first))
					return (it);
				it++;
			}
			return (end());
		}
		const_iterator upper_bound (const key_type& k) const
		{
			iterator it = begin();
			while (it != end())
			{
				if(this->comp(k, it->first))
					return (it);
				it++;
			}
			return (end());
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}
		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}
		//Allocator
		allocator_type get_allocator() const			{return(this->_allocator);}
		node<key_type, mapped_type>   *getmom(void) const          		{return(this->three.getmother());}

		
	private:
		allocator_type											_allocator;
		three<key_type, mapped_type, Compare, Alloc>			three;
		key_compare     										comp;
};

	template <class _Key, class _Tp, class _Compare, class _Allocator>
    bool operator==(const ft::map<_Key, _Tp, _Compare, _Allocator>& x, const ft::map<_Key, _Tp, _Compare, _Allocator>& y)
    {
        return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
    }

	template <class _Key, class _Tp, class _Compare, class _Allocator>
    bool operator!=(const ft::map<_Key, _Tp, _Compare, _Allocator>& x, const ft::map<_Key, _Tp, _Compare, _Allocator>& y)
    {
        return !(x == y);
    }

	template <class _Key, class _Tp, class _Compare, class _Allocator>
    bool operator<(const ft::map<_Key, _Tp, _Compare, _Allocator>& lhs, const ft::map<_Key, _Tp, _Compare, _Allocator>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

	template <class _Key, class _Tp, class _Compare, class _Allocator>
    bool operator<=(const ft::map<_Key, _Tp, _Compare, _Allocator>& lhs, const ft::map<_Key, _Tp, _Compare, _Allocator>& rhs)
    {
        return !(rhs < lhs);
    }


	template <class _Key, class _Tp, class _Compare, class _Allocator>
    bool operator>(const ft::map<_Key, _Tp, _Compare, _Allocator>& lhs, const ft::map<_Key, _Tp, _Compare, _Allocator>& rhs)
    {
		return(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class _Key, class _Tp, class _Compare, class _Allocator>
    bool operator>=(const ft::map<_Key, _Tp, _Compare, _Allocator>& lhs, const ft::map<_Key, _Tp, _Compare, _Allocator>& rhs)
    {
		return(!(rhs > lhs));
	}

	template <class _Key, class _Tp, class _Compare, class _Allocator>
    void swap(const ft::map<_Key, _Tp, _Compare, _Allocator>& x, const ft::map<_Key, _Tp, _Compare, _Allocator>& y)
	{
		x.swap(y);
	}

}
#endif