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
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include <math.h>
#include "./utils.hpp"
namespace ft
{
	typedef  __SIZE_TYPE__  l_size;
	template<class T, class Allocator = std::allocator<T> >

	class Vector{
		private:
			T *_storage;
			Allocator alloc;
			l_size _size;
			l_size _capacity;
			l_size calcule_new_capacity(l_size n)
			{
				l_size new_size = _capacity * 2;
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
			typedef ft::random_access_iterator<std::random_access_iterator_tag, T> iterator ;
			typedef ft::random_access_iterator<std::random_access_iterator_tag, const T> const_iterator;
			typedef reverse_iterator<const_iterator> const_reverse_iterator;
			typedef reverse_iterator<iterator> reverse_iterator;
			typedef size_t size_type;
		private :
				template<class InputIterator>
				void	iterator_construct_by_type(InputIterator first, InputIterator last, std::input_iterator_tag){
					while (first != last){
						push_back(*first);
						++first;
					}
				}

				template<class InputIterator>
				void	iterator_construct_by_type(InputIterator first, InputIterator last, std::forward_iterator_tag){
					this->_size = std::distance(first, last);
					this->_capacity = this->_size;
					this->_storage = this->alloc.allocate(_size);
					int i = 0;
					while (first != last)
					{
						this->alloc.construct(_storage + i, *first);
						first++;
						i++;
					}			
				}
		public:
			explicit Vector(const Allocator& alloc = Allocator()){

				this->alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
				this->_storage = NULL;
			}
		
			explicit Vector(l_size n, const T& val = T(), const Allocator& alloc = Allocator()){
				this->_size = n;
				this->alloc = alloc;
				this->_storage = this->alloc.allocate(n);
				this->_capacity = n;
				for (l_size i = 0; i < n; i++){
					this->alloc.construct(_storage + i, val);
				}
			}
			Vector(const Vector& v){
				_size = 0;
				_capacity = 0;
				_storage = NULL;
				*this = v;
			}
			template <class InputIterator>
			Vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
				_size = 0;
				_capacity = 0;
				this->alloc = alloc;
				typename ft::iterator_traits<InputIterator>::iterator_category test;
				this->alloc = alloc;
				iterator_construct_by_type(first, last, test);
			}
			Vector& operator=(const Vector& v){
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
			
			~Vector(){
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
				return (iterator(_storage));
			}
			iterator end()
			{
				return (iterator(_storage + _size));
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
					return (false);
				return true;
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
				l_size new_capacity = n;
				pointer new_storage = alloc.allocate(new_capacity);
				for (size_t i = 0; i < n; i++){
					if (i < _size)
						alloc.construct(new_storage + i, _storage[i]);					
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
			void reserve (l_size n){
				if (n <= _capacity)
					return ;
				pointer	new__storage = alloc.allocate(n);
				for (l_size i = 0; i < _size; i++){
					alloc.construct(new__storage + i, _storage[i]);
					alloc.destroy(_storage + i);
				}
				if (_capacity)
					alloc.deallocate(_storage, _capacity);
				_storage = new__storage;
				_capacity = n;
			}
			reference at (l_size n){
				if (n > _size)
					throw(std::out_of_range("at"));
					return _storage[n];
			}
			const_reference at (l_size n) const{
				if (n > _size)
					throw(std::out_of_range("at"));
				return (_storage[n]);
			}
			reference front(){
					return (_storage[0]);
			}
			const_reference front() const{
				return (_storage[0]);
			}
			reference back(){
				return (_storage[_size - 1]);
			}
			const_reference back() const{
				return (_storage[_size - 1]);
			}
			template <class InputIterator>
		  	void assign (InputIterator first, InputIterator last,  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
				l_size new_size = last - first;
				l_size index = 0;
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
			void assign (l_size n, const value_type& val){

				l_size new_size = n;
				l_size index = 0;
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
			void push_back (const value_type& val){
				if (_capacity > _size){
					alloc.construct(_storage + _size, val);
					_size++;
					return ;
				}
				l_size new_capacity = calcule_new_capacity(_size + 1);
				pointer new_storage = alloc.allocate(new_capacity);
				for (l_size i = 0; i < _size; i++){
					 alloc.construct(new_storage + i, _storage[i]);
					 alloc.destroy(_storage + i);
				}
				if (_size)
					alloc.deallocate(_storage, _capacity);
				alloc.construct(new_storage + _size, val);
				_capacity = new_capacity;
				++_size;
				_storage = new_storage;

			}
			void pop_back(){
				if (!_size)
					return ;
				_size--;
				alloc.destroy(_storage + _size);
			}
			iterator insert (iterator position_iter, const value_type& val){
				l_size  position = 0;
				iterator iter = this->begin();
				while (position_iter != iter && iter != this->end()){
					iter++;
					position++;
				}
				l_size return_position = position;
				value_type new_value, tmp;
				if (_size < _capacity){
					new_value = val;
					for (; position < _size; position++){
						tmp = _storage[position];
						alloc.construct(_storage + position, new_value);
						new_value = tmp;
					}
					alloc.construct(_storage + position, new_value);
					_size++;
					return (this->begin() + return_position);
				}
				else{
					l_size new_capacity = calcule_new_capacity(_size + 1);
					pointer new_storage = alloc.allocate(new_capacity);
					l_size old_index = 0;
					_size++;
					for(l_size index = 0; index < _size; index++){
						if (index == position)
							alloc.construct(new_storage + index, val);
						else{
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
			void insert (iterator position_iter, l_size	 n, const value_type& val){
				l_size position, new_capacity;
				position  = position_iter  - this->begin();
				if (_capacity >= _size + n){
					for(int index = _size - 1; index >= 0; index--){
						if (index < (int)_size){
							alloc.construct(_storage + index + n, _storage[index]);
							alloc.destroy(_storage + index);
						 }
					}
					for(l_size index = 0; index < n; index++) {
						alloc.construct(_storage + position + index, val);
					}
					_size += n;
				}
				else{
					new_capacity = calcule_new_capacity(_size + n);
					pointer new_storage = alloc.allocate(new_capacity);
					for(l_size index = 0; index < position; index++){
						alloc.construct(new_storage + index, _storage[index]);
						alloc.destroy(_storage + index);
					}
					for(l_size index = 0; index < n; index++){
						alloc.construct(new_storage + index + position, val);
					}
					for(l_size index = position; index < _size; index++){
						alloc.construct(new_storage + index + n, _storage[index]);
						alloc.destroy(_storage + index);
					}
					alloc.deallocate(_storage, _capacity);
					_size += n;
					_capacity = new_capacity;
					_storage = new_storage;
				}
		 	}
			template <class InputIterator>
		    void insert (iterator position_iter, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
				l_size n = last - first;
				l_size position = position_iter  - this->begin();
				if (_size + n <= _capacity){
					for(l_size index = _size - 1; index >= position; index--){
						if (index < _size){
							alloc.construct(_storage + index + n, _storage[index]);
							alloc.destroy(_storage + index);
						}
					}
					for(l_size index = 0; index < n; index++){
						alloc.construct(_storage + position + index, *first);
						first++;
					}
					_size += n;
				}
				else{
						l_size new_capacity = calcule_new_capacity(_size + n);
						pointer new_storage = alloc.allocate(new_capacity);
						for(l_size index = 0; index < position; index++){
							alloc.construct(new_storage + index, _storage[index]);
							alloc.destroy(_storage + index);
						}
						for(l_size index = 0; index < n; index++){
							alloc.construct(new_storage + index + position, *first);
							first++;
						}
						for(l_size index = position; index < _size; index++){
							alloc.construct(new_storage + index + n, _storage[index]);
							alloc.destroy(_storage + index);
						}
						alloc.deallocate(_storage, _capacity);
						_size += n;
						_capacity = new_capacity;
						_storage = new_storage;
				}
			}
			iterator erase (iterator position_iter){
				l_size position = position_iter - this->begin();
				for (size_t index = position; index < _size; index++){
					alloc.destroy(_storage + index);
					if (index + 1 < _size)
						alloc.construct(_storage + index, _storage[index + 1]);
				}
				_size--;
				return (iterator(&_storage[position]));
			}
			iterator erase (iterator first, iterator last){
				l_size position = first - this->begin();
				l_size range_to_erase = last - first;
				for (size_t index = position; index < _size; index++){
					alloc.destroy(_storage + index);
					if (index + range_to_erase < _size)
						alloc.construct(_storage + index, _storage[index + range_to_erase]);
				}
				_size -= range_to_erase;				
				return (iterator(&_storage[position]));
			}

			void clear(){
				for (l_size index = 0; index < _size; index++)
					alloc.destroy(_storage + index);
				_size = 0;
			}

			void swap (Vector& x){
				T* stg = x._storage;
				size_type _sz = x._size, _cp = x._capacity;

				x._capacity = this->_capacity;
				this->_capacity = _cp;
				
				x._size = this->_size;
				this->_size = _sz;

				x._storage = this->_storage;
				this->_storage = stg;

			}
			allocator_type get_allocator() const{
				return (alloc);
			}
	};
	template <class T_V, class Alloc>
  	void swap (Vector<T_V,Alloc>& x, Vector<T_V,Alloc>& y){
		x.swap(y);
  	}
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
		while (first1 != last1){
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred){
		while (first1 != last1){
			if (!pred(*first1,*first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);

	}
	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2){
		while (first1!=last1){
			if (first2==last2 || *first2<*first1) 
				return false;
			else if (*first1<*first2) 
				return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp){
		while (first1!=last1){
			if (first2==last2 || *first2<*first1) 
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}


	template <class T, class Alloc>
  	bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T, class Alloc>
	bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<=  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return !(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template <class T, class Alloc>
	bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template <class T, class Alloc>
	bool operator>=  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return !(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}	

};
#endif
 