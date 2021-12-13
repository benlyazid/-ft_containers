#ifndef BDRCTNL__H
#define BDRCTNL__H
#include "avl.hpp"
#include "util.h"
namespace ft
{
	template <class Category, class T, class Key, class V, class NOOD, class Pointer = T*, class Reference = T& >
	class bidirectional_iterator
	{
		private:
			//typedef pair<const Key, V>	pair_type;
			typedef bidirectional_iterator<std::bidirectional_iterator_tag, const T, Key, V, NOOD> const_iterator;
		public:
			typedef Category iterator_category ;
			typedef T value_type ;
			typedef Pointer pointer ;
			typedef Reference reference ;
            typedef Key     key_type;
            typedef V       mapped_type;
			typedef	 typename Avl<Key, V>::NODE node_t;
        public:
			pointer current;
			NOOD	*_node;

			pair<key_type, mapped_type> _my_pair;
        public:
			bidirectional_iterator(T *m_ptr, int i) :current(ss){
				std::cout << "construct beodirec... " << current->node->key << std::endl;
			}

			// bidirectional_iterator(const bidirectional_iterator  &t){
			// 	*this = t;
			// }

			bidirectional_iterator(){}
			bidirectional_iterator& operator=(bidirectional_iterator const &t){
				if (this == &t)
					return *this;
				this->current = t.current;
				return *this;
			}
			// pair<key_type, mapped_type> operator*(){
            //     ft::pair<key_type, mapped_type> p = make_pair<current->key, current->value>;
			// 	return(p);
			// }
			pair<key_type, mapped_type> *operator->(){
				std::cout << "check for -> "  << current->node->key << std::endl;
				_my_pair.first = current->node->key;
				_my_pair.second = current->node->value;
				return (&_my_pair);
			}

			bidirectional_iterator& operator++(){
				node_t *temp = current->node;
				current->node = current->node->next_node(current->node);
				if (current->node == NULL){
					current->node = temp;
					current->node->is_the_last_node = true;
				}
				//std::cout << "set_the last " << current->key  << "   " << current->is_the_last_node << std::endl;
				return (*this);
			}
			bidirectional_iterator operator++(int){
				bidirectional_iterator tmp = *this;
				//current = current->next_node(current);
				++(*this);
				return tmp;
			}
			bidirectional_iterator& operator--(){
				if (current->node->is_the_last_node){
					current->node->is_the_last_node = false;
					return (*this);
				}
				else
					current->node = current->node->back_node(current);
				return (*this);
			}

			bidirectional_iterator operator--(int){

				bidirectional_iterator tmp = *this;
				--(*this);
				return tmp;
			}
			template <class it_1, class it_2>
			friend bool operator==(const it_1  &iter, const it_2 &iter2){
				if (iter.current->node == iter2.current->node)
					return true;
				return false;
				/*should implement this one */
			}
			template <class it_1, class it_2>
			friend bool operator!=(const it_1  &iter, const it_2 &iter2){

				std::cout << "compare betwwen " << iter.current->node->key << " " << " and " << iter2.current->node->key << " "  << std::endl;
				std::cout << !(iter.current->node == iter2.current->node)<< std::endl;
				return !(iter == iter2);
				/*should implement this one */

			}

	};
};
#endif