/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:55 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/10/22 08:53:17 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>
#include "iterator.hpp"
#include <memory>
namespace ft
{
	typedef  __SIZE_TYPE__  l_size;
	template<class T, class Allocator = std::allocator<T> >
	
	class Vector
	{
		private:
			T *storage;
			Allocator alloc;
			l_size size;
			l_size capcity;
		public:

			typedef T value_type;
			typedef Allocator allocator_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef Iterator<std::random_access_iterator_tag, T> iterator ;
			typedef Iterator<std::random_access_iterator_tag, const T> const_iterator;
	
			explicit Vector(const Allocator& alloc = Allocator())
			{
				this->alloc = alloc;
				this->size = 0;
				this->capcity = 0;
			}
			
			explicit Vector(l_size n, const T& val = T(), const Allocator& alloc = Allocator())
			{
				this->size = n;
				this->alloc = alloc;
				this->storage = this->alloc.allocate(n);
				this->capcity = n;
				for (l_size i = 0; i < n; i++)
				{
					this->storage[i] = val;
				}
			}	

			Vector(const Vector& v)
			{
				this = v;
			}

			/*template <class InputIterator>
			Vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
			{
				this->size = last - first;
				this->capcity = this->size;
				this->alloc = alloc;
				this->storage = alloc.allocate(size);
				int i = 0;
				while (first != last)
				{
					storage[i] = *first;
					first++;
					i++;
				}
			}*/
			
			Vector& operator=(const Vector& v)
			{
				if (this != v)
				{
					this->size = v.size;
					this->alloc = v.alloc;
					this->storage = v.storage;
					this->capcity = v.capcity;
				}
			}
			
			~Vector()
			{				
			}
			
			value_type operator[](l_size n)const
			{
				return this->storage[n];
			}
			iterator begin()
			{
				return (iterator(&storage[0]));
			}
			
			iterator end()
			{
				return (iterator(&storage[size]));
			}
	};

};

#endif