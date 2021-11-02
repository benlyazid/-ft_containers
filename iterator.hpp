#ifndef __ITER__
#define __ITER__

namespace ft
{

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class Iterator
	{		
		public:

			typedef Category iterator_category ;
			typedef T value_type ;
			typedef Pointer pointer ;
			typedef Reference reference ;
			typedef Distance difference_type ;
			typedef Iterator<std::random_access_iterator_tag, const T> const_iterator;

			Iterator(T *m_ptr) :ptr(m_ptr){}

			Iterator(const Iterator  &t)
			{
				*this = t;
			}
			Iterator(const_iterator  &t)
			{
				*this = t;
			}
			operator const_iterator()
			{
				return const_iterator(this->ptr);
			}


			Iterator(){}
			Iterator& operator=(Iterator const &t)
			{
				if (this == &t)
					return *this;
				this->ptr = t.ptr;
				return *this;
			}
			reference operator*()
			{
				return(*ptr);
			}
			pointer operator->() const
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

			Iterator& operator--() 
			{
				ptr--;
				return (*this); 
			}  
			Iterator operator--(int) 
			{ 
				Iterator tmp = *this;
				--(*this); 
				return tmp;
			}
			bool operator==(const Iterator  &iter) const
			{
				return (this->ptr == iter.ptr);
			}
			bool operator!=(const Iterator  &iter) const
			{
				return (this->ptr != iter.ptr);
			}
			bool operator >(const Iterator &iter) const
			{
				return (this->ptr > iter.ptr);
			}				
			bool operator >=(const Iterator &iter) const
			{
				return (this->ptr >= iter.ptr);
			}					
			bool operator <(const Iterator &iter) const
			{
				return (this->ptr < iter.ptr);
			}					
			bool operator <=(const Iterator &iter) const
			{
				return (this->ptr <= iter.ptr);
			}
			Iterator operator+(int incr)
			{
				Iterator iter;
				iter = *this;
				iter.ptr += incr;
				return iter;
			}					
			Iterator operator-(int incr)
			{
				return (this->ptr - incr);
			}	
			int operator -(Iterator &iter)
			{
				return this->ptr - iter.ptr;
			}
			Iterator& operator -=(int incr)
			{
				this->ptr -= incr;
				return *this;
			}	
			Iterator& operator +=(int incr)
			{
				this->ptr += incr;
				return *this;
			}
			friend Iterator operator+(int number, const Iterator& iter)
			{
				return iter.ptr + number;
			}
			reference operator[](__SIZE_TYPE__ index)
			{
				return this->ptr[index];
			}
		protected:
			pointer ptr;
	};
};
#endif