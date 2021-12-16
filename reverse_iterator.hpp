#ifndef __R_iter
#define __R_iter
#include "random_access_iterator.hpp"
namespace ft
{
	template <class Iterator_>
	class reverse_iterator
	{
		private:
			typedef reverse_iterator <random_access_iterator <typename Iterator_::iterator_category, const typename Iterator_::value_type> > const_reverse_iterator;
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
			explicit reverse_iterator (iterator_type it) : current(it){
				std::cout << "check done" << std::endl;
			}

			// template <class Iter>
			explicit reverse_iterator (const reverse_iterator& rev_it){
				this->current = rev_it.base();
				std::cout << "$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
				std::cout << typeid(this->current).name() << std::endl;
				std::cout << "$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
				std::cout << typeid(rev_it.base()).name() << std::endl;
				std::cout << "$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
			}
			
			reverse_iterator& operator=(reverse_iterator const &r_it){
				std::cout << "-------------------" << std::endl;
				std::cout << typeid(reverse_iterator::iterator_type).name() << std::endl;
				std::cout << "-------------------" << std::endl;
				
				if (this == &r_it)
					return (*this);
				//this->current = r_it.current;
				return (*this);
			}

			reference operator*(){
				return *(current - 1);
			}
			operator const_reverse_iterator() {
				return const_reverse_iterator(this->current);
			}
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
			// operator const_reverse_iterator(){
			// 	std::cout << "DKGKDJG" << std::endl;
			//    	return const_reverse_iterator(this->current);
			// }

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