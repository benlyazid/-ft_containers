/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:55 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/10/20 19:59:21 by kbenlyaz         ###   ########.fr       */
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
	
	class vector
	{
		private:
			T *storage;
			Allocator alloc;
			l_size size;

		public:
		
			struct Iterator
			{
				private:
					T ptr;
				
				public:
					typedef std::random_access_iterator_tag iterarator_type;
					Iterator(T m_ptr)
					{
						ptr = m_ptr;
					}
					T& operator*()
					{
						return( *ptr);
					}
					Iterator operator->()
					{
						return (ptr); 
					}
					Iterator& operator++() 
					{
						ptr++;
						return (*this); 
					}  
					Iterator operator++(int) 
					{ 
						Iterator tmp = *this;
						++(*this); 
						return tmp;
					}
			};
			
			vector(const Allocator& alloc = Allocator())
			{
				this->alloc = alloc;
				this->starge = this->alloc.allocate(100);
			}
			
			vector(l_size n, const T& val =T(), const Allocator& alloc = Allocator())
			{
				this->alloc = alloc;
				this->storage = this->alloc.allocate(n * 2);
				for (l_size i = 0; i < n; i++)
				{
					this->storage[i] = val;
				}
				
			}
			
			vector(const vector& v)
			{
				this = v;
			}

			vector(Iterator first, Iterator last, const Allocator& alloc = Allocator())
			{
				std::cout << "her1\n";
				
			}
			vector& operator=(const vector& v)
			{
				
			}
			
			~vector()
			{
				
			}
			
			T operator[](l_size n)const
			{
				return this->storage[n];
			}
			Iterator begin()
			{
				return (Iterator(&storage[0]));
			}
			
			Iterator end()
			{
				return (Iterator(&storage[size]));
			}
	};

};

#endif