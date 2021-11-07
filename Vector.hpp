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
#include "reverse_iterator.hpp"
#include <math.h>
#include "utils.hpp"
namespace ft
{
	typedef  __SIZE_TYPE__  l_size;
	template<class T, class Allocator = std::allocator<T> >
	
	class Vector
	{
		private:
			T *storage;
			Allocator alloc;
			l_size _size;
			l_size _capacity;
		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef Iterator<std::random_access_iterator_tag, T> iterator ;
			typedef Iterator<std::random_access_iterator_tag, const T> const_iterator;
			typedef reverse_iterator<const_iterator> const_reverse_iterator;
			typedef reverse_iterator<iterator> reverse_iterator;
	
			explicit Vector(const Allocator& alloc = Allocator())
			{
				this->alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
			}	
			explicit Vector(l_size n, const T& val = T(), const Allocator& alloc = Allocator())
			{
				this->_size = n;
				this->alloc = alloc;
				this->storage = this->alloc.allocate(n);
				this->_capacity = n;
				for (l_size i = 0; i < n; i++)
				{
					//std::cout << "check 0 for " << i << std::endl;
					this->storage[i] = val;
					//std::cout << "check 1 for " << i << std::endl;

				}
			}
			Vector(const Vector& v)
			{
				*this = v;
			}
			template <class InputIterator>
			Vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())

			{
				this->_size = last - first;
				this->_capacity = this->_size;
				this->alloc = alloc;
				this->storage = this->alloc.allocate(_size);
				int i = 0;
				while (first != last)
				{
					storage[i] = *first;
					first++;
					i++;
				}
			}	
			Vector& operator=(const Vector& v)
			{
				if (this != &v)
				{
					this->_size = v._size;
					this->alloc = v.alloc;
					this->storage = v.storage;
					this->_capacity = v._capacity;
				}
				return *this;
			}
			~Vector()
			{
				/*
					dealocat all memmory  !!!!!!!!!!!!!!!!!!!!
				*/			
			}	
			reference operator[](l_size n) const
			{
				return (this->storage[n]);
			}
			iterator begin()
			{
				return (iterator(&storage[0]));
			}
			iterator end()
			{
				return (iterator(&storage[_size]));
			}
			const_iterator end() const
			{
				return (const_iterator(&storage[_size]));
			}
			const_iterator begin() const
			{
				return (const_iterator(&storage[0]));
			}
			reverse_iterator rbegin()
			{
				return  (reverse_iterator(this->end()));
			}
			const_reverse_iterator rbegin() const
			{
				return  (const_reverse_iterator(this->end()));
			}

			reverse_iterator rend()
			{
				return  (reverse_iterator(this->begin()));
			}
			const_reverse_iterator rend() const
			{
				return  (const_reverse_iterator(this->begin()));
			}
			l_size size() const
			{
				return this->_size;
			}
			l_size capacity() const
			{
				return (_capacity);
			}
			l_size max_size() const
			{
				return alloc.max_size();
			}
			void resize (l_size n, value_type val = value_type())
			{

			}
			void reserve (l_size n)
			{
				if (n <= _capacity)
					return ;

				value_type *new_storage = alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
				{
					new_storage[i] = storage[i];
					alloc.destroy(storage+i);
				}
				if (_capacity)
					alloc.deallocate(storage, n);
				
				storage = new_storage;
				_capacity = n;

			}
	};

};

#endif