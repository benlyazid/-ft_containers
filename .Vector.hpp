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
		
			struct iterator
			{
				private:
					T *ptr;
				
				public:
					iterator(T *m_ptr) :ptr(m_ptr){}
					iterator(){}
					iterator& operator=(iterator const &t)
					{
						if (this == &t)
							return *this;
						this->ptr = t.ptr;
						return *this;
					}
					T& operator*()
					{
						return(*ptr);
					}
					T *operator->() const
					{
						return (ptr); 
					}
					iterator& operator++() 
					{
						ptr++;
						return (*this); 
					}  
					iterator operator++(int) 
					{ 
						iterator tmp = *this;
						++(*this); 
						return tmp;
					}

					iterator& operator--() 
					{
						ptr--;
						return (*this); 
					}  
					iterator operator--(int) 
					{ 
						iterator tmp = *this;
						--(*this); 
						return tmp;
					}
					bool operator==(const iterator  &iter) const
					{
						return (this->ptr == iter.ptr);
					}
					bool operator!=(const iterator  &iter) const
					{
						return (this->ptr != iter.ptr);
					}
					bool operator >(const iterator &iter) const
					{
						return (this->ptr > iter.ptr);
					}				
					bool operator >=(const iterator &iter) const
					{
						return (this->ptr >= iter.ptr);
					}					
					bool operator <(const iterator &iter) const
					{
						return (this->ptr < iter.ptr);
					}					
					bool operator <=(const iterator &iter) const
					{
						return (this->ptr <= iter.ptr);
					}
					
					iterator operator+(int incr)
					{
						iterator iter;
						iter = *this;
						iter.ptr += incr;
						return iter;
					}					
					iterator operator-(int incr)
					{
						return (this->ptr - incr);
					}
						
					int operator -(iterator &iter)
					{
						return this->ptr - iter.ptr;
					}
					iterator& operator -=(int incr)
					{
						this->ptr -= incr;
						return *this;
					}
					
					iterator& operator +=(int incr)
					{
						this->ptr += incr;
						return *this;
					}
					friend iterator operator+(int number, const iterator& iter)
					{
						return iter.ptr + number;
					}
					T& operator[](l_size index)
					{
						return this->ptr[index];
					}
					
			};
			struct const_iterator :
			{
				private:
					T const *ptr;
				
				public:
					const_iterator(T *m_ptr) :ptr(m_ptr){}
					
					const_iterator(){}
					const_iterator& operator=(const_iterator const &t)
					{
						this->ptr = t.ptr;
						return *this;
					}
					const_iterator& operator=(iterator const &t)
					{
						this->ptr = t.ptr;
						return *this;
					}

					T& operator*()
					{
						return(*ptr);
					}
					T *operator->()const
					{
						return (ptr); 
					}
					const_iterator& operator++() 
					{
						ptr++;
						return (*this); 
					}  
					const_iterator operator++(int) 
					{ 
						const_iterator tmp = *this;
						++(*this); 
						return tmp;
					}

					const_iterator& operator--() 
					{
						ptr--;
						return (*this); 
					}  
					const_iterator operator--(int) 
					{ 
						const_iterator tmp = *this;
						--(*this); 
						return tmp;
					}
					bool operator==(const_iterator  &iter)
					{
						return (this->ptr == iter.ptr);
					}
					bool operator!=(const_iterator  &iter)
					{
						return (this->ptr != iter.ptr);
					}
					bool operator >(const_iterator &iter)
					{
						return (this->ptr > iter.ptr);
					}				
					bool operator >=(const_iterator &iter)
					{
						return (this->ptr >= iter.ptr);
					}					
					bool operator <(const_iterator &iter)
					{
						return (this->ptr < iter.ptr);
					}					
					bool operator <=(const_iterator &iter)
					{
						return (this->ptr <= iter.ptr);
					}
					
					const_iterator operator+(int incr)
					{
						const_iterator iter;
						iter = *this;
						iter.ptr += incr;
						return iter;
					}					
					const_iterator operator-(int incr)
					{
						return (this->ptr - incr);
					}
						
					int operator -(const_iterator &iter)
					{
						return this->ptr - iter.ptr;
					}
					const_iterator& operator -=(int incr)
					{
						this->ptr -= incr;
						return *this;
					}
					
					const_iterator& operator +=(int incr)
					{
						this->ptr += incr;
						return *this;
					}
					friend const_iterator operator+(int number,  const_iterator& iter)
					{
						return iter.ptr + number;
					}
					T& operator[](l_size index)
					{
						return this->ptr[index];
					}
					
			};
			Vector(const Allocator& alloc = Allocator())
			{
				this->alloc = alloc;
				this->size = 0;
				this->capcity = 0;
			}
			
			Vector(l_size n, const T& val = T(), const Allocator& alloc = Allocator())
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

			Vector(iterator first, iterator last, const Allocator& alloc = Allocator())
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
			}
			
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
			
			T operator[](l_size n)const
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