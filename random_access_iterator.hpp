#ifndef __ITER__
#define __ITER__

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class random_access_iterator
	{
		private:
			typedef random_access_iterator<std::random_access_iterator_tag, const T> const_iterator;
		public:
			typedef Category iterator_category ;
			typedef T value_type ;
			typedef Pointer pointer ;
			typedef Reference reference ;
			typedef Distance difference_type ;
		protected:
			pointer current;
		public:
			random_access_iterator(T *m_ptr) :current(m_ptr){
			}

			random_access_iterator(const random_access_iterator  &t){
				*this = t;
			}
			
			operator const_iterator(){
			 	std::cout << "JHDGFKDGH" << std::endl;
			   	return const_iterator(this->current);
			}

			random_access_iterator(){}
			random_access_iterator& operator=(random_access_iterator const &t){
				// if (this == &t)
				// 	return *this;
				// this->current = t.current;
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

			random_access_iterator& base(){
				return (*this);
			}
			
			random_access_iterator operator--(int){
				random_access_iterator tmp = *this;
				--(*this);
				return tmp;
			}
			// change this from const it_1 ... to rando....<category, it_1> 
			template <class it_1, class it_2>
			friend bool operator==(const it_1  &iter, const it_2 &iter2){
				return (iter.current == iter2.current);
			}

			template <class it_1, class it_2>
			friend bool operator!=(const it_1  &iter, const it_2 &iter2){
				return (iter.current != iter2.current);
			}

			template <class it_1, class it_2>
			friend bool operator >(const it_1  &iter, const it_2 &iter2){
				return (iter.current > iter2.current);
			}

			template <class it_1, class it_2>
			friend bool operator >=(const it_1  &iter, const it_2 &iter2){
				return (iter.current >= iter2.current);
			}

			template <class it_1, class it_2>
			friend bool operator <(const it_1  &iter, const it_2 &iter2){
				return (iter.current < iter2.current);
			}

			template <class it_1, class it_2>
			friend bool operator <=(const it_1  &iter, const it_2 &iter2){
				return (iter.current <= iter2.current);
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

			template <class it_1, class it_2>
			friend long long operator-(random_access_iterator<Category, it_1>  const &iter, random_access_iterator<Category, it_2> const &iter2){
				return (iter.current - iter2.current);
			}

			random_access_iterator& operator -=(int incr){
				this->current -= incr;
				return *this;
			}
			random_access_iterator& operator +=(int incr){
				this->current += incr;
				return *this;
			}
			template <class it_1>
			
			friend random_access_iterator operator+(int number, const random_access_iterator<Category, it_1> & iter){
				return (iter.current + number);
			}
			reference operator[](__SIZE_TYPE__ index){
				return this->current[index];
			}
	};
};
#endif
