#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "utils.hpp"
# include "pair.hpp"
# include "three.hpp"

namespace ft
{

template<class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<std::pair<const Key, T> > >

class map
{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef std::pair<const Key, T>				value_type;
		typedef	Compare								key_compare;
		typedef	Alloc								allocator_type;
		typedef value_type&							reference;
		typedef	const value_type&					const_reference;
		typedef value_type*							pointer;
		typedef const value_type*					const_pointer;
		typedef	ptrdiff_t							difference_type;
		typedef size_t								size_type;

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
		// bool empty() const
		// {
		// 	;
		// }
		// size_type size() const
		// {
		// 	;
		// }
		// size_type max_size() const
		// {
		// 	;
		// }

		//Element acces
		// mapped_type& operator[] (const key_type& k)			{}
		// mapped_type& at (const key_type& k)					{}
		// const mapped_type& at (const key_type& k) const		{}

		//Modifiers
		// pair<iterator,bool> insert (const value_type& val)
		// {
		// 	;
		// }
		// iterator insert (iterator position, const value_type& val)
		// {
		// 	;
		// }
		// template <class InputIterator>  void insert (InputIterator first, InputIterator last)
		// {
		// 	;
		// }
		// void erase (iterator position)
		// {
		// 	;
		// }
		// size_type erase (const key_type& k)
		// {
		// 	;
		// }
		// void erase (iterator first, iterator last)
		// {
		// 	;
		// }
		// void swap (map& x)
		// {
		// 	;
		// }
		// void clear()
		// {
		// 	;
		// }
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
		
	private:
		allocator_type	_allocator;

};



}
#endif