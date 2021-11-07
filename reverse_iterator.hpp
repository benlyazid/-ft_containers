#ifndef __R_iter
#define __R_iter
#include "iterator.hpp"
namespace ft
{
	template <class Iterator_>
	class reverse_iterator
	{
		public:
			typedef 			Iterator_ iterator_type;
			typedef typename	Iterator_::iterator_category iterator_category;
			typedef typename 	Iterator_::value_type value_type;
			typedef typename 	Iterator_::difference_type difference_type;
			typedef typename 	Iterator_::pointer pointer;
			typedef typename 	Iterator_::reference reference;
			typedef reverse_iterator <Iterator <typename Iterator_::iterator_category, const typename Iterator_::value_type> > const_reverse_iterator;

			reverse_iterator() : current(NULL)
			{

			}

			explicit reverse_iterator (iterator_type it) : current(it)
			{
			}

			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it)
			{
				*this = rev_it;
			}
			
			reverse_iterator& operator=(reverse_iterator const &r_it)
			{
				if (this == &r_it)
					return (*this);
				this->current = r_it.current;
				return (*this);
			}
			reference operator*()
			{
				return *(current - 1);
			}
			operator const_reverse_iterator() //!!!!!!!!!!!!!!!!!!!!!!!
			{
				return const_reverse_iterator(this->current);
			}

			iterator_type base() const
			{
				return  current;
			}
			bool operator==(const reverse_iterator  &iter) const
			{
				return (this->base() == iter.base());
			}
	
			bool operator!=(const reverse_iterator  &iter) const
			{
				return (this->base() != iter.base());
			}

			bool operator >(const reverse_iterator &iter) const
			{
				return !(this->base() > iter.base());
			}
			bool operator >=(const reverse_iterator &iter) const
			{
				return !(this->base() >= iter.base());
			}

			bool operator<(const reverse_iterator &iter) const
			{
				return !(this->base() < iter.base());
			}
			bool operator <=(const reverse_iterator &iter) const
			{
				return !(this->base() <= iter.base());
			}
			pointer operator->() 
			{
				return &(operator*());
			}
			int operator-(reverse_iterator iter)
			{
				return (iter.current - current);
			}

			reverse_iterator operator+(difference_type n)
			{
				return reverse_iterator(current - n);
			}
			reverse_iterator& operator+=(difference_type n)
			{
				current -= n;
				return (*this);
			}
			reverse_iterator& operator-=(difference_type n)
			{
				current += n;
				return (*this);
			}
 			reference operator[](difference_type n) //const 
			{
				return (current[n - 1]);
			}
			reverse_iterator& operator++()
			{
				--current;
				return *this;
			}
			reverse_iterator& operator--()
			{
				++current;
				return *this;
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp(*this);
				--current;
				return tmp;
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp(*this);
				++current;
				return tmp;
			}
			reverse_iterator  operator- (difference_type n) const 
			{
				return reverse_iterator(current + n);
			}
			reverse_iterator operator+ (difference_type n) const 
			{
				return reverse_iterator(current - n);
			}
			friend reverse_iterator operator+(difference_type number, const reverse_iterator& iter)
			{
				return reverse_iterator(iter.current - number);
			}

		protected:
			iterator_type current;
	};
};

#endif