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
			Iterator operator+(int incr)const
			{
				Iterator iter;
				iter = *this;
				iter.current += incr;
				return iter;
			}
			Iterator operator-(int incr)const
			{
				return (this->current - incr);
			}
			int operator-(Iterator  const &iter) const
			{
				return (this->current - iter.current);
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
				return (iter.current + number);
			}


			//SHOULD DELETE THIS FUNCTION ;
			/*friend Iterator operator-(int number, const Iterator& iter)
			{
				return iter.current - number;
			}*/


			reference operator[](__SIZE_TYPE__ index)
			{
				return this->current[index];
			}
		protected:
			pointer current;
	};
	/*template < class T>
	Iterator<std::random_access_iterator_tag, T> operator+(int number, const Iterator<std::random_access_iterator_tag, T>& iter)
	{
		return iter.current + number;
	}*/
};


/*
	comparison functions are not members shoould put them outside the class ;
*/
#endif
