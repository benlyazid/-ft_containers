#ifndef __ITER__
#define __ITER__

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
class Iterator
{		
	public:
		typedef Category iterator_category ;
		typedef T value_type ;
		typedef Pointer pointer ;
		typedef Reference reference ;
		typedef Iterator<std::random_access_iterator_tag, const T> const_iterator;

		Iterator(T *m_ptr) :ptr(m_ptr){}

		Iterator(Iterator const  &t)
		{
			*this = t;
		}
		Iterator(const_iterator  &t)
		{
			*this = t;
		}
		operator Iterator<std::random_access_iterator_tag, const T>()
		{
			return Iterator<std::random_access_iterator_tag, const T>(this->ptr);
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
	private:
		pointer ptr;
};

#endif