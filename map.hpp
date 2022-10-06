#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "utils.hpp"
# include "pair.hpp"
# include "three.hpp"
# include "node.hpp"
# include "const_map_iterator.hpp"
# include "map_iterator.hpp"
# include "reverse_map_iterator.hpp"
# include "const_reverse_map_iterator.hpp"

namespace ft
{

template<class Key, class T, class Compare = ft::less<Key>,class Alloc = std::allocator<ft::pair<Key, T> > >

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

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->_allocator = alloc;
			this->comp = comp;
			this->three = ft::three<key_type, mapped_type>(comp, alloc);	
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
				for(iterator it = x.begin(); it != x.end(); it++)
					insert(ft::make_pair(it->first, it->second));

			}
		}
		virtual ~map()									{}
		//Capacity
		bool empty() const			{return(this->size == 0);}
		size_type size() const		{return(this->size);}
		size_type max_size() const	{return(this->allocator.max_size());}

		//Element acces
		mapped_type& operator[] (const key_type& k)	
		{
			if(this->three.findm(k))
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

		iterator begin()								{return(this->three.getstart());}
		const_iterator begin() const					{return(this->three.getstart());}
		iterator end()									{return(this->three.getend());}
		const_iterator end() const						{return(this->three.getend());}
		const_iterator cbegin() const					{return(this->three.getstart());}
		const_iterator cend() const 					{return(this->three.getend());}
		reverse_iterator rbegin()						{return(this->three.getrbegin());}
		const_reverse_iterator rbegin() const			{return(this->three.getrbegin());}
		reverse_iterator rend()							{return(this->three.getrend());}
		const_reverse_iterator rend() const				{return(this->three.getrend());}
		const_reverse_iterator crbegin() const 			{return(this->three.getrbegin());}
		const_reverse_iterator crend() const 			{return(this->three.getrend());}

		//Modifiers
		pair<iterator,bool> insert (const_reference val)
		{
			std::cout << "-\n";
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
			this->three.r_delete(*position.getkey());
		}
		size_type erase (const key_type& k)
		{
			this->three.r_delete(k);
			return(1);
		}
		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				this->three.r_delete();
			}
		}
		void swap (map& x)
		{
			std::swap(*this, x);
		}
		void clear()
		{
			this->three.clear_three(this->three.getmother);
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
		allocator_type							_allocator;
		three<key_type, mapped_type>			three;
		key_compare     						comp;
};



}
#endif