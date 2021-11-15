#ifndef __ITER__
#define __ITER__

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class random_access_iterator
	{
		private:
			typedef random_access_iterator<std::random_access_iterator_tag, const T> const_iterator;
		protected:
			pointer current;
		public:
			typedef Category iterator_category ;
			typedef T value_type ;
			typedef Pointer pointer ;
			typedef Reference reference ;
			typedef Distance difference_type ;

			random_access_iterator(T *m_ptr) :current(m_ptr){}

			random_access_iterator(const random_access_iterator  &t){
				*this = t;
			}
			random_access_iterator(const_iterator  &t){
				*this = t;
			}
			operator const_iterator(){
				return const_iterator(this->current);
			}

			random_access_iterator(){}
			random_access_iterator& operator=(random_access_iterator const &t){
				if (this == &t)
					return *this;
				this->current = t.current;
				return *this;
			}
			reference operator*(){
				return(*current);
			}
			pointer operator->() const{
				return (current);
			}

			random_access_iterator& operator++(){
				current++;
				return (*this);
			}
			random_access_iterator operator++(int){
				random_access_iterator tmp = *this;
				++(*this);
				return tmp;
			}
			random_access_iterator& operator--(){
				current--;
				return (*this);
			}
			random_access_iterator operator--(int){
				random_access_iterator tmp = *this;
				--(*this);
				return tmp;
			}
			bool operator==(const random_access_iterator  &iter) const{
				return (this->current == iter.current);
			}
			bool operator!=(const random_access_iterator  &iter) const{
				return (this->current != iter.current);
			}
			bool operator >(const random_access_iterator &iter) const{
				return (this->current > iter.current);
			}
			bool operator >=(const random_access_iterator &iter) const{
				return (this->current >= iter.current);
			}
			bool operator <(const random_access_iterator &iter) const{
				return (this->current < iter.current);
			}
			bool operator <=(const random_access_iterator &iter) const{
				return (this->current <= iter.current);
			}
			random_access_iterator operator+(int incr)const{
				random_access_iterator iter;
				iter = *this;
				iter.current += incr;
				return iter;
			}
			random_access_iterator operator-(int incr)const{
				return (this->current - incr);
			}
			int operator-(random_access_iterator  const &iter) const{
				return (this->current - iter.current);
			}
			random_access_iterator& operator -=(int incr){
				this->current -= incr;
				return *this;
			}
			random_access_iterator& operator +=(int incr){
				this->current += incr;
				return *this;
			}
			friend random_access_iterator operator+(int number, const random_access_iterator& iter){
				return (iter.current + number);
			}

			reference operator[](__SIZE_TYPE__ index){
				return this->current[index];
			}
	};
};
#endif
