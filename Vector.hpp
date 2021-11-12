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
			T *_storage;
			Allocator alloc;
			l_size _size;
			l_size _capacity;
			l_size calcule_new_capacity(l_size n)
			{
				l_size upgrade = 2;
				l_size new_size = _size * upgrade;
				if (new_size >= n)
					return new_size;
				return (n);
			}
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
			typedef size_t size_type;

			explicit Vector(const Allocator& alloc = Allocator())
			{

				this->alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
				this->_storage = NULL;
			}
			explicit Vector(l_size n, const T& val = T(), const Allocator& alloc = Allocator())
			{
				this->_size = n;
				this->alloc = alloc;
				this->_storage = this->alloc.allocate(n);
				this->_capacity = n;
				for (l_size i = 0; i < n; i++)
				{
					this->alloc.construct(_storage + i, val);
				}
			}
			Vector(const Vector& v)
			{
				_size = 0;
				_capacity = 0;
				_storage = NULL;
				*this = v;
			}
			template <class InputIterator>
			Vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				this->_size = abs(last - first);
				this->_capacity = this->_size;
				this->alloc = alloc;
				this->_storage = this->alloc.allocate(_size);
				int i = 0;
				while (first != last)
				{
					this->alloc.construct(_storage + i, *first);
					first++;
					i++;
				}
			}
			Vector& operator=(const Vector& v)
			{
				if (this != &v)
				{
					for (size_t i = 0; i < _size ; i++)
					{
						alloc.destroy(_storage + i);
					}
					if (_capacity)
						alloc.deallocate(_storage, _capacity);
					this->alloc = v.alloc;

					this->_size = v._size;
					this->_capacity = v._capacity;
					if (_capacity)
						this->_storage = alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
					{
						alloc.construct(_storage + i, v._storage[i]);
					}
				}
				return *this;
			}
			~Vector()
			{
				for (size_t i = 0; i < _size; i++)
				{
					alloc.destroy(_storage + i);
				}
				if (_capacity)
					alloc.deallocate(_storage, _capacity);
			}
			reference operator[](l_size n)
			{
				return (this->_storage[n]);
			}

			const_reference operator[](l_size n) const
			{
				return (this->_storage[n]);
			}

			iterator begin()
			{
				return (iterator(&_storage[0]));
			}
			iterator end()
			{
				return (iterator(&_storage[_size]));
			}
			const_iterator end() const
			{
				return (const_iterator(&_storage[_size]));
			}
			const_iterator begin() const
			{
				return (const_iterator(&_storage[0]));
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
				return (_size);
			}
			bool empty() const
			{
				if (_size)
					return (true);
				return false;
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
				if (n == _size)
					return ;
				if (n < _capacity)
				{
					for (l_size i = _size; i < n; i++)
					{
						alloc.construct(_storage + i, val);
					}
					_size = n;
					return;
				}
				l_size new_capacity = std::max(_capacity, n);
				pointer new_storage = alloc.allocate(new_capacity);
				for (size_t i = 0; i < n; i++)
				{
					if (i < _size)
					{
						alloc.construct(new_storage + i, _storage[i]);
					}
					else
						alloc.construct(new_storage + i, val);
				}
				for (size_t i = 0; i < _size; i++)
					alloc.destroy(_storage + i);
				alloc.deallocate(_storage, _capacity);
				_size = n;
				_capacity = new_capacity;
				_storage = new_storage;
			}
			void reserve (l_size n)
			{
				if (n <= _capacity)
					return ;
				pointer	new__storage = alloc.allocate(n);
				for (l_size i = 0; i < _size; i++)
				{
					alloc.construct(new__storage + i, _storage[i]);
				}
				if (_capacity)
					alloc.deallocate(_storage, _capacity);
				_storage = new__storage;
				_capacity = n;
			}
			reference at (l_size n)
			{
				if (n > _size)
					throw(std::out_of_range("at"));
					return _storage[n];
			}
			const_reference at (l_size n) const
			{
				if (n > _size)
					throw(std::out_of_range("at"));
				return (_storage[n]);
			}
			reference front()
			{
					return (_storage[_size - 1]);
			}
			const_reference front() const
			{
				return (_storage[_size - 1]);
			}
			reference back()
			{
				return (_storage[0]);
			}
			const_reference back() const
			{
				return (_storage[0]);
			}
			template <class InputIterator>
		  	void assign (InputIterator first, InputIterator last)
			{
				l_size new_size = last - first;
				int index = 0;
				if (_capacity >=  new_size)
				{
					while (first != last)
					{
						if (_size > index)
							alloc.destroy(_storage + index);
						alloc.construct(_storage + index, *first);
						++first;
						++index;
					}
					_size = new_size;
				}
				else
				{
					pointer new_storage = alloc.allocate(new_size);
					for (size_t i = 0; i < _size; i++)
					{
						alloc.destroy(_storage + i);
					}
					if (_capacity)
						alloc.deallocate(_storage, _capacity);
					_size = new_size;
					_capacity = new_size;
					index = 0;
					while (first != last)
					{
						alloc.construct(new_storage + index, *first);
						++first;
						++index;
					}
					_storage = new_storage;
				}
			}
			void assign (l_size n, const value_type& val)
			{

				l_size new_size = n;
				int index = 0;
				if (_capacity >=  new_size)
				{
					while (index < n)
					{
						if (_size > index)
							alloc.destroy(_storage + index);
						alloc.construct(_storage + index, val);
						++index;
					}
					_size = new_size;
				}
				else
				{
					pointer new_storage = alloc.allocate(new_size);
					for (size_t i = 0; i < _size; i++)
					{
						alloc.destroy(_storage + i);
					}
					if (_capacity)
						alloc.deallocate(_storage, _capacity);
					_size = new_size;
					_capacity = new_size;
					index = 0;
					while (index < n)
					{
						alloc.construct(new_storage + index, val);
						++index;
					}
					_storage = new_storage;
				}
			}
			void push_back (const value_type& val)
			{
				if (_capacity > _size)
				{
					alloc.construct(_storage + _size, val);
					_size++;
					return ;
				}
				l_size new_capacity = calcule_new_capacity(_size + 1);
				pointer new_storage = alloc.allocate(new_capacity);
				for (l_size i = 0; i < _size; i++)
				{
					 alloc.construct(new_storage + i, _storage[i]);
					 alloc.destroy(_storage + i);
				}
				alloc.deallocate(_storage, _capacity);
				alloc.construct(new_storage + _size, val);
				_capacity = new_capacity;
				++_size;
				_storage = new_storage;

			}
			void pop_back()
			{
				if (!_size)
					return ;
				_size--;
				alloc.destroy(_storage + _size);
			}
			iterator insert (iterator position_iter, const value_type& val)
			{
				l_size  position = 0;
				iterator iter = this->begin();
				while (position_iter != iter && iter != this->end())
				{
					iter++;
					position++;
				}
				l_size return_position = position;
				value_type new_value, tmp;
				if (_size < _capacity)
				{
					new_value = val;
					for (; position < _size; position++)
					{
						tmp = _storage[position];
						alloc.construct(_storage + position, new_value);
						new_value = tmp;
					}
					alloc.construct(_storage + position, new_value);
					_size++;
					return (this->begin() + return_position);
				}
				else
				{
					l_size new_capacity = calcule_new_capacity(_size + 1);
					pointer new_storage = alloc.allocate(new_capacity);
					l_size old_index = 0;
					_size++;
					for(l_size index = 0; index < _size; index++)
					{
						if (index == position)
							alloc.construct(new_storage + index, val);
						else
						{
							alloc.construct(new_storage + index, _storage[old_index]);
							alloc.destroy(_storage + old_index);
							old_index++;
						}
					}
					alloc.deallocate(_storage, _capacity);
					_storage = new_storage;
					_capacity = new_capacity;
					return (this->begin() + return_position);
				}
			}
			void insert (iterator position_iter, l_size	 n, const value_type& val)
		 	{
				l_size old_index, position, new_index, new_capacity;
				position = 0;
				iterator iter = this->begin();
				while (position_iter != iter && iter != this->end())
				{
					iter++;
					position++;
				}

				if (_capacity >= _size + n)
				{
					/*
						ERROR IN THIS FUNCTION;
						IN INSERTING WHAT COME AFTER THE POSITION RANGE !!!
					*/
					for(l_size index = 0; index < n; index++)
					{
						if (index < _size)
						{
							alloc.construct(_storage + position + index + n, _storage[position + index]);
							alloc.destroy(_storage + position + index);
						}
					}
					for(l_size index = 0; index < n; index++)
					{
						alloc.construct(_storage + position + index, val);
					}
				}
				else
				{
					new_capacity = calcule_new_capacity(_size + n);
					pointer new_storage = alloc.allocate(new_capacity);
					for(l_size index = 0; index < position; index++)
					{
						alloc.construct(new_storage + index, _storage[index]);
						alloc.destroy(_storage + index);
					}
					for(l_size index = 0; index < n; index++)
					{
						alloc.construct(new_storage + index + position, val);
					}
					for(l_size index = position; index < _size; index++)
					{
						alloc.construct(new_storage + index + n, _storage[index]);
						alloc.destroy(_storage + index);
					}
					alloc.deallocate(_storage, _capacity);
					_size += n;
					_capacity = new_capacity;
					_storage = new_storage;
				}
		 	}

	};

};

#endif
