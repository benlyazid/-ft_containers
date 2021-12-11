#ifndef MAP_H
#define MAP_H
#include "avl.hpp"
#include "bidirectional_iterator.hpp"

namespace ft{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
	class map{
		public:
			typedef Key 																	key_type;
			typedef T																		mapped_type;
			typedef pair<const key_type, mapped_type>										value_type;
			typedef	Compare																	key_compare;
			typedef	Alloc																	allocator_type;
			typedef	size_t																	size_type;
			typedef	ptrdiff_t																difference_type;
			typedef typename allocator_type::reference										reference;
			typedef typename allocator_type::const_reference								const_reference;
			typedef typename allocator_type::pointer										pointer;
			typedef typename allocator_type::const_pointer									const_pointer;
			typedef bidirectional_iterator<std::bidirectional_iterator_tag,typename 
					ft::Avl<key_type, mapped_type>::NODE, key_type, mapped_type>			iterator;
			typedef bidirectional_iterator<std::bidirectional_iterator_tag, const typename
					ft::Avl<key_type, mapped_type>::NODE, key_type, mapped_type>			const_iterator;
			// 	typedef	**********														value_compare;
			//	typedef ***********								reverse_iterator
			//	typedef ***********								const_reverse_iterator

			map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				_key_compare = comp;
				_allocator = alloc;
				_my_tree.node = NULL;	
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				_key_compare = comp;
				_allocator = alloc;
				_my_tree.node = NULL;
				while(first != last){
					_my_tree.add_node(*(first).first, *(first).second, _my_tree.node, comp);
					first++;
				}
			}
			map (const map& x){
				/* should implement this function */		
			}
			~map(){
				/* destroy all elements in map */	
			}
			map& operator= (const map& x){
				/* asigement operator ;( */
			}

			iterator begin(){

				typename ft::Avl<key_type, mapped_type>::NODE *temp = _my_tree.node->get_the_smallest_one(_my_tree.node);
				return iterator(*temp);
			}
			iterator end(){

				typename ft::Avl<key_type, mapped_type>::NODE *temp = _my_tree.node->get_the_beggist_one(_my_tree.node);
				return iterator(*temp);
			}

			pair<iterator,bool> insert (const value_type& val){
				_my_tree.add_node(val.first, val.second);
				NODE *temp = _my_tree.node->find_node(_my_tree.node, val.first);
				return make_pair(val.first, val.second);
			}
			iterator insert (iterator position, const value_type& val);
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);



		private:
			Avl<key_type, mapped_type> _my_tree;
			key_compare		_key_compare;
			allocator_type	_allocator;
			size_type		_size;
			
	};

};

#endif