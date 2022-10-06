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

template<class Key, class T, class Compare = ft::less<Key>,class Alloc = std::allocator<std::pair<const Key, T> > >

class map
{
	public:
		typedef Key																key_type;
		typedef T																mapped_type;
		typedef std::pair<const Key, T>											value_type;
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

		

		// explicit map (const key_compare& comp = key_compare(),              const allocator_type& alloc = allocator_type())
		// {
		// 	;
		// }
		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
		// {
		// 	;
		// }
		// map (const map& x)
		// {
		// 	;
		// }
		// map& operator= (const map& x)
		// {
		// 	;
		// }
		virtual ~map()									{}
		//Capacity
		bool empty() const			{return(this->size == 0);}
		size_type size() const		{return(this->size);}
		size_type max_size() const	{return(this->allocator.max_size());}

		//Element acces
		mapped_type& operator[] (const key_type& k)	
		{
			if(this->three.find(k))
				return(this->three.find(k));
			else
			{
				node nw(ft::pair(k, value_type()));
				this->three.insert(this->three.getmother(), nw, nullptr);
				return(at(k));
			}
		}
		mapped_type& at (const key_type& k)	
		{
			if (this->three.find(k))
				return(this->three.find(k));
			throw(std::out_of_range("Not found"))
		}
		const mapped_type& at (const key_type& k) const
		{
			if (this->three.find(k))
				return(this->three.find(k));
			throw(std::out_of_range("Not found"))
		}

		//Iterator

		iterator begin()								{return(this->three.getstart());}
		const_iterator begin() const					{return(this->three.getstart());}
		iterator end()									{return(this->three.getend());}
		const_iterator end() const						{return(this->three.getend());}
		const_iterator cbegin() const noexcept			{return(this->three.getstart());}
		const_iterator cend() const noexcept			{return(this->three.getend());}
		reverse_iterator rbegin()						{return(this->three.getrbegin());}
		const_reverse_iterator rbegin() const			{return(this->three.getrbegin());}
		reverse_iterator rend()							{return(this->three.getrend());}
		const_reverse_iterator rend() const				{return(this->three.getrend());}
		const_reverse_iterator crbegin() const noexcept	{return(this->three.getrbegin());}
		const_reverse_iterator crend() const noexcept	{return(this->three.getrend());}

		//Modifiers
		pair<iterator,bool> insert (const value_type& val)
		{
			node nw(val);
			this->three.insert(this->three.getmother(), val, nullptr);
			return(this->three.getnewnode());
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				node nw(*first);
				this->three.insert(this->three.getmother(), nw, nullptr);
				first++;
			}
			
		}
		void erase (iterator position)
		{
			this->three.deleteNode(this->three.getmother(),*position.getkey());
		}
		size_type erase (const key_type& k)
		{
			this->three.deleteNode(this->three.getmother(), k);
		}
		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				this->three.deleteNode(this->three.getmother(),);
			}
		}
		void swap (map& x)
		{
			std::swap(*this, x);
		}
		void clear()
		{
			iterator	it = begin();
			iterator	end = end();
		}
		// template <class... Args>  pair<iterator,bool>
		// emplace (Args&&... args)
		// {
		// 	;
		// }
		// template <class... Args>
		// iterator emplace_hint (const_iterator position, Args&&... args)
		// {
		// 	;
		// }

		//Obserbvers
		// key_compare key_comp() const					{}
		// value_compare value_comp() const				{}

		//Operations
		// iterator find (const key_type& k)
		// {
		// 	;
		// }
		// const_iterator find (const key_type& k) const
		// {
		// 	;
		// }
		// size_type count (const key_type& k) const
		// {
		// 	;
		// }
		// iterator lower_bound (const key_type& k)
		// {
		// 	;
		// }
		// const_iterator lower_bound (const key_type& k) const
		// {
		// 	;
		// }
		// iterator upper_bound (const key_type& k)
		// {
		//	;
		// }
		// const_iterator upper_bound (const key_type& k) const
		// {
		// 	;
		// }
		// pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		// {
		//	;
		// }
		// pair<iterator,iterator>             equal_range (const key_type& k)
		// {
		// 	;
		// }
		//Allocator
		allocator_type get_allocator() const			{return(this->_allocator);}

		class value_compare : public ft::binary_function<value_type,value_type,bool>
		{
			friend class map<key_type, mapped_type, key_compare>;
			protected:
				key_compare comp;
				value_compare (key_compare c) : comp(c) {}
			public:
				bool operator() (const value_type& x, const value_type& y) const{return comp(x.first, y.first);}
		}
		
	private:
		allocator_type							_allocator;
		size_type								size;
		three<key_type, mapped_type>			three;
};



}
#endif