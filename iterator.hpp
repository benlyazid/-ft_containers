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

			Iterator(T *m_ptr) :current(m_ptr){}

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
				return const_iterator(this->current);
			}


			Iterator(){}
			Iterator& operator=(Iterator const &t)
			{
				if (this == &t)
					return *this;
				this->current = t.current;
				return *this;
			}
			reference operator*()
			{
				return(*current);
			}
			pointer operator->() const
			{
				return (current); 
			}

			Iterator& operator++() 
			{
				current++;
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
				current--;
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
				return (this->current == iter.current);
			}
			bool operator!=(const Iterator  &iter) const
			{
				return (this->current != iter.current);
			}
			bool operator >(const Iterator &iter) const
			{
				return (this->current > iter.current);
			}				
			bool operator >=(const Iterator &iter) const
			{
				return (this->current >= iter.current);
			}					
			bool operator <(const Iterator &iter) const
			{
				return (this->current < iter.current);
			}					
			bool operator <=(const Iterator &iter) const
			{
				return (this->current <= iter.current);
			}
			Iterator operator+(int incr)
			{
				Iterator iter;
				iter = *this;
				iter.current += incr;
				return iter;
			}					
			Iterator operator-(int incr)
			{
				return (this->current - incr);
			}	
			int operator -(Iterator &iter)
			{
				return this->current - iter.current;
			}
			Iterator& operator -=(int incr)
			{
				this->current -= incr;
				return *this;
			}	
			Iterator& operator +=(int incr)
			{
				this->current += incr;
				return *this;
			}
			friend Iterator operator+(int number, const Iterator& iter)
			{
				return iter.current + number;
			}
			reference operator[](__SIZE_TYPE__ index)
			{
				return this->current[index];
			}
		protected:
			pointer current;
	};
};
#endif