#ifndef __R_iter
#define __R_iter
#include "random_access_iterator.hpp"
namespace ft
{
	template <class Iterator_>
	class reverse_iterator
	{
		private:
			// typedef reverse_iterator <random_access_iterator <typename Iterator_::iterator_category, const typename Iterator_::value_type> > const_reverse_iterator;

			// typedef reverse_iterator <const  Iterator_ > const_reverse_iterator;
		public:
			typedef 			Iterator_ iterator_type;
			typedef typename	Iterator_::iterator_category iterator_category;
			typedef typename 	Iterator_::value_type value_type;
			typedef typename 	Iterator_::difference_type difference_type;
			typedef typename 	Iterator_::pointer pointer;
			typedef typename 	Iterator_::reference reference;
		protected:
			iterator_type current;
		public:
			reverse_iterator() : current(NULL){
			}
			reverse_iterator (iterator_type  it) : current(it){
			}

			reverse_iterator (const reverse_iterator& rev_it){
				this->current = rev_it.base();
			}
			
			template <class iter_t>
			reverse_iterator& operator=(iter_t const &r_it){
				this->current = r_it.base();
				return (*this);
			}

			reference operator*(){
				iterator_type tmp = current;
				--tmp;
				return *tmp;

			}
			// operator reverse_iterator<const iterator_type>() {
			// 	return reverse_iterator<const iterator_type>(this->current);
			// }

			iterator_type base() const{
				return  current;
			}
			pointer operator->(){
				return &(operator*());
			}
			reverse_iterator operator+(difference_type n){
				return reverse_iterator(current - n);
			}
			reverse_iterator& operator+=(difference_type n){
				current -= n;
				return (*this);
			}
			reverse_iterator& operator-=(difference_type n){
				current += n;
				return (*this);
			}
 			reference operator[](difference_type n){
				return *(current - 1 - n);
			}
			reverse_iterator& operator++(){
				--current;
				return *this;
			}
			reverse_iterator& operator--(){
				++current;
				return *this;
			}
			
			reverse_iterator operator++(int){
				reverse_iterator tmp(*this);
				--current;
				return tmp;
			}
			reverse_iterator operator--(int){
				reverse_iterator tmp(*this);
				++current;
				return tmp;
			}
			reverse_iterator  operator- (difference_type n) const {
				return reverse_iterator(current + n);
			}
			reverse_iterator operator+ (difference_type n) const {
				return reverse_iterator(current - n);
			}
	};
	template <class Iterator_class>
  	reverse_iterator<Iterator_class> operator+ (typename reverse_iterator<Iterator_class>::difference_type n, const reverse_iterator<Iterator_class>& rev_it){
		return reverse_iterator<Iterator_class>(rev_it + n);
	}
	template <class Iterator_class>
  	typename reverse_iterator<Iterator_class>::difference_type operator- (const reverse_iterator<Iterator_class>& lhs, const reverse_iterator<Iterator_class>& rhs){
			return (rhs.base()  - lhs.base());
	}
	template <class Iterator_class, class Iterator_class_2>
  	bool operator== (const reverse_iterator<Iterator_class>& lhs, const reverse_iterator<Iterator_class_2>& rhs){
		return (lhs.base() == rhs.base());
	}
	template <class Iterator_class, class Iterator_class_2>
  	bool operator!= (const reverse_iterator<Iterator_class>& lhs, const reverse_iterator<Iterator_class_2>& rhs){
		return (lhs.base() != rhs.base());
	}
	template <class Iterator_class, class Iterator_class_2>
  	bool operator<  (const reverse_iterator<Iterator_class>& lhs,  const reverse_iterator<Iterator_class_2>& rhs){
		return (rhs.base() < lhs.base());
	}
	template <class Iterator_class, class Iterator_class_2>
  	bool operator<= (const reverse_iterator<Iterator_class>& lhs, const reverse_iterator<Iterator_class_2>& rhs){
		return (rhs.base() <= lhs.base());
	}
	template <class Iterator_class, class Iterator_class_2>
  	bool operator>  (const reverse_iterator<Iterator_class>& lhs, const reverse_iterator<Iterator_class_2>& rhs){
		return (rhs.base() > lhs.base());
	}
	template <class Iterator_class, class Iterator_class_2>
	bool operator>= (const reverse_iterator<Iterator_class>& lhs, const reverse_iterator<Iterator_class_2>& rhs){
		return (rhs.base() >= lhs.base());
	}	
};

#endif