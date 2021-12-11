#ifndef BDRCTNL__H
#define BDRCTNL__H
#include "avl.hpp"
namespace ft
{
	template <class Category, class T, class Key, class V, class Pointer = T*, class Reference = T& >
	class bidirectional_iterator
	{
		private:
			typedef bidirectional_iterator<std::bidirectional_iterator_tag, const T, Key, V> const_iterator;
		public:
			typedef Category iterator_category ;
			typedef T value_type ;
			typedef Pointer pointer ;
			typedef Reference reference ;
            typedef Key     key_type;
            typedef T       mapped_type;
        private:
			pointer current;
        public:
			bidirectional_iterator(T *m_ptr) :current(m_ptr){
			}

			bidirectional_iterator(const bidirectional_iterator  &t){
				*this = t;
			}

			bidirectional_iterator(){}
			bidirectional_iterator& operator=(bidirectional_iterator const &t){
				if (this == &t)
					return *this;
				this->current = t.current;
				return *this;
			}
			pair<key_type, mapped_type> operator*(){
                ft::pair<key_type, mapped_type> p = make_pair<current->key, current->value>;
				return(p);
			}
			pair<key_type, mapped_type> operator->() const{
                ft::pair<key_type, mapped_type> p = make_pair<current->key, current->value>;
				return (p);
			}

			bidirectional_iterator& operator++(){
				current = current->next_node(current);
				return (*this);
			}
			bidirectional_iterator operator++(int){
				bidirectional_iterator tmp = *this;
				current = current->next_node(current);
				return tmp;
			}
			bidirectional_iterator& operator--(){
				current = current->back_node(current);
				return (*this);
			}

			bidirectional_iterator operator--(int){
				bidirectional_iterator tmp = *this;
				current = current->back_node(current);
				return tmp;
			}
			template <class it_1, class it_2>
			friend bool operator==(const it_1  &iter, const it_2 &iter2){
				/*should implement this one */
			}
			template <class it_1, class it_2>
			friend bool operator!=(const it_1  &iter, const it_2 &iter2){
				/*should implement this one */

			}

	};
};
#endif