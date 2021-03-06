#ifndef BDRCTNL__H
#define BDRCTNL__H
#include <type_traits>
#include "avl.hpp"
#include "utils.hpp"
namespace ft
{
	template <class T, class pair_t, class Pointer = T*, class Reference = T&>
	class bidirectional_iterator
	{
		public:
			typedef	typename	std::bidirectional_iterator_tag		iterator_category;
			typedef 			T 									tree_t;
			typedef	typename 	tree_t::key_t     					key_t;
			typedef typename 	tree_t::mapped_t     				mapped_t;
			typedef typename 	tree_t::node_t 						nood_t;
			typedef	typename 	Avl<key_t, mapped_t, typename tree_t::Compare>::NODE 	value_type;
			typedef 			pair_t*								pointer ;
			typedef				pair_t&								reference ;
			// typedef	typename 	Avl<key_t, mapped_t, typename tree_t::Compare>::NODE 			node_t;
			typedef				ptrdiff_t							difference_type;

		private:	
			typedef 			bidirectional_iterator< const T, const pair_t >	const_iterator;
			typedef 			bidirectional_iterator<T, pair_t >	test_iter;
			tree_t					*current_tree;
			nood_t					*_node;
		public:
			bidirectional_iterator(tree_t *m_ptr) : current_tree(m_ptr){
			}
			bidirectional_iterator(tree_t *m_ptr, nood_t* &node_ptr) :current_tree(m_ptr), _node(node_ptr){
			}

			bidirectional_iterator(const bidirectional_iterator  &t){
				*this = t;
			}

			bidirectional_iterator(){}

			operator const_iterator(){
				return const_iterator(this->current_tree, this->_node);
			}

			bidirectional_iterator& operator=(bidirectional_iterator const &t){
				if (this == &t)
					return *this;
				this->current_tree = t.current_tree;
				this->_node = t._node;
				return *this;
			}
		
			pair_t& operator*() {
				return (_node->node_pair);
			}
			
			pair_t* operator->() const{
				 return (&(_node->node_pair));
			}

			bidirectional_iterator& operator++(){
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
	
			// template <class it_1, class it_2>
			friend bool operator==(const bidirectional_iterator  &iter, const bidirectional_iterator &iter2){
				if (iter._node == iter2._node)
					return true;
				return false;
			}
		
			// template <class it_1, class it_2>
			friend bool operator!=(const bidirectional_iterator  &iter, const bidirectional_iterator &iter2){
				return !(iter == iter2);
			}
	};
};
#endif