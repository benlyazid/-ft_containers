#ifndef BDRCTNL__H
#define BDRCTNL__H
#include "avl.hpp"
#include "util.h"
namespace ft
{
	template <class T, class Pointer = T*, class Reference = T& >
	class bidirectional_iterator
	{
		public:
			typedef	typename	std::bidirectional_iterator_tag		iterator_category;
			typedef 			T 									tree_t;
			typedef typename 	tree_t::node_t 						nood_t;
			typedef 			Pointer								pointer ;
			typedef				Reference							reference ;
			typedef	typename 	tree_t::key_t     					key_t;
			typedef typename 	tree_t::mapped_t     				mapped_t;
			typedef	typename 	Avl<key_t, mapped_t>::NODE 			node_t;
			typedef 			pair<key_t, mapped_t>				pair_t;

		private:	
			typedef 			bidirectional_iterator<const T> 	const_iterator;
			tree_t					*current_tree;
			nood_t					*_node;
			pair<key_t, mapped_t>	_my_pair;
		public:
			bidirectional_iterator(tree_t *m_ptr, nood_t *node_ptr) :current_tree(m_ptr), _node(node_ptr){
			}

			bidirectional_iterator(const bidirectional_iterator  &t){
				*this = t;
			}

			bidirectional_iterator(){}
			bidirectional_iterator& operator=(bidirectional_iterator const &t){
				if (this == &t)
					return *this;
				this->current_tree = t.current_tree;
				this->_node = t._node;
				return *this;
			}
		
			pair_t operator*(){
				_my_pair.first = _node->key;
				_my_pair.second = _node->value;
				return(_my_pair);
			}
			
			pair_t *operator->(){
				_my_pair.first = _node->key;
				_my_pair.second = _node->value;
				 return (&_my_pair);
			}

			bidirectional_iterator& operator++(){
				node_t *temp = _node;
				_node = _node->next_node(_node);
				if (_node == NULL){
					_node = current_tree->the_last_node;
				}
				return (*this);
			}

			bidirectional_iterator operator++(int){
				bidirectional_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			bidirectional_iterator& operator--(){
				if (_node == current_tree->the_last_node){
					_node = _node->get_the_beggist_one(current_tree->node);
					return (*this);
				}
				else
					_node = _node->back_node(_node);
				return (*this);
			}

			bidirectional_iterator operator--(int){

				bidirectional_iterator tmp = *this;
				--(*this);
				return tmp;
			}
	
			template <class it_1, class it_2>
			friend bool operator==(const it_1  &iter, const it_2 &iter2){
				if (iter._node == iter2._node)
					return true;
				return false;
			}
		
			template <class it_1, class it_2>
			friend bool operator!=(const it_1  &iter, const it_2 &iter2){
				return !(iter == iter2);
			}
	};
};
#endif